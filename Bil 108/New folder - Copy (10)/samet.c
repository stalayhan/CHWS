#include "samet.h"

/*----------------------------------------------------------------*/
/* Function getItems                                              */
/*----------------------------------------------------------------*/
void getItems( item itemArray[],int size )
{

	int i;
	for(i=0;i<size;i++)
	{
		do
		{
			printf("Enter of id=%d\n",i);
			scanf("%d",&itemArray[i].id);
		}while(itemArray[i].id<0);
		printf("Enter of name=%d\n",i);
		scanf("%s",itemArray[i].name);
		
		printf("Enter of price=%d\n",i);
		scanf("%lf",&itemArray[i].price);
/*		
		#if defined(DEBUG)
		printf("\nitemArray[0].id= %d",itemArray[i].id);
		printf("\nitemArray[0].name= %s",itemArray[i].name);
		printf("\nitemArray[0].price= %.2f",itemArray[i].price);
		#endif
*/
	}	
}
/*----------------------------------------------------------------*/
/* Function printItems                                            */
/*----------------------------------------------------------------*/
void printItems(const item itemArray[],int size )
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("\nitemArray[%d].id= %d",i,itemArray[0].id);
		printf("\nitemArray[%d].name= %s",i,itemArray[0].name);
		printf("\nitemArray[%d].price= %.2f",i,itemArray[0].price);
	}

}
