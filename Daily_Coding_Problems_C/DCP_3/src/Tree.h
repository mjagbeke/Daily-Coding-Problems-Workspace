/*
 * Tree.h
 *
 *  Created on: Aug 14, 2019
 *      Author: julian_home
 */
#include "Node.h"

struct Tree{
	struct Node* root;
}tree;

void addNode(struct Node* newNode, struct Node* currentNode);
