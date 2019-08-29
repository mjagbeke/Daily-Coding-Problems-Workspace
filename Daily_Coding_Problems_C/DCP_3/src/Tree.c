/*
 * tree.c
 *
 *  Created on: Aug 19, 2019
 *      Author: julian_home
 */


#include "Tree.h"
#include <stdlib.h>
void addNode(struct Node* newNode, struct Node* currentNode){

	//add root
	if(currentNode == NULL){
		currentNode =  newNode;
	}

	//add Node if not root
	else{
		//less than current
		if(newNode->val < currentNode->val){
//			//check if next node is null
//			if(currentNode->left ==NULL){
//				//create new new node
//			}
			addNode(newNode, currentNode->left);
		}

		//greater than or equal to root
		else {
			if(newNode->val >= currentNode->val){
				addNode(newNode, currentNode->right);

			}

		}
	}
}


