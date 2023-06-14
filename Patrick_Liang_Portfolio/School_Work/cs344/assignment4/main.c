#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

//Max size for this buffer is input length:1000
char inputBuffer[1000];
pthread_mutex_t inputMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t inputFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t inputEmpty = PTHREAD_COND_INITIALIZER;

//Line Seperator Variables
char lineSepBuffer[1000];
pthread_mutex_t lineSepMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t lineSepFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t lineSepEmpty = PTHREAD_COND_INITIALIZER;

//Plus Sign Variables
char plusSignBuffer[1000];
pthread_mutex_t plusSignMutex = PTHREAD_MUTEX_INITIALIZER;

int stop = 0;

//Producer of inputBuffer
void * input(){
    while(!stop){
        //Lock mutex before checking buffer
        pthread_mutex_lock(&inputMutex);
        while(strlen(inputBuffer)){
            //Wait for buffer to be empty
            pthread_cond_wait(&inputEmpty, &inputMutex);
        }
        //take input
        char* line = NULL;
        size_t lineSize = 1000;
        getline(&line, &lineSize, stdin);

        //Check "STOP"
        if(strcmp(line, "STOP\n") == 0){
            stop = 1;
            exit(0);
        } else {
            strcpy(inputBuffer, line);
            pthread_cond_signal(&inputFull);
        }
        pthread_mutex_unlock(&inputMutex);
    }
    return NULL;
}

//This function is the consumer of inputBuffer and the producer of the lineSepBuffer
void * lineSeparator(){
    while(!stop){
        //Lock mutex before checking buffer
        pthread_mutex_lock(&inputMutex);
        while(!strlen(inputBuffer)){
            //Wait for buffer to have data
            pthread_cond_wait(&inputFull, &inputMutex);
        }
        
        pthread_mutex_lock(&lineSepMutex);
        while(strlen(lineSepBuffer)){
            //Wait for buffer to be empty
            pthread_cond_wait(&lineSepEmpty, &lineSepMutex);
        }
        //move buffer, clear inputBuffer, unlock input mutex
        strcpy(lineSepBuffer, inputBuffer);
        strcpy(inputBuffer, "");
        pthread_cond_signal(&inputEmpty);
        pthread_mutex_unlock(&inputMutex);

        //Switch out \n character
        lineSepBuffer[strcspn(lineSepBuffer, "\n")] = ' ';

        pthread_cond_signal(&lineSepFull);
        pthread_mutex_unlock(&lineSepMutex);
    }
    return NULL;
}

//This function is the consumer of lineSepBuffer and the producer of the plusSignBuffer
void * plusSign(){
    while(!stop){
        //Lock mutex before checking buffer
        pthread_mutex_lock(&lineSepMutex);
        while(!strlen(lineSepBuffer)){
            //Wait for buffer to have data
            pthread_cond_wait(&lineSepFull, &lineSepMutex);
        }

        pthread_mutex_lock(&plusSignMutex);
        while(strlen(plusSignBuffer) >= 80){
            //Wait for buffer to have less than 80 characters
            pthread_mutex_unlock(&plusSignMutex);
            sleep(1);
            pthread_mutex_lock(&plusSignMutex);
        }

        //Replace all ++ with ^
        char* needle = strstr(lineSepBuffer, "++");
        char* replacement = "^";
        while(needle != NULL){
            //Move the everything after ++ to where they should be
            memmove(needle + strlen(replacement), needle + strlen("++"), strlen(needle) - strlen("++") + 1);
            memmove(needle, replacement, strlen(replacement));
            needle = strstr(lineSepBuffer, "++");
        }

        //move buffer, clear lineSepBuffer, unlock lineSep mutex
        strcat(plusSignBuffer, lineSepBuffer);
        strcpy(lineSepBuffer, "");
        pthread_cond_signal(&lineSepEmpty);
        pthread_mutex_unlock(&lineSepMutex);

        pthread_mutex_unlock(&plusSignMutex);
    }
    return NULL;
}

//Consumer of plusSignBuffer
void * output(){
    while(!stop){
        pthread_mutex_lock(&plusSignMutex);
        while(strlen(plusSignBuffer) < 80){
            //Wait for buffer to be empty
            pthread_mutex_unlock(&plusSignMutex);
            sleep(1);
            pthread_mutex_lock(&plusSignMutex);
        }

        //Print 80 characters and remove
        printf("%.80s\n", plusSignBuffer);
        int length = strlen(plusSignBuffer);
        memmove(plusSignBuffer, plusSignBuffer+80, length - 80 + 1);
        pthread_mutex_unlock(&plusSignMutex);
    }
    return NULL;
}

int main(){
    pthread_t input_t, lineSep_t, plusSign_t, output_t;
    pthread_create(&input_t, NULL, input, NULL);
    pthread_create(&lineSep_t, NULL, lineSeparator, NULL);
    pthread_create(&plusSign_t, NULL, plusSign, NULL);
    pthread_create(&output_t, NULL, output, NULL);
    pthread_join(input_t, NULL);
    pthread_join(lineSep_t, NULL);
    pthread_join(plusSign_t, NULL);
    pthread_join(output_t, NULL);
    return 0;
}