/* 
* Verilen Celsius değerini, Fahrenheit'e çevirir.
*                       Coded by Talayhan.
*
*/

/*************/
/* Includes  */
/*************/

#include <stdio.h>

#define SABIT 1.8
#define SABIT2 32

int main(void)
{
	double celsius; /*girilen celsius değerini tutar*/
	double fahrenheit; /* girilen fahrenheit değerini tutar */

	FILE * inputFile, * outputFile; /* Dosyalar */

	inputFile = fopen("in.txt", "r");
	outputFile = fopen("out.txt", "w");

	fscanf(inputFile, "%lf" , &celsius);
	fscanf(inputFile, "%lf" , &fahrenheit);

	/*in.text deki değerin fahrenheit karşılığını verir.*/
	fahrenheit = (celsius*SABIT) + SABIT2;
	

	fprintf(outputFile, "%f fahrenheit = %f celsius\n", fahrenheit ,celsius);


	/* Dosyaları kapama */
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}

