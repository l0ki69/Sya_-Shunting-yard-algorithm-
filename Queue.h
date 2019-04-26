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
	void push_front(char value); // добавляет элемент в начало 
	void push_fron(char value); //вставляет элемент в начало очереди
	bool empty(); // проверяет пустая ли очередь
	bool oper(); // проверяет из чего состоит очередь, если из цифр то вернет 1 иначе 0
};



