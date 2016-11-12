#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;

int n=0;
char** a; //dynamic 2d array for the board
list<int*> solutionSpace;
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
	return true;
}
void reduceSolutionSpace(int* prefix, int index)
{
	int *x= new int[n];
	for (list<int*>::iterator it=solutionSpace.begin(); it != solutionSpace.end(); ++it)
	{
		*it = x;
		for (int i = 0; i < n; ++i)
		{
			if(x[i]==prefix[i])
			{
				if( i > index)
					solutionSpace.remove(x);
			}
			else
			{
				i=n;
				it=solutionSpace.end(); //skip the rest
			}

		}
	}
}
/* NQueens takes the global charmatrix a as input, its size and solution to try. returns true upon success. */
bool NQueens(char** &a, int n, int* solution) // main function for NQueen markings.
{
	//printArray(solution,0,n);
	for (int i = 0; i < n; ++i)
	{
		if(!markPath(a,n,i,solution[i]))
		{
			reduceSolutionSpace(solution,i);
			return false;
		}
		
	}
	//printMatrix(a,n);
	printArray(solution,0,n);
	cout<<endl;
	return true;
}


void perm(int* A, int k, int n)
{
	int temp=0;
	if(k==n)
	{
		//printArray(A,0,n);
		//cout<<"\n";
		int *X = new int[n];
		for (int i = 0; i < n; ++i)
			X[i]=A[i];
		solutionSpace.push_back(X);
	}
	else
		for(int i=k;i<n;i++)
		{
			temp=A[k]; A[k]=A[i]; A[i]=temp;
			perm(A,k+1,n);
			temp=A[k]; A[k]=A[i]; A[i]=temp;
		}
}
void resetMatrix(char** &a, int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j]='-'; //initially set all positions to be vacant
}

int main()
{
	n=8;
	//cin>>n;
	a = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		a[i]= new char[n];
	}
	resetMatrix(a,n);
	int *x = new int[n];
	for (int i = 0; i < n; ++i)
	{
		x[i]=i;
		//cout <<x[i];
	}
	perm(x,0,n);
	for (list<int*>::iterator it=solutionSpace.begin(); it != solutionSpace.end(); ++it)
	{
		NQueens(a,n, *it);
		resetMatrix(a,n);
		//cout<<endl;
	}
	
	return 0;
}