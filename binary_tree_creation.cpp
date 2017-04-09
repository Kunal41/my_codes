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
void print (struct node * tree)
{
	if (tree == NULL)
	{
		return;
	}
	cout<<tree->data<<endl;
	print(tree->left);
	print(tree->right);
}
int main()
{
	int i,j,k,l;
	struct node * root;
	root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	print(root);
	return 0;
}
