/*################################################################*/
/* LW04_101044044part1.c                                          */
/* ----------------------                                         */
/* Created on 16.03.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Aciklama                                                       */
/* ----------------------                                         */
/* 
/* ----------------------                                         */
/*                                                                */
/*################################################################*/

/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>

/*----------------------------------------------------------------*/
/*                   Function Prototypes                          */
/*----------------------------------------------------------------*/
int printChars(char ch, int n); 

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/

int main(void)
{
    int choose,n=1,i,
        height;
    
    printf("[1] Upper Triangle, [2] Lower Triangle, [3] Diamond, [0] Exit:");
    scanf("%d",&choose);
    printf("Enter the Height:");
    scanf("%d",&height);
    


    switch(choose)
        {
		    case 1:
		    {  
		       while(n<=height){ 
		       printChars('*',n);
		       printf("\n");
		       n = n++;
		       }
		    }
		    case 2:
		    { 
		       height = i;
		       while(n<=height){ 
		       printChars('*',n);
		       printf("\n");
		       n = n++;
		       }
		    }
		    case 3:
		    
		    case 0:
		    return 0;
		    
		    
			
	    }
}

/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* ifChoice Fonksiyonu                                            */
/* -------------------                                            */
/* Kullanicidan aldigi karakteri yine kullanicidan aldigi sayi    */
/* kadar bir bosluklu ekrana bastirir. Negatif degerler icin      */
/* return -1 dondurur.                                            */
/*----------------------------------------------------------------*/
int printChars(char ch, int n)
{
    int i,toplam=0;
    char bosluk=' ';
    
    if(n<=0)
    {
        return (-1);
    }
   
    /*  for(başlangıç ; koşul ; artım ) */
    for(i=1; i<=n; ++i)
    {
        toplam += printf("%c%c",ch,bosluk);
    }

    return (toplam);
}
/*################################################################*/
/*                  End of LW04_101044044part2.c                  */
/*################################################################*/ 
