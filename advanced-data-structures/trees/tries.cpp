#include "bits/stdc++.h"
#define MIN(a,b,res) ((a)>(b))? (res)=(b):(res)=(a)
#define MAX(a,b,res) ((a)<(b))? (res)=(b):(res)=(a)
#define repeat(x) while(x--)
#define printArray(a,l,n) for(int(i)=(l);(i)<int(n);i++) { cout<<(a[i])<<' ';}
using namespace std;
struct trieNode
{
	bool isLeaf;
	std::map<char, trieNode*> children;
	trieNode()
	{
		isLeaf=false;
	}
};
bool searchTrie(trieNode*,string);
trieNode* insertToTrie(trieNode *root, string word)
{
	
	if(root== NULL)
	{
		root= new trieNode;
		//cout<<root;
	}
	trieNode *temp;
	temp=root;
	for(int i=0;i< word.length();i++)
	{
		if(temp->children.count(word[i])==0) // no such key exists
		{
			temp->children[word[i]] = new trieNode; //create it
		}
		temp = temp-> children[word[i]]; // set new root as it's child
	}
	temp->isLeaf = true; // mark new word entry
	cout<<"root in insertToTrie() is "<<root<<endl;
	return root;
}
bool deleteFromTrie(trieNode *root, string word, int index=0)
{
	if(root== NULL)
		return false;
	trieNode *temp;
	temp=root;
	if(!searchTrie(temp,word))
	{
		cout<<"word not found"<<endl;
		return false;
	}
	if(index == (word.length()-1)) // means we are at leaf
	{
		if(temp->children.size() == 0) // no other words extend beyond this word
			temp->isLeaf=false;
	}
	return true;
}
bool searchTrie(trieNode *root,string word)
{
	if(root==NULL)
		return false;
	for(int i=0;i< word.length();i++)
	{
		if(root->children.count(word[i])==0) // no such key exists
		{
			cout<<"prefix is "<<word.substr(0,i)<<endl; // print the closest thing to our query
			return false;
		}
		root = root-> children[word[i]]; // set new root as it's child
	}
	//finished traversal through word[]
	if(root->isLeaf)
		return true;
}
int main()
{
	trieNode *root= NULL;
	string str="hello";
	root=insertToTrie(root, str);
	cout<<"root in main() is "<<root<<endl;
	searchTrie(root,"hello")?cout<<"yes, it exists":cout<<"not found\n";
	return 0;
}