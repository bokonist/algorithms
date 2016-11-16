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
int indexOfMostValuble(float* &arr,int n)
{
	int bigg=INT_MIN, index=-1;
	repeat(n)
	{
		if(arr[i]>bigg)
		{
			bigg= arr[i];
			index=i;
		}
	}
	if(bigg!=INT_MIN)
	{
		arr[index]=INT_MIN;
		return index;
	}
	return -1;
}
int main()
{
	int n, capacity, *w, *v;
	float *vpu;
	op "Enter number of items"; nl
	ip n;
	w= new int[n];
	v= new int[n];
	vpu= new float[n];
	op "enter weights of items 1 to "<<n; nl
	repeat(n)
		ip w[i];
	op "enter values of items 1 to "<<n; nl
	repeat(n)
		ip v[i];
	repeat(n)
		vpu[i]=(float)v[i]/(float)w[i];
	op "Enter the maximum capacity of the knapsack"; nl
	ip capacity;
	int index=0, totalWorth=0;
	while(capacity>=0 && index!=-1)
	{
		index= indexOfMostValuble(vpu,n);
		if(index!=-1 && w[index]<=capacity)
		{
			op "Took "<<w[index]<<" units (all) of item "<<index+1; nl
			totalWorth+= v[index];
			op "Knapsack is now worth "<<totalWorth; nl 
			capacity -= w[index];
			op "Capacity left in knapsack is "<<capacity; nl nl
		}
	}
	op "Total worth of knapsack is "<<totalWorth; nl
	op "Free space in the knapsack is "<<capacity; nl
	return 0;
}