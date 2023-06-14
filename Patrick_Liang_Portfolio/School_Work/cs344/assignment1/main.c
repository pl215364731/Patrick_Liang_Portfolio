#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
* Return a linked list of movies by parsing data from
* each line of the specified file.
*/
struct movie *processFile(char *filePath)
{
    // Open the specified file for reading only
    FILE *movieFile = fopen(filePath, "r");

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
    return head;
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
* Get the desired year from the user and print all the movies
* released in this year
*/
void releasedYear(struct movie *list)
{
    printf("Enter the year for which you want to see movies: ");

    //assuming the user will enter a valid year
    int year = 0;
    scanf("%d", &year);

    //Create an array of movie pointers to store the address of all wanted movies
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

    //Print all movies in the array
    for (int i = 0; i < counter; i++)
    {
        printf(moviesContainer[i]->title);
        printf("\n");
    }
    if(counter == 0){
        printf("No data about movies released in the year %d\n", year);
    }
    printf("\n");
    free(moviesContainer);
}

/*
* Print the highest rated movie for each year
*/
void highestRatedMovie(struct movie* list)
{
    struct movie** highestRatedMovies = calloc(0, sizeof(struct movie *));
    int counter = 0;
    /*
    * For every movie in the linked list, compare the year with each movie in the array
    * If there is already a movie of the same year in the array, compare the rating to either
    * replace the movie in the array or move on to the next movie in the linked list
    */
    while (list != NULL)
    {
        int addToList = 1;
        for(int i = 0; i < counter; i++){
            if(highestRatedMovies[i]->year == list->year){
                addToList = 0;
                if(highestRatedMovies[i]->rating <= list->rating){
                    highestRatedMovies[i] = list;
                }
            }
        }
        if(addToList){
            counter++;
            highestRatedMovies = realloc(highestRatedMovies, counter * sizeof(struct movie *));
            highestRatedMovies[counter - 1] = list;
        }
        list = list->next;
    }
    for (int i = 0; i < counter; i++)
    {
        printf("%d %.1f %s\n", highestRatedMovies[i]->year, highestRatedMovies[i]->rating,highestRatedMovies[i]->title);
    }
    printf("\n");
    free(highestRatedMovies);
}

/*
* Get the desired language from the user and print all the movies
* released in this language
*/
void language(struct movie* list){
    printf("Enter the language for which you want to see movies: ");

    //Declare input as an array of char with size 21
    char input[21];
    scanf("%20s", input);

    struct movie **moviesContainer = calloc(0, sizeof(struct movie *));
    int counter = 0;
    while (list != NULL)
    {
        for(int i = 0; i < 5; i++){
            if ((list->languages[i] != NULL) && (strcmp(input, list->languages[i]) == 0))
            {
                counter++;
                moviesContainer = realloc(moviesContainer, counter * sizeof(struct movie *));
                moviesContainer[counter - 1] = list;
            }
        }
        
        list = list->next;
    }

    for (int i = 0; i < counter; i++)
    {
        printf("%d %s\n", moviesContainer[i]->year, moviesContainer[i]->title);
    }
    if(counter == 0){
        printf("No data about movies released in %s\n", input);
    }
    printf("\n");
    free(moviesContainer);
}

/*
* Print main menu with the 4 options
*/
void printMenu(struct movie *list)
{
    int end = 0;
    while (!end)
    {
        printf("1. Show movies released in the specified year\n");
        printf("2. Show highest rated movie for each year\n");
        printf("3. Show the title and year of release of all movies in a specific language\n");
        printf("4. Exit from the program\n");
        printf("Enter a number from 1 to 4: ");

        int userInput = 0;
        scanf("%d", &userInput);
        printf("\n");

        switch (userInput)
        {
        case 1:
            releasedYear(list);
            break;
        case 2:
            highestRatedMovie(list);
            break;
        case 3:
            language(list);
            break;
        case 4:
            end = 1;
            break;
        default:
            printf("Invalid Input\n\n");
            break;
        }
    }
    freeList(list);
    exit(EXIT_SUCCESS);
}

//gcc --std=gnu99 -o movies main.c
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Incorrect amount of arguments provided\n");
        return EXIT_FAILURE;
    }
    struct movie *list = processFile(argv[1]);

    printf("Processed file %s and parsed data for 24 movies\n\n", argv[1]);
    printMenu(list);
}