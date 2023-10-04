#include "binary_tree_header.h"
int main() {//main function, split the functions to cases that chosen by the user.
	int cnt = 0;
	char s;
	int k, high;
	float key;
	tnode* root = NULL;
	while (1){
		rewind(stdin);
		s = menu();//call the menu
		switch (s){
		case '1':
			while (1){
				printf("\nenter new key to add:\n");
				scanf("%f", &key);
				if (search(root, key) != 1) {
					insert_tree(&root, key);
					printf("\nadded to tree.\n");
					break;
				}
				else {
					printf("\nkey allready in tree enter new key.\n");
				}
			}
			cnt++;
			break;
		case '2':
			printtreepreorder(root);
			break;
		case'3':
			high = treeHight(root);
			printf("\ntree height is %d.\n", high);
			break;
		case'4':
			SmallestKey(root);
			break;
		case'5':
			printf("\nenter key to search:\n");
			scanf("%f", &key);
			if (search(root, key))
				printf("%.2f in the tree.\n", key);
			else
				printf("%.2f not in the tree.\n", key);
			break;
		case'6':
			while (1){
				printf("\nenter k:\n");
				scanf("%d", &k);
				if (k > cnt || cnt == 0) {
					printf("\nerror enter new k.\n");
				}
				else {
					PrintKmax(root, &k);
					break;
				}
			}
			break;
		case'7':
			empty_tree(&root);
			exit(1);
		}

	}
}