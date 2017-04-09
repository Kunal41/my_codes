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
void print_LOT (struct node * tree,int level)
{
	if (tree == NULL)
	{
		return;
	}
	else if (level == 1)
	{
		cout<<tree->data<<endl;
	}
	else {
		print_LOT(tree->left,level-1);
		print_LOT(tree->right,level-1);
	}
}
void level_order_traversal (struct node *tree)
{
	int i = height(tree);
	for ( int j = 1; j <= i ; j++)
	{
		print_LOT(tree,j);
	}
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
	level_order_traversal (root);
	return 0;
}
