#include "bits/stdc++.h"
using namespace std;
/* useful utility macros */
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
#define printWholeArray(a) for(int(i)=0;(i)<int((sizeof(a)/sizeof(a[0])));i++) { cout<<(a[i])<<' ';}
#define repeat(n) for(int (i)=0;(i)<(int)(n);++(i)) //repeat n times
#define repeatBounds(l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i)) //repeat lower to upperbound
#define until(x,val) for(int(i) = int(x); int(x)!=int(val); (i<val)?x++:x--) //until x becomes value through increment or decrement

/*some constants*/
static const long double PI = 3.142857143;

/*some shorthands*/
typedef long long ll;
#define op cout<< // output to stdout
#define ip cin>> //input from stdin
#define err cerr<< //output to stderr
#define nl cout<<"\n"; //newline

struct node //node in the graph
{
    int value; //value of node
    int distance; //distance from root
};

int minOperationsBFS(int source, int target)
{
	set<int> visited; //to keep track of unvisited sources
	queue<node> q; //to run BFS
	node n,temp; n.value=source; n.distance=0; //start with node value source
	q.push(n); 
	while(!q.empty())
	{
		temp= q.front();
		q.pop();
		if(temp.value == target) // reached the target
		{
			return temp.distance; //return the number of operations
		}
		visited.insert(temp.value); //mark visited
		if (visited.find(temp.value*2) == visited.end()) //if source*2 is unvisited
        {
            n.value = temp.value*2;
            n.distance = temp.distance+1;
            q.push(n);
        }
        if (temp.value-1 >= 0 && visited.find(temp.value-1) == visited.end()) //if source-1 is unvisited
        {
            n.value = temp.value-1;
            n.distance = temp.distance+1;
            q.push(n);
        }
	}
}
int main()
{
	//program transforms source to target in minumum number of operations. the two operations allowed are *2 and -1
	int x=42,y=35;
	ip x>>y;
	op minOperationsBFS(x,y);
	return 0;
}