/*################################################################*/
/* HW05_101044044_PART2.c                                         */
/* ----------------------                                         */
/* Created on 03.05.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* Verilen stringin icerisindeki kelimeleri cogul yapar.          */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main()
{
	int i,j,k,uzunluk;
	char source[MAX_LEN],copy[MAX_LEN];	

	printf("Enter the source string:\n> ");  
	gets(source);    

	uzunluk=strlen(source);
	for(i=0;i<MAX_LEN;i++)
	{
		if(source[i+1]==' ' || source[i+1]=='\0')
		{
			if(source[i] == 'y')
			{	
				/* stringin y den sonrasini copye atiyoruz. */				
				strcpy(copy,&source[i+1]); 
				for(k=i;k<strlen(source);k++)
				{
					source[k]='\0';
				}
				strcat(source,"ies"); /* y yerine ies yaziyoruz. */
				/* y den sonra kopyaladigimiz kismi geri ekliyoruz. */
				strcat(source,copy); 
				i +=4;
			}		
			else if(source[i-1]=='c' && source[i]=='h')
			{
				for(k=0;k<strlen(copy);k++)
				{
					copy[k]='\0';
				}
				strcpy(copy,&source[i+1]);
				strcpy(&source[i+1],"es");
				strcat(source,copy); 
				i +=3;
			}
			else if(source[i-1]=='s' && source[i]=='h')
			{
				for(k=0;k<strlen(copy);k++)
				{
					copy[k]='\0';
				}
				strcpy(copy,&source[i+1]);				
				strcpy(&source[i+1],"es");
				strcat(source,copy); 
				i +=3;
			}
			else if(source[i]=='s')
			{
				for(k=0;k<strlen(copy);k++)
				{
					copy[k]='\0';
				}
				strcpy(copy,&source[i+1]);
				strcpy(&source[i+1],"es");
				strcat(source,copy); 
				i +=3;
			}
			else if(source[i]!='y' && source[i]!='s' &&	(source[i-1]!='c' && source[i]!='h') 
					&& (source[i-1]!='s' && source[i]!='h')); 
			{
				for(k=0;k<strlen(copy);k++)
				{
					copy[k]='\0';
				}
				strcpy(copy,&source[i+1]);
				strcpy(&source[i+1],"s");
				strcat(source,copy); 
				i +=1;
			}
		}				
	}
	printf("String after make to plural: %s\n",source);
	return 0;
}
/*################################################################*/
/*                  End of HW05_101044044_PART2.c                 */
/*################################################################*/
