#include "Stack.h"


void push(Stack_t *stack, const char value) // вставляет элемент на вверх
{
	stack->data.push_back(value);
}

char pop(Stack_t *stack) // возвращает и  удаляет верхний элемент
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

char peek(const Stack_t *stack) // возвращает последний элемент
{
	if (stack->data.size() == 0)
	{
		fputs( "Error: stack is empty\n", stderr );
	}
	return stack->data.back();
}

int size(const Stack_t *stack) // возвращает кол-во элементов в стеке
{
	return stack->data.size();
}
