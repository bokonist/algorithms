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
struct node
{
    int data;
   	node* next;
};
 
void insertAtFront(struct node** root, int data)
{
    node* newNode = new node;
    newNode->data  = data;
    // insert to beginning
    newNode->next = (*root);
    // new node is the new root
    (*root)    = newNode;
}
 
bool floydDetect(struct node *list)
{
    node *tortoise = list, *hare = list; //both start at beginning
  
    while (tortoise && hare && hare->next ) //while all pointers are valid
    {
        tortoise = tortoise->next; //tortoise move
        hare  = hare->next->next; //hare move
        if (tortoise == hare) //both are at same point
           return true;
    }
    return false;
}
int main()
{
    node* root = NULL;
 	for (int i = 0; i < 4; ++i)
 	{
 		insertAtFront(&root, rand()%100); //insert random elements
 	}
    root->next->next->next->next = root; //create a loop
    (floydDetect(root))?op "loop detected":op "no loops detected";
    return 0;
}