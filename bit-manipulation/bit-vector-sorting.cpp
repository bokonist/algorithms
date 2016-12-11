// sorting n non-repetetive integer elements using a bit vector
/* author: github.com/bokonist */
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

int main()
{
	bitset<1000000> *bitmap =  new bitset<1000000>; //allocate memory on the heap. don't do it on stack.
	op "Enter the number of elements \n";
	int n,temp,highest=INT_MIN;
	ip n;
	op "Enter the non-repetetive non-negative elements. must be < 1e6\n";
	for (int i = 0; i < n; ++i)
	{
		ip temp;
		bitmap->set(temp);
		if(temp>highest)
			highest=temp;
	}
	op "Sorted list is : ";
	for (int i = 0; i <= highest; ++i)
	{
		if(bitmap->test(i))
			op i<<' ';
	}
	nl
	return 0;
}