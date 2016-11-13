#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define nl cout<<"\n";
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
int noOfSetBits(int n)
{
	int count =0;
	while(n)
	{
		count++;
		n=n&(n-1);
	}
	return count;
}
int main()
{	
	int n;
	cin>>n;
	cout<<"The number of set bits in the binary representation of "<<n<<" is "<<noOfSetBits(n); nl
	return 0;
}