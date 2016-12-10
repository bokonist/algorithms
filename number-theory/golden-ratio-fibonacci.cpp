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
static const long double GOLDEN = 1.61803;
static const long double ObR5 = 0.447214;

/*some shorthands*/
typedef long long ll;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline

//the n'th fibonacci number is (1/sqrt(5))* ((golden ratio)^(n+1)) rounded off to the nearest integer
// golden ratio  is 1/(1+ sqrt(5)) = 1.61803
ll fibo(long n) 
{

	double nfb = (ObR5*pow(GOLDEN,n+1));
	double f_nfb = floor(nfb);
	if(nfb-f_nfb < 0.5)
		return f_nfb;
	else
		return ceil(nfb);
}
int main()
{
	int t;
	op "Enter limit : ";
	ip t;
	for (int i = 0; i < t; ++i)
	{
		op fibo(i)<<' ';
	}
	return 0;
}