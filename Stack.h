#pragma once

#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

typedef struct Stack*  pStack;
struct Stack
{
	pStack next;
	string data;
};

void push(pStack* stack, string value); // ��������� ������� �� ����
string pop(pStack* stack); // ������� ������� ������� � ���������� ���
string top(pStack* stack); // ���������� ������� �������
bool empty(pStack* stack); // ��������� ���������� ��������� � ����������



typedef struct nStack*  pnStack;
struct nStack
{
	pnStack next;
	Node data;

	void push(pnStack* stack, Node value); // ��������� ������� �� ����
	Node pop(pnStack* stack); // ������� ������� ������� � ���������� ���
	Node top(pnStack* stack); // ���������� ������� �������
	bool empty(pnStack* stack); // ��������� ���������� ��������� � ����������
};