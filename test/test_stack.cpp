// тесты для стека

#include "stack.h"
#include <gtest.h>

class TestSt : public ::testing::Test
{
protected:
	Stack<int> st;
public:
	TestSt() : st(10)
	{
		for (int i = 0; i < st.GetSize(); i++)
			st.Push(i);
	}
	~TestSt() {}
};