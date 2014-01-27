
/* Size of array */
#define SIZE 50

typedef struct {
		int id;
		char name[SIZE];
		double price;
} item;

void getItems( item itemArray[],int size );
void printItems(const item itemArray[],int size );

