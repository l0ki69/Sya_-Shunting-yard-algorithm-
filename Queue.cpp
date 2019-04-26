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
	//cout << "queue out" << endl;
	cout << "Queue" << endl;
	cout << "front = " << frnt << "  rear  = " << rear << endl;
	for (int i = frnt; i < rear ; i++)
		cout << queue[i];
	cout << endl;
	//cout << "queue out end" << endl;
}

void Queue::push(char num) // Помещение элемента в очередь
{
	rear++;
	queue.push_back(num);
}


void Queue::pop() // Извлечение элемента из очереди 
{
	cout << "queue pop" << endl;
	if (frnt == rear) {
		cout << "queue is full" << endl;
		return;
	}
	if (frnt == queue.size()) frnt = 0;
	frnt++;
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

void Queue::push_front(char value) //вставляет элемент в начало очереди
{
	vector<char> buf;
	int size = queue.size();
	buf.push_back(value);
	for (int i = frnt; i < rear; i++)
	{
		buf.push_back(queue[i]);
		cout << queue[i] << " ";
	}
	queue.swap(buf);
}

void Queue::push_fron(char value)  //вставляет элемент в начало очереди
{
	frnt--;
	queue[frnt] = value;
	this->out();
}

bool Queue::empty() // проверяет пустая ли очередь
{
	if (frnt == rear) return 1;
	return 0;
}

bool Queue::oper() // проверяет из чего состоит очередь, если из цифр то вернет 1 иначе 0
{
	int k = 0;
	for (int i = frnt; i < rear; i++)
	{
		if ((queue[i] < 58) && (queue[i] > 47)) k++;
		else return 0;
	}
	if (k == this->size()) return 1;
}