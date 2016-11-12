#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
void countSort(int a[], int n)
{
	int largest= INT_MIN;
	for (int i = 0; i < n; ++i) //loop to find the largest element
		if(a[i]>largest)
			largest=a[i];
	int *freq= new int[largest]; //make a new array with size = largest element
	for (int i = 0; i < n; ++i) //loop through the input and increment the frequency of each element when it is encountered
		freq[a[i]]++;
	for (int i = 0; i < largest; ++i) //loop through the freq count and print the elements however many times it occurs.
		while(freq[i]--!=0)
			cout<<i<<' ';
}

int main()
{
	int input[10];
	for (int i = 0; i < 10; ++i)
		input[i]=rand()%50;
	cout<<"Unsorted: ";
	printArray(input,0,10);
	cout<<endl<<"Sorted : ";
	countSort(input, 10);
	return 0;
}