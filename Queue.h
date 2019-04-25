#pragma once

#include <vector>
#include <iostream>

using namespace std;


class Queue //очередь
{
	std::vector<char> queue;
	int frnt, rear;
public:
	Queue();
	~Queue();
	void push(char num); // Помещение элемента в очередь
	void out(); // Вывод элементов очереди
	int size(); // Определение размера очереди
	void pop(); // Извлечение элемента из очереди 
	char front(); // Первый элемент очереди
	char back();  // Последний элемент очереди
	
};



