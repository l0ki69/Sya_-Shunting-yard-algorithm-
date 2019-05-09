#pragma once

#include <iostream>


using namespace std;


class Node
{
public:
	string value;
	Node* left;
	Node* rigth;

	Node& operator = (Node& rhs);
	Node();
	~Node();
};




