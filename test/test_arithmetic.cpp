// тесты для вычисления арифметических выражений
#include "stack.h"
#include "arithmetic.h"
#include <gtest.h>

class TestStackLexem : public ::testing::Test
{
protected:
	Stack<Lexem> s1;
	Stack<Lexem> s2;

public:
	TestStackLexem()
	{
		s1.Push(10.0);    s2.Push(10.0);
		s1.Push('+');	  s2.Push(12.0);
		s1.Push('(');	  s2.Push(5.0);
		s1.Push(12.0);    s2.Push(3.0);
		s1.Push('-');     s2.Push('*');
		s1.Push(5.0);     s2.Push('-');
		s1.Push('*');     s2.Push('+');
		s1.Push(3.0);
		s1.Push(')');
	}
	~TestStackLexem() {}
};

string t[18] = { "", "+", "25+-5", "*25+5", "25+5*", "25 + 5", "(", ")", "(25+5", "25+5)", "25(5+5)", "(25+5)5", "25.5.5", "25..5", "a.5+5", "(2+3)(5+6)", "(25+5+)", "(+25+5)" };
string tt[3] = { "25+5+10-(3*2-1)", "-5", "(-5)" };
string ttt[5] = { "6+4", "13-3", "5*2", "50/5", "-5+15" };

class ParArithmetic : public ::testing::TestWithParam<string>
{
protected:
	string s;
public:
	ParArithmetic() { s = GetParam(); }
	~ParArithmetic() {}
};
class ParArithmetic2 : public ParArithmetic
{
protected:
	string s2;
public:
	ParArithmetic2() { s2 = GetParam(); }
	~ParArithmetic2() {}
};
class ParArithmetic3 : public ParArithmetic2
{
protected:
	string s3;
public:
	ParArithmetic3() { s3 = GetParam(); }
	~ParArithmetic3() {}
};

TEST_F(TestStackLexem, work_convert_string_to_stack)
{
	string a = "10+(12-5*3)";
	Stack<Lexem> b = convertstr(a);
	EXPECT_EQ(s1, b);
}

TEST_F(TestStackLexem, work_polish_notation)
{
	EXPECT_EQ(s2, polishnot(s1));
}

TEST_F(TestStackLexem, work_the_solution_of_the_expression)
{
	EXPECT_EQ(7, sol(s1));
}