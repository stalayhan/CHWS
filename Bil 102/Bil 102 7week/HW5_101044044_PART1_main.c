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
void zeybek(int*, courses, char[][WIDTH]);

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
            step,   /* The step number that at he character moves in a direction */
			i;      /* Hareketlerin tekrar sayisi. */
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
			case 'z':
				for(i=0;i<2;i++)
				{
					zeybek(&currentPosition,direction,cinAli);
				}
				break;
            default:
                error(incorrectInput); /* Incorrect input from the user */
                break;
        }
        flushInputBuffer(); /* Clean the input buffer */

    }while(action!='x');

    return 0;
}
/* Zeybek oynatma.
*  Pre: Cin Ali'nin yapacagi hareketleri belirtir.
*  Post: Zeybek oyunu ekranda gosterildikten sonra biter.
*/
void zeybek(int*currentPosition, courses direction, char character[][WIDTH])
{
	int step = 4,i;	

    for(i=0; i<step; ++i)
    {
		move((*currentPosition)++, direction, character, toRightFootsDown);
        move((*currentPosition)++, direction, character, toRightBeckFootUp);
        move((*currentPosition)++, direction, character, toRightCenteral);
        move((*currentPosition)++, direction, character, toRightFrontFootUp);
		move((*currentPosition), direction, character, rightPosture);
	}
	move((*currentPosition), direction, character, zeybek1);
	move((*currentPosition), direction, character, zeybek1);
	move((*currentPosition), direction, character, zeybek1);
    move((*currentPosition), direction, character, zeybek2);
    move((*currentPosition), direction, character, zeybek2);
    move((*currentPosition), direction, character, zeybek2);
    move((*currentPosition), direction, character, zeybek3);
    move((*currentPosition), direction, character, zeybek3);
    move((*currentPosition), direction, character, zeybek3);
    move((*currentPosition), direction, character, zeybek3);
    move((*currentPosition), direction, character, zeybek4);
    move((*currentPosition), direction, character, zeybek4);
    move((*currentPosition), direction, character, zeybek4);
	move((*currentPosition), direction, character, zeybek5);
	move((*currentPosition), direction, character, zeybek5);
	move((*currentPosition), direction, character, zeybek5);

    for(i=0; i<step; ++i)
    {
		move((*currentPosition)--, direction, character, toLeftFootsDown);
        move((*currentPosition)--, direction, character, toLeftBeckFootUp);
        move((*currentPosition)--, direction, character, toLeftCenteral);
        move((*currentPosition)--, direction, character, toLeftRightFootUp);
		move((*currentPosition), direction, character, leftPosture);
	}
	move((*currentPosition), direction, character, zeybek1);
	move((*currentPosition), direction, character, zeybek1);
	move((*currentPosition), direction, character, zeybek1);
    move((*currentPosition), direction, character, zeybek2);
    move((*currentPosition), direction, character, zeybek2);
    move((*currentPosition), direction, character, zeybek2);
    move((*currentPosition), direction, character, zeybek3);
    move((*currentPosition), direction, character, zeybek3);
    move((*currentPosition), direction, character, zeybek3);
    move((*currentPosition), direction, character, zeybek3);
    move((*currentPosition), direction, character, zeybek4);
    move((*currentPosition), direction, character, zeybek4);
    move((*currentPosition), direction, character, zeybek4);
	move((*currentPosition), direction, character, zeybek5);
	move((*currentPosition), direction, character, zeybek5);
	move((*currentPosition), direction, character, zeybek5);
	move((*currentPosition), direction, character, zeybek6);
	move((*currentPosition), direction, character, zeybek6);
	move((*currentPosition), direction, character, zeybek6);
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
	printf("Enter 'z' for Cin Ali to play Zeybek\n");
    scanf("%c",&select);
    return select;
}


/*
* Function Objective
* Kullaniciya gerekli secenekleri gosterir ve Cin Aliyi ekranda gosterir.
* Pre: Figurun yonunu, o anlık pozisyonunu, o anki goruntusunu alir.
* Post: Ekrana Cin Aliyi bastirir düz sekilde.
*/
void initialize(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=FRONT;
    move(currentPosition, *direction, character, frontPosture);
}


/*
* Function Objective
* Pre: (input Arguman = *step)
* Post: (Adim sayisini kullanicidan alir.Output Argüman olarak geri döndürür.)
*/
void setStepNumber(int *step)
{
    printf("Step Number: ");
    scanf("%d", step);
}


/*
* Function Objective
* Ekrandaki Cin Ali figurunu siler.
* Pre: character arraye ihtiyac duyar. 
* Post: character[][] stringi elemanlarina bosluk karakteriyle doldurulur,
* ve ekran bosalir.
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
* Ekrana gecerli frameler bastirilir.
* Pre: Figurun o anlık pozisyonunu, o anki goruntusunu alir 
* Post: Cin Ali'nin yaptigi hareket ekrana bastirilir.
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
* Figuru saga,sola yurutup saga sola dondurebilir ve zıplatabilir.
* Pre: Figurun yonunu, o anlık pozisyonunu, o anki goruntusunu alir 
* ve hareket stringini alir.
* Post: Cin Ali kullanicinin secimine gore hareket etmis olur.
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
* Karakterin sola donmesini saglar.
* Pre: Figurun yonunu, o anlık pozisyonunu, ve o anki goruntusunu alir.
* Post: Cin ali, sola doner.
*/
void turnLeft(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=LEFT;
    move(currentPosition, *direction, character, leftPosture);
}


/*
* Function Objective
* Karakterin saga donmesini saglar.
* Pre: Figurun yonunu, o anlık pozisyonunu, ve o anki goruntusunu alir.
* Post: Cin ali, saga doner.
*/
void turnRight(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=RIGHT;
    move(currentPosition, *direction, character, rightPosture);
}


/*
* Function Objective
* Karakterin one donmesini saglar.
* Pre: Figurun yonunu, o anlık pozisyonunu, ve o anki goruntusunu alir.
* Post: Cin ali, duz doner.
*/
void turnFront(int currentPosition, courses* direction, char character[][WIDTH])
{
    *direction=FRONT;
    move(currentPosition, *direction, character, frontPosture);
}


/*
* Function Objective
* Saga veya sola yurume islemi gerceklesir.
* Pre: Adim saiyisi, yonunu, o anlık pozisyonunu, ve o anki goruntusunu alir.
* Post: Girilen adim saiyisi kadar saga veya sola dogru yurur.
* Ve o anki donuk pozisyonda kalir.
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
* Saga dogru yurume gerceklesir.
* Pre: Adim saiyisi, yonunu, o anlık pozisyonunu, ve o anki goruntusunu alir.
* Post: Girilen adim saiyisi kadar saga dogru yurur. Ve saga donuk pozisyonda kalir.
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
/*
* Function Objective
* Pre: (if exist, write the requirements)
* Post: (if exist, write the effects)
*/
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
* Sola dogru yurume gerceklesir.
* Pre: Adim saiyisi, yonunu, o anlık pozisyonunu, ve o anki goruntusunu alir.
* Post: Girilen adim saiyisi kadar sola dogru yurur. Ve sola donuk pozisyonda kalir.
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
* Yanlis secim yapilip yapilmadigini kontrol eder.
* Pre: Kullanicinin girdigi karakter.
* Post: Hata mesaji.
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
* Kullanici x girene kadar program calisir.
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
* Figurlerin ekranda ne kadar sureyle gosterilecegi belirtilir.
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

