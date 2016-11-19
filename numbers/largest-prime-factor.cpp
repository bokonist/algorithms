//https://projecteuler.net/problem=3
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
typedef long double ld;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline

//method is
/* Use a loop that always finds the smallest (positive integer) factor of a number.
 When the smallest factor of a number is that number, then you've found the greatest prime factor*/
ll largestPrimeFactor(ll x)
{
        ll lpf = 2; //start largestprimefactor with 2
        while (x > lpf) // loop till we get our ans or the next value to try
        {
                if (x%lpf==0) //x is divisible by our current largest prime
                {
                        x = x/lpf; //divide it and assign it to x
                        lpf = 2; //reset lpf so we can begin this process all over again to check the new x
                }
                else //not divisible. so try next odd number
                {
                    if(lpf!=2)
                        lpf+=2; //increment by 2
                    else
                        lpf++; //increment
                }
        } //loop ends when our x becomes equal to lpf.
        return lpf;
}
int main()
{
    ll n;
    op "Enter number (type: long long int) to find largest prime factor of :";
    cin>>n;
	//op largestPrimeFactor(600851475143);
    op "Largest prime factor of "<<n<<" is "<<largestPrimeFactor(n);
	return 0;
}