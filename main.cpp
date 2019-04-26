#include <iostream>
#include <vector>
#include "Stack.h"
#include "Queue.h"

using namespace std;

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
#define is_ident(c) ((c >= '0') && (c <= '9'))

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

int pow(int value, int n)
{
	int res = 1;
	for (int i = 0; i < n; i++) {
		res *= value;
	}
	return res;
}

int priority(char c)
{
	switch (c)
	{
	case '*': return 2;
	case '/': return 2;
	case '+': return 1;
	case '-': return 1;
	case '^': return 3;
	case '(': return -1;
	case ')': return 10;
	}
	return 0;
}

void treatment(const string str) //обработка 
{
	char c;
	for (int i = 0; i < str.length(); i++) 
	{
		c = str[i];
		if (c == ' ') continue;
		if is_ident(c)
		{
			queue.push(c);
		}
		else
		{
			if is_operator(c)
			{
				if (c == '^')
				{
				//	queue.out();
					//out(stack);
				}
				while (priority(c) <= priority(pop1(stack)))
				{
					queue.push(pop(stack));
				}
				push(stack, c);
			}
			else
			{
				if (c == '(') push(stack, c);
				else if (c == ')')
				{
					while (pop1(stack) != '(')
					{
						//cout << "pop1 = " << pop1(stack) << endl;
						queue.push(pop(stack));
						if (size(stack) == 0)
						{
							cout << "Ошибка балансировки скобок";
							system("pause>NULL");
							exit(0);
						}
					}
					pop(stack);
				}
				else
				{
					cout << "Ошибка: неопознаный токен ";
					cout << c;
					system("pause>NULL");
					exit(0);
				}
			}
		}
	}
}

double Calculat()
{
	int res = 0;
	int buf = 0;
	char c;
	while (!queue.oper())
	{
		cout << "--------------" << endl;
		queue.out();
		c = queue.front();
		cout << "c = " << c << endl;
		queue.pop();
		queue.out();
		if is_ident(c) push(stack, c);
		else
		{	
			cout << "operator" << endl;
			out(stack);
			if (c == '+') buf = (int)(pop(stack) - 48) + (int)(pop(stack) - 48);
			if (c == '-') buf = (int)(pop(stack) - 48) - (int)(pop(stack) - 48);
			if (c == '*') buf = (int)(pop(stack) - 48) * (int)(pop(stack) - 48);
			if (c == '/') buf = (int)(pop(stack) - 48) / (int)(pop(stack) - 48);
			if (c == '^') buf = pow((int)(pop(stack) - 48),(int)(pop(stack) - 48));
			cout << "buf = " << buf << endl;
			if (buf <10 ) queue.push_fron((char)(buf+48));
			else while (buf != 0)
			{
				queue.push_fron((char)((buf % 10) + 48));
				buf /= 10;
			}
		}
		buf = 0;
		cout << "--------------" << endl;
	}
	cout << "--------------------------------------------------------" << endl;
	while (!queue.empty())
	{
		cout << "res = " << res << endl;
		res += (int)(queue.front()-48)*pow(10, queue.size()-1);
		queue.pop();
	}
	return res;
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
	string str;
	//str = "(3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3)";
	str = "(9+2+3)";

	treatment(str);
	cout << endl;
	queue.out();
	out_end(stack);

	system("pause");

	cout << " res = " << Calculat();

	del(stack);
	queue.~Queue();
	system("pause>NULL");
	return 0;
}