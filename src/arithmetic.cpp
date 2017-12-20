// реализация функций и классов для вычисления арифметических выражений
#include "..\include\arithmetic.h"
#include <iostream>
#include <cstring>

Lexem::Lexem(const Lexem& s)
{
	num = s.num;
	sign = s.sign;
	flag = s.flag;
}

Lexem::Lexem(const double q)
{
	num = q;
	flag = true;
}

Lexem::Lexem(const char s)
{
	sign = s;
	flag = false;
}

Lexem& Lexem::operator=(const Lexem& v)
{
	num = v.num;
	sign = v.sign;
	flag = v.flag;
	return *this;
}

Lexem& Lexem::operator=(const double n)
{
	num = n;
	flag = true;
	return *this;
}

Lexem& Lexem::operator=(const char s)
{
	sign = s;
	flag = false;
	return *this;
}

bool Lexem::operator==(const Lexem & v) const
{
	if (this != &v)
		if (flag == v.flag)
			if (flag)
				if (num != v.num)
					return false;
				else
					return true;
			else
				if (sign != v.sign)
					return false;
				else
					return true;
		else
			return false;
	else
		return true;
}

bool Lexem::operator!=(const Lexem & v) const
{
	return (!(*this == v));
}

double Lexem::retn() const
{
	return num;
}

char Lexem::rets() const 
{
	return sign;
}

bool Lexem::retb() const
{
	return flag;
}

ostream& operator<<(ostream& out, const Lexem &v)
{
	if (v.flag)
		out << v.num;
	else
		out << v.sign;
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
	int k = 1;
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
				for (int i = 0; i < len; i++)
					string_parametr = string_parametr + s[i];
			else
			{
				if (string_parametr != "")
				{
					cout << "Write parametr " << string_parametr << endl;
					double parametr;
					cin >> parametr;
					if (f)
					{
						parametr *= -1;
						f = false;
					}
					b = parametr;
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
		cout << "Write parametr " << string_parametr << endl;
		double parametr;
		cin >> parametr;
		if (f)
		{
			parametr *= -1;
			f = false;
		}
		b = parametr;
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
		if (element_stack_1.retb())
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
	Stack<Lexem> stack = polishnot(s);
	cout << stack << endl;
	stack.Convert();
	Stack<double> number_stack;
	while (!(stack.IsEmpty()))
	{
		Lexem d = stack.Pop();
		if (d.retb())
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