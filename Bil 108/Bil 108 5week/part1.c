/************************************************************************/
/*                                                                      */
/*    A sample solution for Labwork 5 Part-1.                             */
/*                                                                      */
/*                                                                      */
/************************************************************************/

/* Include libraries */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN_NUMBER_OF_TURNS 10
#define MAX_NUMBER_OF_TURNS 100

/* Roll dice and count each side */
int rollDice(int numberOfTurns, int *one, int *two, int *three, int *four, int *five, int *six);

/* print histogram */
int printHistogram(int one, int two, int three, int four, int five, int six);

int main()
{

	int numberOfTurns = -1;
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;  /* do not forget to initialize the local variables */
	
	srand(time(NULL)); /* call it in the main function */

	while (numberOfTurns < MIN_NUMBER_OF_TURNS || numberOfTurns > MAX_NUMBER_OF_TURNS)
	{
		printf("Number of turns [%d, %d] :", MIN_NUMBER_OF_TURNS, MAX_NUMBER_OF_TURNS);
		scanf("%d", &numberOfTurns);
	}	/* input validation */

	printf("%d\n", rollDice(numberOfTurns, &one, &two, &three, &four, &five, &six));

	printf("%d\n", printHistogram(one, two, three, four, five, six)); /* print histogram */
	
	return 0;
} 

/* Roll dice and count each side */
int rollDice(int numberOfTurns, int *one, int *two, int *three, int *four, int *five, int *six)
{
	int i;
	int current;

	for (i=0;i<numberOfTurns;++i)
	{
		current = rand()%6 + 1;

		if (current == 1) (*one)++;
		else if (current == 2) (*two)++;
		else if (current == 3) (*three)++;	/* count each side */
		else if (current == 4) (*four)++;
		else if (current == 5) (*five)++;
		else if (current == 6) (*six)++;
	}

	return *one + *two + *three + *four + *five + *six;
}

/* Print the histogram */
int printHistogram(int one, int two, int three, int four, int five, int six)
{
	int i, totalChar = 0;

	printf("1: ");
	for (i=0;i<one;++i)
		 totalChar += printf("*"); 
	printf("\n");

	printf("2: ");
	for (i=0;i<two;++i)
		 totalChar += printf("*"); 
	printf("\n");

	printf("3: ");
	for (i=0;i<three;++i) 
		 totalChar += printf("*"); 
	printf("\n");

	printf("4: ");
	for (i=0;i<four;++i) 
		 totalChar += printf("*"); 
	printf("\n");

	printf("5: ");
	for (i=0;i<five;++i)
		 totalChar += printf("*"); 
	printf("\n");

	printf("6: ");
	for (i=0;i<six;++i)
		 totalChar += printf("*"); 
	printf("\n");

	return totalChar;
}