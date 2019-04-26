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
	//cout << "queue out" << endl;
	cout << "Queue" << endl;
	cout << "front = " << frnt << "  rear  = " << rear << endl;
	for (int i = frnt; i < rear ; i++)
		cout << queue[i];
	cout << endl;
	//cout << "queue out end" << endl;
}

void Queue::push(char num) // ��������� �������� � �������
{
	rear++;
	queue.push_back(num);
}


void Queue::pop() // ���������� �������� �� ������� 
{
	cout << "queue pop" << endl;
	if (frnt == rear) {
		cout << "queue is full" << endl;
		return;
	}
	if (frnt == queue.size()) frnt = 0;
	frnt++;
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

void Queue::push_front(char value) //��������� ������� � ������ �������
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

void Queue::push_fron(char value)  //��������� ������� � ������ �������
{
	frnt--;
	queue[frnt] = value;
	this->out();
}

bool Queue::empty() // ��������� ������ �� �������
{
	if (frnt == rear) return 1;
	return 0;
}

bool Queue::oper() // ��������� �� ���� ������� �������, ���� �� ���� �� ������ 1 ����� 0
{
	int k = 0;
	for (int i = frnt; i < rear; i++)
	{
		if ((queue[i] < 58) && (queue[i] > 47)) k++;
		else return 0;
	}
	if (k == this->size()) return 1;
}