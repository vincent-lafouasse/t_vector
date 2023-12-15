#include "t_vector.h"
#include "unity.h"

static void test_default_constructor(void)
{
	t_vector* v = vec_new();

	TEST_ASSERT(v->data == NULL);
	TEST_ASSERT(v->size == 0);
	TEST_ASSERT(v->capacity == 0);

	vec_delete(v);
}

static void test_constructor_with_size(void)
{
	t_vector* v = vec_new_with_size(42);
	
	if (!v)
		TEST_FAIL();

	TEST_ASSERT(v->data != NULL);
	TEST_ASSERT(v->size == 42);
	TEST_ASSERT(v->capacity == 42);

	vec_delete(v);
}


static void test_constructor_with_capacity(void)
{
	t_vector* v = vec_new_with_capacity(42);
	
	if (!v)
		TEST_FAIL();

	TEST_ASSERT(v->data != NULL);
	TEST_ASSERT(v->size == 0);
	TEST_ASSERT(v->capacity == 42);

	vec_delete(v);
}

static void test_constructor_with_size_and_value(void)
{
	t_vector* v = vec_new_init(42, 69);
	
	if (!v)
		TEST_FAIL();

	TEST_ASSERT(v->data != NULL);
	TEST_ASSERT(v->size == 42);
	TEST_ASSERT(v->capacity == 42);

	for (size_t i = 0; i < 42; i++)
	{
		TEST_ASSERT(v->data[i] == 69);
	}

	vec_delete(v);
}

static void test_constructor_from_array(void)
{
	int array[5] = {1, 3, 5, 69, 420};
	size_t size = sizeof(array)/sizeof(int);

	t_vector* v = vec_new_from_array(array, size);
	
	if (!v)
		TEST_FAIL();

	for (size_t i = 0; i < size; i++)
	{
		char error[100] = "";
		sprintf(error, "error found at index %zu, expected %d was %d\n", i, v->data[i], array[i]);
		TEST_ASSERT_MESSAGE(v->data[i] == array[i], error);
	}

	vec_delete(v);
}

void run_test_constructor(void)
{
    printf("\n----- Allocation -----\n");
    RUN_TEST(test_default_constructor);
    RUN_TEST(test_constructor_with_size);
    RUN_TEST(test_constructor_with_size_and_value);
    RUN_TEST(test_constructor_with_capacity);
    RUN_TEST(test_constructor_from_array);
}
