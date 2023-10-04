// binary_tree.h – header file.
#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct tnode
{
	float number;
	struct tnode* left;
	struct tnode* right;
} tnode;

tnode* create_tree_node(float number);
void insert_tree(tnode* root, float data);
int treeHight(tnode* tree);
void empty_tree(tnode** root);
void SmallestKey(tnode* tree);
void printtreepreorder(tnode* tree);
void SmallestKey(tnode* tree);
int search(tnode* tree, float x);
void PrintKmax(tnode* root, int* k);

#endif
