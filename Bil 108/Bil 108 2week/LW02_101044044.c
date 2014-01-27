/*################################################################*/
/*                                                                */
/* Input.txt dosyasindaki degerlerin ortalama faktoriyel          */
/* degerlerini verir.                                             */
/* --------------------------------------------------------       */                                           
/* Coded on 02.03.2012 by Samet Sait Talayhan.                    */
/*                                                                */
/*                                                                */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                   Includes                                     */
/*################################################################*/
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void)

{
   double deger,  /* Input degerlerini alicagimiz degiskenler.  */
          deger2,
          deger3,
          deger4,
          deger5;
                    
    double x,y,t,m,n;   /* Islem karmasikligini onlemek icin degiskenler. */   


 
     /* Dosyalar */
     FILE * inputFile, * outputFile; 

 
     /* Dosyalari aciyoruz */
     inputFile = fopen("input.txt", "r");
     outputFile = fopen("output.txt", "w");

/*################################################################*/
/*                        1. Deger                                */
/*################################################################*/ 

     fscanf(inputFile, "%lf" , &deger); /* Ilk degeri okuyoruz input.txt den  */
        
     x = pow(deger,deger); /* Aldigimiz degerin karesini x'e atıyoruz. */
     y = exp(-deger);  /* e^(-deger) hesaplıyoruz */
     m = (2*PI*deger + ((double)1/3));
     t = sqrt(m); /* Karakokunu hesaplıyoruz. */
     n = x*y*t;
        
     fprintf(outputFile, " %1.0f! equals approximately     %13.2f.\n", deger, n);
        
/*################################################################*/
/*                        2. Deger                                */
/*################################################################*/         

     fscanf(inputFile, "%lf" , &deger2);
        
     x = pow(deger2,deger2);
     y = exp(-deger2);
     m = (2*PI*deger2 + ((double)1/3));
     t = sqrt(m);
     n = x*y*t;
        
     fprintf(outputFile, " %1.0f! equals approximately     %13.2f.\n", deger2, n);
        
/*################################################################*/
/*                        3. Deger                                */
/*################################################################*/         
        
            
        
     fscanf(inputFile, "%lf" , &deger3);
        
     x = pow(deger3,deger3);
     y = exp(-deger3);
     m = (2*PI*deger3 + ((double)1/3));
     t = sqrt(m);
     n = x*y*t;
        
     fprintf(outputFile, " %1.0f! equals approximately     %13.2f.\n", deger3, n);
        
/*################################################################*/
/*                        4. Deger                                */
/*################################################################*/         
        
     fscanf(inputFile, "%lf" , &deger4);
        
     x = pow(deger4,deger4);
     y = exp(-deger4);
     m = (2*PI*deger4 + ((double)1/3));
     t = sqrt(m);
     n = x*y*t;
        
     fprintf(outputFile, " %01.0f! equals approximately     %13.2f.\n",deger4,n);
        
/*################################################################*/
/*                        5. Deger                                */
/*################################################################*/        
        
        
     fscanf(inputFile, "%lf" , &deger5);
        
        
     x = pow(deger5,deger5);
     y = exp(-deger5);
     m = (2*PI*deger5 + ((double)1/3));
     t = sqrt(m);
     n = x*y*t;
        
     fprintf(outputFile, "%2.0f! equals approximately  %13.2f.\n", deger5, n);
       
        



     /* Dosyaları kapama */

     fclose(inputFile);
     fclose(outputFile);
        
     return 0;
        
}
