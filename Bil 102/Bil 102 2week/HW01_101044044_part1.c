/*################################################################*/
/* HW01_101044044_PART_1.c                                        */
/* ----------------------                                         */
/* Created on 07.03.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* This implementation evaluates the below function for some user */
/* supplied z and n=1,2, ..10.                                    */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/


/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int main(void)
{
	int z;
	double n,
	       result;

	/* Take the Z value from user. */
	printf("Enter one number except one: \n");
	scanf("%d",&z);

	/* Compute for the value of z=1 */
	n = 1;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,1) is %1.3f\n", z, result);

	/* Compute for the value of z=2 */
	n = 2;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,2) is %1.3f\n", z, result);	

	/* Compute for the value of z=3 */
	n = 3;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,3) is %1.3f\n", z, result);

	/* Compute for the value of z=4 */
	n = 4;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,4) is %1.3f\n", z, result);
	
	/* Compute for the value of z=5 */
	n = 5;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,5) is %1.3f\n", z, result);

	/* Compute for the value of z=6 */
	n = 6;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,6) is %1.3f\n", z, result);

	/* Compute for the value of z=7 */
	n = 7;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,7) is %1.3f\n", z, result);

	/* Compute for the value of z=8 */
	n = 8;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,8) is %1.3f\n", z, result);

	/* Compute for the value of z=9 */
	n = 9;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,9) is %1.3f\n", z, result);
	
	/* Compute for the value of z=10 */
	n = 10;
	result = ((z*(1-(n+1)*pow(z,n)+n*pow(z,n+1))/pow(1-z,2))+exp(-z*n));
	result = sqrt(result);
	printf("The result of F(%d,10) is %1.3f\n", z, result);

	return 0;
}
/*################################################################*/
/*                  End of HW01_101044044_part1.c                 */
/*################################################################*/
