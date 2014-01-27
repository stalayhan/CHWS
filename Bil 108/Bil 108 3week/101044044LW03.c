/*################################################################*/
/* 101044044LW03.c                                                */
/* ----------------------                                         */
/* Created on 09.03.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* This implementation compute the average of a student grade     */
/* and prints it to the screen.                                   */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>


/* Function prototypes */
char gradeToLetter(double grade);


/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main(void)
{
    double first,second,third,fourth,fifth,
           average;
	double grade,examsNumber;
	char result;
	
	/* get number of exams */
	printf(" Enter the number of exams:");
	scanf("%lf", &examsNumber);

/*----------------------------------------------------------------*/
/*                if number of exams 5                            */
/*----------------------------------------------------------------*/
	if(examsNumber > 5 )
	{
	printf(" The number of exams can be at most 5.\n");
	}
	if(examsNumber == 5)
	{
	printf(" Enter the first grade: ");
	scanf("%lf", &first);
	if(first > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the second grade: ");
	scanf("%lf", &second);
	if(second > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the third grade: ");
	scanf("%lf", &third);
	if(third > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the fourth grade: ");
	scanf("%lf", &fourth);
	if(fourth > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the fifth grade: ");
	scanf("%lf", &fifth);
	if(fifth > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	average = (first+second+third+fourth+fifth)/5;
	printf(" Your average grade %c \n",gradeToLetter(average));
	}
	
/*----------------------------------------------------------------*/
/*                if number of exams 4                            */
/*----------------------------------------------------------------*/	
	if(examsNumber == 4)
	{
	printf(" Enter the first grade: ");
	scanf("%lf", &first);
	if(first > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the second grade: ");
	scanf("%lf", &second);
	if(second > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the third grade: ");
	scanf("%lf", &third);
	if(third > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the fourth grade: ");
	scanf("%lf", &fourth);
	if(fourth > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	average = (first+second+third+fourth)/4;
	printf(" Your average grade %c \n",gradeToLetter(average));
	}

/*----------------------------------------------------------------*/
/*                if number of exams 3                            */
/*----------------------------------------------------------------*/	
	if(examsNumber == 3)
	{
	printf(" Enter the first grade: ");
	scanf("%lf", &first);
	if(first > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the second grade: ");
	scanf("%lf", &second);
	if(second > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the third grade: ");
	scanf("%lf", &third);
	if(third > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	average = (first+second+third)/3;
	printf(" Your average grade %c \n",gradeToLetter(average));
	}
/*----------------------------------------------------------------*/
/*               if number of exams 2                             */
/*----------------------------------------------------------------*/	
	if(examsNumber == 2)
	{
	printf(" Enter the first grade: ");
	scanf("%lf", &first);
	if(first > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	printf(" Enter the second grade: ");
	scanf("%lf", &second);
	if(second > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	average = (first+second)/2;
	printf(" Your average grade %c \n",gradeToLetter(average));
	}
/*----------------------------------------------------------------*/
/*                if number of exams 1                            */
/*----------------------------------------------------------------*/	
	if(examsNumber == 1)
	{
	printf(" Enter the first grade: ");
	scanf("%lf", &first);
	if(first > 100 ){
	printf(" A valid grade can be between 0 and 100\n ");
	return 0;
	}
	average = first/1;
	printf(" Your average grade %c \n",gradeToLetter(average));
	}


	
	return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function gradeToLetter                                         */
/*---------------------                                           */
/*This function convert average grade to letter code.             */
/*----------------------------------------------------------------*/
char gradeToLetter(double grade)
{
    char result;
    if(grade == 100)
    {
    result = 'A';
    }
    if(grade >= 80 && grade < 100)
    {
    result = 'B';
    }
    if(grade >= 50 && grade < 80)
    {
    result = 'C';
    }
    if(grade >= 20 && grade < 50)
    {
    result = 'D';
    }
    if(grade >= 1 && grade < 20)
    {
    result = 'E';
    }
    if(grade == 0)
    {
    result = 'F';
    }
    
           
    return (result);
}
/*################################################################*/
/*                  End of 101044044LW03.c                        */
/*################################################################*/
