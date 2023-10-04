#include "binary_tree_header.h"

tnode* create_tree_node(float number) {//function that creates new node by dynamic allocation 
	tnode* new_node = NULL;
	new_node = (tnode*)malloc(sizeof(tnode));
	if (new_node != NULL) {
		new_node->number = number;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;

}

void insert_tree(tnode** root, float data) //function that insert new node to the tree.
{
	tnode* newkey = NULL, ** proot = root, * temp = NULL;
	newkey = create_tree_node(data);
	if (*(root) == NULL) {
		if (newkey == NULL) {
			printf("failed to allocate memory");
			empty_tree(root);
			exit(1);
		}
		*root = newkey;
	}
	else {
		while (*proot != NULL) { //sort by bigger or smaller than the root number.//
			temp = *proot;
			if (data < (*proot)->number) {//smaller numbers going to the left branch of the tree.//
				proot = &((*proot)->left);
			}
			else
				proot = &((*proot)->right);//bigger going to the right branch of the tree.//
		}
		if (data < temp->number)
			temp->left = newkey;
		else {
			temp->right = newkey;
		}
	}
}


int treeHight(tnode* tree)//function that calculate the height of the tree (empty tree height is -1).
{
	int lh, rh;
	if (tree == NULL)
		return -1;
	lh = treeHight(tree->left);
	rh = treeHight(tree->right);
	if (lh > rh)
		return 1 + lh;
	else
		return 1 + rh;
}

void empty_tree(tnode** root)//free the nodes of the tree.
{
	if ((*root) == NULL)
		return;
	empty_tree(&((*root)->left));
	empty_tree(&((*root)->right));
	free(*root);
	*root = NULL;
}


void printtreepreorder(tnode* tree)//prints the tree nodes by "preorder" order
{
	if (tree == NULL)
		return;
	printf("%.2f ->", tree->number);
	printtreepreorder(tree->left);
	printtreepreorder(tree->right);
}

void SmallestKey(tnode* tree) {//prints the minimum number of the tree.
	tnode* temp = tree;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	printf("\nthe min is: %.2f\n", temp->number);
}
int search(tnode* tree, float x)//search for a number in the tree and returns 1 if the number exists in the tree and 0 if not.
{
	if (tree == NULL) {
		return 0;
	}
	if (tree->number == x) {
		return 1;
	}
	else if (x > tree->number)
		return search(tree->right, x);
	else
		return search(tree->left, x);
}


void PrintKmax(tnode* root, int* k)//prints the K biggest numbers in the tree, in descending order.
{
	if (root == NULL)
		return;
	PrintKmax(root->right, k);
	if (*k != 0)
	{
		printf("%.2f -> ", root->number);
		*k = *k - 1;
	}
	else
		return;
	PrintKmax(root->left, k);
}
char menu() {
	char b;
	printf("\n1 - add new node.\n");
	printf("2 - print tree in preorder. \n");
	printf("3 - tree height.\n");
	printf("4 - min key in tree.\n");
	printf("5 - search for key in the tree.\n");
	printf("6 - print the k biggest keys in.  \n");
	printf("7 - to finish.\n");
	b = getchar();
	return b;
}