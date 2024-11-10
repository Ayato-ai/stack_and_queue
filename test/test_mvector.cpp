#include "stack_and_queue.h"

#include <gtest.h>

TEST(Mvector, can_vector_with_positive_lenn){

	ASSERT_NO_THROW(Mvector<int> vector(5));

}
TEST(Mvector, can_vector_with_negative_lenn) {

	ASSERT_ANY_THROW(Mvector<int> vector(-5));

}
TEST(Mvector, create_vector_with_array) {

	int *arr = new int[3]{ 1, 2, 3 };

	ASSERT_NO_THROW(Mvector<int> vector(arr, 3));

	delete[] arr;
}
TEST(Mvector, create_vector_with_null_array) {

	int *null = nullptr;

	ASSERT_ANY_THROW(Mvector<int> vector(null, 0));
}
TEST(Mvector, copy_vector) {

	int *arr = new int[3]{ 1, 2, 3 };
	Mvector<int> vector(arr, 3);
	delete[] arr;

	Mvector<int> vector_copy(vector);

	EXPECT_EQ(vector, vector_copy);
}
TEST(Mvector, can_assign_with_equal_size) {

	int *array_1 = new int[3]{ 1, 2, 3 };
	int *array_2 = new int[3]{ 2, 3, 4 };

	Mvector<int> vector_1(array_1, 3); // 1, 2, 3
	Mvector<int> vector_2(array_2, 3); // 2, 3, 4

	delete[] array_1;
	delete[] array_2;

	vector_1 = vector_2;

	EXPECT_EQ(vector_1, vector_2);
}
TEST(Mvector, can_assign_with_not_equal_size) {

	int *array_1 = new int[3]{ 1, 2, 3 };
	int *array_2 = new int[4]{ 2, 3, 4, 5 };

	Mvector<int> vector_1(array_1, 3); // 1, 2, 3
	Mvector<int> vector_2(array_2, 4); // 2, 3, 4, 5

	delete[] array_1;
	delete[] array_2;

	vector_1 = vector_2;

	EXPECT_EQ(vector_1, vector_2);
}
TEST(Mvector, back_elem_with_correct_lenght) {

	int *arr = new int[3]{ 1, 2, 3 };
	Mvector<int> vector(arr, 3);
	delete[] arr;

	EXPECT_EQ(vector.back(), 3);
}
TEST(Mvector, full_vector) {

	int *arr = new int[2]{ 1, 2 }; 
	Mvector<int> vector(arr, 2); // 1, 2
	delete[] arr;

	vector.push_back(3);  // 1, 2, 3
	vector.push_back(4);  // 1, 2, 3, 4
	vector.push_back(5);  // 1, 2, 3, 4, 5

	EXPECT_EQ(vector.full(), 1);
}
TEST(Mvector, empty_vector) {

	int *arr = new int[2]{ 1, 2 };
	Mvector<int> vector(arr, 2); // 1, 2
	delete[] arr;

	vector.pop_back(); // 1
	vector.pop_back(); // {}
	 
	EXPECT_EQ(vector.empty(), 1);
}
TEST(Mvector, pop_back_vector_with_correct_length) {

	int *array_1 = new int[3]{ 1, 2, 3 };
	int *array_2 = new int[2]{ 1, 2 };
	Mvector<int> vector_1(array_1, 3); // 1, 2, 3
	Mvector<int> vector_2(array_2, 2); // 1, 2

	delete[] array_1;
	delete[] array_2;

	vector_1.pop_back();

	EXPECT_EQ(vector_1, vector_2);
}
TEST(Mvector, pop_back_vector_with_null_length) {

	int *arr = new int[2]{ 1, 2 };
	Mvector<int> vector(arr, 2); // 1, 2
	delete[] arr;

	vector.pop_back(); // 1
	vector.pop_back(); // {}

	ASSERT_ANY_THROW(vector.pop_back());
}
TEST(Mvector, push_back_with_not_resize_vector) {

	int *array_1 = new int[3]{ 1, 2, 3 };
	int *array_2 = new int[2]{ 1, 2 };
	Mvector<int> vector_1(array_1, 3); // 1, 2, 3
	Mvector<int> vector_2(array_2, 2); // 1, 2

	delete[] array_1;
	delete[] array_2;

	vector_2.push_back(3);

	EXPECT_EQ(vector_1, vector_2);
}
TEST(Mvector, push_back_with_resize_vector) {

	int *array_1 = new int[3]{ 1, 2, 3 };
	int *array_2 = new int[2]{ 1, 2 };
	Mvector<int> vector_1(array_1, 3); // 1, 2, 3
	Mvector<int> vector_2(array_2, 2); // 1, 2

	delete[] array_1;
	delete[] array_2;

	vector_2.push_back(3);

	EXPECT_EQ(vector_1, vector_2);
}
TEST(Mvector, resize_vector) {

	int *array_1 = new int[6]{ 1, 2, 3, 4, 5, 6 };
	int *array_2 = new int[2]{ 1, 2 };
	Mvector<int> vector_1(array_1, 6); // 1, 2, 3, 4, 5, 6
	Mvector<int> vector_2(array_2, 2); // 1, 2

	delete[] array_1;
	delete[] array_2;

	vector_2.push_back(3);
	vector_2.push_back(4);
	vector_2.push_back(5);
	vector_2.push_back(6);

	EXPECT_EQ(vector_1, vector_2);
}
TEST(Mvector, can_erase_with_not_empty_vector_and_correct_index) {

	int *array_1 = new int[3]{ 1, 2, 3 };
	int *array_2 = new int[2]{ 1, 3 };
	Mvector<int> vector_1(array_1, 3); // 1, 2, 3
	Mvector<int> vector_2(array_2, 2); // 1, 3

	delete[] array_1;
	delete[] array_2;

	vector_1.erase(1); // 1, 3

	EXPECT_EQ(vector_1, vector_2);
}
TEST(Mvector, can_erase_with_empty_vector) {

	int *arr = new int[2]{ 1, 2 };
	Mvector<int> vector(arr, 2); // 1, 2
	delete[] arr;

	vector.pop_back(); // 1
	vector.pop_back(); // {}

	ASSERT_ANY_THROW(vector.erase(0));
}
TEST(Mvector, can_erase_with_not_empty_vector_and_ancorrect_index) {

	int *arr = new int[2]{ 1, 2 };
	Mvector<int> vector(arr, 2); // 1, 2
	delete[] arr;

	ASSERT_ANY_THROW(vector.erase(6));
}

