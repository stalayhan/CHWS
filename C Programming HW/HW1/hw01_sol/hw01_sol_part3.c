/*###############################################################*/
/*                                                               */
/*                                                               */
/*                    HW1 Sample Solution                        */
/*                          Part3                                */
/*                                                               */ 
/*			                                                     */
/*                                                               */  
/*				                            					 */
/*###############################################################*/

#include<stdio.h>
#include<math.h>

/*Prototypes*/
double getRoot(double a,double b,double c,int rootNumber);

int main(void)
{
	/*Declaring file pointers */
	FILE *inp, 
		*outp; 

	/*Declaring Variables */
	int rootNumber;
	double a, 
		b, 
		c, 
		root; 

	/*Setting file pointers   */
	inp=fopen("inputs.txt","r"); 
	outp=fopen("results.txt","w+"); 


	/*1st UI conversation */
	printf("Please choose which root you want of 1st Polynom\n"); 
	printf("(1 for negative delta / 2 for positive delta :> ");
	scanf("%d",&rootNumber);

	/*Taking Multiplier values from inp file */
	fscanf(inp,"%lf %lf %lf",&a,&b,&c); 

	/*Calculating root of polynom */
	root=getRoot(a,b,c*(-1),rootNumber); 

	/*Printing to outp file */
	fprintf(outp,"Roots of (%.2fx^2 %.2fx %.2f) = %.2f\n",a,b,c,root); 

	/*2nd UI conversation */
	printf("Please choose which root you want of 2nd Polynom\n"); 
	printf("(1 for negative delta / 2 for positive delta :> ");
	scanf("%d",&rootNumber);

	/*Taking Multiplier values from inp file */
	fscanf(inp,"%lf %lf %lf",&a,&b,&c); 

	/*Calculating root of polynom */
	root=getRoot(a,b,c*(-1),rootNumber); 

	/*Printing to outp file */
	fprintf(outp,"Roots of (%.2fx^2 %.2fx %.2f) = %.2f\n",a,b,c,root); 
	
	/*3rd UI conversation */
	printf("Please choose which root you want of 3rd Polynom\n"); 
	printf("(1 for negative delta / 2 for positive delta :> ");
	scanf("%d",&rootNumber);

	/*Taking Multiplier values from inp file */
	fscanf(inp,"%lf %lf %lf",&a,&b,&c); 

	/*Calculating root of polynom */
	root=getRoot(a,b,c*(-1),rootNumber); 

	/*Printing to outp file */
	fprintf(outp,"Roots of (%.2fx^2 %.2fx %.2f) = %.2f\n",a,b,c,root); 

	printf("\n\aResults saved to results.txt file at same directory.\n");

	return 0;
}

double getRoot(double a,double b,double c,int rootNumber)
{
	/*Declaring Variables */
	double sqrtDelta, /*Square Root of Delta(b^2-4ac) */
		root; /*Root of polynom*/

	/*Mathematical Calculations */
	sqrtDelta=sqrt(pow(b,2)-(4*a*c));
	root=(-b+pow(-1,rootNumber)*sqrtDelta)/(2*a);

	return root;
}
