// cpp program to invert a binary tree along the horizonal axis. i.e mirror flip
/* author: github.com/bokonist */
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
	int val;
	node* left;
	node* right;
};

void inorder(node* root)
{
	if(root->left != NULL)
		inorder(root->left);
	if(root!=NULL)
		op root->val<<" ";
	if(root->right != NULL)
		inorder(root->right);
}
void invert(node* root)
{
	node* temp;
	temp = root->left;
	root->left=root->right;
	root->right=temp;
	if(root->left != NULL)
		invert(root->left);
	if(root->right != NULL)
		invert(root->right);

}
node* makeNode(int val)
{
	node* nd = new node;
	nd->val= val;
	nd->left=nd->right=NULL;
	return nd;
}
int main()
{
	node* root= makeNode(1);
	root->left=makeNode(2);
	root->right=makeNode(3);
	root->left->left=makeNode(4);
	root->left->right=makeNode(5);
	//root->right->left=makeNode(6);
	root->right->right=makeNode(7);
/*
				1
		2				3
	4		5				7

flipped to 

				1
		3				2
	7				5		4


*/
	inorder(root); nl
	invert(root);
	inorder(root);

	return 0;
}