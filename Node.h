#pragma once

#include <iostream>


using namespace std;

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
#define is_ident(c) ((c >= '0') && (c <= '9'))

class Node
{
public:
	string value;
	Node* left;
	Node* right;
	Node* parent;

	bool isNumber();
	Node();
	~Node();
};




