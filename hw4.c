#include "header.h"

int CompareInt(void* element1, void* element2) /*function definition*/
{
	if (*(int*)element1 > *(int*)element2)
		return 1;
	if (*(int*)element1 < *(int*)element2)
		return -1;
	return 0;
}

void PrintInt(void* key, FILE* out, int number) /*function definition*/
{
	if (number == 0)
		fprintf(out, "\n%d found in tree", *(int*)key);
	else if (number == 1)
		fprintf(out, "\n%d was added to the tree", *(int*)key);
	else if (number == 3)
		fprintf(out, "%d-->", *(int*)key);
	else if (number == 4)
		fprintf(out, "\nThe height of your tree is %d", *(int*)key);
	else if (number == 5)
		fprintf(out, "\nThe maximum is %d", *(int*)key);
	else if (number == 6)
		fprintf(out, "%d ", *(int*)key);
}

void DeleteInt(void* key) /*function definition*/
{
	free((int*)key); /*casting to integer, free memmory*/
}

int main()
{
	int temp, number, height, k, NumberOfNode=0;
	int* key, *Value;
	FILE* in, * out;
	Ptree TheTree = NULL;

	if ((in = fopen("Instructions.txt", "rt")) == NULL) /*in will get value from the file "Instructions.txt". in open the file to read*/
		Error_Msg("The file did not open"); /*function call, to print Error message and finish the program*/
	if ((out = fopen("output.txt", "w")) == NULL) /*out will get value from the file "output.txt". in open the file to write*/
		Error_Msg("The file did not open"); /*function call, to print Error message and finish the program*/

	while ((fscanf(in, "%d", &temp)) != EOF) /*while loop until fscanf is equal to EOF, temp will get the value from the digit in the file*/
	{
		if (temp == 1)
		{
			fscanf(in, "%d", &number);
			key = (int*)malloc(sizeof(int)); /*Dynamic memory allocation*/
			if (key == NULL) /*if Dynamic memory allocation failed*/
			{
				DeleteTree(&TheTree, DeleteInt);
				Error_Msg("Error!"); /*function call, to print Error message*/
			}
			*key = number; 
			if (AddToTree(&TheTree, key, CompareInt, out) == 1) /*If we were able to add a node to a tree*/
			{
				PrintInt(key, out, 1); /*function call to print a message*/
				NumberOfNode++; /*NumberOfNode = NumberOfNode + 1*/
			}
			else /*If we were unable to add a node to a tree*/
				PrintInt(key, out, 0); /*function call to print a message*/
		}
		else if (temp == 2)
		{
			fprintf(out, "\nInorder tree:  ");
			PrintInOrder(TheTree, PrintInt, out); /*function call to print InOrder tree*/
		}
		else if (temp == 3)
		{
			height = HeightTree(TheTree); /*function call, height recived return value from the function*/
			PrintInt(&height, out, 4); /*function call to print a message*/
		}
		else if (temp == 4)
		{
			Maximum(TheTree, PrintInt, out); /*function call, to find and print Maximum key in the tree*/
		}
		else if (temp == 5)
		{
			fscanf(in, "%d", &k);
			if (k > NumberOfNode) /*if k is bigger then NumberOfNode*/
				fprintf(out, "\nThere are no %d elements in this tree", k); /*print Error message*/
			else
			{
				fprintf(out, "\nThere are %d small elements in this tree:", k);
				Value = (int*)malloc(sizeof(int)); /*Dynamic memory allocation*/
				if (Value == NULL) /*if Dynamic memory allocation failed*/
				{
					DeleteTree(&TheTree, DeleteInt);
					Error_Msg("Error!"); /*function call, to print Error message*/
				}
				*Value = k;
				Minimum(TheTree, PrintInt, Value, out); /*function call, to find and print Minimum accordingly to k*/
			}
		}
	}
	DeleteTree(&TheTree, DeleteInt); /*function call, to free memory*/
	fclose(in); /*fclose have to come after fopen*/
	fclose(out);  /*fclose have to come after fopen*/
	return 0;
}