#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define nl cout<<"\n";
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
int main()
{
	int source[]= {-1,0,1,0,1,6,2,5,4,10,6};
	int x;
	stack<int> dfs;
	dfs.push(0);
	cout<<"Depth first traversal is : ";
	while(!dfs.empty())
	{
		x=dfs.top();
		cout<<x<<' ';
		dfs.pop();
		for (int i = 0; i < sizeof(source)/sizeof(source[0]); ++i)
		{
			if(source[i]==x)
				dfs.push(i);
		}
	}
	return 0;
}