/*################################################################*/
/* HW04_101044044.c                                               */
/* ----------------------                                         */
/* Created on 18.04.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 20

/*--------------------------------------------------------------- */
/*--------------------- Function Prototypes---------------------- */
/*--------------------------------------------------------------- */
int get_corners (FILE *inputFile, double array[][2], int sizeOfArray);
void output_corners(FILE *outputFile, double array[][2],int sizeOfArray);
double polygon_area(double array[][2], int sizeOfArray);

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main(void)
{
	int count=0;
	double array[MAX_SIZE][2],result;

	/* Definition to folders. */
	FILE *inputFile, *outputFile;	
	
	/* Open folders. */
	inputFile = fopen("input.txt", "r");
	outputFile = fopen("output.txt", "w");	

	count = get_corners(inputFile, array, MAX_SIZE);
	
	output_corners(outputFile, array, count);
	
	/* Verilen polygon un alani. */
	result = polygon_area( array, count);
	printf("Sonuc=%1.1f\n",result);


	/* Close folders. */
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function get_corners                                           */
/*--------------------                                            */
/*----------------------------------------------------------------*/
int get_corners (FILE *inputFile, double array[][2], int sizeOfArray)
{
	int status=0,j,i=0,count=0;
	
		/* Degerleri input.txt den okuyoruz.txt dosyasindeki degerlerin
		 	20 den küçük olup olmadigina bakiyoruz.*/

	while(status != EOF )
	{
		for(j=0;j<2;j++)
		{
		status = fscanf(inputFile, "%lf" , &array[i][j]);
		}
		i++;
	}
		 /* i=8 cıkıyo 1 eksigi bize kaç sayı ol
										olduğunu vericek.*/
	i--;
	if( i < sizeOfArray ) 
	{
		sizeOfArray = i; /* Arrayde kaç nokta oldugu şuan elimizde. */
	}
	
	status=0;/* Status ü sıfırlıyoruz yukarıda arrayin kaç elemanlı olduğunu
				öğrenmek için kullandık.*/
	
	/* Read the value in input.txt */
	for(i=0; i<sizeOfArray; ++i )
	{
		for(j=0;j<2;j++)
		{
	 		status += fscanf(inputFile, "%lf" , &array[i][j]);
	 	}	
	}
	return ((-1)*(status/2));
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function output_corners                                        */
/*--------------------                                            */
/*----------------------------------------------------------------*/

void output_corners (FILE *outputFile, double array[][2], int sizeOfArray)
{
	int i,j,status;
	for(i=0; i<sizeOfArray; ++i )
	{
		for(j=0;j<2;j++)
		{
	 		status += fprintf(outputFile, "%.1f\t" , array[i][j]);
	 	}	
	 	fprintf(outputFile,"\n");
	}
	
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function output_corners                                        */
/*--------------------                                            */
/*----------------------------------------------------------------*/
double polygon_area(double array[][2], int sizeOfArray)
{
	int i;
	double result=0;
	for(i = 0; i < sizeOfArray; ++i)
	{
		result = result + (array[i+1][0] + array[i][0])
					* (array[i+1][1] - array[i][1]);
	}
	
	if(result < 0)
	{
		/* Mutlak degerin saglanmasi için. */
		result = result * (-1);
	}
	return(result/2);
}
/*################################################################*/
/*                  End of HW04_101044044_part1.c                 */
/*################################################################*/