/*################################################################*/
/* HW03_101044044.c                                               */
/* ----------------------                                         */
/* Created on 07.04.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* Kullanici tarafindan secilen yapiya gore (two-point form veya  */
/* point-slope form) egim ve y-kesisim noktasini hesaplar.        */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/

/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>

/* -------------------------------------------------------------- */
/*--------------------- Function Prototypes --------------------- */
/* -------------------------------------------------------------- */
int get_problem();
void get2_pt(double *firstX, double *firstY, double *secondX, double *secondY);
void get_pt_slope(double *, double *, double *);
void slope_intcpt_from2_pt(double ,double ,double ,double ,double* ,double*);
double intcpt_from_pt_slope( double, double, double);
void display2_pt(double, double, double, double);
void display_pt_slope(double, double, double);
void display_slope_intcpt(double, double);

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main(void)
{
	int userChoose;
	char userContinue = 0;
	double firstX=0,
		firstY=0,
		secondX=0, 
		secondY=0,
		slope = 0,
		yIntcpt = 0;

	do
	{		
	

		do
		{
			userChoose = get_problem(); /* Kullanicidan secimini alma islemi.*/
		}while( userChoose != 1 && userChoose != 2 );

		if ( userChoose == 1 )
		{
			/* Kullanicidan 2 nokta aliyoruz. */
			get2_pt(&firstX, &firstY, &secondX, &secondY); 
		
			/* Aldigimiz noktalari ekranda gosteriyoruz. */
			display2_pt(firstX, firstY, secondX, secondY);

			/* Egim ve y-kesisim noktasini hesapliyoruz. */
			slope_intcpt_from2_pt(firstX,firstY,
									secondX,secondY, &slope, &yIntcpt);
		
			/* Egim ve y-kesisim noktasini ekrana basiyoruz. */
			display_slope_intcpt(slope, yIntcpt);
		}
		else if ( userChoose == 2 )
		{
			/* Kullanicidan bir nokta ve egim aliyoruz. */
			get_pt_slope(&slope, &firstX, &firstY);

			/* Egim ve noktayi ekrana bastiriyoruz. */
			display_pt_slope( firstX, firstY, slope );

			/* Egim ve noktanin koordinatlari yardimiyle y-kesisim noktasini
		   	buluyoruz */
			yIntcpt = intcpt_from_pt_slope( firstX, firstY, slope );		
		
			/* Egim ve kesisim noktasini ekrana bastiriyoruz. */		
			display_slope_intcpt(slope, yIntcpt);
		}

		do
		{
		printf("Do another conversion (Y or N)=> ");
		scanf(" %c",&userContinue);
		printf("\n");
		}while( userContinue != 'Y' && userContinue != 'N' );

	}while( userContinue == 'Y' );

	return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function get_problem                                           */
/*---------------------                                           */
/* Kullanici menusunu gosterir, ve kullanicinin sectigi islem     */
/* numarasini return eder.                                        */
/*----------------------------------------------------------------*/
int get_problem(void)
{
	int select;
	
	printf("Select the form that you would like to convert to slope-");
	printf("\nintercept form: \n");
	printf("1) Two-point form (you know two points on the line)\n");
	printf("2) Point-slope form (you know the line's slope and one point)");
	printf("\n=> ");
	scanf("%d",&select);
	printf("\n");
	
	return (select);
}
/*----------------------------------------------------------------*/
/* Function get2_pt                                               */
/*------------------------                                        */
/* Kullanicidan 2 noktanin x-y koordinatlarini ister, ve bu deger-*/
/* leri output-parametresi olarak geri dondurur.                  */
/*----------------------------------------------------------------*/
void get2_pt(double *firstX, double *firstY, double *secondX, double *secondY)
{
	double x1,y1,x2,y2;
	
	printf("Enter the x-y coordinates of the first point separated by a\n");
	printf("space=> ");
	scanf("%lf%lf",&x1,&y1);
	printf("Enter the x-y coordinates of the second point separated by a\n");
	printf("space=> ");
	scanf("%lf%lf",&x2,&y2);
	
	*firstX = x1;
	*firstY = y1;
	*secondX = x2;
	*secondY = y2;
		
}
/*----------------------------------------------------------------*/
/* Function get_pt_slope                                          */
/*---------------------                                           */
/* Kullanicidan noktanin x-y koordinatlarini  ve egim degeri ister*/
/* Bu verileri output-parametresi olarak geri dondurur.           */
/*----------------------------------------------------------------*/
void get_pt_slope(double *slopePt, double *xPt, double *yPt)
{
	double slope,
		x,
		y;
	
	printf("Enter the slope=> ");
	scanf("%lf",&slope);
	printf("Enter the x-y coordinates of the point separated by a space => ");
	scanf("%lf%lf",&x,&y);
	printf("\n");
	
	*slopePt = slope;
	*xPt = x;
	*yPt = y;
	
}
/*----------------------------------------------------------------*/
/* Function slope_intcpt_from2_pt                                 */
/*---------------------                                           */
/* Input parametresi olarak 2 noktanin x-y koordinatlarini alir,  */
/* Egim ve y-kesisim noktasini hesaplar, output-parametresi       */
/* olarak geri dondurur.                                          */
/*----------------------------------------------------------------*/
void slope_intcpt_from2_pt(double firstX, double firstY, 
	double secondX, double secondY, double *slopePt, double *yIntcpt)
{	
	double m, /* Egim */
		   b; /* y-kesisim noktasi. */
	
	m = ( secondY - firstY ) / ( secondX - firstX );
	b = firstY - ( m * firstX );
	
	*slopePt = m;
	*yIntcpt = b;

}
/*----------------------------------------------------------------*/
/* Function intcpt_from_pt_slope                                  */
/*---------------------                                           */
/* Input-parametresi olarak bir noktanin x-y koordinatlarini ve   */
/* egim degerini alir. y-kesisim noktasini hesaplar, fonksiyonda  */
/* return eder. */
/*----------------------------------------------------------------*/
double intcpt_from_pt_slope( double x, double y, double slope )
{
		return ( y - ( slope * x ) );
}
/*----------------------------------------------------------------*/
/* Function display2_pt                                           */
/*---------------------                                           */
/* Input-parametresi olarak 2 noktanin x-y koordinatlarini alir.  */
/* Two-Point formuna gore ekrana bastirir.                        */
/*----------------------------------------------------------------*/
void display2_pt(double firstX, double firstY, double secondX, double secondY)
{
	printf("Two-point form\n");
	printf("      (%.2f - %.2f)\n",secondY,firstY);
	printf(" m = ---------------\n");
	printf("      (%.2f - %.2f)\n\n",secondX,firstX);
}
/*----------------------------------------------------------------*/
/* Function display_pt_slope                                      */
/*---------------------                                           */
/* Input-parametresi olarak bir noktanin x-y koordinatlarini alir.*/
/* Point-slope esitlik formuna gore ekrana bastirir.              */
/*----------------------------------------------------------------*/
void display_pt_slope(double firstX, double firstY, double slope)
{
	printf("Point-slope form\n");
	printf("  y - %.2f = %.2f(x - %.2f)\n\n",firstY,slope,firstX);
}
/*----------------------------------------------------------------*/
/* Function display_slope_intcpt                                  */
/*---------------------                                           */
/* Input-parametresi olarak egim ve y-kesisim noktasini alir.     */
/* Slope-intercept esitlik formuna gore ekrana bastirir.          */
/*----------------------------------------------------------------*/
void display_slope_intcpt(double slope, double yIntcpt) 
{
	printf("Slope-intercept form\n");
	printf("  y = %.2fx + %.2f\n",slope,yIntcpt);	
}
/*################################################################*/
/*                  End of HW03_101044044.c                       */
/*################################################################*/
