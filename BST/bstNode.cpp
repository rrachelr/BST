/*
 * bstNode.cpp
 *
 *  Created on: Oct 11, 2022
 *      Author: rachelrobins
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

