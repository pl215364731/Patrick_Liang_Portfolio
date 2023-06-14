#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>

/* struct for movie*/
struct movie
{
    char *title;
    int year;
    char *languages[5];
    double rating;
    struct movie *next;
};

/* Parse the current line which is space delimited and create a
*  movie struct with the data in this line
*/
struct movie *createMovie(char *currLine)
{
    struct movie *currMovie = malloc(sizeof(struct movie));
    for (int i = 0; i < 5; i++)
    {
        currMovie->languages[i] = NULL;
    }

    // For use with strtok_r
    char *saveptr;

    char *token = strtok_r(currLine, ",", &saveptr);
    currMovie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->title, token);

    token = strtok_r(NULL, ",", &saveptr);
    currMovie->year = atoi(token);

    //storing languages
    token = strtok_r(NULL, ",", &saveptr);
    token[strlen(token) - 1] = '\0';
    //token is used as a substring including language information. langStr is the saveptr for using strtok_r
    char *langStr;
    char *langToken = strtok_r(&token[1], ";", &langStr);
    int langCounter = 0;
    while (langToken != NULL)
    {
        currMovie->languages[langCounter] = calloc(strlen(langToken) + 1, sizeof(char));
        strcpy(currMovie->languages[langCounter], langToken);
        langCounter++;
        langToken = strtok_r(NULL, ";", &langStr);
    }

    token = strtok_r(NULL, "\n", &saveptr);
    currMovie->rating = strtod(token, NULL);

    // Set the next node to NULL in the newly created movie entry
    currMovie->next = NULL;

    return currMovie;
}

/*
* Free a linked list of movies
*/
void freeList(struct movie *list)
{
    struct movie *tmpPtr;
    while (list != NULL)
    {
        tmpPtr = list;
        list = list->next;
        //free title
        free(tmpPtr->title);
        //free languages
        for (int i = 0; i < 5; i++)
        {
            if (tmpPtr->languages[i] != NULL)
            {
                free(tmpPtr->languages[i]);
            }
        }
        free(tmpPtr);
    }
}

/*
* Create a .txt file for every year that a movie was released in
*/
void createTextFiles(struct movie *head, char *filePath)
{
    for(int year = 1900; year < 2022; year++){
        //Create an array of movie pointers to store the address of all wanted movies
        struct movie* list = head;
        struct movie **moviesContainer = calloc(0, sizeof(struct movie *));
        int counter = 0;
        while (list != NULL)
        {
            //If the movie is released in the given year, add it to the array
            if (list->year == year)
            {
                counter++;
                moviesContainer = realloc(moviesContainer, counter * sizeof(struct movie *));
                moviesContainer[counter - 1] = list;
            }
            list = list->next;
        }
        //Make .txt file
        if(counter > 0){
            char txtFileName[256];
            //set permission
            sprintf(txtFileName, "%s/%d.txt", filePath, year);
            int fd = open(txtFileName, O_CREAT, 0640);
            close(fd);
            //print to file
            FILE *txtFile = fopen(txtFileName, "w");
            for (int i = 0; i < counter; i++)
            {
            fprintf(txtFile, moviesContainer[i]->title);
            fprintf(txtFile, "\n");
            }
            fclose(txtFile);
        }
        free(moviesContainer);
    }
}

/*
* Process the given file and create a random folder to store
* all the .txt files of each year.
*/
void processFile(char *filePath)
{
    // Open the specified file for reading only
    FILE *movieFile = fopen(filePath, "r");

    printf("Now processing the chosen file named %s\n", filePath);

    char *currLine = NULL;
    size_t len = 0;
    ssize_t nread;
    char *token;

    // The head of the linked list
    struct movie *head = NULL;
    // The tail of the linked list
    struct movie *tail = NULL;

    // Get rid of the label line
    getline(&currLine, &len, movieFile);

    // Read the file line by line
    while ((nread = getline(&currLine, &len, movieFile)) != -1)
    {
        // Get a new movie node corresponding to the current line
        struct movie *newNode = createMovie(currLine);

        // Is this the first node in the linked list?
        if (head == NULL)
        {
            // This is the first node in the linked link
            // Set the head and the tail to this node
            head = newNode;
            tail = newNode;
        }
        else
        {
            // This is not the first node.
            // Add this node to the list and advance the tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    free(currLine);
    fclose(movieFile);

    //Create random folder
    char randomFolderName[256];
    int randomNumber = (random() % 99999) + 1;
    sprintf(randomFolderName, "liangpa.movies.%d", randomNumber);
    int newDir = mkdir(randomFolderName, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP);
    while(newDir == -1){
        randomNumber = (random() % 99999) + 1;
        sprintf(randomFolderName, "liangpa.movies.%d", randomNumber);
        newDir = mkdir(randomFolderName, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP);
    }

    printf("Created directory with name %s\n\n", randomFolderName);

    createTextFiles(head, randomFolderName);
    freeList(head);
}

/*
* Print menu of process file option and perform each option
*/
void processFileOptions(){
    DIR* currDir = opendir(".");
    struct dirent *aDir;
    struct stat dirStat;
    char largestFile[256];
    int largestSize = 0;
    char smallestFile[256];
    int smallestSize = 2147483647;

  // Go through all the files in the current directory to file the largest and smallest file
    while((aDir = readdir(currDir)) != NULL){
        char fileEx[4];
        strncpy(fileEx, aDir->d_name+strlen(aDir->d_name)-4, 4);
        if(strncmp("movies_", aDir->d_name, strlen("movies_")) == 0 && strncmp(".csv", fileEx, 4) == 0){
            stat(aDir->d_name, &dirStat);
            if(dirStat.st_size > largestSize){
                largestSize = dirStat.st_size;
                strcpy(largestFile, aDir->d_name);
            }
            if(dirStat.st_size < smallestSize){
                smallestSize = dirStat.st_size;
                strcpy(smallestFile, aDir->d_name);
            }
        }
    }
    closedir(currDir);
    //menu
    int end = 0;
    while(!end){
        printf("Which file you want to process?\n");
        printf("Enter 1 to pick the largest file\n");
        printf("Enter 2 to pick the smallest file\n");
        printf("Enter 3 to specify the name of a file\n");
        printf("Enter a choice from 1 to 3: ");

        int userInput = 0;
        scanf("%d", &userInput);
        printf("\n");

        char fileNameInput[256];
        switch (userInput)
        {
        case 1:
            processFile(largestFile);
            end = 1;
            break;
        case 2:
            processFile(smallestFile);
            end = 1;
            break;
        case 3:
            printf("Enter the filename: ");
            scanf("%256s", fileNameInput);
            printf("\n");
            int fileCheck = open(fileNameInput, O_RDONLY);
            if (fileCheck == -1){
                printf("The file %s was not found. Try again\n", fileNameInput);
                break;
            }
            close(fileCheck);
            //if cannot open file, redo this input switch
            processFile(fileNameInput);
            end = 1;
            break;
        default:
            printf("Invalid Input\n\n");
            break;
        }
    }
}

/*
* Print main menu with the 2 options
*/
void printMenu()
{
    int userInput = 0;
    while (1)
    {
        printf("1. Select file to process\n");
        printf("2. Exit the program\n");
        printf("Enter a choice 1 or 2: ");

        scanf("%d", &userInput);
        printf("\n");

        switch (userInput)
        {
        case 1:
            processFileOptions();
            break;
        case 2:
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invalid Input\n\n");
            break;
        }
    }
}

//gcc --std=gnu99 -o movies main.c
int main(int argc, char *argv[])
{
    printMenu();
}