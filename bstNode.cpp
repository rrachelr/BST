/*
 * bstNode.cpp
 *
 *  Created on: Oct 11, 2022
 *      Author: Rachel Robins
 */

#include <stdlib.h>
#include <iostream>
#include "bstNode.hpp"
#include "Student.hpp"
using namespace std;

bstNode::bstNode(){
	left = NULL;
	right = NULL;
	parent = NULL;
	student = NULL;
	height = 0;
}

bstNode::bstNode(string firstName, string lastName, int favNum, string joke){
	student = new Student(firstName, lastName, favNum, joke);
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
}

bstNode::~bstNode(){

}

void printNode(){
	bstNode *n = new bstNode();
	n->left;
	n->right;
	cout << "Height of node: " << n->left << ", Name: " << n->right << endl;
}
