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

#define MAX_SIZE 9

/*--------------------------------------------------------------- */
/*--------------------- Function Prototypes---------------------- */
/*--------------------------------------------------------------- */
/* Read coefficients from a given input file */
void getPoly(FILE *inputFile, double coeff[], int *degreep);

/* Evaluate a polynomial at a given value of x */
double evaluate( const double coeff[], int defree, double x);

/* Set all coefficients to zero */
void setToZero(double coeff[], int degree);

/* result = poly1 + poly2 */
double addPoly(const double poly1[], const double poly2[], double result[],
			   int degreePoly1, int degreePoly2, int degreeResult);

/* result = poly1 * poly2 */
double multiplyPoly(const double poly1[], const double poly2[], double result[],
			   int degreePoly1, int degreePoly2, int degreeResult);

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main()
{
	int degreep,degreep2,i,p=0,choose=0,degreePoly1,degreePoly2;
	double coeff[MAX_SIZE],coeff2[MAX_SIZE],result[MAX_SIZE],maxKatsayi;
	/* Definition to folders. */
	FILE *inputFile1, *inputFile2;	
	
	/* Open folders. */
	inputFile1 = fopen("point1.txt", "r");
	inputFile2 = fopen("point2.txt", "r");
	
	setToZero(coeff,MAX_SIZE-1);
	setToZero(coeff2,MAX_SIZE-1);
	
	getPoly(inputFile1,coeff,&degreep);
	getPoly(inputFile2,coeff2,&degreep2);
	
	degreePoly1=degreep;
	degreePoly2=degreep2;
	
	printf("Bir polinom secin:\n");
	printf("1)");
	printf("degreep = %d\n",degreep);
	for(p=0; p<degreep;--degreep)
	{
		printf("%.1fx^%d +",coeff[degreep],degreep);
	}
	printf("%.1f\n",coeff[0]);
	
	printf("2)");
	printf("degreep2 = %d\n",degreep2);
	for(p=0; p<degreep2;--degreep2)
	{
		printf("%.1fx^%d +",coeff2[degreep2],degreep2);
	}
	printf("%.1f\n",coeff2[0]);
	
	/*User choose*/
	do
	{
	scanf("%d",&choose);
	}while(choose != 1 && choose != 2);
	
	

	maxKatsayi = addPoly(coeff, coeff2, result,
			   degreePoly1, degreePoly2, MAX_SIZE);
	printf("maxkatasyi = %.2f",maxKatsayi);
	
	/* Close folders. */
	fclose(inputFile1);
	fclose(inputFile2);
	
	return 0;
}
void setToZero(double coeff[], int degree)
{
	int i;
	for(i=0; i <= degree;i++)
	{
		coeff[i] = 0;
	}
}
void getPoly(FILE *inputFile, double coeff[], int *degreep)
{
	int i=0,status=0,x[MAX_SIZE];
	int testValue,zero=0;
	
	do
	{
		status = fscanf(inputFile, "%lf", &coeff[i]);
		i++;
	}while(status != EOF );

	*degreep = i-2;
	testValue = *degreep;
		
	for(i=0; i <= testValue ;i++)
	{
		x[i] = coeff[i];
	}
	i--;
	for(i; i>=0 ;--i)
	{
		coeff[zero] = x[i];
		zero++;
	}
}
double addPoly(const double poly1[], const double poly2[], double result[],
			   int degreePoly1, int degreePoly2, int degreeResult)
{
	int degree,i=0;
	printf("degreePoly1 %d\n",degreePoly1);
	printf("degreePoly2 %d\n",degreePoly2);
	if (degreePoly1 > degreePoly2)
	{
		degree = degreePoly1;
	}
	else
	{
		degree = degreePoly2;
	}
	printf("degree = %d\n",degree);
	for(i=0;i<=degree;i++)
	{
		result[i] = poly1[i] + poly2[i];
		printf("sonuc result[%d] = %f\n",i,result[i]);
	}
	return(result[degree]);
}