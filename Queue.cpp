#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() 
{
	frnt = rear = 0;
}

Queue::~Queue() 
{
	queue.clear();
}

void Queue::out()  // Вывод элементов очереди
{
	cout << endl;
	for (int i = frnt; i < rear ; i++)
		cout << queue[i] << " ";
	cout << endl;
}

void Queue::push(char num) // Помещение элемента в очередь
{
	rear++;
	queue.push_back(num);
}


void Queue::pop() // Извлечение элемента из очереди 
{
	if (frnt == rear) {
		cout << "queue is full" << endl;
		return;
	}
	frnt++;
	if (frnt == queue.size()) frnt = 0;
}

int Queue::size() //Определение размера очереди
{
	int s = 0;
	for (int i = frnt; i < rear; i++)
		s++;
	return s;
}


char Queue::back() // Последний элемент очереди
{
	return queue[rear-1];
}

char Queue::front() // Первый элемент очереди
{
	return queue[frnt];
}