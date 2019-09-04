/*
 ============================================================================
 Name        : DCP_3.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Given the root to a binary tree, implement
 serialize(root), which serializes the tree into a string,
 and deserialize(s), which deserializes the string back into the tree.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

//create root struct

//create tree struct

struct Tree serialize(char* input){
	int newValue, currentValue;
	struct Tree tree ;

	struct Node* newNode, *currentNode;


	//loop through input and add to the tree

	//create nodes from values in input

	//check if first entry

	//add node to tree
	addNode(tree, newNode, currentNode);

	return tree;
}

char* deserialize(){
	char * string ;
	return string;
}

int main(void) {
	//call function to create and int pointer from argV (create library from DCP 1

	//call/create function to calculate the number of integers in a comma separated string
	parseInput();
	//create/read in string for serialization
	serialize("1,2,3,6,5,4");

	//create tree for deserialization
	printf("%s", deserialize(serialize("1,2,3,6,5,4")));

	return EXIT_SUCCESS;
}
