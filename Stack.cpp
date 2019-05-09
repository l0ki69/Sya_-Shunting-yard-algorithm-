#include "Stack.h"
#include <iostream>

using namespace std;


void push(pStack* stack, string value)
{
	pStack newp = new Stack;
	newp->data = value;
	newp->next = *stack;
	*stack = newp;
}

string pop(pStack* stack)
{
	string buf = (*stack)->data;
	pStack p = (*stack)->next;
	delete *stack;
	*stack = p;
	return buf;
}

string top(pStack* stack)
{
	return (*stack)->data;
}

bool empty(pStack* stack)
{
	if ((*stack) == NULL) return 1;
	else return 0;
}


void nStack::push(pnStack* stack, Node value)
{
	pnStack newp = new nStack;
	newp->data = value;
	newp->next = *stack;
	*stack = newp;
}

Node* nStack::pop(pnStack* stack)
{
	Node* buf = new Node();
	buf = &(*stack)->data;
	pnStack p = (*stack)->next;
	//delete *stack;
	*stack = p;
	return buf;
}

Node nStack::top(pnStack* stack)
{
	return (*stack)->data;
}

bool nStack::empty(pnStack* stack)
{
	if ((*stack) == NULL) return 1;
	else return 0;
}
