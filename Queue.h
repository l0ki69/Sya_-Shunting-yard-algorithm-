#pragma once

#include <vector>
#include <iostream>

using namespace std;


class Queue //�������
{
	std::vector<string> queue;
	int frnt, rear;
public:
	Queue();
	~Queue();
	void push(string num); // ��������� �������� � �������
	void out(); // ����� ��������� �������
	int size(); // ����������� ������� �������
	string pop(); // ���������� �������� �� ������� 
	string front(); // ������ ������� �������
	string back();  // ��������� ������� �������
	void push_front(string value); // ��������� ������� � ������ 
	void push_fron(string value); //��������� ������� � ������ �������
	bool empty(); // ��������� ������ �� �������
};



