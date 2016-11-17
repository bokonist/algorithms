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
void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int partition(int *a,int low, int high)
{
	int pivot=  a[high];
	int i= low-1;
	for (int j = low; j < high; ++j)
	{
		if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
	}
	swap(a[i+1], a[high]);
    return (i + 1);
}
void quickSort(int* a, int low,int high)
{
	if(low<high)
	{
		int part= partition(a,low,high);
		quickSort(a,low, part-1);
		quickSort(a,part+1,high);
	}
}
int main()
{
	int n=10;
	op "Enter number of elements ";
	ip n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		a[i]=rand()%100;
	}
	op "Unsorted array is \t: ";
	printWholeArray(a); nl
	quickSort(a,0,n-1);
	op "Sorted array is \t: ";
	printWholeArray(a);nl
	return 0;
}