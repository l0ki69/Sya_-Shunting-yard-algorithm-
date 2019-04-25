#pragma once

#include <vector>
#include <iostream>

typedef struct Stack {
	std::vector<char> data;
}Stack_t;

void push(Stack_t *stack, const char value); // ��������� ������� �� �����
char pop(Stack_t *stack); // ���������� �  ������� ������� �������
char peek(const Stack_t *stack); // ���������� ��������� �������
int size(const Stack_t *stack); // ���������� ���-�� ��������� � �����