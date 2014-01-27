/*################################################################*/
/* HW01_Samet_Sait_Talayhan_101044044_part3.c                     */
/* ----------------------                                         */
/* Created on March 1, 2013, 9:49 PM by Samet Sait Talayhan.      */ 
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* This program read 3 second degree polynomials from an input 
/* text file “polynomials.txt” and outputs their roots.
/* And Program assume that the polynomials have reel roots.
/* ----------------------                                         */
/*                                                                */
/*################################################################*/
/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------*/
/*                    Function Prototypes                         */
/*----------------------------------------------------------------*/
double getRoot(double a,double b,double c,int rootNumber);/*1 or 2*/

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
    FILE *inp;
    double a,   /* coefficients */
           b,
           c;
    inp = fopen("polygons.txt","r");
    
    /* Get a,b,c value for first equation from polygons.txt */
    fscanf(inp,"%lf%lf%lf",&a,&b,&c);
    printf("Test1 getRoot Function %.2f:\n",getRoot(a,b,c,1));

    /* Get a,b,c value for second equation from polygons.txt */
    fscanf(inp,"%lf%lf%lf",&a,&b,&c);
    printf("Test2 getRoot Function %.2f:\n",getRoot(a,b,c,1));

    /* Get a,b,c value for third equation from polygons.txt */
    fscanf(inp,"%lf%lf%lf",&a,&b,&c);
    printf("Test3 getRoot Function %.2f:\n",getRoot(a,b,c,2));
    
    fclose(inp);
    return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* getRoot Function      					                      */
/* -------------------                                            */
/* double a, - input Parameter // Polygon's degree
   double b,
   double c,
   int rootNumber //determine root which is returned                                                                             
/* This function returns the specified root                       */
/*----------------------------------------------------------------*/
double
getRoot(double a,double b,double c,int rootNumber)
{
	double delta; /* Discriminant */

	/* Calculate discriminant */
	delta = (b * b) - (4 * a * c);

	return (-b + pow(-1.0,(double)rootNumber)*sqrt(delta)) / (2 * a);
}
