#include "Stack.h"
#include <iostream>


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

char pop1(Stack_t *stack) // возвращает верхний элемент
{
	return stack->data.back();
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

void out_end(Stack_t *stack) // выводит стек и очищает его
{
	std::cout << std::endl <<  "Stack " << std::endl;
	while (size(stack))
	{
		std::cout << pop(stack);
	}
}

void out(Stack_t *stack) // выводит стек
{
	std::cout << std::endl << "Stack " << std::endl;
	for (int i = 0; i < size(stack); i++)
	{
		std::cout << stack->data[i] << " ";
	}
	std::cout << std::endl;
}

void del(Stack_t *stack) //удаление стека
{
	stack->data.clear();
}