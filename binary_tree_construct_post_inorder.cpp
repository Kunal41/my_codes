#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	char data;
	struct node *left;
	struct node *right;
};
struct node* newnode (int data)
{
	struct node * tree = (struct node*)malloc(sizeof(struct node));
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
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
struct node * buildtree(char in[],char post[],int instart,int inend)
{
	if (instart > inend)
	{
		return NULL;
	}
	static int postindex = inend;
	struct node *root = newnode(post[postindex--]);
	if (instart == inend)
	{
		return root;
	}
	int i = search(in,root->data,instart,inend);
	root->right = buildtree(in,post,i+1,inend);
	root->left = buildtree(in,post,instart,i-1);
	return root;
}
void printpreorder(struct node * root)
{
	if (root == NULL)
	{
		return;
	}
	cout<<root->data;
	printpreorder(root->left);
	printpreorder(root->right);
}
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char post[] = {'D', 'E', 'B', 'F', 'C', 'A'};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildtree(in, post, 0, len - 1);
  printpreorder(root);
  return 0;
}
