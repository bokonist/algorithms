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

int power(int a, int b, int p) // function to calculate (a to the power b)%p in O(log n) time
{
    int result = 1;
    a%=p;  // reset the power cycle to a number less than a
    while (b>0)
    {
        if (b & 1) //if b is odd, multiply result with a
            result = (result*a) % p;
        b = b>>1; // divide by two
        a = (a*a) % p;
    }
    return result;
}

bool isPrime(int n, int k=3) // higher the val of k, higher the probability of correct result
{
	if (n <= 1 || n == 4) //exceptional cases 
		return false;
   	if (n <= 3) 
   		return true;
 	int a;
   // Try k times
   while (k>0)
   {
       // Pick a random number in 2..n-2
       a = 2 + rand()%(n-4);  
       // Fermat's little theorem
       if (power(a, n-1, n) != 1)
          return false;
       k--;
    }
    return true;
}

int main()
{
    isPrime(43)? op "true": op "false"; nl
    isPrime(100003,43)? op "true": op "false"; nl //doesn't work cuz value of n is too much
	return 0;
}