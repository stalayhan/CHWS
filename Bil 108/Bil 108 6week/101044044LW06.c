/*################################################################*/
/* 101044044LW06.c                                                */
/* ----------------------                                         */
/* Created on 06.04.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* F(x)= x + 5 fonksiyonu için girilen alt taban(a) ve ust taban  */
/* (b) için alan hesaplar.                                        */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>

/* Function prototypes */
double areaUnderTheCurve(int ,int ,int );
double f(double );

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/* 0 on success                                                   */
/*################################################################*/
int main(void)
{
   int a;
   int b;
   int n;
   
   double sonuc;
   
   do
   {  
   printf("A degeri girin: \n");
   scanf("%d",&a);
   }while( a < 0 );
   do
   { 
   printf("B degeri girin: \n");
   scanf("%d",&b);
   }while( a < 0 );
   do
   { 
   printf("N degeri girin: \n");
   scanf("%d",&n);
   }while( a < 0 );

    
   sonuc = areaUnderTheCurve(a,b,n);
   
   printf("Sonuc %.2f\n",sonuc);
   
   
   return 0;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function areaUnderTheCurve                                     */
/*---------------------                                           */
/* Bu fonksiyon aldigi degerleri kullanarak yamuk alani hesaplar. */
/*----------------------------------------------------------------*/
double areaUnderTheCurve( int a, int b, int n )
{
   double h;
   double toplam=0;
   
   h = (double)b-a;
   
   
   toplam = ( f(a) + f(b) ) * h;
   toplam = toplam / 2 ;
   
   
   return (toplam);
}
/* Function f                                                     */
/*---------------------                                           */
/*Bu fonksiyon F(x)= x + 5 hesaplar y degerini dondurur.          */
/*----------------------------------------------------------------*/
double f(double x)
{
   return( x+5 );
}
/*################################################################*/
/*                  End of 101044044LW06.c                        */
/*################################################################*/