#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* newnode(int d)
{
	struct node *nnode=(struct node *)malloc(sizeof(struct node));
	nnode->data=d;
	nnode->left=NULL;
	nnode->right=NULL;
	return nnode;
}
void inorder(struct node *node)
{
	if(node==NULL)
		return;
	inorder(node->left);
	printf("%d\t",node->data);
	inorder(node->right);
}
void preorder(struct node *node)
{
	if(node==NULL)
		return;
	printf("%d\t",node->data);
	preorder(node->left);
	preorder(node->right);
}
void postorder(struct node *node)
{
	if(node==NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("%d\t",node->data);
}
int main()
{
	struct node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	/*root->left->left->left=newnode(6);
	root->left->right->left=newnode(7);
	root->left->right->left->right=newnode(8);
	root->right->left=newnode(9);
	root->right->right=newnode(10);
	root->right->left->left=newnode(11);*/

	printf("inorder :\t");
	inorder(root);
	printf("\n");

	printf("preorder :\t");
	preorder(root);
	printf("\n");

	printf("postorder :\t");
	postorder(root);
	printf("\n");
}


