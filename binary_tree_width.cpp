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
int max (int i,int j)
{
	if (i>j)
	{
		return i;
	}
	else return j;
}
int getwidth (struct node * tree,int level)
{
	if (tree == NULL)
	{
		return 0;
	}
	if ( level == 1)
	{
		return 1;
	}
	else
	{
		return (getwidth(tree->left,level-1) + getwidth(tree->right,level-1));
	}
}
int max_width (struct node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int i = height(root);
	int maxwidth = 0,width;
	for (int j = 1 ; j <= i ; j++)
	{
		width = getwidth(root,j);
		if ( width > maxwidth)
		{
			maxwidth = width;
		}
	}
	return maxwidth;
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
  cout<<"width "<<max_width(root)<<endl;
  return 0;
}
