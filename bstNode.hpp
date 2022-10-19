/*
 * bstNode.hpp
 *
 *  Created on: Oct 11, 2022
 *      Author: Rachel Robins and Jon O'Connell
 */

#ifndef BSTNODE_HPP_
#define BSTNODE_HPP_

#include "Student.hpp"
using namespace std;

class bstNode {
	friend class bst;
	bstNode *left;
	bstNode *right;
	bstNode *parent;
	int height;
	Student *student;
public:
	bstNode();
	bstNode(string firstName, string lastName, int favNum, string joke);
	~bstNode();
	void printNode();
};

#endif /* BSTNODE_HPP_ */
