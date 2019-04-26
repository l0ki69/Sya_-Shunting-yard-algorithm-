#include "Stack.h"
#include <iostream>


void push(Stack_t *stack, const char value) // ��������� ������� �� �����
{
	stack->data.push_back(value);
}

char pop(Stack_t *stack) // ���������� �  ������� ������� �������
{
	if (stack->data.size() == 0)
	{
		fputs("Error: stack is empty\n", stderr);
		abort();
	} 

	char buf = stack->data.back();
	stack->data.pop_back();
	return buf;
}

char pop1(Stack_t *stack) // ���������� ������� �������
{
	return stack->data.back();
}

char peek(const Stack_t *stack) // ���������� ��������� �������
{
	if (stack->data.size() == 0)
	{
		fputs( "Error: stack is empty\n", stderr );
	}
	return stack->data.back();
}

int size(const Stack_t *stack) // ���������� ���-�� ��������� � �����
{
	return stack->data.size();
}

void out_end(Stack_t *stack) // ������� ���� � ������� ���
{
	std::cout << std::endl <<  "Stack " << std::endl;
	while (size(stack))
	{
		std::cout << pop(stack);
	}
}

void out(Stack_t *stack) // ������� ����
{
	std::cout << std::endl << "Stack " << std::endl;
	for (int i = 0; i < size(stack); i++)
	{
		std::cout << stack->data[i] << " ";
	}
	std::cout << std::endl;
}

void del(Stack_t *stack) //�������� �����
{
	stack->data.clear();
}