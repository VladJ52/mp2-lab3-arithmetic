// тесты для стека

#include "stack.h"
#include <gtest.h>

class TestStack : public ::testing::Test
{
protected:
	Stack<int> st;
public:
	TestStack() : st(10) {
		for (int i = 0; i < st.GetSize(); i++)
			st.Push(i);
	}
	~TestStack() {}
};

TEST(Stack, can_create_stack_with_positive_size) {
	ASSERT_NO_THROW(Stack<int> st(10));
}

TEST(Stack, throws_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(Stack<int> st(-10));
}

TEST_F(TestStack, can_get_size) {
	EXPECT_EQ(10, st.GetSize());
}

TEST_F(TestStack, can_push_value) {
	EXPECT_EQ(st.Peek(), 9);
}

TEST_F(TestStack, can_pop_value) {
	
	EXPECT_EQ(st.Pop(), 9);
}

TEST_F(TestStack, can_peek_value) {
	EXPECT_EQ(st.Peek(), 9);
}

TEST(Stack, can_check_empty) {
	Stack<int> st(1);
	EXPECT_EQ(st.IsEmpty(), true);
}

TEST_F(TestStack, can_clean_stack) {
	st.Clean();
	EXPECT_EQ(st.IsEmpty(), true);
}

TEST_F(TestStack, throws_when_peek_or_pop_empty_stack){
	st.Clean();
	ASSERT_ANY_THROW(st.Pop());
	ASSERT_ANY_THROW(st.Peek());
}