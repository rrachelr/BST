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
	root = new bstNode(f, l, n, j);
}

bool bst::insert(string f, string l, int n, string j){
	bstNode *node = new bstNode(f, l, n, j);
	bstNode *curr = root;
	if (root == NULL){
		root = node;
		cout <<"set root node to " << root->student->last<<endl;
		return true;
	} else {
		while (curr != NULL){
			if (node->student->last < curr->student->last){
				if (curr->left == NULL){
					curr->left = node;
					curr->left->parent = curr;
					setHeight(curr->left);
					cout <<"inserted left node " << curr->student->last <<endl;
					return true;
				}
				curr = curr->left;
			} else if (node->student->last > curr->student->last){
				if (curr->right == NULL){
					curr->right = node;
					curr->right->parent = curr;
					setHeight(curr->right);
					cout <<"inserted right node " << curr->student->last <<endl;
					return true;
				}
				curr = curr->right;
			} else if (node->student->first < curr->student->last){
				if (curr->left == NULL){
					curr->left = node;
					curr->left->parent = curr;
					setHeight(curr->left);
					cout <<"inserted left node " << curr->student->first <<endl;
					return true;
				}
				curr = curr->left;
			} else if (node->student->first > curr->student->first){
				if (curr->right == NULL){
					curr->right = node;
					curr->right->parent = curr;
					setHeight(curr->right);
					cout <<"inserted right node " << curr->student->first <<endl;
					return true;
				}
				curr = curr->right;
			} else {
				return false;
			}
		}
		return false;
	}
}

bstNode *bst::find(string l, string f){
	//bstNode *curr
	if (root == NULL){
		return NULL;
	} else {
		if (l == root->student->last){
			if (f == root->student->first){
				return root;
			}
			return find(root->right->student->last, root->right->student->first);
		}
		if (l < root->student->last){
			return find(root->left->student->last, root->left->student->first);
		}
		if (l > root->student->last){
			return find(root->right->student->last, root->right->student->first);
		}
		return NULL;
	}

}


bstNode *bst::removeNoKids(bstNode *tmp){
	tmp->parent = NULL;
	delete tmp;
	return tmp;
}

bstNode *bst::removeOneKid(bstNode *tmp, bool leftFlag){
	if (leftFlag == true){
		tmp->parent = tmp->left;
	} else {
		tmp->parent = tmp->right;
	}
	delete tmp;
	return tmp;
}

bstNode *bst::remove(string f, string l){
	bstNode *n = find(l, f);
	if (n->left == NULL && n->right == NULL){
		n = removeNoKids(n);
	} else if (n->left != NULL && n->right == NULL){
		n = removeOneKid(n, true);
	} else if (n->left == NULL && n->right != NULL){
		n = removeOneKid(n, false);
	} else {
		n = n->left;
		while (n && n->right != NULL){
			n = n->right;
		}
		if (n->left == NULL && n->right == NULL){
			n = removeNoKids(n);
		} else if (n->left != NULL && n->right == NULL){
			n = removeOneKid(n, true);
		} else if (n->left == NULL && n->right != NULL){
			n = removeOneKid(n, false);
		}
	}
	return n;
}

void bst::setHeight(bstNode *n){
	n->height = 1;
	while ((n->parent != NULL) && (n->height == n->parent->height)){
		n->parent->height = n->height + 1;
		n = n->parent;
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
		cout << "Empty Tree" << endl; }
	else {
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


void bst::printTreeIO(bstNode *n) { // Just the start – you must write the recursive version
	if (n == NULL ) {
		return;
	} else {
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void bst::printTreePre(bstNode *n) {
	if (n == NULL ) {
		return;
	} else {
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void bst::printTreePost(bstNode *n) {
	if (n == NULL ) {
		return;
	} else {
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}







