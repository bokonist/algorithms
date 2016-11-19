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

//algorithm is
/*
Start with random x and c. Take y equal to x and f(x) = x^2 + c.
While a divisor isn’t obtained
	Update x to f(x) (modulo n) (tortoise) (read floyd's cycle detection algorithm)
	Update y to f(f(y)) (modulo n) (hare)
	Calculate GCD of |x-y| and n
	if GCD is not 1
		if GCD is n 
			repeat from step 2 with new values of x, y and c
		Else 
			GCD is our answer
*/

ll gcd(ll a, ll b) 
{
	ll remainder;
	while (b != 0) 
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

ll power(ll a, ll b, ll p) // function to calculate (a to the power b)%p in O(log n) time
{
    ll result = 1;
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

ll PollardRhoFactor(ll n)
{
 
    // no prime divisor for 1
    if (n==1) 
    	return 1;
    if (n & 1 == 0) //even. so one of the divisors will be 2 
    	return 2;
 

    // pick a random number in range 2 to N-1
    ll x = (rand()%(n-2))+2;
    ll y = x;
 
    // the constant in f(x). pick rand from range 1 to n-2
    ll c = (rand()%(n-1))+1;
 
    ll d = 1; //initial divisor. d will become our final answer when we get a divisor other than 1
 
    /* until the prime factor isn't obtained. if n is prime, return n */
    while (d==1)
    {
        // tortoise Move
        x = (power(x, 2, n) + c)%n; // ((x^2)%n + c)%n . the internal modular exponentiation is to prevent overflows
 
        // hare Move
        y = (power(y, 2, n) + c)%n;
        y = (power(y, 2, n) + c)%n;

        /* check gcd of |x-y| and n */
        d = gcd(abs(x-y), n);
        if (d==n) //gcd is the number itself for current values of x and c
        	return PollardRhoFactor(n); //retry with new x,c
    } //loop breaks when we get out answer i.e, value of d changes to anything other than 1. means we got a divisor other than 1.
    return d;
}
int main()
{
    ll n = 10967535067;
    op "One of the divisors for "<<n<<" is "<<PollardRhoFactor(n); nl
    return 0;
}