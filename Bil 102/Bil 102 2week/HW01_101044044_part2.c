/*################################################################*/
/* HW01_101044044_PART_2.c                                        */
/* ----------------------                                         */
/* Created on 07.03.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* This implementation determines total cost of some houses for a */
/* period of 5 years.                                             */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>
/*################################################################*/
/*                           #defines                             */
/*################################################################*/
#define PERIOD_FIVE_YEARS 5

/* Function prototypes */
int topla(int, int, double);
void writeToFile(FILE * outputFile,
		int initialHouseCost, int annualFuelCost, double taxRate, int sonuc);

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main(void)
{
	int initialHouseCost,
		annualFuelCost,
		sonuc;
	double taxRate;


	/* Definition to folders. */
	FILE * inputFile, *outputFile;	
	
	/* Open folders. */
	inputFile = fopen("input.txt", "r");
	outputFile = fopen("output.txt", "w");

	/* Read the value of 1 row in input.txt */
	fscanf(inputFile, "%d%d%lf" , &initialHouseCost,&annualFuelCost,&taxRate);
	
	/* Compute the total cost. */
	sonuc = topla(initialHouseCost, annualFuelCost, taxRate);

	fprintf(outputFile, "Initial House Cost\t Annual Fuel Cost\tTax Rate\t");
	fprintf(outputFile, "Total Cost\n");
	writeToFile(outputFile, initialHouseCost, annualFuelCost, taxRate, sonuc);
	
	/* Read the value of 2 row in input.txt */
	fscanf(inputFile, "%d%d%lf" , &initialHouseCost,&annualFuelCost,&taxRate);
	sonuc = topla(initialHouseCost, annualFuelCost, taxRate);
	writeToFile(outputFile, initialHouseCost, annualFuelCost, taxRate, sonuc);
	
	/* Read the value of 3 row in input.txt */
	fscanf(inputFile, "%d%d%lf" , &initialHouseCost,&annualFuelCost,&taxRate);
	sonuc = topla(initialHouseCost, annualFuelCost, taxRate);
	writeToFile(outputFile, initialHouseCost, annualFuelCost, taxRate, sonuc);
	
	/* Read the value of 4 row in input.txt */
	fscanf(inputFile, "%d%d%lf" , &initialHouseCost,&annualFuelCost,&taxRate);
	sonuc = topla(initialHouseCost, annualFuelCost, taxRate);
	writeToFile(outputFile, initialHouseCost, annualFuelCost, taxRate, sonuc);
	
	/* Read the value of 5 row in input.txt */
	fscanf(inputFile, "%d%d%lf" , &initialHouseCost,&annualFuelCost,&taxRate);
	sonuc = topla(initialHouseCost, annualFuelCost, taxRate);
	writeToFile(outputFile, initialHouseCost, annualFuelCost, taxRate, sonuc);
	

	/* Close folders. */
	fclose(inputFile);
	fclose(outputFile);
	
	return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/

/* Function Total_Cost                                            */
/*--------------------                                            */
/* This function compute the total cost for five years by adding  */
/* annual fuel costs and taxes to the initial costs for each year */
/*----------------------------------------------------------------*/

int topla(int initialHouseCost, int annualFuelCost, double taxRate)
{
	int process; 
	process = (annualFuelCost*PERIOD_FIVE_YEARS)+
	((initialHouseCost*taxRate)*PERIOD_FIVE_YEARS);
	return (process+initialHouseCost);	

}

/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function writeToFile                                           */
/*---------------------                                           */
/*This function writes integers and double values to a file.      */
/*----------------------------------------------------------------*/
void writeToFile(FILE * filePtr,
		int initialHouseCost, int annualFuelCost, double taxRate, int sonuc)
{
	fprintf(filePtr, "%5.0d\t\t\t\t%5.0d\t\t\t\t%1.3f\t\t%5.0d\n",
			initialHouseCost, annualFuelCost, taxRate, sonuc);
}
/*################################################################*/
/*                  End of HW01_101044044_part2.c                 */
/*################################################################*/
