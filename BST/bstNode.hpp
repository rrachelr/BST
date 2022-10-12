/*
 * bstNode.hpp
 *
 *  Created on: Oct 11, 2022
 *      Author: rachelrobins
 */

#ifndef BSTNODE_HPP_
#define BSTNODE_HPP_

#include <iostream>
#include <stdlib.h>
#include <Student.hpp>

class bstNode {
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
