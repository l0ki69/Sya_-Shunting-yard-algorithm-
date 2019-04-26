#pragma once

#include <vector>
#include <iostream>

typedef struct Stack {
	std::vector<char> data;
}Stack_t;

void push(Stack_t *stack, const char value); // вставляет элемент на вверх
char pop(Stack_t *stack); // возвращает и  удаляет верхний элемент
char peek(const Stack_t *stack); // возвращает последний элемент
int size(const Stack_t *stack); // возвращает кол-во элементов в стеке
char pop1(Stack_t *stack); // возвращает верхний элемент
void out_end(Stack_t *stack); // выводит стек и очищает его
void out(Stack_t *stack); // выводит стек
void del(Stack_t *stack); //удаление стека