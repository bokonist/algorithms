#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { //cout<<(a[i])<<' ';}
using namespace std;
char** a; //dynamic 2d array for the board
int solNumber=1; // to print solution numbers
int stateNumber=0; // primary key to identify save states
std::map<int, string> savedStates; // map of stateNumber -> MatrixString
void printMatrix(char** &a,int n) //to print the current matrix
{
	cout<<setw(5)<<"*";
	cout<<" ";
	for (int i = 0; i < n; ++i)
	{
		cout<<i<<' ';
	}
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<setw(5)<<i<<' ';
		for (int j = 0; j < n; ++j)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
void saveState(char** &a, int n) //save the current state 
{
	//cout<<"saving state #"<<stateNumber<<"...\n";
	string str;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			str=str+a[i][j];
		}
	}
	savedStates[stateNumber]=str;
	//cout<<"\nState #"<<stateNumber<<"is\n";
	//printMatrix(a,n);
	stateNumber++;
}
void restoreState(int stateNumber_local, char** &a, int n) // restore the passed state number
{
	//cout<<"restoring state #"<<stateNumber_local<<"...\n";
	string str= savedStates[stateNumber_local];
	int k=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j]=str[k];
			k++;
		}
	}
	//cout<<"\nRestored State #"<<stateNumber_local<<"is\n";
	//printMatrix(a,n);
	return;

}

int findAvailablePosition(char** &a, int n, int row=0, int col=0) //find vacant pos on passed row after and including the given column.
{
	for (int i = col; i < n; ++i)
	{
		if(a[row][i] == '-')
		{
			return i;
		}
	}
	return -1; // no vacant positions on current row
}
bool markPath(char** &a,int n, int row,int col) // mark all the x's on the passed (row,col) co-ordinates on the board. return bool indicates success or failure
{

	if(a[row][col] == 'x' || a[row][col] == 'Q')
	{
		return false; //trying to mark a non-vacant position
	}
	a[row][col]='Q'; //mark it with Q.
	for (int i = 0; i < n; ++i) //orthogonal markings
	{
		if(a[row][i] == '-')
		{
			a[row][i]= 'x';
		}
		if(a[i][col] == '-')
		{
			a[i][col]= 'x';
		}
	}
	//now, marking primary diagonal
	int j=0;
	if(col>=row) // (row,col) lies on the upper triangle of the primary diagonal including the diagonal
	{
		for(int i= col-row; i<n; ++i )
		{
			if(a[j][i] == '-')
			{
				a[j][i]= 'x';
			}
			j++;
		}
		j=0;
	}
	else // (row,col) lies on the lower triangle of the primary diagonal not including the diagonal
	{
		for(int i= row-col; i<n; ++i )
		{
			if(a[i][j] == '-')
			{
				a[i][j]= 'x';
			}
			j++;
		}
		j=0;
	}
	//now marking secondary diagonal
	if((col+row) <= (n-1) ) // (row,col) lies on the upper triangle of the secondary diagonal including the diagonal
	{
		for (int i = col+row; i >=0; --i)
		{
			if(a[j][i] == '-')
			{
				a[j][i]= 'x';
			}
			j++;
		}
		j=0;
	}
	else // (row,col) lies on the lower triangle of the secondary diagonal not including the diagonal 
	{
		j=n-1;
		for (int i = (col+row) - (n-1); i <=(n-1); ++i)
		{
			if(a[i][j] == '-')
			{
				a[i][j]= 'x';
			}
			j--;
		}
		j=0;	
	}
	//cout<<"\nState #"<<stateNumber<<" after marking the path is\n";
	//printMatrix(a,n);
	//cout<<endl;
	return true;
}
int queenCount(char** &a, int n) //counts the current number of queens set on the board. too much complexity overhead. change it later.
{
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		for (int g = 0; g < n; ++g)
		{
			if(a[i][g]=='Q')
			{
				count++;
				break;
			}
		}
	}
	return count;
}
/* NQueens takes the global charmatrix a as input, its size and the row to place the queen. called recursively. returns true upon success. */
bool NQueens(char** &a, int n, int currentRow=0) // main function for NQueen markings.
{
	if(n==currentRow) // the row to be marked matches the size. this means all rows are marked. return success(true).
		return true;
	//cout<<"\ncalling NQueens on row #"<<currentRow<<endl;
	//getchar();
	saveState(a,n); //save the current state so we can restore it later.
	int j=0;
	int pos=0;
	int savedStateNumber=stateNumber; // save the stateNumber so we can call restoreState() if needed later.
	//cout<<"processing row #"<<currentRow<<"\n";
	pos= findAvailablePosition(a,n,currentRow,j); //find a vacant position on current row
	j=pos;
	while(j != -1) //vacant pos found at current row
	{
		//cout<<"found viable pos at row #"<<currentRow<<"! marking "<<currentRow<<" "<<j<<"\n";
		//cout<<"pos to try marking is "<<currentRow<<','<<j<<endl;
		//getchar();
		markPath(a,n,currentRow,j); //mark the current path with a Queen on coordinates (currentRow,j)
		////cout<<"currentRow here is "<<currentRow<<endl;	
		if(currentRow+1 <= n) // is true till the last row
		{
			if(queenCount(a,n)==n) //all queens are places. print solution.
			{
				cout<<"Solution #"<<solNumber++<<"\n";
				printMatrix(a,n);
			}
			if( !NQueens(a,n,currentRow+1)) //if Nqueens on the next row fails. (recursive call)
			{
				restoreState(savedStateNumber-1,a,n); //restore the previous state
				/*for(int ii= currentRow;ii<n;ii++) // if no more positions are left to be explored on this row
					if(findAvailablePosition(a,n,currentRow,j+1) == -1)
						return false;*/
				int nexpos=findAvailablePosition(a,n,currentRow,j+1);
				//cout<<"State is now. next pos to try is "<<currentRow<<","<<nexpos<<"\n";
				//printMatrix(a,n);
				//getchar();
				//a[currentRow][j]='x';
				j=nexpos;
			}
			else
				return false; //after all rows are explored and we get a solution, return false to explore other solutions.
		}
	}
	if(pos == -1) //no vacant pos for current row
	{
		return false; // don't know what this does but number of solutions gets reduced for N>5. set true to possibly eliminate duplicates? 			
	}
	return true; //return success to main()
}
int main()
{
	int n=0;
	cin>>n;
	a = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		a[i]= new char[n];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j]='-'; //initially set all positions to be vacant
	NQueens(a,n,0);
	return 0;
}
