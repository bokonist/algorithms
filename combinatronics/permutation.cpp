#include <iostream>
using namespace std;
void printarr(int A[],int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<"\n";
}
void perm(int A[], int k, int n)
{
	int temp=0;
	if(k==n)
		printarr(A,n);
	else
		for(int i=k;i<n;i++)
		{
			temp=A[k]; A[k]=A[i]; A[i]=temp;
			perm(A,k+1,n);
			temp=A[k]; A[k]=A[i]; A[i]=temp;
		}
}
int main()
{
	int A[10000],n=1;
	cin>>n;
	for(int i=0;i<n;i++)
		A[i]=i;
	perm(A,0,n);
}