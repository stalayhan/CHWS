/*###############################################################*/
/*                                                               */
/*                                                               */
/*                    HW1 Sample Solution                        */
/*                          Part1                                */
/*                                                               */ 
/*			                                                     */
/*                                                               */  
/*				                            					 */
/*###############################################################*/

#include<stdio.h>
#include<math.h>

#define WORKING_HOURS 184
#define BHP 6
#define ADDITIONAL_PAY_MULT 1.5
#define LOPM 0.8
#define QOPM 0.15
#define WDOM 2
#define WEOM 3

int main(void)
{
	/*Declaring File pointers */
    FILE *inp;  
    FILE *outp; 

	/*Section 2 : Declaring Variables */
    int workingYears,
		numberOfProjects,
		performancePoint, 
		departmentMultiplier, 
		wdo,
		weo;
	double overPaymentmentBase, 
		experiencePoint, 
		salaryPerHour, 
		overPayment, 
		normalPayment, 
		salary;

	/*Setting pointer to salaries.txt file*/
    outp=fopen("salaries.txt","w+"); 

	/*Employee 1       */
	
	/*Setting pointer to employee1.txt file*/
	inp=fopen("employee1.txt","r");

	/*Taking values from employee's file*/
	fscanf(inp,"%d %d %d %d",&workingYears,&numberOfProjects,&performancePoint,&departmentMultiplier);

	/*Taking values from user*/
	printf("Employee%d : Please enter Weekday-Overtime-Working-Hour and press return :> ",1);
	scanf("%d",&wdo);
	printf("Employee%d : Please enter Weekend-Overtime-Working-Hour and press return :> ",1);
	scanf("%d",&weo);

	/*Mathematical Calculations */
	overPaymentmentBase=WEOM*weo+WDOM*wdo;
	experiencePoint=log(workingYears*numberOfProjects)/log(2);
	salaryPerHour=BHP+ADDITIONAL_PAY_MULT*departmentMultiplier*(experiencePoint+performancePoint);
	overPayment=(QOPM*pow(overPaymentmentBase,2)+LOPM*overPaymentmentBase)*salaryPerHour;
	normalPayment=salaryPerHour*WORKING_HOURS;
	salary=normalPayment+overPayment;                   */

	/*Printing results to salaries.txt file */
	fprintf(outp,"***************************************************************\n");
	fprintf(outp,"*                         Employee%d                           *\n",1);
	fprintf(outp,"*Working for %2d years with us                                 *\n",workingYears);
	fprintf(outp,"*%d projects done for us                                       *\n",numberOfProjects);
	fprintf(outp,"*Working %2d hours every weekday for us                        *\n",wdo);
	fprintf(outp,"*Working %2d hours every weekend for us                        *\n",weo);
	fprintf(outp,"*                                                             *\n");
	fprintf(outp,"*He/she takes %9.2f $ salary ,and sure he/she deserve it. *\n",salary);
	fprintf(outp,"***************************************************************\n\n");
	
	fclose(inp);
	
	/*Employee 2        */
	
	/*Setting pointer to employee1.txt file*/
	inp=fopen("employee2.txt","r");

	/*Taking values from employee's file*/
	fscanf(inp,"%d %d %d %d",&workingYears,&numberOfProjects,&performancePoint,&departmentMultiplier);

	/*Taking values from user*/
	printf("Employee%d : Please enter Weekday-Overtime-Working-Hour and press return :> ",2);
	scanf("%d",&wdo);
	printf("Employee%d : Please enter Weekend-Overtime-Working-Hour and press return :> ",2);
	scanf("%d",&weo);

	/*Mathematical Calculations */
	overPaymentmentBase=WEOM*weo+WDOM*wdo;
	experiencePoint=log(workingYears*numberOfProjects)/log(2);
	salaryPerHour=BHP+ADDITIONAL_PAY_MULT*departmentMultiplier*(experiencePoint+performancePoint);
	overPayment=(QOPM*pow(overPaymentmentBase,2)+LOPM*overPaymentmentBase)*salaryPerHour;
	normalPayment=salaryPerHour*WORKING_HOURS;
	salary=normalPayment+overPayment;                   */

	/*Printing results to salaries.txt file */
	fprintf(outp,"***************************************************************\n");
	fprintf(outp,"*                         Employee%d                           *\n",2);
	fprintf(outp,"*Working for %2d years with us                                 *\n",workingYears);
	fprintf(outp,"*%d projects done for us                                       *\n",numberOfProjects);
	fprintf(outp,"*Working %2d hours every weekday for us                        *\n",wdo);
	fprintf(outp,"*Working %2d hours every weekend for us                        *\n",weo);
	fprintf(outp,"*                                                             *\n");
	fprintf(outp,"*He/she takes %9.2f $ salary ,and sure he/she deserve it. *\n",salary);
	fprintf(outp,"***************************************************************\n\n");
	
	fclose(inp);
	
	/*Employee 3       */
	
	/*Setting pointer to employee1.txt file*/
	inp=fopen("employee3.txt","r");

	/*Taking values from employee's file*/
	fscanf(inp,"%d %d %d %d",&workingYears,&numberOfProjects,&performancePoint,&departmentMultiplier);

	/*Taking values from user*/
	printf("Employee%d : Please enter Weekday-Overtime-Working-Hour and press return :> ",3);
	scanf("%d",&wdo);
	printf("Employee%d : Please enter Weekend-Overtime-Working-Hour and press return :> ",3);
	scanf("%d",&weo);

	/*Mathematical Calculations */
	overPaymentmentBase=WEOM*weo+WDOM*wdo;
	experiencePoint=log(workingYears*numberOfProjects)/log(2);
	salaryPerHour=BHP+ADDITIONAL_PAY_MULT*departmentMultiplier*(experiencePoint+performancePoint);
	overPayment=(QOPM*pow(overPaymentmentBase,2)+LOPM*overPaymentmentBase)*salaryPerHour;
	normalPayment=salaryPerHour*WORKING_HOURS;
	salary=normalPayment+overPayment;                   */

	/*Printing results to salaries.txt file */
	fprintf(outp,"***************************************************************\n");
	fprintf(outp,"*                         Employee%d                           *\n",3);
	fprintf(outp,"*Working for %2d years with us                                 *\n",workingYears);
	fprintf(outp,"*%d projects done for us                                       *\n",numberOfProjects);
	fprintf(outp,"*Working %2d hours every weekday for us                        *\n",wdo);
	fprintf(outp,"*Working %2d hours every weekend for us                        *\n",weo);
	fprintf(outp,"*                                                             *\n");
	fprintf(outp,"*He/she takes %9.2f $ salary ,and sure he/she deserve it. *\n",salary);
	fprintf(outp,"***************************************************************\n\n");
	
	fclose(inp);
	
	/*Employee 4        */
	
	/*Setting pointer to employee1.txt file*/
	inp=fopen("employee4.txt","r");

	/*Taking values from employee's file*/
	fscanf(inp,"%d %d %d %d",&workingYears,&numberOfProjects,&performancePoint,&departmentMultiplier);

	/*Taking values from user*/
	printf("Employee%d : Please enter Weekday-Overtime-Working-Hour and press return :> ",4);
	scanf("%d",&wdo);
	printf("Employee%d : Please enter Weekend-Overtime-Working-Hour and press return :> ",4);
	scanf("%d",&weo);

	/*Mathematical Calculations */
	overPaymentmentBase=WEOM*weo+WDOM*wdo;
	experiencePoint=log(workingYears*numberOfProjects)/log(2);
	salaryPerHour=BHP+ADDITIONAL_PAY_MULT*departmentMultiplier*(experiencePoint+performancePoint);
	overPayment=(QOPM*pow(overPaymentmentBase,2)+LOPM*overPaymentmentBase)*salaryPerHour;
	normalPayment=salaryPerHour*WORKING_HOURS;
	salary=normalPayment+overPayment;                   */

	/*Printing results to salaries.txt file */
	fprintf(outp,"***************************************************************\n");
	fprintf(outp,"*                         Employee%d                           *\n",4);
	fprintf(outp,"*Working for %2d years with us                                 *\n",workingYears);
	fprintf(outp,"*%d projects done for us                                       *\n",numberOfProjects);
	fprintf(outp,"*Working %2d hours every weekday for us                        *\n",wdo);
	fprintf(outp,"*Working %2d hours every weekend for us                        *\n",weo);
	fprintf(outp,"*                                                             *\n");
	fprintf(outp,"*He/she takes %9.2f $ salary ,and sure he/she deserve it. *\n",salary);
	fprintf(outp,"***************************************************************\n\n");
	
	fclose(inp);
	
	
	/*Employee 5       */
	
	/*Setting pointer to employee1.txt file*/
	inp=fopen("employee5.txt","r");

	/*Taking values from employee's file*/
	fscanf(inp,"%d %d %d %d",&workingYears,&numberOfProjects,&performancePoint,&departmentMultiplier);

	/*Taking values from user*/
	printf("Employee%d : Please enter Weekday-Overtime-Working-Hour and press return :> ",5);
	scanf("%d",&wdo);
	printf("Employee%d : Please enter Weekend-Overtime-Working-Hour and press return :> ",5);
	scanf("%d",&weo);

	/*Mathematical Calculations */
	overPaymentmentBase=WEOM*weo+WDOM*wdo;
	experiencePoint=log(workingYears*numberOfProjects)/log(2);
	salaryPerHour=BHP+ADDITIONAL_PAY_MULT*departmentMultiplier*(experiencePoint+performancePoint);
	overPayment=(QOPM*pow(overPaymentmentBase,2)+LOPM*overPaymentmentBase)*salaryPerHour;
	normalPayment=salaryPerHour*WORKING_HOURS;
	salary=normalPayment+overPayment;                   */

	/*Printing results to salaries.txt file */
	fprintf(outp,"***************************************************************\n");
	fprintf(outp,"*                         Employee%d                           *\n",5);
	fprintf(outp,"*Working for %2d years with us                                 *\n",workingYears);
	fprintf(outp,"*%d projects done for us                                       *\n",numberOfProjects);
	fprintf(outp,"*Working %2d hours every weekday for us                        *\n",wdo);
	fprintf(outp,"*Working %2d hours every weekend for us                        *\n",weo);
	fprintf(outp,"*                                                             *\n");
	fprintf(outp,"*He/she takes %9.2f $ salary ,and sure he/she deserve it. *\n",salary);
	fprintf(outp,"***************************************************************\n\n");
	
	fclose(inp);
	fclose(outp);
	
}