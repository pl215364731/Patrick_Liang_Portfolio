#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

int foregroundOnly = 0;
//struct to organize and store the command line 
struct commandLine {
    //The first argument is the command itself, 512 arguments + command = 513
    char* args[513];
    int argCount;
    char* input_file;
    char* output_file;
    int background;
};

void SIGTSTP_handler(int sigNum){
    char* message;
    if(foregroundOnly){
        foregroundOnly = 0;
        message = "\nExiting foreground-only mode\n: ";
    } else{
        foregroundOnly = 1;
        message = "\nEntering foreground-only mode (& is now ignored)\n: ";
    }
    write(STDOUT_FILENO, message, strlen(message));
}

void setup_SIGTSTP(){
    signal(SIGTSTP, SIGTSTP_handler);
}

void setup_parent_SIGINT(){
    struct sigaction SIGINT_action = {0};
    // Fill out the SIGINT_action struct
	SIGINT_action.sa_handler = SIG_IGN;
	sigfillset(&SIGINT_action.sa_mask);
	SIGINT_action.sa_flags = 0;
	// Install signal handler
	sigaction(SIGINT, &SIGINT_action, NULL);
}

void setup_child_SIGINT(){
    struct sigaction SIGINT_action = {0};
    // Fill out the SIGINT_action struct
	SIGINT_action.sa_handler = SIG_DFL;
	sigfillset(&SIGINT_action.sa_mask);
	SIGINT_action.sa_flags = 0;
	// Install signal handler
	sigaction(SIGINT, &SIGINT_action, NULL);
}

//print function for debugging, this is not used in the actual program
void printCommandData(struct commandLine* currLine){
    printf("------------------------\nCommand: %s\n", currLine->args[0]);
    for(int i = 1; i < currLine->argCount; i++){
        printf("Arg%d: %s \n", i, currLine->args[i]);
    }
    if(currLine->input_file != NULL){
        printf("Input File: %s\n", currLine->input_file);
    }
    if(currLine->output_file != NULL){
        printf("Output File: %s\n", currLine->output_file);
    }
    if(currLine->background){
        printf("Background process\n------------------------\n");
    } else{
        printf("Foreground process\n------------------------\n");
    }
   
}

struct commandLine* processInput(char *input){
    //getting rid of \n
    input[strlen(input) - 1] = '\0';

    char* saveptr;
    int itemCounter = 0;
    struct commandLine* currLine = malloc(sizeof(struct commandLine));
    currLine->argCount = 0;
    currLine->background = 0;
    currLine->input_file = NULL;
    currLine->output_file = NULL;

    char* token = strtok_r(input, " ", &saveptr);
    while (token != NULL)
    {
        if(token[0] == '<'){ //check for input redirection
            token = strtok_r(NULL, " ", &saveptr);
            currLine->input_file = calloc(strlen(token) + 1, sizeof(char));
            strcpy(currLine->input_file, token);
        } else if(token[0] == '>') { //check for output redirection
            token = strtok_r(NULL, " ", &saveptr);
            currLine->output_file = calloc(strlen(token) + 1, sizeof(char));
            strcpy(currLine->output_file, token);
        } else if(strcmp(token, "$$") == 0){ //check for variable expansion
            char pid[256];
            sprintf(pid, "%d", getpid());
            currLine->args[currLine->argCount] = calloc(strlen(pid) + 1, sizeof(char));
            strcpy(currLine->args[currLine->argCount], pid);
            currLine->argCount++;
            currLine->args[currLine->argCount] = NULL;
        }
        else {
            currLine->args[currLine->argCount] = calloc(strlen(token) + 1, sizeof(char));
            strcpy(currLine->args[currLine->argCount], token);
            currLine->argCount++;
            currLine->args[currLine->argCount] = NULL;
        }
        itemCounter++;
        token = strtok_r(NULL, " ", &saveptr);
    }
    if(currLine->argCount > 0 && currLine->args[currLine->argCount - 1][0] == '&'){
        //if last argument is &, set background to true
        currLine->background = 1;
        free(currLine->args[currLine->argCount - 1]);
        currLine->args[currLine->argCount - 1] = NULL;
        currLine->argCount--;
    }
    return currLine;
}

//Free the memory of the struct
void freeCommandLine(struct commandLine* currLine) {
    for(int i = 0; i < currLine->argCount; i++){
        free(currLine->args[i]);
    }
    if(currLine->input_file != NULL){
        free(currLine->input_file);
    }
    if(currLine->output_file != NULL){
        free(currLine->output_file);
    }
    free(currLine);
}

//Built in cd command
void cd(struct commandLine* currLine){
    if(currLine->argCount == 1){
        chdir(getenv("HOME"));
    } else{
        chdir(currLine->args[1]);
    }
}

//Built in status command
void status(int exited, int foregroundStatus){
    if(exited){
        printf("exit value %d\n", foregroundStatus);
    }else{
        printf("terminated by signal %d\n", foregroundStatus);
    }
    
}

void otherCommands(struct commandLine* currLine, int* foregroundStatus, int* exited, int* backgroundPids, int* backgroundCount){
    pid_t spawnpid = -5;
    int childStatus = 0;
    // If fork is successful, the value of spawnpid will be 0 in the child, the child's pid in the parent
	spawnpid = fork();
	if(spawnpid == -1){
        // Code in this branch will be exected by the parent when fork() fails and the creation of child process fails as well
		perror("fork() failed!");
		exit(1);
	} 
    else if(spawnpid == 0){
        // spawnpid is 0. This means the child will execute the code in this branch
        if(currLine->background == 0){
            setup_child_SIGINT();
        }
        //file redirection
        int inFd = -1;
        int outFd = -1;
        if(currLine->input_file != NULL){ //input redirection
            inFd = open(currLine->input_file, O_RDONLY);
            if(inFd == -1){
                printf("cannot open %s for input\n", currLine->input_file);
                exit(1);
            }
            if(dup2(inFd, STDIN_FILENO) < 0) {
                printf("Unable to duplicate file descriptor.");
                exit(1);
            }
        } else if(currLine->background){ //No input redirection, background redirected to /dev/null
            inFd = open("/dev/null", O_RDONLY);
            if(inFd == -1){
                printf("cannot open %s for input\n", currLine->input_file);
                exit(1);
            }
            if(dup2(inFd, STDIN_FILENO) < 0) {
                printf("Unable to duplicate file descriptor.");
                exit(1);
            }
        }
        if(currLine->output_file != NULL){ //output redirection
            outFd = open(currLine->output_file, O_WRONLY | O_CREAT | O_APPEND, 0666);
            if(outFd == -1){
                printf("cannot open %s for output\n", currLine->output_file);
                exit(1);
            }
            if(dup2(outFd, STDOUT_FILENO) < 0) {
                printf("Unable to duplicate file descriptor.");
                exit(1);
            }
        } else if(currLine->background){ //No output redirection, background redirected to /dev/null
            outFd = open("/dev/null", O_WRONLY);
            if(outFd == -1){
                printf("cannot open %s for output\n", currLine->output_file);
                exit(1);
            }
            if(dup2(outFd, STDOUT_FILENO) < 0) {
                printf("Unable to duplicate file descriptor.");
                exit(1);
            }
        }
        
        int status = execvp(currLine->args[0], currLine->args);
        //close file descriptor
        if(inFd > 0){
            close(inFd);
        }
        if(outFd > 0){
            close(outFd);
        }

        //exit with sucess or failare signal
        if(status != 0){
            printf("%s: no such file or directory\n", currLine->args[0]);
            exit(1);
        }
        exit(0);
    }       
	else{
        // spawnpid is the pid of the child. This means the parent will execute the code in this branch
        if(currLine->background && !foregroundOnly){
            //store background pid in the array
            printf("background pid is %d\n", spawnpid);
            backgroundPids[*backgroundCount] = spawnpid;
            (*backgroundCount)++;
        } else{
            //wait for child until it is terminated or exited
            pid_t childPid = waitpid(spawnpid, &childStatus, 0);
            //printf("The parent is done waiting. The pid of child that terminated is %d. Status is %d\n", childPid, childStatus);
            if(WIFEXITED(childStatus)){
                *foregroundStatus = WEXITSTATUS(childStatus);
                *exited = 1;
            } else{
                *foregroundStatus = WTERMSIG(childStatus);
                printf("terminated by signal %d\n", *foregroundStatus);
                *exited = 0;
            }
        }
    }
}

//shell menu function
void shellMenu(){
    int foregroundStatus = 0;
    int exited = 1;
    int backgroundPids[1028];
    int backgroundCount = 0;
    while(1){
        usleep(1000);
        //check for background processes
        for(int i = 0; i < backgroundCount; i++){
            int status;
            pid_t pid = waitpid(backgroundPids[i], &status, WNOHANG);
            if(pid > 0){
                if(WIFEXITED(status)){
                printf("background pid %d is done: exit value %d\n", pid, WEXITSTATUS(status));
                } else{
                    printf("background pid %d is done: terminateed by signal %d\n", pid, WTERMSIG(status));
                }
            }
        }
        printf(": ");
        char* input = NULL;
        size_t inputSize = 2048;
        getline(&input, &inputSize, stdin);

        //variable expansion
        char pid[256];
        sprintf(pid, "%d", getpid());
        char* variable = strstr(input, "$$");
        while(variable != NULL){
            //Move the everything after $$ to where they should be
            memmove(variable + strlen(pid), variable + strlen("$$"), strlen(variable) - strlen("$$") + 1);
            memmove(variable, pid, strlen(pid));
            variable = strstr(input, "$$");
        }
        struct commandLine* currLine = processInput(input);
        free(input);
        if(currLine->argCount == 0 || currLine->args[0][0] == '#'){
            //do nothing
        } else if(strcmp(currLine->args[0], "exit") == 0){
            freeCommandLine(currLine);
            exit(0);
        } else if(strcmp(currLine->args[0], "cd") == 0){
            cd(currLine);
        } else if(strcmp(currLine->args[0], "status") == 0){
            status(exited, foregroundStatus);
        } else{
            otherCommands(currLine, &foregroundStatus, &exited, backgroundPids, &backgroundCount);
        }
        freeCommandLine(currLine);
    }
}

int main(){
    setup_parent_SIGINT();
    setup_SIGTSTP();
    shellMenu();
}