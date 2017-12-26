// реализация функций и классов для вычисления арифметических выражений
#include "..\include\arithmetic.h"
#include <iostream>
#include <cstring>

Lexem::Lexem(const int n, const string s, const double d, const char c)
{
	parametr = s;
	num = n;
	sign = c;
	flag = n;
}
Lexem::Lexem(const Lexem& s)
{
	parametr = s.parametr;
	num = s.num;
	sign = s.sign;
	flag = s.flag;
}

Lexem::Lexem(const double q)
{
	num = q;
	flag = 1;
}

Lexem::Lexem(const string & s)
{
	parametr = s;
	flag = 2;
}
Lexem::Lexem(const char s)
{
	sign = s;
	flag = 0;
}

Lexem& Lexem::operator=(const Lexem& v)
{
	num = v.num;
	parametr = v.parametr;
	sign = v.sign;
	flag = v.flag;
	return *this;
}

Lexem& Lexem::operator=(const string & s)
{
	parametr = s;
	flag = 2;
	return *this;
}

Lexem& Lexem::operator=(const double n)
{
	num = n;
	flag = 1;
	return *this;
}

Lexem& Lexem::operator=(const char s)
{
	sign = s;
	flag = 0;
	return *this;
}

bool Lexem::operator==(const Lexem & v) const
{
	if (this != &v)
	{
		if (flag == v.flag)
		{
			if (flag == 1)
			{
				if (num != v.num)
					return false;
				else
					return true;
			}
			else
			{
				if (flag == 0)
				{
					if (sign != v.sign)
						return false;
					else
						return true;
				}
				else
				{
					if (parametr != v.parametr)
						return false;
					else
						return true;
				}
			}

		}
		else
			return false;
	}
	else
		return true;
}

bool Lexem::operator!=(const Lexem & v) const
{
	return (!(*this == v));
}

string Lexem::retp() const
{
	return parametr;
}

double Lexem::retn() const
{
	return num;
}

char Lexem::rets() const 
{
	return sign;
}

int Lexem::retb() const
{
	return flag;
}

ostream& operator<<(ostream& out, const Lexem &v)
{
	if (v.flag == 1)
		out << v.num;
	else
		if (v.flag == 0)
			out << v.sign;
		else
			out << v.parametr;
	return out;
}

double rankn(const double a, const int i)
{
	double b = 1;
	for (int j = 0; j < i; j++)
		b *= a;
	return b;
}

double convertn(const string &s)
{
	int len = s.length();
	double a = 0.0;
	int i = 0;
	for (i = 0; ((i < len) && (s[i] != '.')); i++)
		a = a * 10.0 + (s[i] - '0');
	int j = i;
	if (s[j] == '.')
		for (i = j + 1; i < len; i++)
			a = a + (s[i] - '0') / (rankn(10.0, (i - j)));
	return a;
}

int signpr(const char c)
{
	switch (c)
	{
	case '(':
		return 0;
		break;
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	}
}

double evaluating(const double a, const double b, const char c)
{
	switch (c)
	{
	case '+':
		return (a + b);
		break;
	case '-':
		return (b - a);
		break;
	case '*':
		return (a * b);
		break;
	case '/':
		return (b / a);
		break;
	}
}

bool iscorrect(const string &s)
{
	if (s != "")
	{
		string c;
		c = c + ' ';
		c = c + s;
		c = c + ' ';
		string sign = "*+-/";
		string wrongsign = "=\\|&!`~@#%^_?,:;'\№ ";
		int len = c.length();
		int f = 0;
		int t = 0;
		if ((sign.find(c[1]) != sign.npos) && (c[1] != '-'))
		{
			cout << "Sign at the beginning of the expression";
			return false;
		}
		if (sign.find(c[len - 2]) != sign.npos)
		{
			cout << "The sign at the end of the expression" << endl;
			return false;
		}
		for (int i = 1; i < len - 1; i++)
		{
			if (wrongsign.find(c[i]) != wrongsign.npos)
			{
				cout << "Wrong sign" << endl;
				return false;
			}
			if ((sign.find(c[i]) != sign.npos) && (sign.find(c[i + 1]) != sign.npos))
			{
				cout << "Two sign in a row" << endl;
				return false;
			}
			if ((sign.find(c[i]) != sign.npos) && (c[i + 1] == ')'))
			{
				cout << "Sign before close parenthesis" << endl;
				return false;
			}
			if ((c[i] == '(') && (c[i + 1] != '-') && (sign.find(c[i + 1]) != sign.npos))
			{
				cout << "Sign after open parenthesis" << endl;
				return false;
			}
			if ((c[i] == ')') && (c[i + 1] == '('))
			{
				cout << "Not enough sign" << endl;
				return false;
			}
			if ((c[i] == '(') && (c[i + 1] == ')'))
			{
				cout << "Not enough expression" << endl;
				return false;
			}
			if ((c[i] >= '0') && (c[i] <= '9') && (c[i + 1] == '('))
			{
				cout << "Lost sign" << endl;
				return false;
			}
			if ((c[i] == ')') && (c[i + 1] >= '0') && (c[i + 1] <= '9'))
			{
				cout << "Lost sign" << endl;
				return false;
			}
			if ((c[i] == '.') && (((c[i + 1] < '0') || (c[i + 1] >= '9')) || ((c[i - 1] < '0') || (c[i - 1] >= '9'))))
			{
				cout << "Wrong signs" << endl;
				return false;
			}
			if (((c[i] >= '0') && (c[i] <= '9')) || (c[i] == '.'))
			{
				if ((c[i] == '.'))
					t++;
				if (t > 1)
				{
					cout << "Wrong signs" << endl;
					return false;
				}
			}
			else
				t = 0;
			if (c[i] == ')')
				f--;
			if (f < 0)
			{
				cout << "More )" << endl;
				return false;
			}
			if (c[i] == '(')
				f++;
		}
		if (f > 0)
		{
			cout << "More (" << endl;
			return false;
		}
		return true;
	}
	else
	{
		cout << "Null" << endl;
		return false;
	}
}

Stack<Lexem> convertstr(const string & c)
{
	if (!iscorrect(c))
		throw "Not correct";
	string s;
	s = s + ' ';
	s = s + c;
	int len = s.length();
	Stack<Lexem> stack;
	string string_number;
	string string_parametr;
	Lexem b;
	int j = 1;
	bool f = false;
	if (s[1] == '-')
	{
		f = true;
		j = 2;
	}
	for (int i = j; i < len; i++)
	{
		if ((s[i] == '-') && (s[i - 1] == '('))
			f = true;
		else
		{
			if ((((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z'))) || ((s[i] <= '9') && (s[i] >= '0') && (string_parametr != "")))
				string_parametr = string_parametr + s[i];
			else
			{
				if (string_parametr != "")
				{
					if (f)
					{
						string_parametr = '-' + string_parametr;
						f = false;
					}
					b = string_parametr;
					stack.Push(b);
					string_parametr = "";
				}
				if ((((s[i] <= '9') && (s[i] >= '0')) || (s[i] == '.')))
					string_number = string_number + s[i];
				else
				{
					if (string_number != "")
					{
						double k = convertn(string_number);
						if (f)
						{
							k *= -1;
							f = false;
						}
						b = k;
						stack.Push(b);
						string_number = "";
					}
					b = s[i];
					stack.Push(b);
				}
			}
		}
	}
	if (string_parametr != "")
	{
		if (f)
		{
			string_parametr = '-' + string_parametr;
			f = false;
		}
		b = string_parametr;
		stack.Push(b);
	}
	if (string_number != "")
	{
		double k = convertn(string_number);
		if (f)
		{
			k *= -1;
			f = false;
		}
		b = k;
		stack.Push(b);
	}
	return stack;
}


Stack<Lexem> polishnot(const Stack<Lexem>& s)
{
	Stack<Lexem> stack_1 = s;
	stack_1.Convert();
	Stack<Lexem> stack_2;
	Lexem element_stack_1;
	Stack<char> sign_stack;
	while (!(stack_1.IsEmpty()))
	{
		element_stack_1 = stack_1.Pop();
		if (element_stack_1.retb() != 0)
			stack_2.Push(element_stack_1);
		else
		{
			char c = element_stack_1.rets();
			if (sign_stack.IsEmpty())
				sign_stack.Push(c);
			else
			{
				if (c == '(')
					sign_stack.Push(c);
				else
				{
					if (c == ')')
					{
						while (sign_stack.Peek() != '(')
							stack_2.Push(sign_stack.Pop());
						sign_stack.Pop();
					}
					else
					{
						while ((!(sign_stack.IsEmpty())) && (signpr(c) <= signpr(sign_stack.Peek())))
							stack_2.Push(sign_stack.Pop());
						sign_stack.Push(c);
					}
				}
			}
		}
	}
	while (!(sign_stack.IsEmpty()))
		stack_2.Push(sign_stack.Pop());
	return stack_2;
}

double sol(const Stack<Lexem>& s)
{
Stack<Lexem> stack_p = s;
Stack<Lexem> stack;
int i = stack_p.GetSize();
Lexem* st = new Lexem[i / 2 + 1];
i = 0;
while (!(stack_p.IsEmpty()))
{
	Lexem b = stack_p.Pop();
	if (b.retb() == 2)
	{
		int k = 1;
		string min = b.retp();
		if (min[0] == '-')
		{
			k = -1;
			min.erase(0, 1);
			b = min;
		}
		bool f = true;
		for (int j = 0; ((j < i) && (f)); j++)
			if (st[j].retp() == b.retp())
			{
				f = false;
				b = st[j];
			}
		if (f)
		{
			cout << "Write parametr " << b.retp() << endl;
			double d;
			cin >> d;
			Lexem a(b.retb(), b.retp(), d, b.rets());
			b = k * d;
			stack.Push(b);
			st[i++] = a;
		}
		else
		{
			Lexem e = b.retn();
			if (k == -1)
				e = k * b.retn();
			stack.Push(e);
		}
	}
	else
		stack.Push(b);
}
delete[] st;
Stack<double> number_stack;
while (!(stack.IsEmpty()))
{
	Lexem d = stack.Pop();
	if (d.retb() != 0)
		number_stack.Push(d.retn());
	else
	{
		double number_1 = number_stack.Pop();
		double number_2 = number_stack.Pop();
		char sign = d.rets();
		number_stack.Push(evaluating(number_1, number_2, sign));
	}
}
return number_stack.Peek();
}