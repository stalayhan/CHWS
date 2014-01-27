#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100
#define NOT_FOUND -1

char *delete(char *source, int index, int n); 
char *do_edit(char *source, char command);   
char  get_command(void);
char *insert(char *source, const char *to_insert, int index);
int   pos(const char *source, const char *to_find);
char* findAndReplace(char* source, const char* toFind, const char* toReplace);

int
main()
{
	char source[MAX_LEN], command;
	
	printf("Enter the source string:\n> ");  
	gets(source);                                  /* Stringi alıyoruz. */
	
	for(command = get_command();
		command != 'Q';
		command = get_command())
	{
		do_edit(source, command);
		printf("New source: %s\n\n",source);
	}
	
	printf("String after editing: %s\n",source);
	
	return 0;
}

char*
delete(char *source,	/* Input/output - string from which to delete part */
	   int index,		/* Input - index of first char to delete */
	   int n)			/* Input - number of chars to delete */
{
	char rest_str[MAX_LEN];	/* Copy of source substring following 
											characters to delete */
	
	/* If there are no characters in source following portion to
	   delete, delete rest of string */
	if(strlen(source) <= index + n)
	{
		source[index] = '\0';
	}
	
	/* Otherwise, copy the portion following the portion to delete
	   and place it in source beginning at the index position */
	else
	{
		strcpy(rest_str, &source[index + n]);
		strcpy(&source[index], rest_str);
	}
	
	return (source);
}

/*
 * Performs the edit operation specified by command
 * Pre:  Command and source are defined.
 * Post: After scanning additional information needed, performs a
 *		 deletion (command = 'D') or insertion (command = 'I') or
 *		 finds a substring ('F') and displays result; returns
 *		 (possibly modified) source.
 */
 char*
 do_edit(char *source,	/* Input/output - string to modify or search */
		 char command)	/* Input - character indicating operation */
{
	char str[MAX_LEN], find[MAX_LEN],replace[MAX_LEN];	/* Work string */
	int index,indexReplace;
	
	switch(command)
	{
		case 'D':
			printf("String to delete> ");
			gets(str);
			index = pos(source, str);
			
			if(index == NOT_FOUND)
			{
				printf("'%s' not found\n",str);
			}
			else
			{
				delete(source, index, strlen(str));
			}
			break;
			
		case 'I':
			printf("String to insert> ");
			gets(str);
			printf("Position of insertion> ");
			scanf("%d", &index);
			
			insert(source, str, index);
			break;
		
		case 'F':
			printf("String to find> ");
			gets(str);
			index = pos(source, str);
			
			if(index == NOT_FOUND)
			{
				printf("'%s' not found\n",str);
			}
			
			else
			{
				printf("'%s' found at position %d\n", str, index);
			}
			break;
			
		case 'R':
			printf("String to find> ");
			gets(find); /* Aranıcak kelimeyi aldık */
			
			printf("String to replace> ");
			gets(replace); /* Yerine konulacak  */
			
			findAndReplace(source, 
			   			   find, 
					   	   replace);
			
			break;
		
			
		default:
			printf("Invalid edit command '%c'\n",command);
			
	}
	
	return (source);
}

/* 
 * Prompt for and get a character representing an edit command and 
 * convert it to uppercase. Returns the uppercase character and ignore 
 * rest of input line.
 */
char
get_command(void)
{
	char command, ignore;
	
	printf("Enter D(delete), I(insert), F(find), R(Replace) or Q(quit)> ");
	scanf(" %c", &command);
	
	do
	{
		ignore = getchar();
	}while(ignore != '\n');
	
	return (toupper(command));
}

char*
insert(char 	  *source,		/* Input/output - target of insertion */
	   const char *to_insert,	/* Input - string to insert */
	   int 		   index)		/* Input - position where to_insert 
								   is to be inserted */
{
	char rest_str[MAX_LEN];		/* Copy of rest of source beginning 
								   with source[index] */
	
	if( strlen(source) <= index )
	{
		strcat(source, to_insert);
	}
	
	else
	{
		strcpy(rest_str, &source[index]);
		strcpy(&source[index], to_insert);
		strcat(source, rest_str);
	}
	
	return (source);
}

int
pos(const char *source,		/* Input - string in which to look for to_find */
	const char *to_find)	/* Input - string to find */
{
	int i = 0, find_len, found = 0, position;
	char substring[MAX_LEN];
	
	find_len = strlen(to_find);
	
	while(!found && i <= strlen(source) - find_len)
	{
		strncpy(substring, &source[i], find_len);
		substring[find_len] = '\0';
		
		if(strcmp(substring, to_find) == 0)
		{
			found = 1;
		}
		
		else
		{
			++i;
		}
	}
	
	if(found)
	{
		position = i;
	}
	
	else
	{
		position = NOT_FOUND;
	}
	
	return (position);
}
char* 
findAndReplace(char* source, 
			   const char* toFind, 
			   const char* toReplace)
{
	char str[MAX_LEN], find[MAX_LEN],replace[MAX_LEN];	/* Work string */
	int index,indexReplace;
	
	
	do
	{
	index = pos(source, toFind);
			printf("index = %d\n",index);
			if(index == NOT_FOUND)
			{
				printf("'%s' not found\n",toFind);
			}
			else
			{
				delete(source, index, strlen(toFind));
				insert(source, toReplace, index);
			}
			

			
			
	}while(index != NOT_FOUND);
	
	return (source);
}
