/*################################################################*/
/* 101044044LW07.c                                                */
/* ----------------------                                         */
/* Created on 13.04.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>

/* Function prototypes */
int ReadPoints(FILE *inputFile, double points[][2],int sizeOfArray);

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main()
{
	double number,points[15][2],result=0,buyuk;
	int count=15,n,i,j;

	/* Definition to folders. */
	FILE *inputFile, *outputFile;	
	
	/* Open folders. */
	inputFile = fopen("points.txt", "r");
	outputFile = fopen("output.txt", "w");

	n = ReadPoints(inputFile, points ,count);
	

	for(i=0; i<count; ++i )
	{
		for(j=0;j<2;j++)
		{
	 		result = sqrt( pow((points[i+1][0] - points[i][0]),2)
			 + pow((points[j+1][1] - points[j][1]),2) );
			 if(result > buyuk)
			 {
			 	buyuk = result;
			 }
	 	}	
	}
	
	
	printf("%.2f\n",buyuk);


	/* Close folders. */
	fclose(inputFile);
	fclose(outputFile);
		
	return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function ReadPoints                                            */
/*--------------------                                            */
/*----------------------------------------------------------------*/
int ReadPoints(FILE *inputFile, double points[][2],int sizeOfArray)
{
	int status=0,j,i,count;
	
	fscanf(inputFile, "%d" , &count);
	
	if( count > sizeOfArray ) 
	{
		count = sizeOfArray ;
	}
	/* Read the value in points.txt */
	for(i=0; i<count; ++i )
	{
		for(j=0;j<2;j++)
		{
	 		status += fscanf(inputFile, "%lf" , &points[i][j]);
	 	}	
	}
	return (status);
}
/*################################################################*/
/*                  End of 101044044LW07.c                        */
/*################################################################*/
