/*###############################################################*/
/*                                                               */
/*                                                               */
/*                    HW1 Sample Solution                        */
/*                          Part2                                */
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

/*Prototypes        */
int getWeekdayOvertime(int employeeNo);
int getWeekendOvertime(int employeeNo);
double obtainDataAndCalculateSalary(FILE *employeeFile, int employeeNo);
double calculateSalary(int workingYear,int numOfProjects,int performancePoint,double departmentMultiplier,int weekdayOvertime,int weekendOvertime);
double getSalaryPerHour(int workingYear,int numOfProjects,int performancePoint,double departmentMultiplier);
double getOvertimePayment(int weekdayOvertime,int weekendOvertime,double salaryPerHour);
void writeSalaryToFile(FILE *outFile,int employeeNo,double salary);


int main(void)
{
	/**Section 1 : Declaring File pointers */
    FILE *inp;  /*Input file pointer  */
    FILE *outp; /*Output file pointer */
    /**End of Section 1                    */

	/**Section 2 : Declaring Variables */
	double salary;
	/**End of Section 2                */

    outp=fopen("salaries.txt","w+"); /**Setting our pointer to salaries.txt file*/

	inp=fopen("employee1.txt","r");
	salary=obtainDataAndCalculateSalary(inp,1);
	writeSalaryToFile(outp,1,salary);
	fclose(inp);

	inp=fopen("employee2.txt","r");
	salary=obtainDataAndCalculateSalary(inp,2);
	writeSalaryToFile(outp,2,salary);
	fclose(inp);

	inp=fopen("employee3.txt","r");
	salary=obtainDataAndCalculateSalary(inp,3);
	writeSalaryToFile(outp,3,salary);
	fclose(inp);

	inp=fopen("employee4.txt","r");
	salary=obtainDataAndCalculateSalary(inp,4);
	writeSalaryToFile(outp,1,salary);
	fclose(inp);

	inp=fopen("employee5.txt","r");
	salary=obtainDataAndCalculateSalary(inp,5);
	writeSalaryToFile(outp,1,salary);
	fclose(inp);
	fclose(outp);
	
	return 0;
}

double obtainDataAndCalculateSalary(FILE *employeeFile, int employeeNo)
{
	/*Declaring Variables */
	int wY,  /*WorkingYears  */
		noP, /*NumberofProjects */
		pP,  /*PerformancePoint */
		wdo, /*WeekdaysOvertime */
		weo; /*WeekendsOvertime */
	double dM,  /*DepartmentMultiplier */
		salary; /*Salary of employee                                */

	/*Taking values from employee's file*/
	fscanf(employeeFile,"%d%d%d%lf",&wY,&noP,&pP,&dM);

	/*Taking values from the user*/
	wdo=getWeekdayOvertime(employeeNo);
	weo=getWeekendOvertime(employeeNo);

	salary=calculateSalary(wY,noP,pP,dM,wdo,weo);

	return salary;
}

int getWeekdayOvertime(int employeeNo)
{
	/*Declaring variable */
	int wdo; 

	/*Taking WeekdayOverTimeWorkingHour from user*/
	printf("Employee%d : Please enter Weekday-Overtime-Working-Hour and press return :> ",employeeNo);
	scanf("%d",&wdo);

	return wdo;
}

int getWeekendOvertime(int employeeNo)
{
	/*Declaring variable */
	int weo; 

	/*Taking WeekendOverTimeWorkingHour from user*/
	printf("Employee%d : Please enter Weekend-Overtime-Working-Hour and press return :> ",employeeNo);
	scanf("%d",&weo);

	return weo;
}

double calculateSalary(int workingYear,int numOfProjects,int performancePoint,double departmentMultiplier,int weekdayOvertime,int weekendOvertime)
{
	/*Declaring Variables */
	double salPerHour, 
		overPay, 
		normPay, 
		salary; 

	/*Mathematical Calculations */
	salPerHour=getSalaryPerHour(workingYear,numOfProjects,performancePoint,departmentMultiplier);
	overPay=getOvertimePayment(weekdayOvertime,weekendOvertime,salPerHour);
	normPay=salPerHour*WORKING_HOURS;
	salary=normPay+overPay;

	return salary;
}

double getSalaryPerHour(int workingYear,int numOfProjects,int performancePoint,double departmentMultiplier)
{
	/**Section 1 : Declaring Variables */
	double exPt, /*Total Experience Point of employee       */
		salPerHour; /*Earned Salary Per Hour                */
	/**End of Section 1                */

	/**Section 2 : Mathematical Calculations */
	exPt=log(workingYear*numOfProjects)/log(2);
	salPerHour=BHP+ADDITIONAL_PAY_MULT*departmentMultiplier*(exPt+performancePoint);
	/**End of Section 2*/

	return salPerHour;
}

double getOvertimePayment(int weekdayOvertime,int weekendOvertime,double salaryPerHour)
{
	/*Declaring Variables */
	double overPayBase,
		overPay;

	/*Mathematical Calculations */
	overPayBase=WEOM*weekendOvertime+WDOM*weekdayOvertime;
	overPay=(QOPM*pow(overPayBase,2)+LOPM*overPayBase)*salaryPerHour;

	return overPay;
}

void writeSalaryToFile(FILE *outFile,int employeeNo,double salary)
{
	/*Printing results to salaries.txt file */
	fprintf(outFile,"***************************************************************\n");
	fprintf(outFile,"*                         Employee%d                           *\n",employeeNo);
	fprintf(outFile,"*He/she takes %9.2f $ salary ,and sure he/she deserve it. *\n",salary);
	fprintf(outFile,"***************************************************************\n\n");
}
