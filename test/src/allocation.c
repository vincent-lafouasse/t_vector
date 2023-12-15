/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:13 by poss              #+#    #+#             */
/*   Updated: 2023/12/15 21:18:29 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"
#include "unity.h"

static int to_int(const void* int_ptr)
{
    return *(int*)int_ptr;
}

static void test_default_constructor(void)
{
    t_vector* v = vec_new(sizeof(long));

    TEST_ASSERT(v->data == NULL);
    TEST_ASSERT(v->size == 0);
    TEST_ASSERT(v->capacity == 0);

    vec_delete(v, NULL);
}

static void test_constructor_with_size(void)
{
    t_vector* v = vec_new_with_size(4, 42);

    if (!v)
        TEST_FAIL();

    TEST_ASSERT(v->data != NULL);
    TEST_ASSERT(v->size == 42);
    TEST_ASSERT(v->capacity == 42);

    // vec_delete(v);
    vec_delete(v, NULL);
}

static void test_constructor_with_size_and_value(void)
{
    const int three = 3;
    t_vector* v = vec_new_init(sizeof(int), 42, &three);

    if (!v)
        TEST_FAIL();

    TEST_ASSERT(v->data != NULL);
    TEST_ASSERT(v->size == 42);
    TEST_ASSERT(v->capacity == 42);

    for (size_t i = 0; i < 42; i++)
    {
        TEST_ASSERT(to_int(vec_at(v, i)) == three);
    }

    // vec_delete(v);
    vec_delete(v, NULL);
}

static void test_constructor_from_array(void)
{
    const int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = sizeof(array) / sizeof(int);

    t_vector* v = vec_new_from_array(sizeof(int), array, size);

    if (!v)
        TEST_FAIL();

    for (size_t i = 0; i < size; i++)
    {
        char error[100] = "";
        sprintf(error, "error found at index %zu, expected %d was %d\n", i,
                to_int(vec_at(v, i)), array[i]);
        TEST_ASSERT_MESSAGE(to_int(vec_at(v, i)) == array[i], error);
    }

    // vec_delete(v);
    vec_delete(v, NULL);
}

void run_test_constructor(void)
{
    printf("\n----- Allocation -----\n");
    RUN_TEST(test_default_constructor);
    RUN_TEST(test_constructor_with_size);
    RUN_TEST(test_constructor_with_size_and_value);
    RUN_TEST(test_constructor_from_array);
}
