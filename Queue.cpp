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

void Queue::out()  // ����� ��������� �������
{
	cout << endl;
	for (int i = frnt; i < rear ; i++)
		cout << queue[i] << " ";
	cout << endl;
}

void Queue::push(char num) // ��������� �������� � �������
{
	rear++;
	queue.push_back(num);
}


void Queue::pop() // ���������� �������� �� ������� 
{
	if (frnt == rear) {
		cout << "queue is full" << endl;
		return;
	}
	frnt++;
	if (frnt == queue.size()) frnt = 0;
}

int Queue::size() //����������� ������� �������
{
	int s = 0;
	for (int i = frnt; i < rear; i++)
		s++;
	return s;
}


char Queue::back() // ��������� ������� �������
{
	return queue[rear-1];
}

char Queue::front() // ������ ������� �������
{
	return queue[frnt];
}