#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	int data;
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
int max (int i,int j)
{
	if (i>j)
	{
		return i;
	}
	else return j;
}
int height ( struct node *tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	int lheight = height(tree->left);
	int rheight = height(tree->right);
	return max(lheight,rheight)+1;
}
void printnode(struct node *tree,int level)
{
	if ( tree == NULL)
	{
		return;
	}
	if ( level == 1)
	{
		cout<<tree->data<<endl;
	}
	else
	{
		printnode(tree->left,level-1);
		printnode(tree->right,level-1);
	}
}
int main()
{
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->right->right = newnode(8);
  root->right->right->left  = newnode(6);
  root->right->right->right  = newnode(7);
  cout<<"enter distance   ";
  int i;
  cin>>i;
  printnode(root,i);
  return 0;
}
