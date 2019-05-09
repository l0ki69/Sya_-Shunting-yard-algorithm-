#pragma once

#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

typedef struct Stack*  pStack;
struct Stack
{
	pStack next;
	string data;
};

void push(pStack* stack, string value); // Вставляет элемент на верх
string pop(pStack* stack); // Удаляет верхний элемент и возвращает его
string top(pStack* stack); // Возвращает верхний элемент
bool empty(pStack* stack); // Проверяет отсутствие элементов в контейнере



typedef struct nStack*  pnStack;
struct nStack
{
	pnStack next;
	Node data;

	void push(pnStack* stack, Node value); // Вставляет элемент на верх
	Node pop(pnStack* stack); // Удаляет верхний элемент и возвращает его
	Node top(pnStack* stack); // Возвращает верхний элемент
	bool empty(pnStack* stack); // Проверяет отсутствие элементов в контейнере
};