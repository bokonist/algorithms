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
bool swapBits(int &val,int i, int j) //swap the i'th and j'th Least significant bits of val
{
	if(i==j) //same bit, no swap needed
		return false; //not swapped
	int a,b;
	a= (val&(1<<i)) >> i; //get the i'th bit of val
	b= (val&(1<<j)) >> j; //get the j'th bit of val
	if(a==b) // no swap needed
		return false; //not swapped
	else
	{
		val = val^(1<<i); //flip the ith bit
		val = val^(1<<j); //flip the jth bit
		return true; //swapped
	}
}
int highest=0;
void generateKBitNumbers(int val, int k,int n, int mode=0) //permute the kth to n'th bit of val. mode 1 to print in binary
{
	int temp=0;
	if(k==n)
	{
		if(val>highest)
		{
			highest=val;	
			if(mode==1)
			{
				op bitset<5>(val); nl
			}
			else
			{
				op val; nl
			}
		}
	}
	else
		for(int i=k;i<n;i++)
		{
			swapBits(val,k,i);
			generateKBitNumbers(val,k+1,n,mode);
			swapBits(val,k,i);
		}
	highest=0; //reset highest for multiple calls
}

int main()
{
	int n=5,k=3;
	op "Enter limit. limit is 2 to the power of ";
	//ip n; nl
	op "Enter the number of set bits needed "; nl
	//ip k;
	k=pow(2,k)-1;
	generateKBitNumbers(k,0,n,1);
	return 0;
}