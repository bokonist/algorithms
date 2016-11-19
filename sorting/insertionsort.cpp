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
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void insertionSort(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j>0 && (array[j]<array[j-1]) ; --j)
		{
			swap(array[j],array[j-1]);
		}
	}
}
int main()
{
	int* arr;
	op "enter number of elements"; nl
	int n=10;
	ip n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i]=rand()%100;
	}
	op "Unsorted array is ";
	printArray(arr,0,n); nl
	op "Sorted array is ";
	insertionSort(arr,n);
	printArray(arr,0,n);nl
	return 0;
}