/* ************************************************************************* */
/*                               INCLUDES                                    */
/* ************************************************************************* */
#include <stdio.h>

/* ************************************************************************* */
/*                               DEFINITIONS                                 */
/* ************************************************************************* */
int printChars(char chr, int num);
int printSpecialFigures(char chr, char choice, int height);

/* ************************************************************************* */
/*                         FUNCTION PROTOTYPES                               */
/* ************************************************************************* */
void printLine(char chr, int num)
{
	int counter=0, totalChars=0, charCount=0;

	for(counter = 0; counter < num; counter += 1)
    {
        charCount = printf("%c ", chr);
        totalChars += charCount;
    }
}

int main(void)
{
    char choice, chr='s';
    int num=0, count=0, height=0, isTrue=1;
    
    
    while(isTrue)
    {
        printf("Select one of choices below\n");
        printf("[1]Upper Triangle\n[2]Lower Triangle\n[3]Diamond\n");
		printf("[4]BonusPart1\n[5]BonusPart2\n[6]BonusPart3\n[0]Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice)
        {
            case '0':
                isTrue = 0;
                printf("Program is shutting down...\n");
                return 0;
                break;
            
            case '1': /* Option for Upper Triangle */
                printf("Enter value of height: ");
                scanf("%d", &height);
                printSpecialFigures(chr, choice, height);
                break;
            
            case '2': /* Option for Lower Triangle */
                printf("Enter value of height: ");
                scanf("%d", &height);
                printSpecialFigures(chr, choice, height);
                break;
            
            case '3': /* Option for Diamond */
                printf("Enter value of height: ");
                scanf("%d", &height);
                printSpecialFigures(chr, choice, height);
                break;
			case '4': /* Bonus Part 1 */
				printf("Enter value of height: ");
                scanf("%d", &height);
                printSpecialFigures(chr, choice, height);
				break;
			case '5': /* Bonus Part 2 */
				printf("Enter value of height: ");
                scanf("%d", &height);
                printSpecialFigures(chr, choice, height);
				break;
			case '6': /* Bonus Part 3 */
				printf("Enter value of height: ");
                scanf("%d", &height);
                printSpecialFigures(chr, choice, height);
				break;
            
            default:
                printf("There is no option like %c", choice);
                break;
        }
    }
    
        /*printf("Enter number of repetetion: ");
        scanf("%d", &num);
    
        count = printChars(chr, num);
        printf("%d chars succesfuly printed\n", count);*/
     
    return 0;
}

/* ************************************************************************* */
/*                          FUNCTION DEFINITIONS                             */
/* ************************************************************************* */
int printChars(char chr, int num) /* Prints given char by wanted number per line */
{
    int counter=0, totalChars=0, charCount=0;
    
    
    if(num < 0)
    {
        printf("This input is illegal\n");
        printf("Your can't print %c for %d times \n", chr, num);
        printf("Error code -1");
        return -1;
    }
    else if(num == 0)
    {
        printf("You can't print something for zero times \n");
        printf("Error code -2");
        return -2;
        
    }
    else
    {
        for(counter = 0; counter < num; counter += 1)
        {
            charCount = printf("%c ", chr);
            totalChars += charCount;
        };
        printf("\n");
    };
    
    return totalChars;
}


int printSpecialFigures(char chr, char choice, int height)
{
    int counter=0, line=0, buffer=0;
	char chE = ' ';
    
    
    
    switch (choice)
    {
    case '1':
        for(counter = 0; counter < height; counter += 1)
        {
            line += 1;
            buffer = printChars(chr, line);
        };
        return 1; /* job succesfuly done */
        break;
    
    case '2':
        line = height;
        for(counter = height; counter >= 1; counter -= 1)
        {
            buffer = printChars(chr, line);
            line -= 1;
        };
        return 1; /* job succesfuly done */
        break;
    
    case '3':
        printf("NOTE: Even numbers act like odd numbers while printing diamond\n");
        height /= 2;
         for(counter = 0; counter < height+1; counter += 1)
        {
            line += 1;
            buffer = printChars(chr, line);
        };
        line = height;
        for(counter = height; counter >= 1; counter -= 1)
        {
            buffer = printChars(chr, line);
            line -= 1;
        };
        return 1; /* job succesfuly done */
        break;
	case '4':
		for(counter = 1; counter<=height;counter++)
		{
			printLine(chE,(height-counter));
			printLine(chr,((2*counter)-1));
			printLine(chE,(height-counter));
			printf("\n");
		}
		break;
	case '5':
		for(counter = height; counter>1;counter--)
		{
			printLine(chE,(height-counter));
			printLine(chr,((2*counter)-1));
			printLine(chE,(height-counter));
			printf("\n");
		}
		break;
	case '6':
		printf("NOTE: Even numbers act like odd numbers while printing diamond\n");
        height /= 2;
		for(counter = 1; counter<=height-1;counter++)
		{
			printLine(chE,(height-counter));
			printLine(chr,((2*counter)-1));
			printLine(chE,(height-counter));
			printf("\n");
		}
		for(counter = height; counter>0;counter--)
		{
			printLine(chE,(height-counter));
			printLine(chr,((2*counter)-1));
			printLine(chE,(height-counter));
			printf("\n");
		}
		break;
    default:
        printf("There is no option like %c \n", choice);
        break;
    }
}

/* ************************************************************************* */
/*                         END OF [PROJECT NAME].c                           */
/* ************************************************************************* */
