// объ€вление и реализаци€ шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удалени€)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыдел€тьс€ пам€ть

// ќбъ€вление шаблонного стека

#ifndef __Stack_H__
#define __Stack_H__
#include <iostream>
#include <string>

using namespace std;
template <class sType>
class Stack 
{
private:
	int top; // верхний элемент
	sType* st;
	int size; // размер стека
public:
	Stack(); // конструктор
	Stack(const int s);
	Stack(const Stack<sType> &s);  // конструктор копировани€
	~Stack();  // деструктор
	int GetSize() const;  // количество элементов в стеке
	void Push(const sType &v); // вставить элемент на вершину стека
	sType Pop();  //  просмотр верхнего элемента (с удалением)
	sType Peek(); //  просмотр верхнего элемента (без удалени€)
	bool IsEmpty() const;  // проверка на пустоту
	void Clean(); // очистка стека
	void Convert(); // конвертирование стека
	bool operator==(const Stack<sType>& s) const;
	bool operator!=(const Stack<sType>& s) const;
	friend ostream & operator<<(ostream &out, const Stack<sType> &mt) // печать стека
	{
		for (int i = 0; i < mt.size; i++)
			out << mt.st[i] << " ";
		out << endl;
		return out;
	}
};

// –еализаци€ шаблонного стека
template <class sType>
inline Stack<sType>::Stack()
{
		size = 10;
		top = 0;
		st = new sType[size];
}

template <class sType>
inline Stack<sType>::Stack(const int s)
{
	if ((s > 1000000) || (s < 0))
		throw "negative";
	size = s;
	top = 0;
	st = new sType[size];

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
inline void Stack<sType>::Push(const sType &v)
{
		if (size == top)
		{
			Stack<sType> s(size + 10);
			for (int i = 0; i < size; i++)
				s.st[i] = st[i];
			s.st[top] = v;
			s.top = top + 1;
			*this = s;
		}
		else
		{
			st[top] = v;
			top++;
		}
}

template <class sType>
sType Stack<sType>::Pop() {
	if (!IsEmpty()) {
		return st[--top];
		top--;
	}
	else
		throw "Empty!";
}

template <class sType>
sType Stack<sType>::Peek() {
	if (!IsEmpty())
		return st[--top];
	else
		throw "Empty!";
}

template <class sType>
bool Stack<sType>::IsEmpty() const {
	return top == 0;
}

template <class sType>
void Stack<sType>::Clean() {
	top = 0;
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

template<class sType>
inline bool Stack<sType>::operator==(const Stack<sType>& s) const
{
	if (this != &s)
	{
		if (size == s.size)
		{
			for (int i = 0; i < size; i++)
				if (st[i] != s.st[i])
					return false;
			return true;
		}
		else
			return false;
	}
	else
		return true;
}

template<class sType>
inline bool Stack<sType>::operator!=(const Stack<sType>& s) const
{
	return (!(*this == s));
}
#endif