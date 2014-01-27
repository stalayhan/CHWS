/*################################################################*/
/* HW01_Samet_Sait_Talayhan_101044044_part2.c                     */
/* ----------------------                                         */
/* Created on March 1, 2013, 9:49 PM by Samet Sait Talayhan.      */ 
/*                                                                */
/* Description                                                    */
/* ----------------------                                         */
/* This program calculates the salaries of 5 employees  according */
/* to particular formulation. Program read the parameters 
/* "workingYears",
/* "numberOfProjects",
/* "performancePoint",
/* "departmentMultiplier" from the text files prepared for each   *
/* employee specific name(employee1.txt, employee2.txt vs..).     */
/*                                                                */
/* And Program take "Overtime Working Hours" from the console.    */
/* The results print the file "salaries.txt".                     */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/
/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <math.h>

/*################################################################*/
/*                           Defines                              */
/*################################################################*/
#define WORKING_HOURS 184	
#define BHP 6	/* Base Hourly Payment */ 
#define ADDITIONAL_PAY_MULT 1.5
#define LOPM 0.8 /* Linear Overtime Payment Multiplier */
#define QOPM 0.15 /* Quadratic Overtime Payment Multiplier */
#define WDOM 2	/* Weekday Overtime Multiplier */
#define WEOM 3	/* Weekend Overtime Multiplier */

/*----------------------------------------------------------------*/
/*                    Function Prototypes                         */
/*----------------------------------------------------------------*/
int getWeekDayOvertime(int employeeNo);
int getWeekendOvertime(int employeeNo);
double obtainDataAndCalculateSalary(FILE *employeeFile, int employeeNo);
double calculateSalary(int workingYear, int numOfProjects,
                         int performancePoint, double departmentMultiplier,
                         int weekdayOvertime, int weekendOvertime);
double getSalaryPerHour(int workingYear, int numberOfFinishedProjects,
                          int performancePoint, double departmentMultiplier);
double getOverTimePayment(int weekdayOvertime, int weekendOvertime,
                          double salaryPerHour);
void writeSalaryToFile(FILE *outFile, int employeeNo, double salary);

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/
int
main(void) 
{
    double salary = 0,      /* The total salary of the employee. */
           normalPayment = 0, overtimePayment = 0,
           salaryPerHour = 0,
           experiencePoint = 0,
           opb = 0; /* Overtime Payment Base */
    int    workingYears = 0,   /* Below variables get from the text file. */
           performancePoint = 0,    
           departmentMultiplier = 0,
           numberOfFinishedProjects = 0,
           weo = 0, /* Weekend Overtime gets from the user via console */
           wdo = 0; /* Weekday Overtime gets from the user via console */
    FILE *inFileForEmployee1,       /* Pointer to input file */
         *inFileForEmployee2,
         *inFileForEmployee3,
         *inFileForEmployee4,
         *inFileForEmployee5,
         *outFile;                  /* Pointer to output file */
    
    /* Open the input and output files. */
    inFileForEmployee1 = fopen("employee1.txt","r");
    inFileForEmployee2 = fopen("employee2.txt","r");
    inFileForEmployee3 = fopen("employee3.txt","r");
    inFileForEmployee4 = fopen("employee4.txt","r");
    inFileForEmployee5 = fopen("employee5.txt","r");
    outFile = fopen("salaries.txt","w");
    
    writeSalaryToFile(inFileForEmployee1,1,
            obtainDataAndCalculateSalary(inFileForEmployee1,1));
    writeSalaryToFile(inFileForEmployee2,2,
            obtainDataAndCalculateSalary(inFileForEmployee2,2));
    writeSalaryToFile(inFileForEmployee3,3,
            obtainDataAndCalculateSalary(inFileForEmployee3,3));
    writeSalaryToFile(inFileForEmployee4,4,
            obtainDataAndCalculateSalary(inFileForEmployee4,4));
    writeSalaryToFile(inFileForEmployee5,5,
            obtainDataAndCalculateSalary(inFileForEmployee5,5));
    
    
    fclose(inFileForEmployee1);
    fclose(inFileForEmployee2);
    fclose(inFileForEmployee3);
    fclose(inFileForEmployee4);
    fclose(inFileForEmployee5);
    fclose(outFile);
    
    return 0;
}
/*################################################################*/
/*                  End of HW01_101044044.c                       */
/*################################################################*/
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* getWeekDayOvertime Function                                    */
/* -------------------                                            */
/* int employeeNo - Input Parameter //Get Employee Number         */                     
/* This function returns  total weekday overtime of the employee  */
/*----------------------------------------------------------------*/
int getWeekDayOvertime(int employeeNo)
{
    int wdo; /* gets Weekday Overtime from the user via console */
    
    /* Gets from the user Overtime Working Hours */
    printf("Enter the Overtime Working Hour of Weekday for Employee%d:",
            employeeNo);
    scanf("%d",&wdo);
    
    return wdo;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* getWeekendOvertime Function                                    */
/* -------------------                                            */
/* int employeeNo - Input Parameter //Get Employee Number         */                     
/* This function returns  total weekend overtime of the employee  */
/*----------------------------------------------------------------*/
int getWeekendOvertime(int employeeNo)
{
    int weo; /* gets Weekend Overtime from the user via console */
    
    /* Gets from the user Overtime Working Hours */
    printf("Enter the Overtime Working Hour of Weekend for Employee%d:",
            employeeNo);
    scanf("%d",&weo);
    
    return weo;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* getSalaryPerHour Function                                      */
/* -------------------                                            */
/* Input Parameter                                                */
/* -------------------                                            */
/* int workingYear,
   int numberOfFinishedProjects,
   int performancePoint,
   double departmentMultiplier                                    */
/* -------------------                                            */
/* Outputs:                                                       */
/* -------------------                                            */                     
/* This function returns  salary per hour.                        */
/*----------------------------------------------------------------*/
double getSalaryPerHour(int workingYear, int numberOfFinishedProjects,
                          int performancePoint, double departmentMultiplier)
{
    int experiencePoint = log2(workingYear * numberOfFinishedProjects);
    
    return ( BHP + ADDITIONAL_PAY_MULT * departmentMultiplier *
            (experiencePoint + performancePoint));
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* getOverTimePayment Function                                    */
/* -------------------                                            */
/* int weekdayOvertime,
   int weekendOvertime,
   double salaryPerHour,                  
/* This function returns  over time payment value.                */
/*----------------------------------------------------------------*/
double getOverTimePayment(int weekdayOvertime, int weekendOvertime,
                          double salaryPerHour)
{
    double opb = WEOM * getWeekendOvertime() + WDOM * getWeekDayOvertime();
    
    return  ((QOPM * (opb * opb) + LOPM * opb) * salaryPerHour);
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* calculateSalary Function                                       */
/* This function calculate employee salary.
/* -------------------                                            */
/* Input Parameter                                                */
/* -------------------                                            */
/* int workingYear,
   int numOfProjects,
   int performancePoint,
   double departmentMultiplier,
   int weekdayOvertime,
   int weekendOvertime
   This function returns employee salary.
        
/*----------------------------------------------------------------*/
double calculateSalary(int workingYear, int numOfProjects,
                         int performancePoint, double departmentMultiplier,
                         int weekdayOvertime, int weekendOvertime)
{
    return (getSalaryPerHour(workingYear,numOfProjects,
                    performancePoint,departmentMultiplier) * WORKING_HOURS);
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* obtainDataAndCalculateSalary Function                          */
/* This function obtain and calculate employee salary.
/* -------------------                                            */
/* Input Parameter                                                */
/* -------------------                                            */
/* FILE *outFile, // Input and Output parameters, used pointer
/* int employeeNo
/* This function returns employee total salary.                   */       
/*----------------------------------------------------------------*/
double obtainDataAndCalculateSalary(FILE *employeeFile, int employeeNo)
{
    int workingYears = 0,   /* Below variables get from the text file. */
        performancePoint = 0,    
        departmentMultiplier = 0,
        numberOfFinishedProjects = 0;
    double normalPayment = 0,
           overtimePayment = 0,
           salaryPerHour = 0,
           opb = 0;   
    
    fscanf(employeeFile,"%d",&workingYears);
    fscanf(employeeFile,"%d",&numberOfFinishedProjects);
    fscanf(employeeFile,"%d",&performancePoint);
    fscanf(employeeFile,"%d",&departmentMultiplier);
    
    opb = WEOM * getWeekendOvertime(employeeNo) +
          WDOM * getWeekDayOvertime(employeeNo);
    salaryPerHour = getSalaryPerHour(workingYears,numberOfFinishedProjects,
                        performancePoint,departmentMultiplier);
    normalPayment = salaryPerHour * WORKING_HOURS;
    overtimePayment = (QOPM * (opb * opb) + LOPM * opb) * salaryPerHour;
    
    return normalPayment + overtimePayment;
}
/*----------------------------------------------------------------*/
/*               Function Implementations                         */
/*----------------------------------------------------------------*/
/* writeSalaryToFile Function                                     */
/* This function write employee salary to file.
/* -------------------                                            */
/* Input Parameter                                                */
/* -------------------                                            */
/* FILE *outFile, // Input and Output parameters, used pointer
/* int employeeNo,
/* double salary,        
/*----------------------------------------------------------------*/
void writeSalaryToFile(FILE *outFile, int employeeNo, double salary)
{ 
     /* Print the salary of Employee1 "to salaries.txt" */
    fprintf(outFile,"|---------------------------------------|\n");
    fprintf(outFile,"| Salary of the Employee%d :$%.2f    |\n",
                                                employeeNo,salary);
    fprintf(outFile,"|---------------------------------------|\n");
    
}
