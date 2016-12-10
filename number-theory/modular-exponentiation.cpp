//program to return (a^b)%mod in O(log n) time
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
/*
	algorithm is,
	start with result = 1
	traverse the binary representation of exponent right to left.
	At each step, square the base and mod, also, if current exponent is odd, muliply with result with the base and mod.
	rightshift the exponent by 1.
*/

ll power(ll base, ll exponent, ll mod) 
{
    ll result = 1;
    base%=mod;  
    while (exponent>0)
    {
        if (exponent & 1) 
            result = (result*base) % mod;
        exponent = exponent>>1; 
        base = (base*base) % mod;
    }
    return result;
}
int main()
{
	op power(2000,2000,3000);
	return 0;
}