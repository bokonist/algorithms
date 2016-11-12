#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void generateSubsets(string &str)
{
	int len=str.length();
	for(ll i=0;i< pow(2,len);i++)
	{
		for(int j=0;j<len;j++)
			if(i&(1<<j))
				cout<<str[j]<<' ';
		cout<<endl;
	}
}
int main()
{
	string str;
	//cin>>str;
	str="q";
	generateSubsets(str);
	return 0;
}