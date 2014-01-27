/*################################################################*/
/* 101044044LW08.c                                                */
/* ----------------------                                         */
/* Created on 20.04.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_SIZE 50

/* Function prototypes */
int isPalindrome(char *str);
char* deleteChar(char str[], char charToDel);

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main()
{
	char str[MAX_SIZE];
	int sonuc,i=0,count=0,isAlpha;

    printf("Bir string giriniz: ");
    gets(str);
    
    sonuc = isPalindrome(str);

    if( sonuc == 1)
    {
        printf("Bu string bir palidromdur!\n");    
    }
    else
    {
        printf("Bu string bir palidrom degildir!\n"); 
    }
	return 0;
}

/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function isPalindrome                                          */
/*--------------------                                            */
/* Girilen stringin palidrom olup olmadigini kontrol eder.        */
/* Polidromsa "1" degilse "0" dondurur.                           */
/*----------------------------------------------------------------*/
int isPalindrome(char *str)
{
    int i=0,count=0,zero=0,sayac=0;
    char x[MAX_SIZE],a,b;
    
    while(str[i] != '\0' )
    {
        printf("%c",str[i]);
        i++;
        count++;
    }
    printf("\n");
    printf("Sayisi = %d\n",count);

    /* count su anda girilen kelimenin harf sayisi */
    for(i=0; i < count ;i++)
	{
		x[i] = str[i];
	}
        /* i suan 6  */
    i--; /* i=5 */
	for(i; i>0 ;--i)
	{
		str[zero] = x[i];
        zero++;
	}
    /* str de donmus hali var, x[i] kopyasi suanda. */

    for(i=0;i<count;i++)
    {
        if(str[i] == x[i])
        {
            sayac++;        
        }
    }
    /* count sayaca esitse demekki butun degerler esit ve polidrom */
    if(sayac == count)
    {
        return 1;    
    }
	else
    {
    return 0;
    }
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* Function deleteChar                                            */
/*--------------------                                            */
/* Girilen stringten istenilen karakteri siler.                   */
/*----------------------------------------------------------------*/
/*
char* deleteChar(char str[], char charToDel);
{



    return 0;
}
*/
/*################################################################*/
/*                  End of 101044044LW08.c                        */
/*################################################################*/
