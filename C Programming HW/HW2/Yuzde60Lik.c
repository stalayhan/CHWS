/*################################################################*/
/* HW02_Samet_Sait_Talayhan_101044044.c   		                  */
/* ----------------------                                         */
/* Created on March 7, 2013, 8:16 PM by Samet Sait Talayhan.      */ 
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* This program calculates and print the result of the operations */
/* written in a text file. 
/* ----------------------                                         */
/*                                                                */
/*################################################################*/
/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>

/*################################################################*/
/*                           Defines                              */
/*################################################################*/


/*----------------------------------------------------------------*/
/*                    Function Prototypes                         */
/*----------------------------------------------------------------*/
int convertToInt1d(char ch);
int convertToInt2d(char ch1, char ch2);
int convertToInt3d(char ch1, char ch2, char ch3);
int isDigit(char ch);
int isSign(char ch);
int isPlusSign(char ch);
int isMinusSign(char ch);
int isMultiplicationSign(char ch);
int isDivisionSign(char ch);
int convertToInt(char ch);
int calculate(int leftInt, int rightInt, char sign);


/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int
main(void) 
{ 
	/* Declaring Variables */
	int result;
	char chr1, chr2, chr3;

	/*Declaring File pointers */
	FILE *inFile = fopen("text.txt","r");

	/* Read char by char an integer from the file. */
	fscanf(inFile,"%c",&chr1);
	fscanf(inFile,"%c",&chr2);
	fscanf(inFile,"%c",&chr3);
	/* Close file. */
	fclose(inFile);

	result = convertToInt3d(chr1,chr2,chr3);
	printf("Result is :%5d\n",(result*2));

	return 0;
}
/*################################################################*/
/*        End of HW02_Samet_Sait_Talayhan_101044044.c             */
/*################################################################*/
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* convertToInt1d Function  	                                  */
/* -------------------                                            */
/* Converts the given character to its equivalent integer, 
/* prints error message if the input doesnt refer a number        */
/*----------------------------------------------------------------*/
int
convertToInt1d(char ch)
{ 
	return convertToInt(ch);
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* convertToInt2d Function  	                                  */
/* -------------------                                            */
/* Converts the given characters to their equivalent integer of  
/* two digit, prints error message if the input doesnt refer 
/* a number.      
/*----------------------------------------------------------------*/
int
convertToInt2d(char ch1, char ch2)
{ 
	return 10*convertToInt(ch1) + convertToInt(ch2);
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* convertToInt3d Function  	                                  */
/* -------------------                                            */
/* Converts the given characters to their equivalent integer of  
/* three digit, prints error message if the input doesnt refer 
/* a number.      
/*----------------------------------------------------------------*/
int
convertToInt3d(char ch1, char ch2, char ch3)
{ 
	return 100*convertToInt(ch1) + 10*convertToInt(ch2)
                        + convertToInt(ch3);
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* isDigit Function  			                                  */
/* -------------------                                            */
/* Returns 1 if the input refers a number and 0 otherwise
/*----------------------------------------------------------------*/
int
isDigit(char ch)
{
	switch(ch)
	{
		case '0':
			return 1;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 1;
			break;
		case '3':
			return 1;
			break;
		case '4':
			return 1;
			break;
		case '5':
			return 1;
			break;
		case '6':
			return 1;
			break;
		case '7':
			return 1;
			break;
		case '8':
			return 1;
			break;
		case '9':
			return 1;
			break;
		default :
			printf("Error! ch is not digit!\n");
			return 0;
	}	
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* isPlusSign Function  		                                  */
/* -------------------                                            */
/* Returns 1 if the input refers a plus sign and 0 otherwise
/*----------------------------------------------------------------*/
int
isPlusSign(char ch)
{
	if (ch == '+')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* isMinusSign Function  		                                  */
/* -------------------                                            */
/* Returns 1 if the input refers a minus sign and 0 otherwise
/*----------------------------------------------------------------*/
int
isMinusSign(char ch)
{
	if (ch == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* isMultiplicationSign Function  		                          */
/* -------------------                                            */
/* Returns 1 if the input refers a multiplication sign and
/* 0 otherwise
/*----------------------------------------------------------------*/
int
isMultiplicationSign(char ch)
{
	if (ch == '*')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* isDivisionSign Function  		                              */
/* -------------------                                            */
/* Returns 1 if the input refers division sign and 0 otherwise
/*----------------------------------------------------------------*/
int
isDivisionSign(char ch)
{
	if (ch == '/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* isSign Function  		                                 	  */
/* -------------------                                            */
/* Returns 1 if the input refers any operator sign and 0 otherwise
/*----------------------------------------------------------------*/
int
isSign(char ch)
{
	if (ch == '+')
	{
		return 1;
	}
	else if (ch == '-')
	{
		return 1;
	}
	else if (ch == '*')
	{
		return 1;
	}
	else if (ch == '/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* convertToInt Function  		                                  */
/* -------------------                                            */
/* Input - Character that keep integer char. ie. '4', '5' single
/* digit.
/* Output - Integer value of character 
/*----------------------------------------------------------------*/
int
convertToInt(char ch)
{
	switch(ch)
	{
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
	}
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* calculate Function  	   		                                  */
/* -------------------                                            */
/* Input - leftInt and rightInt of a binary operator, and operator
/* sign as char.
/* Output - Result of the given process. 
/*----------------------------------------------------------------*/
int
calculate(int leftInt, int rightInt, char sign)
{
	if (isPlusSign(sign))
	{
		return (leftInt + rightInt);
	}
	else if (isMinusSign(sign))
	{
		return (leftInt - rightInt);
	}
	else if (isMultiplicationSign(sign))
	{
		return (leftInt * rightInt);
	}
	else if (isDivisionSign(sign))
	{
		return (leftInt / rightInt);
	}
}

