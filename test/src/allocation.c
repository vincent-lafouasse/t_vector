#include "t_vector.h"
#include "unity.h"

static void test_default_constructor(void)
{
	t_vector* v = vector_new();

	TEST_ASSERT(v->data == NULL);
	TEST_ASSERT(v->len == 0);
	TEST_ASSERT(v->capacity == 0);
}

static void test_constructor_with_size(void)
{
	t_vector* v = vector_new_with_capacity(42);
	
	if (!v)
		TEST_FAIL();

	TEST_ASSERT(v->data != NULL);
	TEST_ASSERT(v->len == 0);
	TEST_ASSERT(v->capacity == 42);

}

void run_test_constructor(void)
{
    printf("\n----- Allocation -----\n");
    RUN_TEST(test_default_constructor);
    RUN_TEST(test_constructor_with_size);
}
