#include "Node.h"



Node::Node()
{
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

Node::~Node()
{
	
}


bool Node::isNumber()
{
	string buf = this->value;
	if (is_ident(buf[0]) || is_ident(buf[1])) return 1;
	else return 0;
}