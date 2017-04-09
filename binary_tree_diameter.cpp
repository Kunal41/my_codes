#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
	int data;
	struct node * left;
	struct node * right;
};
struct node * newnode (int num)
{
	struct node * tree = (struct node*)malloc(sizeof(struct node));
	tree->data = num;
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

int diameter (struct node *tree){
	if (tree == NULL)
	{
		return 0;
	}
	int l = height(tree->left);
	int r = height(tree->right);
	int i = diameter(tree->left);
	int j = diameter(tree->right);
	return max(l+r+1,max(i,j));
}

int main()
{
	struct node * root;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->left->left->left = newnode(6);
	cout<<diameter(root);
	return 0;
}
