/*################################################################*/
/* HW02_101044044_part1.c                                        */
/* ----------------------                                         */
/* Created on 10.03.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Aciklama                                                       */
/* ----------------------                                         */
/* Verilen fonksiyona kullanicidan aldigi z degerini ve n=1,2,3.. */
/* 10'a kadar fonksiyona sokar ve sonucunu ekrana bastirir.       */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------*/
/*                   Function Prototypes                          */
/*----------------------------------------------------------------*/  
double fooFonksiyonu(double, int);


/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/

int main(void)
{
	int n, /* Fonksiyon un 'n' icin baslangic degeri. */
	counter; /* Dongu icin sayac atamasi. */
	double z,result;
	
	n = 1; /* Baslangic degeri n icin. */
	counter = 0;
	/* Kullanicidan 'z' degeri aliyoruz. */
	printf("Bir sayi giriniz(1 haric):");
	scanf("%lf",&z);
	if( z == 1 || z <= 0  ) /* Hatali girisi kontrol icin.*/
	{        
		printf("Hatali giris!\n");
		return 0;
	}
		
	while( counter < 10 ) /* counterin 10 dan kucuk oldugu durumlarda*/
		{							/* While icini calistirir. */
		counter+=1; /* Dongu nun sonlanmasi icin sayaci arttiriyoruz. */
		result = fooFonksiyonu(z,n);
		printf("F(%1.1f,%d) %4.2f\n",z,n,result);
		n = ++n;
		}
	return 0;
}
/*----------------------------------------------------------------*/
/*               Fonksiyon Uygulamasi                             */
/*----------------------------------------------------------------*/
/* F(z,n) Fonksiyonu                                              */
/* -------------------                                            */
/* Bu fonksiyon asagidaki isleme kullanicidan aldigi z degerini ve*/
/* n icin n=1,2, ..10.a kadar isleme sokar.                       */
/* ------------------------                                       */
/*                                                                */
/******************************************************************/

double fooFonksiyonu(double z, int n)
{	
	double result;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	return (result);

}
/*################################################################*/
/*                  End of HW02_101044044_part1.c                 */
/*################################################################*/
