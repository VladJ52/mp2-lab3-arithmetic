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
		s1.Push(25.0);    s2.Push(25.0);
		s1.Push('+');     s2.Push(5.0);
		s1.Push(5.0);     s2.Push('+');
		s1.Push('+');     s2.Push(10.0);
		s1.Push(10.0);    s2.Push('+');
		s1.Push('-');     s2.Push(3.0);
		s1.Push('(');     s2.Push(2.0);
		s1.Push(3.0);     s2.Push('*');
		s1.Push('*');     s2.Push(1.0);
		s1.Push(2.0);     s2.Push('-');
		s1.Push('-');     s2.Push('-');
		s1.Push(1.0);
		s1.Push(')');
	}
	~TestStackLexem() {}
};

string t[17] = { "", "+", "25+-5", "*25+5", "25+5*", "(", ")", "(25+5", "25+5)", "25(5+5)", "(25.0+5.0)5.0", "25.5.5", "25..5", "a.5+5", "(2+3)(5+6)", "(25+5+)", "(+25+5)" };
string tt[2] = { "25+5+10-(3*2-1)", "-5" };
string ttt[10] = { "-6+4*2*(1+1)", "13-3", "5*2", "50/5", "5+5", "2*(4+1)", "20.5-(12.25-1.5*1.5)-0.5", "a+b*c", "2*a+3/b-c", "-a+(-b+a)" };

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

TEST_P(ParArithmetic, isIncorrect1)
{
	EXPECT_EQ(false, iscorrect(s));
}
INSTANTIATE_TEST_CASE_P(i1, ParArithmetic, ::testing::ValuesIn(t));

TEST_P(ParArithmetic2, isIncorrect2)
{
	EXPECT_EQ(true, iscorrect(s2));
}
INSTANTIATE_TEST_CASE_P(i2, ParArithmetic2, ::testing::ValuesIn(tt));

TEST_P(ParArithmetic3, isIncorrect3)
{
	EXPECT_EQ(10, sol(convertstr(s3)));
}
INSTANTIATE_TEST_CASE_P(i3, ParArithmetic3, ::testing::ValuesIn(ttt)); 

TEST_F(TestStackLexem, work_convert_string_to_stack)
{
	string a = "25+5+10-(3*2-1)";
	Stack<Lexem> b = convertstr(a);
	EXPECT_EQ(s1, b);
}

TEST_F(TestStackLexem, work_polish_notation)
{
	EXPECT_EQ(s2, polishnot(s1));
}

TEST_F(TestStackLexem, work_the_solution_of_the_expression)
{
	EXPECT_EQ(35, sol(s1));
}