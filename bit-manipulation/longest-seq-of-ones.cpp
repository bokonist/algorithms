// progam to find length of the longest string of ones in binary representation of a number in O(count) time
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
int longestChainLength(ll a)
{
	int count=0;
	while(a)
	{
		count++;
		a= a&(a<<1);
		/*at every loop iteration, the longest chain gets reduced by 1 in length.*/
	}
	return count;
}
int main()
{
	int x=1023;
	op "Enter the number to count length of longest chain of 1s in : ";
	ip x;
	op "The binary representation of entered number is "<<bitset<32>(x);nl
	op "Length of longest 1 chain is "<<longestChainLength(x);
	return 0;
}