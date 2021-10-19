#ifndef HW4
#define HW4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Max(a,b) ((a) > (b)? (a): (b)) 

typedef struct Tree* Ptree; /*Ptree pointer to Tree*/

typedef int (*CompareType)(void*, void*); 
/*Specific comparison function
function name: ComaprType
input: 2 pointers of void*
output: Return 1/0/-1 ,depending on the outcome*/

typedef void (*PrintType)(void*, FILE* out, int number); 
/*Specific print function
function name: PrintType
input: 1 pointer of void*, 1 pointer of FILE*, 1 integer number
output: Correct string printing, casting accordingly*/

typedef void (*DeleteType)(void*);
/*Specific delete function
function name: DeleteType
input: 1 pointer of void*
output: do casting to int, free memory*/

Ptree CreateNode(void* key, FILE* out);
/*function declaration
function name: CreateNode
input: 1 pointer of void*, 1 pointer of FILE*
output: Creates a node, and returns a pointer to a node */

int AddToTree(Ptree* tree, void* key, CompareType, FILE* out);
/*function declaration
function name: AddToTree
input: 1 pointer of Ptree*, 1 pointer of void*, 1 function, 1 pointer of FILE*
output: Return 1/0 ,depending on the outcome*/

void PrintInOrder(Ptree tree, PrintType, FILE* out);
/*function declaration
function name: PrintInOrder
input: 1 pointer of Ptree, 1 function, 1 pointer of FILE*
output: Print the tree in inorder type*/

int HeightTree(Ptree tree);
/*function declaration
function name: HeightTree
input: 1 pointer of Ptree
output: Returns the height of the tree*/

void Maximum(Ptree tree, PrintType, FILE* out);
/*function declaration
function name: Maximum
input: 1 pointer of Ptree, 1 function, 1 pointer of FILE*
output: Returns the key in the highest value*/

void Minimum(Ptree tree, PrintType, int* Value, FILE* out);
/*function declaration
function name: Minimum
input: 1 pointer of Ptree, 1 function, 1 pointer of int*, 1 pointer of FILE*
output: Returns the lowest keys, depending on the value number*/

void DeleteTree(Ptree* tree, DeleteType);
/*function declaration
function name: DeleteTree
input: 1 pointer of Ptree, 1 function
output: Free memory */

void Error_Msg(char* msg);
/*function declaration
function name: Error_Msg
input: 1 pointer of char* (string)
output: Print the string, and end the program*/

#endif HW4