#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        perror("Please provide length for keygen");
        exit(1);
    }
    srand(time(NULL));
    for(int i = 0; i < atoi(argv[1]); i++){
        int randomNum = 65 + (rand() % 27);
        if(randomNum == 91){
            printf(" ");
        } else {
            printf("%c", (char) randomNum);
        }
        
    }
    printf("\n");
}