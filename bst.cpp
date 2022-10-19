/*
 * bst.cpp
 *
 *  Created on: Oct 11, 2022
 *      Author: Rachel Robins and Jon O'Connell
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
		return true;
	} else {
		while (curr != NULL){
			if (node->student->last < curr->student->last){
				if (curr->left == NULL){
					curr->left = node;
					curr->left->parent = curr;
					setHeight(curr->left);
					return true;
				}
				curr = curr->left;
			} else if (node->student->last > curr->student->last){
				if (curr->right == NULL){
					curr->right = node;
					curr->right->parent = curr;
					setHeight(curr->right);
					return true;
				}
				curr = curr->right;
			} else if (node->student->first < curr->student->first){
				if (curr->left == NULL){
					curr->left = node;
					curr->left->parent = curr;
					setHeight(curr->left);
					return true;
				}
				curr = curr->left;
			} else if (node->student->first > curr->student->first){
				if (curr->right == NULL){
					curr->right = node;
					curr->right->parent = curr;
					setHeight(curr->right);
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
	bstNode *curr = root;
	int count = 0;
	if (root == NULL){
		return NULL;
	} else {
		while (curr != NULL){
			if (l < curr->student->last){
				curr = curr->left;
				count++;
			} else if (l > curr->student->last){
				curr = curr->right;
				count++;
			} else if (l == curr->student->last){
				if (f == curr->student->first){
					curr->printNode();
					count++;
					cout<<"found in " << count << " comparisons" <<endl;
					return curr;
				} else {
					curr = curr->left;
					count++;
				}
			}
		}
	}
	return NULL;
}


bstNode *bst::removeNoKids(bstNode *tmp){
	if (tmp->parent->left == tmp){
		tmp->parent->left = NULL;
	} else {
		tmp->parent->right = NULL;
	}
	delete tmp;
	return tmp;
}

bstNode *bst::removeOneKid(bstNode *tmp, bool leftFlag){
	if (leftFlag == true){
		if (tmp->parent->left == tmp){
			tmp->parent->left = tmp->left;
			tmp->left->parent = tmp->parent;
		} else {
			tmp->parent->right = tmp->left;
			tmp->left->parent = tmp->parent;
		}
		setHeight(tmp->left);
	} else {
		if (tmp->parent->right == tmp) {
			tmp->parent->right = tmp->right;
			tmp->right->parent = tmp->parent;
		} else {
			tmp->parent->left = tmp->right;
			tmp->right->parent = tmp->parent;
		}
		setHeight(tmp->right);
	}
	delete tmp;
	return tmp;
}

bstNode *bst::remove(string l, string f){
	bstNode *curr = find(l, f);
	if ((curr->left == NULL) && (curr->right == NULL)){
		return removeNoKids(curr);
	} else if ((curr->left == NULL)&&(curr->right !=NULL )) {
		return removeOneKid(curr, false);
	} else if ((curr->left != NULL)&&(curr->right == NULL)) {
		return removeOneKid(curr, true);
	} else if ((curr->left != NULL) && (curr->right != NULL)){
		bstNode *n = curr;
		curr = curr->left;
		while(curr->right != NULL){
			curr = curr->right;
		}
		bstNode *n2 = curr;
		n->student->last = n2->student->last;
		n->student->first = n2->student->first;
		n->student->fav_num = n2->student->fav_num;
		n->student->joke = n2->student->joke;
		if(n2->left == NULL && n2->right == NULL){
			removeNoKids(n2);
		}
		else if(n2->left == NULL and n2->right != NULL){
			removeOneKid(n2,false);
		}
		else if(n2->left != NULL and n2->right == NULL){
			removeOneKid(n2,true);
		}


	}
	return curr;
}

void bst::setHeight(bstNode *n){
	n->height = 1;
	while (n->parent != NULL){
		if (n->parent->left != NULL && n->parent->right != NULL){
			if (n->parent->left->height == n->parent->right->height){
				n->parent->height = n->height + 1;
				n = n->parent;
			} else if (n->parent->left->height > n->parent->right->height){
				n->parent->height = n->parent->left->height + 1;
				n = n->parent;
			} else {
				n->parent->height = n->parent->right->height + 1;
				n = n->parent;
			}
		} else {
			n->parent->height = n->height + 1;
			n = n->parent;
		}
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


