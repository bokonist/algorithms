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
	queue<int> bfs;
	bfs.push(0);
	cout<<"Bread first traversal is : ";
	while(!bfs.empty())
	{
		x=bfs.front();
		cout<<x<<' ';
		bfs.pop();
		for (int i = 0; i < sizeof(source)/sizeof(source[0]); ++i)
		{
			if(source[i]==x)
				bfs.push(i);
		}
	}
	return 0;
}