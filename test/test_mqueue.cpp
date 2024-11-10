#include "stack_and_queue.h"

#include <gtest.h>

TEST(Mqueue, create_queue) {

	ASSERT_NO_THROW(Mqueue<int> queue);

}
TEST(Mqueue, full_queue) {

	Mqueue<int> queue; // {}

	queue.push(1);  // 1

	EXPECT_EQ(queue.full(), 1);
}
TEST(Mqueue, empty_queue) {

	Mqueue<int> queue; // {}

	EXPECT_EQ(queue.empty(), 1);
}
TEST(Mqueue, pop_queue) {

	Mqueue<int> queue_1; // {}

	queue_1.push(1);  // 1

	queue_1.pop();  // {}

	EXPECT_EQ(queue_1.get_front_elem(), 0);
}
TEST(Mqueue, pop_queue_is_empty) {

	Mqueue<int> queue; // {}

	ASSERT_ANY_THROW(queue.pop());
}
TEST(Mqueue, push_queue_correct_size) {

	Mqueue<int> queue_1; // {}

	queue_1.push(1);  // 1
	queue_1.push(2);  // 1, 2
	queue_1.push(3);  // 1, 2, 3

	EXPECT_EQ(queue_1.size(), 3);
}
TEST(Mqueue, push_queue) {

	Mqueue<int> queue_1; // {}

	queue_1.push(1);  // 1

	EXPECT_EQ(queue_1.get_back_elem(), 1);
}
TEST(Mqueue, get_back_elem) {

	Mqueue<int> queue_1; // {}

	queue_1.push(1);  // 1
	queue_1.push(2);  // 1, 2

	EXPECT_EQ(queue_1.get_back_elem(), 2);
}
TEST(Mqueue, get_front_elem) {

	Mqueue<int> queue_1; // {}

	queue_1.push(1);  // 1

	EXPECT_EQ(queue_1.get_front_elem(), 1);
}