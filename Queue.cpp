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
	cout << "Queue" << endl;
	for (int i = frnt; i < rear ; i++)
		cout << queue[i].c_str() << " ";
	cout << endl;
}

void Queue::push(string num) // ��������� �������� � �������
{
	rear++;
	queue.push_back(num);
}


string Queue::pop() // ���������� �������� �� ������� 
{
	//cout << "queue pop" << endl;
	if (frnt == rear) {
		cout << "queue is full" << endl;
		return "";
	}
	if (frnt == queue.size()) frnt = 0;
	frnt++;
	return queue[frnt-1];
}

int Queue::size() //����������� ������� �������
{
	int s = 0;
	for (int i = frnt; i < rear; i++)
		s++;
	return s;
}


string Queue::back() // ��������� ������� �������
{
	return queue[rear-1];
}

string Queue::front() // ������ ������� �������
{
	return queue[frnt];
}

void Queue::push_front(string value) //��������� ������� � ������ �������
{
	vector<string> buf;
	int size = queue.size();
	buf.push_back(value);
	for (int i = frnt; i < rear; i++)
	{
		buf.push_back(queue[i]);
		//cout << queue[i] << " ";
	}
	queue.swap(buf);
}

void Queue::push_fron(string value)  //��������� ������� � ������ �������
{
	frnt--;
	queue[frnt] = value;
	//this->out();
}

bool Queue::empty() // ��������� ������ �� �������
{
	if (frnt == rear) return 1;
	return 0;
}
