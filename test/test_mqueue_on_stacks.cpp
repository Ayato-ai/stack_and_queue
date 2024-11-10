#include "stack_and_queue.h"

#include <gtest.h>

TEST(Mqueue_on_stacks, create_queue) {

	ASSERT_NO_THROW(Mqueue_on_stacks<int> queue);

}
TEST(Mqueue_on_stacks, full_queue) {

	Mqueue_on_stacks<int> queue; // {}

	EXPECT_EQ(queue.full(), 0);
}
TEST(Mqueue_on_stacks, empty_queue) { 

	Mqueue_on_stacks<int> queue; // {}

	EXPECT_EQ(queue.empty(), 1);
}
TEST(Mqueue_on_stacks, pop_queue) {

	Mqueue_on_stacks<int> queue_1; // {}

	queue_1.push(1);  // 1
	queue_1.push(2);  // 1, 2

	queue_1.pop();  // 1

	EXPECT_EQ(queue_1.size_(), 1);
}
TEST(Mqueue_on_stacks, pop_queue_is_empty) {

	Mqueue_on_stacks<int> queue; // {}

	ASSERT_ANY_THROW(queue.pop());
}
TEST(Mqueue_on_stacks, push_queue_correct_size) {

	Mqueue_on_stacks<int> queue_1; // {}

	queue_1.push(1);  // 1

	EXPECT_EQ(queue_1.size_(), 1);
}
TEST(Mqueue_on_stacks, push_queue) { 

	Mqueue_on_stacks<int> queue_1; // {}

	queue_1.push(1);  // 1

	EXPECT_EQ(queue_1.get_front_elem(), 1);
}
TEST(Mqueue_on_stacks, get_back_elem) { 

	Mqueue_on_stacks<int> queue_1; // {}

	queue_1.push(1);	// 1
	queue_1.push(2);	// 1, 2

	queue_1.pop();		// 2

	EXPECT_EQ(queue_1.get_back_elem(), 2);
}
TEST(Mqueue_on_stacks, get_front_elem) { 

	Mqueue_on_stacks<int> queue_1; // {}

	queue_1.push(1);  // 1
	queue_1.push(2);  // 1, 2 

	EXPECT_EQ(queue_1.get_front_elem(), 1);
}

