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
#include <iostream>
using namespace std;
template <class sType>
class Stack 
{
private:
	int top; // верхний элемент
	sType* st;
	int size; // размер стека
public:
	Stack(int s = 10); // конструктор
	Stack(const Stack<sType> &s);  // конструктор копировани€
	~Stack();  // деструктор
	int GetSize() const;  // количество элементов в стеке
	void Push(const sType &v); // вставить элемент на вершину стека
	sType Pop();  //  просмотр верхнего элемента (с удалением)
	sType Peek(); //  просмотр верхнего элемента (без удалени€)
	bool IsEmpty() const;  // проверка на пустоту
	void Clean(); // очистка стека
};

// –еализаци€ шаблонного стека
template <class sType>
Stack<sType>::Stack(int s)
{
	size = s;
	top = 0;
	st = new sType[size];
}

template <class sType>
Stack<sType>::Stack(const Stack<sType> &s)
{
	size = s.size;
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
	if (top < Size)
		st[top++] = v;
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
		return st[top--]
	else
		throw "Empty!"
}

template <class sType>
sType Stack<sType>::Peek() {
	if (!IsEmpty())
		return st[top]
	else
		throw "Empty!"
}

template <class sType>
bool Stack<sType>::IsEmpty() const {
	return top == -1;
}

template <class sType>
void Stack<sType>::Clean() {
	top = 0;
	for (int i = 0; i < size; i++)
		st[i] = 0;
}