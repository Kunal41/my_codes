#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
struct node* newnode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
bool print_ancestor (struct node *tree,int key)
{
	if (tree == NULL)
	{
		return false;
	}
	if (tree->data == key)
	{
		return true;
	}
	if ( print_ancestor(tree->left,key) || print_ancestor(tree->right,key))
	{
		cout<<tree->data<<endl;
		return true;
	}
	return false;
}
int main()
{
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);
  print_ancestor(root, 7);
  nreturn 0;
}
