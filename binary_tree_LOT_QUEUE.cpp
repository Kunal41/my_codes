#include<iostream>
#include<stdlib.h>
#include<queue>
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
void level_order_traversal (struct node * tree)
{
	if (tree == NULL)
	{
		return;
	}
	queue <struct node *> q;
	q.push(tree);
	while (!q.empty())
	{
		struct node *temp;
		temp = q.front();
		q.pop();
		cout<<temp->data;
		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
		}		
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
