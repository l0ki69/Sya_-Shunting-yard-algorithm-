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
char pop1(Stack_t *stack); // ���������� ������� �������
void out_end(Stack_t *stack); // ������� ���� � ������� ���
void out(Stack_t *stack); // ������� ����
void del(Stack_t *stack); //�������� �����