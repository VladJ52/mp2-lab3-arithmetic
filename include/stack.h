// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������

// ���������� ���������� �����

#ifndef __Stack_H__
#define __Stack_H__
#include <iostream>
#include <string>

using namespace std;
template <class sType>
class Stack 
{
private:
	int top; // ������� �������
	sType* st;
	int size; // ������ �����
public:
	Stack(int s=10); // �����������
	Stack(const Stack<sType> &s);  // ����������� �����������
	~Stack();  // ����������
	int GetSize() const;  // ���������� ��������� � �����
	void Push(const sType &v); // �������� ������� �� ������� �����
	sType Pop();  //  �������� �������� �������� (� ���������)
	sType Peek(); //  �������� �������� �������� (��� ��������)
	bool IsEmpty() const;  // �������� �� �������
	void Clean(); // ������� �����
	void Convert(); // ��������������� �����
	friend ostream & operator<<(ostream &out, const Stack<sType> &mt) // ������ �����
	{
		for (int i = 0; i < mt.size; i++)
			out << mt.st[i] << " ";
		out << endl;
		return out;
	}
};

// ���������� ���������� �����
template <class sType>
inline Stack<sType>::Stack(int s)
{
	if ((s > 0)&&(s<1000000)) {
		size = s;
		top = -1;
		st = new sType[size];
	}
	else
		throw "negative length";
}

template <class sType>
inline Stack<sType>::Stack(const Stack<sType> &s)
{
		size = s.size;
		top = s.top;
		st = new sType[size];
		for (int i = 0; i < size; i++)
			st[i] = s.st[i];
}

template <class sType>
Stack<sType>::~Stack()
{
	delete[] st;
}

template <class sType>
int Stack<sType>::GetSize() const
{
	return size;
}

template <class sType>
void Stack<sType>::Push(const sType &v)
{
	if (top < size)
		st[++top] = v;
	else
	{
		sType *temp;
		temp = new sType[size];
		for (int i=0; i<size;i++)
		temp[i] = st[i];
		delete[] st;
		st = new sType[size + 1];
		for (int i = 0; i < size; i++)
			st[i] = temp[i];
		delete[] temp;
		st[top++] = v;
	}
}

template <class sType>
sType Stack<sType>::Pop() {
	if (!IsEmpty())
		return st[top--];
	else
		throw "Empty!";
}

template <class sType>
sType Stack<sType>::Peek() {
	if (!IsEmpty())
		return st[top];
	else
		throw "Empty!";
}

template <class sType>
bool Stack<sType>::IsEmpty() const {
	return top == -1;
}

template <class sType>
void Stack<sType>::Clean() {
	top = -1;
	for (int i = 0; i < size; i++)
		st[i] = 0;
}

template <class sType>
void Stack<sType>::Convert()
{
	sType a;
	for (int i = 0; i < (size / 2); i++)
	{
		a = st[i];
		st[i] = st[size - i - 1];
		st[size - i - 1] = a;
	}
}

#endif