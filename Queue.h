#pragma once

#include <vector>
#include <iostream>

using namespace std;


class Queue //очередь
{
	std::vector<string> queue;
	int frnt, rear;
public:
	Queue();
	~Queue();
	void push(string num); // Помещение элемента в очередь
	void out(); // Вывод элементов очереди
	int size(); // Определение размера очереди
	string pop(); // Извлечение элемента из очереди 
	string front(); // Первый элемент очереди
	string back();  // Последний элемент очереди
	void push_front(string value); // добавляет элемент в начало 
	void push_fron(string value); //вставляет элемент в начало очереди
	bool empty(); // проверяет пустая ли очередь
};



