#include "stack_and_queue.h"

#include <gtest.h>

TEST(Mstack, create_vector) {

	ASSERT_NO_THROW(Mstack<int> stack);

}
TEST(Mstack, full_stack) {

	Mstack<int> stack; // {}

	stack.push(1);  // 1

	EXPECT_EQ(stack.full(), 1);
}
TEST(Mstack, empty_stack) {

	Mstack<int> stack; // {}

	EXPECT_EQ(stack.empty(), 1);
}
TEST(Mstack, pop_stack) {

	Mstack<int> stack_1;
	Mstack<int> stack_2;

	stack_1.push(1); // 1
	stack_1.push(2); // 1, 2
	stack_1.push(3); // 1, 2, 3

	stack_2.push(1); // 1
	stack_2.push(2); // 1, 2

	stack_1.pop(); // 1, 2

	EXPECT_EQ(stack_1, stack_2);
}
TEST(Mstack, push_stack) {

	Mstack<int> stack_1;
	Mstack<int> stack_2;

	stack_1.push(1); // 1
	stack_1.push(2); // 1, 2
	stack_1.push(3); // 1, 2, 3

	stack_2.push(1); // 1
	stack_2.push(2); // 1, 2

	stack_2.push(3); // 1, 2, 3

	EXPECT_EQ(stack_1, stack_2);
}
TEST(Mstack, top_stack) {

	Mstack<int> stack_1;

	stack_1.push(1); // 1
	stack_1.push(2); // 1, 2
	stack_1.push(3); // 1, 2, 3

	EXPECT_EQ(stack_1.top(), 3);
}
TEST(Mstack, size_stack) {

	Mstack<int> stack_1;

	stack_1.push(1); // 1
	stack_1.push(2); // 1, 2
	stack_1.push(3); // 1, 2, 3

	EXPECT_EQ(stack_1.size(), 3);
}
TEST(Mstack, capacity_stack) {

	Mstack<int> stack_1;

	stack_1.push(1); // 1
	stack_1.push(2); // 1, 2

	EXPECT_EQ(stack_1.capacity(), 3);
}