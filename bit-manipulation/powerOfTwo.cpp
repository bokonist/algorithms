#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define nl cout<<"\n";
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
bool isPowerOfTwo(int n)
{
	return !(n&(n-1));
}
int closestPowerOfTwo(int n, int mode=0) //mode 1 for closest power of 2 greater than n, mode 2 for both directions
{
	int x=n,g,l;
	if(isPowerOfTwo(n))
		return n;
	n|=n>>1;
	n|=n>>2;
	n|=n>>4;
	n|=n>>8;
	g= (n+1);
	l=g/2;
	if(mode==0)
		return l;
	else if(mode==1)
		return g;
	else //defaults to closest power of 2 greater than n if the distance is same in either direction
	{
		if(abs(x-g)>abs(x-l))
			return l;
		else
			return g;
	}
}
int main()
{
	int n;
	cin>>n;
	(isPowerOfTwo(n))?cout<<"yes, it is a power of 2\n":cout<<"no, it is not a power of 2\n";
	cout<<"The closest power of 2 less than "<<n<<" is "<<closestPowerOfTwo(n); nl
	cout<<"The closest power of 2 greater than "<<n<<" is "<<closestPowerOfTwo(n,1); nl
	cout<<"The closest power of 2 less than or greater than "<<n<<" is "<<closestPowerOfTwo(n,2); nl
	return 0;
}