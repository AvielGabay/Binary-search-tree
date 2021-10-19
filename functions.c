#include "header.h"

typedef struct Tree /*struct definition*/
{
	void* key;
	struct Tree* L;
	struct Tree* R;
}Tree;

int AddToTree(Ptree* tree, void* key, CompareType CompareFunc, FILE* out) /*function definition*/
{
	int check;
	if (*tree == NULL) /*If the tree is empty*/
	{
		*tree = CreateNode(key, out); /*call function, to create new node*/
		return 1;
	}
	else
		if (CompareFunc((*tree)->key, key) == 1) /*if (*tree)->key is bigger then key*/
			AddToTree(&(*tree)->L, key, CompareFunc, out); /*function call, and advanced left in the tree*/
		else if (CompareFunc((*tree)->key, key) == -1) /*if (*tree)->key is less then key*/
			AddToTree(&(*tree)->R, key, CompareFunc, out); /*function call, and advanced right in the tree */
		else if (CompareFunc((*tree)->key, key) == 0) /*if (*tree)->key is equal to key*/
			return 0; /*return 0*/
}

Ptree CreateNode(void* key, FILE* out) /*function definition*/
{
	Ptree New;
	New = (Ptree)malloc(sizeof(struct Tree)); /*Dynamic memory allocation*/
	if (New == NULL) /*if Dynamic memory allocation failed*/
	{
		DeleteType(New);
		Error_Msg("Error!"); /*function call, to print Error message*/
	}
	New->key = key;
	New->L = NULL;
	New->R = NULL;
	return New; /*return the new node*/
}

void PrintInOrder(Ptree tree, PrintType PrintFunc, FILE* out) /*function definition*/
{
	if (tree == NULL) /*If the tree is empty*/
		return;
	PrintInOrder(tree->L, PrintFunc, out); /*recursive function call, and advanced left in the tree*/
	PrintFunc(tree->key, out, 3); /*function call, to print InOrder tree*/
	PrintInOrder(tree->R, PrintFunc, out); /*recursive function call, and advanced right in the tree*/
}

int HeightTree(Ptree tree) /*function definition*/
{
	if (tree == NULL) /*if the tree is empty*/
		return -1; /*return -1*/
	else
	{
		int leftsubtree = HeightTree(tree->L); /*recursive function call*/
		int rightsubtree = HeightTree(tree->R); /*recursive function call*/
		return Max(leftsubtree, rightsubtree) + 1; /*Max will return the maximum value, and add 1*/
	}
}

void Maximum(Ptree tree, PrintType PrintFunc, FILE* out) /*function definition*/
{
	while (tree->R) /*while tree->R is not NULL*/
		tree = tree->R; /*advanced right in tree*/
	PrintFunc(tree->key, out, 5); /*function call, to print the Maximum key in the tree*/
}

void Minimum(Ptree tree, PrintType PrintFunc, int* Value, FILE* out) /*function definition*/
{
	if (tree == NULL) /*if the tree is empty*/
		return;
	Minimum(tree->L, PrintFunc, Value, out); /*recursive function call, advanced left in the tree*/
	if (*Value > 0) /*if Value is bigger then 0*/
	{
		PrintFunc(tree->key, out, 6); /*function call*/
		(*Value)--; /* (*value) = (*value)-1* */
	}
	Minimum(tree->R, PrintFunc, Value, out); /*recursive function call, advanced right in the tree*/
}

void DeleteTree(Ptree* tree, DeleteType DeleteFunc) /*function definition*/
{
	if ((*tree) != NULL) /*if the tree is not empty*/
	{
		DeleteTree(&(*tree)->L, DeleteFunc); /*recursive function call with the left side of the tree*/
		DeleteTree(&(*tree)->R, DeleteFunc); /*recursive function call with the right side of the tree*/
		DeleteFunc((*tree)->key); /*function call, to do casting and free memory*/
		free((*tree)); /*free the allocated memory*/
		(*tree) = NULL;
	}
}

void Error_Msg(char* msg) /*function definition*/
{
	printf("\n%s", msg); /*print Error message*/
	exit(1); /*finish the program*/
}