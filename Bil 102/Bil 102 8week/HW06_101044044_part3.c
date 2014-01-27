/*################################################################*/
/* HW06_101044044_part3.c                                         */
/* ----------------------                                         */
/* Created on 09.05.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* Recursive olarak Bisection methodu kullanilarak verlilen tek   */
/* dereceli fonksiyonun kokunu kullanicidan aldigi tolerance deger*/
/* hassasiyetinde hesaplar.                                       */                    
/*################################################################*/

/*----------------------------------------------------------------*/
/*                           Includes                             */
/*----------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------*/
/*                     Function Prototypes                        */
/*----------------------------------------------------------------*/
double g(double x);
double findRoot(double x_left, double x_right, double epsilon,
			  double f(double farg));
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
	double x_left, x_right,
			epsilon,
			root;

	printf("\nEnter interval endpoints> ");
	scanf("%lf%lf", &x_left, &x_right);
	printf("\nEnter tolerance> ");
	scanf("%lf", &epsilon);

	printf("\nFunction g");
	root=findRoot(x_left, x_right, epsilon, g);

	printf("\n g(root Yani %f) = %f\n",root,g(root));

	return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function findRoot                                              */
/*--------------------                                            */
/* Verilen tek dereceli fonksiyonun koklerini bisection methodunu */
/* recursive olarak kullanarak hesaplar.                          */
/*----------------------------------------------------------------*/
double 
findRoot(double x_left,
	     double x_right,
	     double epsilon,
	     double f(double farg) )
{
    	double x_mid,
		       f_left,
		       f_mid,
		       f_right;
	    int    root_found;

            /* Yarisini aliyoruz bisection method. */
			x_mid = (x_left + x_right) / 2.0; 
			f_mid = f(x_mid); /* Fonksiyonda yerine yaziyoruz degerimizi. */
			
			f_left = f(x_left); /* fonksiyonun min degeri */
	        f_right = f(x_right); /* fonksiyonun max degeri */

            printf("\nNew interval is %f   %f",x_left, x_right);

            if(fabs(x_right - x_left) < epsilon)
            {
                return((x_left + x_right)/2.0);
            }
			if(f_mid == 0.0)
			{
				printf("\nRoot found at x=%f",x_mid);
				/* Fonksiyonu sifirliyorsa demekki koku bulduk. */
				return((x_left + x_right)/2.0); 
			}
			else if(f_left * f_mid < 0.0) 
			{
				return( findRoot(x_left,x_mid,epsilon,g) );
			}
			else
			{
				return( findRoot(x_mid,x_right,epsilon,g) );
			}
				
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function g                                                     */
/*--------------------                                            */
/* g(x)=5x^3-2x^2+3 verilen degerleri fonksiyonda yerine yazar    */
/* ve sonucu return degeri olarak geri dondurur.                  */
/*----------------------------------------------------------------*/
double 
g(double x)
{
	return(5*pow(x,3.0)-2*pow(x,2.0) + 3);
}
/*################################################################*/
/*                  End of HW06_101044044_part3.c                 */
/*################################################################*/
