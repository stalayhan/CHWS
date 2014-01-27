/*################################################################*/
/* HW02_101044044_PART_2.c                                        */
/* ----------------------                                         */
/* Created on 10.03.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Aciklama                                                       */
/* ----------------------                                         */
/* Kullanicinin sectigi mothoda gore, kullanicinin girdigi        */
/* karakterin verilen tabloda gruplandirmasini yapar. Eger        */
/* karakter ingilizce alfabede yoksa hata mesaji verir. Uygulama  */
/* kullanicidan 5 karakter girisi alir. Kullanici 0 karakteri     */ 
/* girerse program sonlanir.                                      */
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
int readIn(void);
void ifChoice(char);
void switchChoice(char);
int userDefineFunctionChoice(char);
int isGroup0(char);
int isGroup1(char);
int isGroup2(char);
int isGroup3(char);


/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/

int main(void)
{
	int check,    /* kontrol icin. */
		choose,  /* Kullanicinin girdigi secim. */
		counter; /* Dongu kontrolu icin. */
	char letter; /* Kullanicinin girdigi karakter. */

	counter = 1;
	choose = readIn(); /* Kullanicidan Method seciminin yapilmasi. */
	
	
	/* Kullanici '1'inci methodu secerse  calistirilacak kod parcasi */
	if(choose == 1)           
	{ 
       /* Counter 6 dan kucuk oldugu surece while icini calistir ve
	  counteri 1 arttir */
	  while( counter < 6)
	  {
		printf("Enter the character (0 to terminate)(%d/5):",counter);
		scanf(" %c",&letter);
		if (letter == '0') /* 0 a basarsa kullanici, program sonlansin. */
		  {            
		  printf("Program is terminated by the user.\n");
		  return 0;  
		  }
		++counter;   /* condition update i */
	    ifChoice(letter);
		}
	  printf("Program is terminated due to completion of the maximum ");
	  printf("number of classifications.\n");	
	}
	
	if(choose == 2)
	{
	  while( counter < 6)
	  {
		printf("Enter the character (0 to terminate)(%d/5):",counter);
		scanf(" %c",&letter);
		if (letter == '0')
		  {            /* 0 a basarsa kullanici program sonlansin. */
			printf("Program is terminated by the user.\n");
			return 0;
		  }
		++counter;   
		switchChoice(letter);
	 }
	  printf("Program is terminated due to completion of the maximum ");
	  printf("number of classifications.\n");
	}


	if(choose == 3)
	{
	  while( counter < 6)
	  {
		printf("Enter the character (0 to terminate)(%d/5):",counter);
		scanf(" %c",&letter);
		if (letter == '0')
		{     /* 0 a basarsa kullanici program sonlansin. */
		  printf("Program is terminated by the user.\n");
		  return 0;
		}
	  ++counter;
	  /* Second degerini fonksiyona sokuyoruz.*/
	  userDefineFunctionChoice(letter);   
	  }
	  printf("Program is terminated due to completion of the maximum ");
	  printf("number of classifications.\n"); 
	}
	return 0; /* main return degeri */
}

/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* ifChoice Fonksiyonu                                            */
/* -------------------                                            */
/* Kullanicinin girdigi karakterin hangi sinifa ait oldugunu      */ 
/* if else yapisini kullanarak secer.                             */
/* Karsilastirma icin isGroup fonksiyonlarini cagirir. Kullanici  */
/* ingilizce olmayan bir karakter girerse hata mesaji verir.      */
/*----------------------------------------------------------------*/
void ifChoice(char letter)
{
   if (letter=='a' || letter=='A' || letter=='b'|| letter=='B'|| letter=='c' ||
letter=='C')
   {
		printf("%c is in group 0.0\n",letter);
   }
   else if (letter=='e' || letter=='E' || letter=='d'|| letter=='D')
   {
		printf("%c is in group 0.1\n",letter);
   }
   else if (letter=='f' || letter=='F' || letter=='g'|| letter=='G')
   {
		printf("%c is in group 0.2\n",letter);
   }
   else if (letter=='h' || letter=='H' || letter=='i'|| letter=='I')
   {
		printf("%c is in group 1.0\n",letter);
   }
   else if (letter=='j' || letter=='J' || letter=='k'|| letter=='K')
   {
		printf("%c is in group 1.1\n",letter);
   }
   else if (letter=='l' || letter=='L' || letter=='m'|| letter=='M')
   {
		printf("%c is in group 1.2\n",letter);
   }
   else if (letter=='n' || letter=='N' || letter=='o'|| letter=='O')
   {
		printf("%c is in group 2.0\n",letter);
   }
   else if (letter=='p' || letter=='P' || letter=='r'|| letter=='R'||
letter=='q'|| letter=='Q')
   {
		printf("%c is in group 2.1\n",letter);
   }
   else if (letter=='t' || letter=='T' || letter=='s'|| letter=='S')
   {
		printf("%c is in group 2.2\n",letter);
   }
   else if (letter=='u' || letter=='U' || letter=='v'|| letter=='V'||
letter=='w'|| letter=='W')
   {
		printf("%c is in group 3.0\n",letter);
   }
   else if (letter=='y' || letter=='Y'|| letter=='x'|| letter=='X')
   {
		printf("%c is in group 3.1\n",letter);
   }
   else if (letter=='z' || letter=='Z')
   {
		printf("%c is in group 3.2\n",letter);
   }
   else
   {
		printf("%c is not in English alphabet\n",letter);
   }
}
/*----------------------------------------------------------------*/
/* switchChoice Fonksiyonu                                        */
/* -------------------                                            */
/* Kullanicinin girdigi karakterin hangi sinifa ait oldugunu      */ 
/* switch yapisini kullanarak secer.Kullanici ingilizce olmayan   */
/* bir karakter girerse hata mesaji verir.                        */
/*----------------------------------------------------------------*/
void switchChoice(char letter)
{
   switch(letter)
   {
		case 'a':
		case 'b':
		case 'c':
		case 'A':
		case 'B':
		case 'C':
			printf("%c is in group 0.0\n",letter);
			break;
	
		case 'd':
		case 'e':
		case 'D':
		case 'E':
			printf("%c is in group 0.1\n",letter);
			break;
	  
		case 'f':
		case 'g':
		case 'F':
		case 'G':
			printf("%c is in group 0.2\n",letter);
			break;
	  
		case 'h':
		case 'i':
		case 'H':
		case 'I':
		  printf("%c is in group 1.0\n",letter);
		  break;  
	  
		case 'j':
		case 'k':
		case 'J':
		case 'K':
		  printf("%c is in group 1.1\n",letter);
		  break;
	  
		case 'l':
		case 'm':
		case 'L':
		case 'M':
		  printf("%c is in group 1.2\n",letter);
		  break;
	  
		case 'n':
		case 'o':
		case 'N':
		case 'O':
		  printf("%c is in group 2.0\n",letter);
		  break;
	  
		case 'p':
		case 'r':
		case 'P':
		case 'R':
		case 'q':
		case 'Q':
		  printf("%c is in group 2.1\n",letter);
		  break;
	  
		case 's':
		case 't':
		case 'S':
		case 'T':
		  printf("%c is in group 2.2\n",letter);
		  break;
	  
		case 'u':
		case 'v':
		case 'U':
		case 'V':
		case 'w':
		case 'W':
		  printf("%c is in group 3.0\n",letter);
		  break;
	  
		case 'y':
		case 'Y':
		case 'x':
		case 'X':
		  printf("%c is in group 3.1\n",letter);
		  break;
	  
		case 'z':
		case 'Z':
		  printf("%c is in group 3.2\n",letter);
		  break;  

		default:
		  printf("%c is not English alphabet\n",letter);

   }
}
/*----------------------------------------------------------------*/
/* userDefineFunctionChoice Fonksiyonu                            */
/* -------------------                                            */
/* Kullanicinin girdigi karakterin hangi sinifa ait oldugunu secer*/
/* .Karsilastirma icin isGroup fonksiyonlarini cagirir. Kullanici */
/* ingilizce olmayan bir karakter girerse hata mesaji verir.      */
/*----------------------------------------------------------------*/
int userDefineFunctionChoice(char letter)
{
	int control0,control1,control2,control3;
	
	control0=isGroup0(letter);
	if(control0 == 1)
	{
		return 0;
	}
	control1=isGroup1(letter);
	if(control1 == 1)
	{
		return 0;
	}
	control2=isGroup2(letter);
	if(control2 == 1)
	{
		return 0;
	}
	control3=isGroup3(letter);
	if(control3 == 1)
	{
		return 0;
	}
	if(control0 == 0 && control1 == 0 && control2 == 0 && control3 == 0)
	{
		printf("%c is not English alphabet\n",letter);
	}  
}
/*----------------------------------------------------------------*/
/* isGroup0 Fonksiyonu                                            */
/* -------------------                                            */
/* 0 karakter grubunun icindeki karakterlerin kontrolu icin       */
/* tanimlanmistir. if yapisiyla kontrol eder, karakter bu grupta  */
/* ise ekrana bastirir ve 1 degerini return eder. Degilse         */
/* 0 degerini return eder.                                        */
/*----------------------------------------------------------------*/
int isGroup0(char c)
{
	if (c=='a' || c=='A' || c=='b'|| c=='B'|| c=='c' || c=='C' ||
	c=='d' || c=='D' || c=='e'|| c=='E'|| c=='f' || c=='F'|| c=='g' || c=='G')
	{
		printf("%c is in group 0\n",c);
		return 1;
	}
  return 0;
}
/*----------------------------------------------------------------*/
/* isGroup1 Fonksiyonu                                            */
/* -------------------                                            */
/* 1 karakter grubunun icindeki karakterlerin kontrolu icin       */
/* tanimlanmistir. if yapisiyla kontrol eder, karakter bu grupta  */
/* ise ekrana bastirir ve 1 degerini return eder. Degilse         */
/* 0 degerini return eder.                                        */
/*----------------------------------------------------------------*/
int isGroup1(char c)
{
if (c=='h' || c=='H' || c=='j'|| c=='J'|| c=='i' || c=='I' ||
	c=='k' || c=='K' || c=='l'|| c=='L'|| c=='m' || c=='M')
	{
	  printf("%c is in group 1\n",c);
	  return 1;
	}
  return 0;
}
/*----------------------------------------------------------------*/
/* isGroup2 Fonksiyonu                                            */
/* -------------------                                            */
/* 2 karakter grubunun icindeki karakterlerin kontrolu icin       */
/* tanimlanmistir. if yapisiyla kontrol eder, karakter bu grupta  */
/* ise ekrana bastirir ve 1 degerini return eder. Degilse         */
/* 0 degerini return eder.                                        */
/*----------------------------------------------------------------*/
int isGroup2(char c)
{
if (c=='n' || c=='N' || c=='o'|| c=='O'|| c=='p' || c=='P' ||
	c=='q' || c=='Q' || c=='r'|| c=='R'|| c=='s' || c=='S'|| c=='t' || c=='T')
	{
	  printf("%c is in group 2\n",c);
	  return 1;
	}
  return 0;
}
/*----------------------------------------------------------------*/
/* isGroup3 Fonksiyonu                                            */
/* -------------------                                            */
/* 3 karakter grubunun icindeki karakterlerin kontrolu icin       */
/* tanimlanmistir. if yapisiyla kontrol eder, karakter bu grupta  */
/* ise ekrana bastirir ve 1 degerini return eder. Degilse         */
/* 0 degerini return eder.                                        */
/*----------------------------------------------------------------*/
int isGroup3(char c)
{
if (c=='u' || c=='U' || c=='v'|| c=='V'|| c=='y' || c=='Y' ||
	c=='w' || c=='W' || c=='x'|| c=='X'|| c=='z' || c=='Z')
	{
	  printf("%c is in group 3\n",c);
	  return 1;
	}
  return 0;
}
/*----------------------------------------------------------------*/
/* readIn Fonksiyonu                                              */
/* -------------------                                            */
/* Kullanicinin girdigi method secimini okur. Hatali giris ise    */
/* uyari mesaji verir.                                            */
/*----------------------------------------------------------------*/
int readIn(void)
{
	int check,choose;
	check = 3; /* Kullanicinin girdigi method numarasini kontrol etmek icin. */
	
     /* Ekran ciktilari  */
	printf("Which implementation method do you prefer");
	printf("(1: if clauses, 2: switch clauses, 3: User-defined functions):");
	scanf("%d",&choose);
	if(choose > check)          /* secim 3 den buyukse hata ver. */
	{
		printf("Illegal choice!\n");
		return (0);	
	}
	return (choose);  /* choose degerini dondur eger 3 den kucukse. */
}
/*################################################################*/
/*                  End of HW02_101044044_part2.c                 */
/*################################################################*/






