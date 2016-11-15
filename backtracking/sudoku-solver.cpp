#include "bits/stdc++.h"
using namespace std;

/* useful utility macros */
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
#define printWholeArray(a) for(int(i)=0;(i)<int((sizeof(a)/sizeof(a[0])));i++) { cout<<(a[i])<<' ';}
#define repeat(n) for(int (i)=0;(i)<(int)(n);++(i)) //repeat n times
#define repeatBounds(l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i)) //repeat lower to upperbound
#define until(x,val) for(int(i) = int(x); int(x)!=int(val); (i<val)?x++:x--) //until x becomes val through increment or decrement

/*some constants*/
static const long double PI = 3.142857143;

/*some shorthands*/
typedef long long ll;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline

#define NOT_FILLED 0
#define gridSize 9

void printMatrix(int grid[gridSize][gridSize]) //to print the current matrix
{
	cout<<endl;
	for (int i = 0; i < gridSize; ++i)
	{
		cout<<setw(5)<<' ';
		for (int j = 0; j < gridSize; ++j)
		{
			if((j)%3==0)
				op '|'<<' ';
			cout<<grid[i][j]<<' ';
		}
		op "|";
		cout<<endl;
		op "     ";
		if((i+1)%3 == 0)
			op "-------------------------";
		nl
	}
}

bool isPlacabale(int grid[gridSize][gridSize], int row, int col, int val)
{
	for (int i = 0; i < gridSize; i++) //check if already in the current row
        if (grid[row][i] == val)
            return false; 
    for (int i = 0; i < gridSize; i++) //check if already in the current column
        if (grid[i][col] == val)
            return false;
    int row_start_index = row - row%3, col_start_index = col-col%3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i+row_start_index][j+col_start_index] == val)
                return false;
    return true;
}

bool findNextCell(int grid[gridSize][gridSize], pair<int,int> &coordinates)
{
	for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            if (grid[i][j] == NOT_FILLED)
            {
            	coordinates.first=i;
            	coordinates.second=j;
                return true;
            }
    return false;
}

bool solveGrid(int grid[gridSize][gridSize])
{
	pair<int,int> result;
	if(!findNextCell(grid,result)) //fully filled condition
		return true;
	else
	{
		for (int i = 1; i <= 9; ++i)
		{
			if(isPlacabale(grid,result.first,result.second,i))
			{
			//	op "trying "<<i<<" on position "<<result.first<<","<<result.second; nl
				grid[result.first][result.second]=i;
				if(solveGrid(grid)) //recursively solve the next position
					return true;
				else
					grid[result.first][result.second]=NOT_FILLED; //reset the fill. because it didn't work
			}
		}
	}
	return false;
}

int main()
{
	int grid[gridSize][gridSize] = 
					{	{0,2,0,6,0,8,0,0,0}, 
						{5,8,0,0,0,9,7,0,0},
						{0,0,0,0,4,0,0,0,0},
						{3,7,0,0,0,0,5,0,0},
						{6,0,0,0,0,0,0,0,4},
						{0,0,8,0,0,0,0,1,3},
						{0,0,0,0,2,0,0,0,0},
						{0,0,9,8,0,0,0,3,6},
						{0,0,0,3,0,6,0,9,0}		};
	op "the sudoku puzzle to solve is"; nl
	printMatrix(grid);
	if (solveGrid(grid) == true)
	{
		op "The solution is"; nl
        printMatrix(grid);
    }
    else
         op "No solution exists"; nl
	return 0;
}