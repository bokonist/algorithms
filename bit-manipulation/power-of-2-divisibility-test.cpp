//check if divisible by powers of 2 only
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
ll whichPowerOfTwo(ll n)
{
	if(n==0)
		return 0;
	int i=0;
	while(!(n& 1<<i))
		i++;
	return i;
}
bool isDivisible(ll a, ll b)
{
	int y = whichPowerOfTwo(b);
	if(a == (a>>y)<<y)
		return true;
	return false;
}
int main()
{
	op "Enter number\n";
	ll x; ip x;
	op "Enter a power of 2 to check divisibility\n";
	ll d; ip d;
	(isDivisible(x,d))? op "Divisible\n": op "Not divisible\n";
	return 0;
}