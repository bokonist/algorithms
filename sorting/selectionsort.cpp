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
void selectionSort(int* a, int size=0)
{
	int smallest=0, temp=0;
	for (int i = 0; i < size; ++i)
	{
		smallest=i;
		for (int j = i; j < size; ++j)
		{
			if(a[j]<a[smallest])
				smallest=j;
		}
		temp=a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
	}
}
int main()
{
	int a[5]= {5,4,3,2,1};
	op "Unsorted array is \t: ";
	printWholeArray(a); nl
	selectionSort(a,5);
	op "Sorted array is \t: ";
	printWholeArray(a);nl
	return 0;
}