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

map<int, vector<int> > neighbours; //adjacency list for the graph
bool *visited; //mark visited
int treeCount=1;
int population=0;

int exploreForest(int src , int mode =0) //mode 0 is for following non-roots, i.e. to follow a separate disjoint tree. mode 1 to follow an internal node of a tree
{
	if(mode==0)
	{
		op "Tree #"<<treeCount++<<" : ";
		op src<<' ';
		population++;
	}
	visited[src]=true;
	vector<int> v = neighbours[src];
	for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
	{
		if(visited[ *it ] == false)
		{
			op *it<<' ';
			exploreForest( *it , 1);
			visited[ *it ]=true;
			population++;
		}
	}
	return 0;
}
int main()
{
	int e,a,b,n_nodes;
	op "Enter number of nodes in total : ";
	ip n_nodes; //input number of nodes
	op "Enter number of edges(connections) : ";
	ip e; //input number of edges
	visited = new bool[n_nodes];
	for (int i = 0; i < n_nodes; ++i)
	{
		visited[i]=false;
	}
	until(e,0)
	{
		op "Enter A and B for edge A----B \n";
		ip a>>b; //input a to b edge
		neighbours[a].push_back(b);
		neighbours[b].push_back(a);
	}

	op "Forest is\n";
	for (int i = 0; i < n_nodes; ++i)
	{
		if(!visited[i])
		{
			exploreForest(i); 
			op ". Population is "<<population;
			population=0;
			nl
		}
	}
	return 0;
}
