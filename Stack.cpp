#include "Stack.h"


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
