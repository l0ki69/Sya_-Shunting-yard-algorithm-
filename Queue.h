#pragma once

#include <vector>
#include <iostream>

using namespace std;


class Queue //�������
{
	std::vector<char> queue;
	int frnt, rear;
public:
	Queue();
	~Queue();
	void push(char num); // ��������� �������� � �������
	void out(); // ����� ��������� �������
	int size(); // ����������� ������� �������
	void pop(); // ���������� �������� �� ������� 
	char front(); // ������ ������� �������
	char back();  // ��������� ������� �������
	
};



