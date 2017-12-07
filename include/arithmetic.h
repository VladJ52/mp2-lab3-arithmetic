// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#ifndef __Arithmetic_H__
#define __Arithmetic_H__
#include "stack.h"


//  ласс лексем
class Lexem 
{
	double num;
	char sign;
	bool flag;
public:
	Lexem() {};
	Lexem(const Lexem &s);
	Lexem(const double q);
	Lexem(const char s);
	~Lexem() {};
	Lexem& operator=(const Lexem& v);
	Lexem& operator=(const double n);
	Lexem& operator=(const char s);
	bool operator==(const Lexem& v) const;
	bool operator!=(const Lexem& v) const;
	double retn() const;
	char rets() const;
	bool retb() const;
	friend ostream& operator<< (ostream& out, const Lexem &v);
};
double rankn(const double a, const int i);
double convertn(const string& s);
int signpr(const char c);
double evaluating(const double a, const double b, const char c);
bool iscorrect(const string &s);
Stack<Lexem> convertstr(const string& s);
Stack<Lexem> polishnot(const Stack<Lexem>);
double sol(const Stack<Lexem> &s);
#endif