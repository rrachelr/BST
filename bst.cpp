/*
 * bst.cpp
 *
 *  Created on: Oct 11, 2022
 *      Author: Rachel Robins
 */


#include "bstNode.hpp"
#include "Student.hpp"
#include "bst.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

bst::bst() { // empty constructor
	root = NULL;
}

bst::bst(string f, string l, int n, string j) { // constructor that forms the root
	root = new bstNode( f,l, n, j);
}

bool insert(string f, string l, int n, string j){
	bstNode* node = new bstNode(f, l, n, j);
	bstNode* curr = bst::root;
	if (bst::root == NULL){
		bst::root = node;
		return true;
	}
	if (node->student->last < curr->student->last) {
		if (curr->left == NULL){
			curr->left = node;
			node->parent = curr;
			return true;
		}
		insert(f, l, n, j);
	}
}

void bst::clearTree() { //clears out an old tree
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	} else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

void bst::clearTree(bstNode *tmp) {
	if (tmp == NULL) {
		return;
	} else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}

void bst::printTreeIO() { // Just the start – you must write the recursive version
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	} else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

void bst::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	} else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void bst::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	} else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}







