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

typedef struct Token 
{
	string token;
	int val;
	void push(string token, int val)
	{
		this->token = token;
		this->val = val;
	}
};

typedef struct Tree
{
	Tree* l;
	Tree* r;
	string val;
	void clear() 
	{
		this->l = NULL;
		this->r = NULL;
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
				if ((c.token != "^") && (pop1(stack) != '^'))
				while (priority(' ',c.token) <= priority(pop1(stack),""))
				{
					//out(stack);
					st.clear();
					st += pop(stack);
					queue.push(st);
					st.clear();
				}
				push(stack,c.token[0]);
			}
			else
			{
				if (c.token == "(")
				{
					char ch = c.token[0];
					push(stack, ch);
				}
				else if (c.token == ")")
				{
					string st;
					while (pop1(stack) != '(')
					{
						st += pop(stack);
						queue.push(st);
						st.clear();
						if (size(stack) == 0)
						{
							cout << "Ошибка балансировки скобок";
							system("pause>NULL");
							return;
						}
					}
					pop(stack);
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

bool empty(vector <string>& tree)
{
	for (int i = 0; i < tree.size(); i++)
	{
		if (tree[i] != "") return 0;
	}
	return 1;
}

void Print(Tree& ast)
{
	if (ast.l != NULL) Print(*ast.l);
	if (ast.r != NULL) Print(*ast.r);
	cout << ast.val.c_str() << "     ";
	//cout << (ast.l)->val.c_str() << "          " << (ast.r)->val.c_str() << endl;
}

void AST(Queue queue, Stack* stack)
{
	vector <string> tree;
	int size = queue.size();
	for (int i = 0; i < size; i++)
	{
		tree.push_back(queue.pop());
	}
	vector <Tree> ast;
	ast.reserve(tree.size());
	int k = 0; //счетчик
	Tree a;
	int m = 0;
	
	for (int i = 0; i < tree.size(); i++)
	{
		if ((!is_operator(tree[i][0])) && (!is_operator(tree[i+1][0])))
		{
			a.l = NULL;
			a.r = NULL;
			a.val = tree[i];
			ast.push_back(a);
			i++;
			a.val = tree[i];
			ast.push_back(a);
			k++;
		}
	}
	for (int i = 0; i < tree.size()-2; i++)
	{
		if ((!is_operator(tree[i][0])) && (!is_operator(tree[i + 1][0])) && (is_operator(tree[i + 2][0])))
		{
			a.clear();
			if (k > 0)
			{
				a.l = &ast[m];
				a.r = &ast[m + 1];
				a.val = tree[i + 2];
				tree[i] = "";
				tree[i + 1] = "";
				tree[i + 2] = "";
				ast.push_back(a);
				i += 2;
				m += 2;
				k--;
			}
		}
	}
	k = m/2;
	a.clear();
	while (!empty(tree))
	{
		for (int i = 0; i < tree.size(); i++)
		{
			if (is_operator(tree[i][0]))
			{
				a.clear();
				if (k > 0)
				{
					a.l = &ast[m];
					a.r = &ast[m + 1];
					a.val = tree[i];
					ast.push_back(a);
					tree[i] = "";
					m += 2;
					k -=2;
				}
				if (is_ident(tree[i - 1][0]))
				{
					if (i == tree.size() - 1)
					{
						a.l = NULL;
						a.r = NULL;
						a.val = tree[i - 1];
						tree[i - 1] = "";
						ast.push_back(a);
						a.l = &ast[m];
						a.r = &ast[m + 1];
						a.val = tree[i];
						ast.push_back(a);
						tree[i] = "";
					}
				}
			}
		}
	} 
	cout << "Tree = " << endl;
	for (int i = 0; i < tree.size(); i++)
	{
		cout << tree[i].c_str() << " ";
	}
	cout << endl;

	for (int i = 0; i < ast.size(); i++)
	{
		cout << "left = " << ast[i].l
			<< "     right = " << ast[i].r
			<< "     val = " << ast[i].val.c_str()
			<< "     addr =" << &ast[i];
		if (i != ast.size() - 1) cout << "     addr[i+1] - addr[i] =   " << (int)(&ast[i+1]) - (int)(&ast[i]);
		cout << endl;
	}

	cout << endl;

	Print(ast[ast.size() - 1]);

}



double Calculat(Queue queue)
{	
	bool q = true;
	int i = 0;
	while (q)
	{
		if ()
	}

	return 0;
}  


int main() 
{
	setlocale(LC_ALL, "Rus");
	string str;
	str = "(3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3)";
	//str = "1-2+3*5";
	//str = "2^3^2";

	Stack a;
	Stack *stack = &a;
	Queue queue;

	vector <Token> tokens;

	getting_tokens(str, tokens);
	system("pause");

	treatment(tokens,queue,stack);

	cout << endl;
	queue.out();
	out_end(stack);

	system("pause");

	//AST(queue, stack);

	//system("pause");

	cout << " res = " << Calculat(queue);

	del(stack);
	queue.~Queue();
	system("pause>NULL");
	return 0;
}