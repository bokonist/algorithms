//https://www.hackerrank.com/challenges/journey-to-the-moon
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

bool **connection; //adjacency matrix
bool *visited; //mark visited
int n_nodes; //number of nodes
int treeCount=1;
int exploreForest(int src)
{
	op "Tree #"<<treeCount++<<" : ";
	stack<int> s;
	s.push(src);
	int i,count=0;
	while(!s.empty())	
	{
		count++;
		i=s.top();
		op i<<"-";
		s.pop();
		visited[i]=true;
		if(i==4)
			op "visited 4\n";
		for (int j = 0; j < n_nodes; ++j)
		{
			if(connection[i][j]==true && ! visited[j])
				s.push(j);
		}
	}
	op "Population is "<<count;
	return count;
}
int main()
{
	int numberOfConnections,a,b;
	op "Enter number of nodes in total : ";
	ip n_nodes; //input number of nodes
	op "Enter number of edges(connections) : ";
	ip numberOfConnections; //input number of edges
	connection = new bool*[n_nodes];
	visited = new bool[n_nodes];

	for (int i = 0; i < n_nodes; ++i)
	{
		visited[i]=false;
		connection[i] = new bool[n_nodes];
		for (int j = 0; j < n_nodes; ++j)
			connection[i][j]=false;
	}

	until(numberOfConnections,0)
	{
		op "Enter A and B for edge A----B \n";
		ip a>>b; //input a to b edge
		connection[a][b]=true;
		connection[b][a]=true;
	}
	op "Forest is\n";
	for (int i = 0; i < n_nodes; ++i)
	{
		if(!visited[i])
		{
			exploreForest(i); 
			nl
		}
	}
	return 0;
}