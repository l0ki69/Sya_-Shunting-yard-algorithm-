#include "Node.h"



Node::Node()
{
	this->left = NULL;
	this->rigth = NULL;
}

Node::~Node()
{
	
}

Node& Node::operator= (Node& rhs) {
	if (&rhs == this) return *this;
	value = rhs.value;
	left = rhs.left;
	rigth = rhs.rigth;
	return *this;
}

/*Node* Node::ptr(pnStack stack, string val)
{
	Node* newNode = new Node;
	newNode->value = val;
	newNode->left = new Node();
	newNode->left = &((*stack).pop(&stack));
	newNode->rigth = new Node();
	newNode->rigth = &((*stack).pop(&stack));
	return newNode;
}
*/