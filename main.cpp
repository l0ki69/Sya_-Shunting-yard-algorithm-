#include <iostream>
#include <vector>
#include "Stack.h"
#include "Queue.h"

using namespace std;

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=')
#define is_ident(c) ((c >= '0' && c <= '9'))

Stack a;
Stack *stack = &a;
Queue queue;

class Calculator 
{
public:
	void RPN(); //Reverse Polish notation
	void AST(); // Abstract syntax tree
	void result(); 
};

class Node 
{
public:
	char value;
	Node* left;
	Node* rigth;

	Node(char value);
	~Node();
};

void treatment(const string str) //обработка 
{
	for (int i = 0; i < str.length(); i++) 
	{
		if is_operator(str[i]) push(stack, str[i]);
		if is_ident(str[i]) queue.push(str[i]);
	}
}

void check(const char c) //проверка
{
	if (c < 58) 
	{

	}
	else
	{
		switch(c) 
		{
			case '*': 
			case '/':
			case '%':
			case '+':
			case '-':
			case '=':
				break;
			//return c;
			default:
				break;
		}
	}
}





int main() 
{
	setlocale(LC_ALL, "Rus");
	string str = "1-2+3-4+5-6+7-8+9";

	treatment(str);

	cout << "Queue " << endl;
	queue.out();
	cout << "Stack " << endl;
	while (size(stack))
	{
		cout << pop(stack);
	}

	system("pause>NULL");
	return 0;
}