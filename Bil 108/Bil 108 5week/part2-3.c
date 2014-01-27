/************************************************************************/
/*                                                                      */
/*    A sample solution for Labwork Part-2 and Part-3.                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

/* Include libraries */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN_NUMBER_OF_TURNS 5000
#define MAX_NUMBER_OF_TURNS 100000
#define MAX_NUMBER_OF_STARS 40

int printHistogram(int one, int two, int three, int four, int five, int six, int step);
int rollDice(int numberOfTurns, int *one, int *two, int *three, int *four, int *five, int *six);
int findMax(int one, int two, int three, int four, int five, int six);

int main()
{
	int numberOfTurns = -1;
	char ch = 'Y';

	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0; /* initialize the local variables */
	
	srand(time(NULL));

	while (ch == 'Y' || ch == 'y')	 /* This program terminates if ch =='n' or ch == 'N' How? */
	{
		one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;  /* do not forget to set the counters to zero */

		/* a random value between MAX_NUMBER_OF_TURNS and MIN_NUMBER_OF_TURNS */
		numberOfTurns = rand()%(MAX_NUMBER_OF_TURNS - MIN_NUMBER_OF_TURNS) + MIN_NUMBER_OF_TURNS;

		printf("Number of turns: %d\n", numberOfTurns);
		rollDice(numberOfTurns, &one, &two, &three, &four, &five, &six);


		printf("%d\n", printHistogram(one, two, three, four, five, six, findMax(one, two, three, four, five, six)/MAX_NUMBER_OF_STARS));

		ch = ' ';
		while (ch != 'Y' && ch !='y' && ch != 'N' && ch != 'n')
		{
			printf("Do you want to continue [Y/N]: ");
			scanf(" %c", &ch);
		}
	}
	
	return 0;
} 

int findMax(int one, int two, int three, int four, int five, int six)
{
	int max = one;

	if (two > max) max = two;
	if (three > max) max = three;
	if (four > max) max = four;
	if (five > max) max = five;
	if (six > max) max = six;

	return max;
}

/* This function has 7 return values */
int rollDice(int numberOfTurns, int *one, int *two, int *three, int *four, int *five, int *six)
{
	int i;
	int current;

	for (i=0;i<numberOfTurns;++i)
	{
		current = rand()%6 + 1;

		if (current == 1) (*one)++;
		else if (current == 2) (*two)++;
		else if (current == 3) (*three)++;
		else if (current == 4) (*four)++;
		else if (current == 5) (*five)++;
		else if (current == 6) (*six)++;
	}

	return *one + *two + *three + *four + *five + *six;
}

/* Prints histogram */
int printHistogram(int one, int two, int three, int four, int five, int six, int step)
{
	int i, totalChar = 0;

	printf("1: ");
	for (i=0;i<one;i+=step)
		 totalChar += printf("*"); 
	printf("\n");

	printf("2: ");
	for (i=0;i<two;i+=step)
		 totalChar += printf("*"); 
	printf("\n");

	printf("3: ");
	for (i=0;i<three;i+=step) 
		 totalChar += printf("*"); 
	printf("\n");

	printf("4: ");
	for (i=0;i<four;i+=step) 
		 totalChar += printf("*"); 
	printf("\n");

	printf("5: ");
	for (i=0;i<five;i+=step)
		 totalChar += printf("*"); 
	printf("\n");

	printf("6: ");
	for (i=0;i<six;i+=step)
		 totalChar += printf("*"); 
	printf("\n");

	printf("Each * show %d turns\n", step); 

	return totalChar;
}