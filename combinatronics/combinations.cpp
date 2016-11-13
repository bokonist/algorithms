#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define nl cout<<"\n";
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
void comb(int A[], int N, int K)
{
    string bitmask(K, 1);
    bitmask.resize(N, 0);
    do 
    {
        for (int i = 0; i < N; ++i)
        {
            if (bitmask[i]) 
            	cout <<A[i]<<' ';
        }
        nl
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}
int main()
{
	int input[] = {1,2,3,4,5,6,7,8,9,10};
	int n,r;
	cout<<"Choose how many elements out of "<<sizeof(input)/sizeof(input[0])<<" elements?\n";
	cin>>r;
	comb(input,sizeof(input)/sizeof(input[0]), r);
	return 0;
}