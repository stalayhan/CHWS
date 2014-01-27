#include <stdio.h>
#include <time.h>

int printfHistogram(int zar1, int zar2, int zar3, int zar4, int zar5, int zar6);

int main(void)
{

	int sayi,rastgele,i,sonuc=0;
	
	int zar1=0,zar2=0,zar3=0,zar4=0,zar5=0,zar6=0;

	
	while(sayi < 10 || sayi > 100)
	{
		printf("Number of turns[10, 100]:");
	    scanf("%d",&sayi);   /* Sayi da adamın istediği var. */
	}
	
	srand(time(NULL));


	for(i=0;i < sayi;i++)
	{
	    rastgele = rand() % 6; /*(0 ile 5 arasında rastgele sayi) */
	    if(rastgele == 0)
	    {
	    	zar1++;
	    }
	    if(rastgele == 1)
	    {
	    	zar2++;
	    }
	    if(rastgele == 2)
	    {
	    	zar3++;
	    }
	    if(rastgele == 3)
	    {
	    	zar4++;
	    }
	    if(rastgele == 4)
	    {
	    	zar5++;
	    }
	    if(rastgele == 5)
	    {
	    	zar6++;
	    }  
	}  
	
	    sonuc = printfHistogram(zar1,zar2,zar3,zar4,zar5,zar6);
	    printf("%d",sonuc);  
	   
	return 0;
}

int printfHistogram(int zar1, int zar2, int zar3, int zar4, int zar5, int zar6)
{

		int i; /* Artış kontrolü */
		int sum=0; /* Histogram toplamı */

 		printf("1:");
	    for(i=0;i<zar1;i++)
	    {
	    	sum += printf("*");
	    }
	    printf("\n");
	    
	    printf("2:");
	    for(i=0;i < zar2;i++)
	    {
	    	sum += printf("*");
	    }
	    printf("\n");
	    
	    printf("3:");
	    for(i=0;i<zar3;i++)
	    {
	    	sum += 	printf("*");
	    }
	    printf("\n");
	    
	    printf("4:");
	    for(i=0;i<zar4;i++)
	    {
	    	sum += 	printf("*");
	    }
	    printf("\n");
	    
	    printf("5:");
	    for(i=0;i<zar5;i++)
	    {
	    	sum += 	printf("*");
	    }
	    printf("\n");
	    
	    printf("6:");
	    for(i=0;i<zar6;i++)
	    {
	    	sum += 	printf("*");
	    }
	    printf("\n");
	
	    return (sum);
}


