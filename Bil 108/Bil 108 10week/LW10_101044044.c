/*##########################################*/
/*                                          */
/*  Samet Sait Talayhan LW10_101044044.c    */
/*                                          */
/*                                          */
/*                                          */
/*                                          */
/*##########################################*/


#include <stdio.h>

int isElement(int num, int array[], int uzunluk);

int main()
{
 	 int array[5]={0,1,2,3,4} ;
	 int num = 19 ;
	 int uzunluk = 5;


 	 if(isElement(num,array,uzunluk)) 
 	 {
 	   printf("\n\n%d Kumededir.\n",num) ;
 	 }
 	 else
 	 {
      printf("\n\n%d Kumede degildir.\n",num) ;
  	 }
  	 return 0;
}


int isElement(int num, int array[], int uzunluk)
{

    if(uzunluk == 0)
    {
      return 0;
    }
    if(array[0] == num)
    {
      return 1 ;
    }
    else
    {
      return(isElement(num,&array[1],uzunluk -1)) ;
	}

}

