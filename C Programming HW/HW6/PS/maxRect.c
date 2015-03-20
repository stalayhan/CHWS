#include <stdio.h>

#define COL_COUNT 8
#define ROW_CAP 10
#define REC_COL 3
#define REC_ROW 2

void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow);
double getSum(double table[][COL_COUNT], int leftUpY, int leftUpX, int rightDownY, int rightDownX);
double getSumConstRec(double table[][COL_COUNT], int leftUpX, int leftUpY);
double maxSumConstSizedRec(double table[][COL_COUNT], int nRow, int* leftUpY, int* leftUpX);
double maxSumConstPoint(double table[][COL_COUNT], int nRow, int leftUpY, int leftUpX, int* rightDownY, int* rightDownX);
double maxSumRec(double table[][COL_COUNT], int nRow, int* leftUpY, int* leftUpX, int* rightDownY, int* rightDownX);

int main(){
	double table[ROW_CAP][COL_COUNT];
	FILE* inFile;
	int nRow;
	double maxSum;
	int lUY, lUX, rDY, rDX;

	inFile=fopen("Table1.txt", "r");

	getArray(inFile, table, &nRow);

	maxSum=maxSumConstSizedRec(table, nRow, &lUY, &lUX);
	printf("MaxSum 3x2 sized Rectangular is %.2lf. Its left upper coordinate (y,x) is %d, %d\n", maxSum, lUY, lUX);

	maxSum=maxSumConstPoint(table, nRow, 0, 0, &rDY, &rDX);
	printf("MaxSum Rectangular starting from origin is %.2lf. Its right down coordinate (y,x) is %d, %d\n", maxSum, rDY, rDX);
	
	maxSum=maxSumRec(table, nRow, &lUY, &lUX, &rDY, &rDX);
	printf("MaxSum Rectangular is %.2lf. Its left upper coordinate (y,x) is %d, %d, right down coordinate is %d, %d\n", maxSum, lUY, lUX, rDY, rDX);

	fclose(inFile);
	return 0;
}

/*Reads the table from a file into a 2D array*/
void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow){
	int row=0;
	int col;
	int status=EOF+1;/*Different from EOF*/

	/*one more row will be read but the values will not be recorded into the table
	therefore, it is safe to use a table having just enough capasity to hold the data*/
	while(status!=EOF){
		for(col=0; col<COL_COUNT; col++)
			status=fscanf(inFile, "%lf", &table[row][col]);
		++row;
	}

	*nRow=row-1;/*one more row read*/
}

/*Returns the sum inside a given rectangular*/
double getSum(double table[][COL_COUNT], int leftUpY, int leftUpX, int rightDownY, int rightDownX){
	int row, col;
	double sum=0;

	for(row=leftUpY; row<=rightDownY; ++row)
		for(col=leftUpX; col<=rightDownX; ++col)
			sum+=table[row][col];

	return sum;
}

/*Returns the sum inside a given constant sized rectangular*/
double getSumConstRec(double table[][COL_COUNT], int leftUpY, int leftUpX){
	return getSum(table, leftUpY, leftUpX, leftUpY+REC_ROW-1, leftUpX+REC_COL-1);
}

/*Finds the constant sized rectangular having the max sum inside*/
double maxSumConstSizedRec(double table[][COL_COUNT], int nRow, int* leftUpY, int* leftUpX){
	int row, col;
	double temp;
	/*initialize the rectangular with the one starting from the origin point*/
	double sum=getSumConstRec(table, 0, 0); /*maxSum found so far*/
	*leftUpX = *leftUpY = 0;

	/*Try all fesible rectangulars*/
	for(row=0; row<nRow-REC_ROW+1; ++row){
		for(col=0; col<COL_COUNT-REC_COL+1; ++col){
			temp=getSumConstRec(table, row, col);
			if(temp>sum){
				/*a better rectangular is found, perform an update*/
				sum=temp;
				*leftUpY=row;
				*leftUpX=col;
			}
		}
	}

	return sum;
}

/*Finds the rectangular left uppper point of which is specified having the max sum inside*/
double maxSumConstPoint(double table[][COL_COUNT], int nRow, int leftUpY, int leftUpX, int* rightDownY, int* rightDownX){
	int rDX;	/*x coordinate of the right down corner of the rec*/
	int rDY;	/*y coordinate of the right down corner of the rec*/
	double temp;
	/*initialize the rectangular with the one including only one point*/
	double sum=table[leftUpX][leftUpY];
	*rightDownY=leftUpY;
	*rightDownX=leftUpX;

	/*Try all feasible rectangulars by changing the right down corner*/
	for(rDY=leftUpY; rDY<nRow; ++rDY){
		for(rDX=leftUpX; rDX<COL_COUNT; ++rDX){
			temp=getSum(table, leftUpY, leftUpX, rDY, rDX);
			if(temp>sum){
				/*a better rectangular is found, perform an update */
				sum=temp;
				*rightDownY=rDY;
				*rightDownX=rDX;
			}
		}
	}

	return sum;
}


double maxSumRec(double table[][COL_COUNT], int nRow, int* leftUpY, int* leftUpX, int* rightDownY, int* rightDownX){
	double temp;
	int lUY, lUX;	/*coordinates of the left upper corner*/
	int rDY, rDX;	/*coordinates of the right down corner*/
	/*initialize the rectangular with the one including only origin point*/
	double maxSum=table[0][0];
	*leftUpY = *leftUpX = *rightDownY = *rightDownX = 0;

	/*For all feasible starting points call maxSumConstPoint*/
	for(lUY=0; lUY<nRow; ++lUY){
		for(lUX=0; lUX<COL_COUNT; ++lUX){
			temp=maxSumConstPoint(table, nRow, lUY, lUX, &rDY, &rDX);
			if(temp>maxSum){
				/*a better rectangular found, perform an update*/
				maxSum=temp;
				*leftUpY=lUY;
				*leftUpX=lUX;
				*rightDownY=rDY;
				*rightDownX=rDX;
			}
		}
	}

	return maxSum;
}


