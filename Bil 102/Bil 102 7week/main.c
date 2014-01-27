
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Postures.h"


#define WAITING_TIME 0.2    /* Wait time between postures */
#define START_POSITION 30   /* Initial Position of the character */


/* Directions that the character can turn or move */
typedef enum
{
    LEFT=-1,FRONT,RIGHT
} courses;

/* Possible error values */
typedef enum
{
    incorrectInput
} errors;


/* Display and initialization functions */
char menu();
void initialize(int ,int* , char [][WIDTH]);

/* Turning functions */
void turnLeft(int, int* , char [][WIDTH]);
void turnRight(int, int* , char [][WIDTH]);
void turnFront(int, int* , char [][WIDTH]);

/* Movement functions */
void walk(int, courses, int*, char [][WIDTH]);
void walkToRight(int , courses , int* , char [][WIDTH]);
void walkToLeft(int , courses , int* , char [][WIDTH]);
void jump(int, int, courses, char character[][WIDTH]);
void move(int , int , char [][WIDTH], void (char [][WIDTH]));

/* Accessory functions */
void deleteCinAli(char [][WIDTH]);
void printCinAli(int , char [][WIDTH]);
void setStepNumber(int *step);
void error(errors i);
void gameOver();
void flushInputBuffer();
void wait ( double );



int main()
{
    courses direction=FRONT;    /* Direction of the character */
    int     currentPosition=START_POSITION, /* Position of the character */
            step;   /* The step number that athe character moves in a direction */

    char    cinAli[HEIGHT][WIDTH], /* the Character of the Game*/
            action;    /* Type of action that user enters */

    /* Initialize Cin Ali */
    initialize(currentPosition, &direction, cinAli);

    /* Play game until user exits */
    do
    {
        /* Display menu and read the order user gave*/
        action=menu();
        /* Do the action */
        switch (action)
        {
            case '>': /* Move Right */
                setStepNumber(&step); /* Read and set the step number */
                turnRight(currentPosition, &direction, cinAli);
                walk(step, direction, &currentPosition, cinAli);
                break;
            case '<': /* Move left */
                setStepNumber(&step);
                turnLeft(currentPosition, &direction, cinAli);
                walk(step, direction, &currentPosition, cinAli);
                break;
            case '=': /* Turn Front */
                turnFront(currentPosition, &direction, cinAli);
                break;
            case 'r': /* Turn Right */
                turnRight(currentPosition, &direction, cinAli);
                break;
            case 'l': /* Turn Left */
                turnLeft(currentPosition, &direction, cinAli);
                break;
            case 'x': /* Exit */
                gameOver();
                break;
            case 'j':
                setStepNumber(&step);
                turnFront(currentPosition, &direction, cinAli);
                jump(step, currentPosition, direction, cinAli);
                break;
            default:
                error(incorrectInput); /* Incorrect input from the user */
                break;
        }
        flushInputBuffer(); /* Clean the input buffer */

    }while(action!='x');

    return 0;
}


/*
 *  Displays options for the user to select an available action
 *  Pre:  database accesses a binary file of product_t records that has
 *        been opened as an input file, and params is defined
 *  Post: It returns the chosen action
 */
char menu()
{
    char select;
    printf("\n\nEnter '>' for Cin Ali to walk right\n");
    printf("Enter '<' for Cin Ali to walk left\n");
    printf("Enter '=' for Cin Ali to turn front\n");
    printf("Enter 'r' for Cin Ali to turn right\n");
    printf("Enter 'l' for Cin Ali to turn left\n");
    printf("Enter 'j' for Cin Ali to jump\n");
    scanf("%c",&select);
    return select;
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void initialize(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=FRONT;
    move(currentPosition, *direction, character, frontPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void setStepNumber(int *step)
{
    printf("Step Number: ");
    scanf("%d", step);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void deleteCinAli(char character[][WIDTH])
{
    int i, j;
    for(i=0; i<HEIGHT; ++i)
    {
        for(j=0; j<WIDTH; ++j)
        {
            character[i][j]=' ';
        }
    }
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void printCinAli(int currentPosition, char character[][WIDTH])
{
    int i, j;
    for(i=0; i<HEIGHT; ++i)
    {
        for(j=0; j<currentPosition; ++j)
        {
            printf(" ");
        }
        for(j=0; j<WIDTH; ++j)
        {
            printf("%c", character[i][j]);
        }
        printf("\n");
    }
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void move(int currentPosition, courses direction, char character[][WIDTH], void posture(char [][WIDTH]))
{
    system("clear");
    deleteCinAli(character);
    posture(character);
    printCinAli(currentPosition, character);
    wait(WAITING_TIME);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void turnLeft(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=LEFT;
    move(currentPosition, *direction, character, leftPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void turnRight(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=RIGHT;
    move(currentPosition, *direction, character, rightPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void turnFront(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=FRONT;
    move(currentPosition, *direction, character, frontPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void walk(int step, courses direction, int *currentPosition, char character[][WIDTH])
{
    switch (direction)
    {
        case LEFT:
            walkToLeft(step, direction, currentPosition, character);
            break;
        case RIGHT:
            walkToRight(step, direction, currentPosition, character);
            break;
        default:
            break;
    }
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void walkToRight(int step, courses direction, int* currentPosition, char character[][WIDTH])
{
    int i;
    for(i=0; i<step; ++i)
    {
        move((*currentPosition)++, direction, character, toRightFootsDown);
        move((*currentPosition)++, direction, character, toRightBeckFootUp);
        move((*currentPosition)++, direction, character, toRightCenteral);
        move((*currentPosition)++, direction, character, toRightFrontFootUp);
    }
    move((*currentPosition), direction, character, rightPosture);
}

void jump(int step, int currentPosition, courses direction, char character[][WIDTH])
{
    int i;
    for(i=0; i<step; ++i)
    {
        move((currentPosition), direction, character, frontPosture);
        move((currentPosition), direction, character, jump1);
        move((currentPosition), direction, character, jump2);
        move((currentPosition), direction, character, jump3);
        move((currentPosition), direction, character, jump2);
        move((currentPosition), direction, character, frontPosture);
    }
}
/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void walkToLeft(int step, courses direction, int* currentPosition, char character[][WIDTH])
{
    int i;
    for(i=0; i<step; ++i)
    {
        move((*currentPosition)--, direction, character, toLeftFootsDown);
        move((*currentPosition)--, direction, character, toLeftBeckFootUp);
        move((*currentPosition)--, direction, character, toLeftCenteral);
        move((*currentPosition)--, direction, character, toLeftRightFootUp);
    }
    move((*currentPosition), direction, character, leftPosture);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void error(errors i)
{
    switch(i)
    {
        case incorrectInput:
            printf("Please, enter the right input\n");
            break;
        default:
            break;
    }
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void gameOver()
{
    printf("Game Over!");
    wait(1);
}


/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void wait ( double seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}



/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
void flushInputBuffer()
{
    char junk;
    /* A loop that cleans the input buffer till '\n' character being entered*/
    do
    {
        scanf("%c",&junk);
    }while(junk!='\n');
}
