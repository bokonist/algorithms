#include "bits/stdc++.h"
using namespace std;
int to_base(int x,int base)
{
	int q;
	stack<int> s;
	while(x>0)
	{
		s.push(x%base);
		x/=base;
	}
	while(!s.empty())
	{
		q=s.top();
		if(q<10)
			cout<<q;
		else
			cout<<(char)(q+55);

		s.pop();
	}
	return 0;
}
int main()
{
	int x=100,b=16;
	cout<<"Enter number and which base to convert it to";
	//cin>>x>>b;
	cout<<"\nResult is ";
	to_base(x,b);
	return 0;
}