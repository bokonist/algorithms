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

//fermat factorization algorithm is 
/*FermatFactor(N): // N should be odd
    a ← ceil(sqrt(N))
    b2 ← a*a - N
    while b2 is not a square:
        a ← a + 1    // equivalently: b2 ← b2 + 2*a + 1
        b2 ← a*a - N //               a ← a + 1
    endwhile
    return a - sqrt(b2) // or a + sqrt(b2)
*/
ld fermatFactor(ll N)
{    
	ld a = ceil(sqrt(N));
    ld b2 = a*a - N;
    while (floor((sqrt(b2)))*floor(sqrt(b2)) - b2 !=0)
    {
        a = a + 1; 
        b2 = a*a - N;
    }
    return a - sqrt(b2); // or a + sqrt(b2)
}

int main()
{
	op fermatFactor(600851475143); //returns any divisor of input
	return 0;
}