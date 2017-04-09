#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	char data;
	struct node * left;
	struct node *right;
};
struct node * newnode (int k)
{
	struct node * root = (struct node*)malloc(sizeof(struct node));
	root->data = k;
	root->left = NULL;
	root->right = NULL;
	return root;
}
int search (char in[],int data,int instart,int inend)
{
	for (int j = instart;j < inend;j++)
	{
		if (in[j] == data)
		{
			return j;
		}
	}
}
struct node * buildtree(char in[],char pre[],int instart,int inend){
	if (instart > inend)
	{
		return NULL;
	}
	static int preindex = 0;
	struct node* tree = newnode(pre[preindex++]);
	if (instart == inend)
	{
		return tree;
	}
	int i = search(in,tree->data,instart,inend);
	tree->left = buildtree(in, pre, instart, i-1);
	tree->right = buildtree(in, pre, i+1,inend);
	return tree;
}
void printinorder(struct node * root)
{
	if (root == NULL)
	{
		return;
	}
	printinorder(root->left);
	cout<<root->data;
	printinorder(root->right);
}
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildtree(in, pre, 0, len - 1);
  printinorder(root);
  return 0;
}
