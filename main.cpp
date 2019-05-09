#include <iostream>
#include <vector>
#include "Stack.h"
#include "Queue.h"

using namespace std;

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
#define is_ident(c) ((c >= '0') && (c <= '9'))

class Calculator 
{
public:
	void RPN(); //Reverse Polish notation
	void AST(Queue queue, Stack* stack); // Abstract syntax tree
	void result(); 
};



int pow(int value, int n)
{
	int res = 1;
	for (int i = 0; i < n; i++) {
		res *= value;
	}
	return res;
}

int priority(char c, string str)
{
	if (c == ' ') c = str[0];

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

struct Token 
{
	string token;
	int val;
	void push(string token, int val)
	{
		this->token = token;
		this->val = val;
	}
};

struct Tree
{
	Tree* l;
	Tree* r;
	string val;
	Tree* par;
	void clear() 
	{
		this->l = NULL;
		this->r = NULL;
		this->par = NULL;
		this->val.clear();
	}
};

void getting_tokens(string str, vector <Token>& tokens) //получение токенов
{	
	Token tok;
	tok.token = "(";
	tok.val = 3;
	tokens.push_back(tok);
	//str = "-5-(-4-1)-1";
	//str = "-1-(-3+2)+1*2-2*(2-1)";
	string buf;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') continue;
		buf += str[i];
	}
	str = buf;
	cout << str.c_str() << endl;

	string token;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ')')
		{
			tok.push(")", 2);
			tokens.push_back(tok);
			if (str[i + 1] == '-')
			{
				i++;
				tok.push("-", 0);
				tokens.push_back(tok);
			}
			continue;
		}

		if (str[i] == '(')
		{
			tok.push("(", 2);
			tokens.push_back(tok);
			if (str[i + 1] == '-')
			{
				i++;
				token += str[i];
				i++;
				while (is_ident(str[i]))
				{
					token += str[i];
					i++;
				}
				i--;
				tok.push(token, 1);
				tokens.push_back(tok);
				token.clear();
			} 
			continue;
		}

		if (str[i] == '-')
		{
			if (i == 0)
			{
				token.clear();
				token += str[i];
				i++;
				while (is_ident(str[i]))
				{
					token += str[i];
					i++;
				}
				i--;
				tok.push(token, 1);
				tokens.push_back(tok);
				token.clear();
				continue;

			} else
			if (is_ident(str[i - 1]) && is_ident(str[i + 1]))
			{
				tok.push("+", 0);
				tokens.push_back(tok);
				token.clear();
				token += str[i];
				i++;
				while (is_ident(str[i]))
				{
					token += str[i];
					i++;
				}
				i--;
				tok.push(token, 1);
				tokens.push_back(tok);
				token.clear();
				continue;
			}  else 
			if (str[i+1] == '(')
			{
				tok.push("-", 0);
				tokens.push_back(tok);
				continue;
			}
		} else
		if (is_operator(str[i]))
		{
			token += str[i];
			tok.token = token;
			tok.val = 0;
		}
		else
		{
			while (is_ident(str[i]))
			{
				token += str[i];
				i++;
			}
			i--;
			tok.token = token;
			tok.val = 1;
		}
		if (token != "") tokens.push_back(tok);
		token.clear();
	}
	tok.token = ")";
	tok.val = 3;
	tokens.push_back(tok);
	for (int i = 0; i < tokens.size(); i++)
	{
		cout << tokens[i].token.c_str() << "                     " << tokens[i].val << endl;
	}
}

void treatment(vector <Token> tokens,Queue& queue,Stack* stack) //обработка 
{
	Token c;
	for (int i = 0; i < tokens.size(); i++) 
	{
		c = tokens[i];

		if (c.val == 1)
		{
			queue.push(c.token);
		}
		else
		{
			if (c.val == 0)
			{
				string st;
				if ((c.token != "^") && (top(&stack)[0] != '^'))
				while (priority(' ',c.token) <= priority(top(&stack)[0],""))
				{
					//out(stack);
					st.clear();
					st += pop(&stack);
					queue.push(st);
					st.clear();
				}
				push(&stack,c.token);
			}
			else
			{
				if (c.token == "(")
				{
					//char ch = c.token[0];
					push(&stack, c.token);
				}
				else if (c.token == ")")
				{
					string st;
					while (top(&stack)[0] != '(')
					{
						st += pop(&stack);
						queue.push(st);
						st.clear();
						if (empty(&stack))
						{
							cout << "Ошибка балансировки скобок";
							system("pause>NULL");
							return;
						}
					}
					pop(&stack);
				}
				else
				{
					cout << "Ошибка: неопознаный токен ";
					cout << c.token.c_str();
					system("pause>NULL");
					return;
				}
			}
		}
	}
}


void Print(Node* node)
{
	cout << node->value.c_str() << "  left =  " << node->left << "  rigth  "  << node->rigth << "  addr =  " << &(node->value) << endl;
	if (node->left != NULL ) Print(node->left);
	if (node->rigth != NULL) Print(node->rigth);
}



void AST(Queue queue)
{
	vector <string> tree;
	pnStack stack = NULL;

	int size = queue.size();

	for (int i = 0; i < size; i++)
	{
		tree.push_back(queue.pop());
	}

	Node ast;


	for (int i = 0; i < size; i++)
	{
		if (is_ident(tree[i][0]) || is_ident(tree[i][1]))
		{
			Node* newNode = new Node();
			newNode->value = tree[i];

			stack->push(&stack, *newNode);
			continue;
		}
		if (is_operator(tree[i][0]))
		{
			Node* newNode = new Node();
			newNode->value = tree[i];

			newNode->left = new Node();
			newNode->left = ((*stack).pop(&stack));

			newNode->rigth = new Node();
			newNode->rigth = ((*stack).pop(&stack));

			stack->push(&stack, *newNode);
		}
	}
	
	Print((*stack).pop(&stack));

}



double Calculat(Queue queue)
{	
	bool q = true;
	int i = 0;
	while (q)
	{
	//	if ()
		return 0;
	}

	return 0;
}  


int main() 
{
	setlocale(LC_ALL, "Rus");
	string str;
	//str = "(3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3)";
	//str = "1+2+3";
	//str = "2^3^2";
	str = "1+2*3-6";

	pStack stack = NULL;
	Queue queue;

	vector <Token> tokens;

	getting_tokens(str, tokens);
	system("pause");

	treatment(tokens,queue,stack);

	cout << endl;
	queue.out();

	system("pause");

	AST(queue);

	//system("pause");

	cout << " res = " << Calculat(queue);

	queue.~Queue();
	system("pause>NULL");
	return 0;
}