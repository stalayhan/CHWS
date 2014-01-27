
/*A Sample Solution for the final Examination*/
/*This code is not preapared in examination format*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define RECORD_COUNT 20
#define NAME_LENGTH 20
#define NAME_INDEX 7
#define SEARCH_LETTER 'e'
#define LIMIT_LETTER 'm'

/*Uncomment the line below to activate DEBUG mode*/
/*#define DEBUG*/

typedef struct{
	int number;
	char name[NAME_LENGTH];
	float grade;
}Student;

typedef struct node_s{
	Student stu;
	struct node_s* next;
}node_t;


void print(int num);
int myAtoi(char * str);
node_t* buildList(FILE* file);
int checkOrdering(node_t* list);
void freeList(node_t* list);
void printStudent(FILE* stream, Student* stu);
void createBinaryFile(FILE* file, char names[][NAME_LENGTH], int size);
int displayContent(FILE* file);
int binToText(FILE* binFile, FILE* textFile);
int numOfOcc(char *str, char key, char limit);


int main(int argc, char* argv[])
{
	/*Names to be used to create Student objects of the binary file*/
	char names[RECORD_COUNT][NAME_LENGTH]={"ali", "fatma", "can", "canan", "veli", "halim", "halime", "egemen", "cumhur", 
		"alp", "erdogan", "ulas", "evren", "hakan", "alper", "arzu", "fatih", "meltem", "salih", "umut"};
	FILE* binFile, * textFile; 
	node_t* list; /*Linked list*/
	int numOfRec; /*number of records*/
	int i;
	

#ifdef DEBUG
	printf("DebugMode: Value of argc is %d\n", argc);
	printf("DebugMode: Contetnt of argv is:");
	for(i=0; i<argc; ++i)
		printf(" %s", argv[i]);
	printf("\n\n");
#endif

	/*Part 1*/
	print(15);
	print(15978);

	/*Part 2*/
	printf("The integer myAtoi function produces for the string \"5789\" is %d\n", myAtoi("5789"));

	/*Part 3*/
	printf("The letter '%c' exists %d times in the word \"%s\" searching until a letter '%c' is met.\n", 
		SEARCH_LETTER, numOfOcc(names[NAME_INDEX], SEARCH_LETTER, LIMIT_LETTER), names[NAME_INDEX], LIMIT_LETTER);

	/*Preapering the binary file and monitoring its contetnt*/
	binFile=fopen(argv[1], "wb");
	createBinaryFile(binFile, names, RECORD_COUNT);
	fclose(binFile); /*File is ready to use*/

	/*reopen the binary file for reading this time*/
	binFile=fopen(argv[1], "rb");
	/*Display the records in the file*/
	numOfRec=displayContent(binFile);

#ifdef DEBUG
	printf("\nDebugMode: Number of records returned by displayContent: %d\n\n", numOfRec);
#endif

	/*Part 4*/
	/*Make the file pointer points the first record, it currrently shows EOF, because of the displayContent*/
	/*Alternatively you can close and reopen the file*/
	rewind(binFile);
	textFile=fopen(argv[2], "w"); /*Opens the text file*/
	numOfRec=binToText(binFile, textFile);
	fclose(textFile); /*Closes the text file*/
	printf("Number of Records: %d \n", numOfRec);
	
	/*Part 5*/
	/*Make the file pointer points the first record*/
	rewind(binFile);
#ifdef DEBUG
		printf("\nDebugMode:\t");
#endif
	list=buildList(binFile);
#ifdef DEBUG
		printf("\n");
#endif
	printf("Number of increasing successive elements: %d\n", checkOrdering(list));

	freeList(list);
	fclose(binFile);
	return 0;
}

/*Prints a number*/
void print(int num)
{
	printf("%04d\n", num);
}

/*Takes a string and returns the integer represented by the string*/
int myAtoi(char * str)
{
	int i, num=0, count=0, digitMult=1;
	while(str[count]!='\0')
		count++;
	count--;
	for(i=count; i>=0; --i)
	{
		num+=((int)str[i]-'0')*digitMult;
		digitMult*=10;
	}
	return num;
}

/*Returns the number of occurances of a character in a given string searching until a limit character is met*/
int numOfOcc(char *str, char key, char limit)
{
	/*Base Case: return zero if the end of the string is reached*/
	if((str[0]=='\0') || (*str==limit))/*Note that str[0] and *str are equivalent*/
		return 0;

	if(*str==key)
		/*if key caracter is met increase and return the return value of the inner func*/
		return numOfOcc(str+1, key, limit) + 1;
	return(numOfOcc(str+1, key, limit));/*otherwise return what the inner func returns*/
}

/*Builds and returns a linkedlist of Student objects from some Student records hosted by a binary file*/
node_t* buildList(FILE* file)
{
	node_t* node=(node_t*)malloc(sizeof(node_t));
	Student stu;
	int count=0;

	
	fread(&node->stu, sizeof(Student), 1, file);

	if(feof(file)){
		free(node);
		return NULL;
	}

#ifdef DEBUG
	printf("<bList>stu with num %d is added ", node->stu.number);
#endif

	node->next=buildList(file);
	return node;
}

/*Returns the number of the ordered successive elements in the given linkedlist*/
int checkOrdering(node_t* list)
{
	if(list->next==NULL)
		return 0;
	if(list->next->stu.grade>list->stu.grade){
#ifdef DEBUG
		printf("DebugMode <insight checkOrdering> increasing sequence detected stu no: %d\n", list->stu.number);
#endif
		return 1+checkOrdering(list->next);
	}
	else
		return checkOrdering(list->next);
}

/*Returns the dynamically allocated memory for the linkedlist*/
void freeList(node_t* list)
{
	/*if this is not the last element - this is not the base case*/
	if(list->next!=NULL)
		freeList(list->next);

#ifdef DEBUG
	printf("DebugMode Node with student number %d is freed\n", list->stu.number);
#endif
	free(list);

	return;
}

/*Prints a Student object in a given stream*/
void printStudent(FILE* stream, Student* stu){
	fprintf(stream, "%4d %25s %8.2f \n", stu->number, stu->name, stu->grade);
}

/*Creates a binary file that store some Student objects
  Students objects to be stored are also created by using the input names
  sequentially generated numbers and randomly generated grades.
  This function is used to generate the binary file provided to you during the exam*/
void 
createBinaryFile(FILE* file, /*pointer of the binary file to be created*/
		char names[][NAME_LENGTH], /*names for the Student objects*/
		int size) /*size of the names array, also number of records in the file*/
{
	int i;
	float grade;
	Student tempStudent;

	/* initialize random seed: */
	srand ( time(NULL) );
	for(i=0; i<size; ++i){
		/*Create a Student Object*/
		tempStudent.number=i+1;
		strcpy(tempStudent.name, names[i]);
		tempStudent.grade=(double)(rand()%10000)/100.0;
		/*Write the student object into the file*/
		fwrite(&tempStudent, sizeof(Student), 1, file);
	}
}

/*Displays all the Student objects in the given binary file*/
/*Returns number of objects, the file hosts*/
int displayContent(FILE* file)
{
	Student stu;
	int status;
	int count=0; /*will hold the number of records*/

	printf("\nContent of the file:\n");
	status=fread(&stu, sizeof(Student), 1, file);
	count+=status;
	while(status>0)
	{
		printStudent(stdout, &stu);
		/*Returns 1 after a succesful read 
				  0 in the case of EOF
		Note the difference from fprintf */
		status=fread(&stu, sizeof(Student), 1, file);
		count+=status;
	}
	return count;
}

/*Reads all the Student objects in a given binary file and writes them to a given text file*/
/*Returns the number of records*/
int binToText(FILE* binFile, FILE* textFile)
{
	Student stu;
	int status, count=0;
	
	count+=fread(&stu, sizeof(Student), 1, binFile);

	while(!feof(binFile)){
		printStudent(textFile, &stu);
		count+=fread(&stu, sizeof(Student), 1, binFile);
	}

	return count;
}

