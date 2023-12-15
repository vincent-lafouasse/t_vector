#include "t_vector.h"
#include "unity.h"

static void test_default_constructor(void)
{
	t_vector* v = vector_new();

	TEST_ASSERT(v->data == NULL);
	TEST_ASSERT(v->len == 0);
	TEST_ASSERT(v->capacity == 0);
}

void run_test_constructor(void)
{
    printf("\n----- Allocation -----\n");
    RUN_TEST(test_default_constructor);
}
