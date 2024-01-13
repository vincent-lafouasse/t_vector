/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:13 by poss              #+#    #+#             */
/*   Updated: 2024/01/13 20:02:35 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"
#include "unity_fixture.h"

#include <stdio.h>

TEST_GROUP(Constructors);
TEST_SETUP(Constructors) {}
TEST_TEAR_DOWN(Constructors) {}

TEST(Constructors, Default)
{
    t_vector* v = vec_new();

    TEST_ASSERT(v->data == NULL);
    TEST_ASSERT(v->size == 0);
    TEST_ASSERT(v->capacity == 0);

    vec_delete(v);
}

TEST(Constructors, WithSize)
{
    t_vector* v = vec_new_with_size(42);

    if (!v)
        TEST_FAIL();

    TEST_ASSERT(v->data != NULL);
    TEST_ASSERT(v->size == 42);
    TEST_ASSERT(v->capacity == 42);

    vec_delete(v);
}

TEST(Constructors, Init)
{
    t_vector* v = vec_new_init(42, 69);

    if (!v)
        TEST_FAIL();

    TEST_ASSERT(v->data != NULL);
    TEST_ASSERT(v->size == 42);
    TEST_ASSERT(v->capacity == 42);

    for (size_t i = 0; i < 42; i++)
    {
        t_opt_TYPE element = vec_at(v, i);
        TEST_ASSERT(opt_TYPE_is_some(&element));
        TEST_ASSERT(element.value == 69);
    }

    vec_delete(v);
}

TEST(Constructors, FromArray)
{
    const int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = sizeof(array) / sizeof(int);

    t_vector* v = vec_new_from_array(array, size);

    if (!v)
        TEST_FAIL();

    for (size_t i = 0; i < size; i++)
    {
        t_opt_TYPE element = vec_at(v, i);
        TEST_ASSERT(opt_TYPE_is_some(&element));

        char error[100] = "";
        sprintf(error, "error found at index %zu, expected %d was %d\n", i,
                array[i], element.value);
        TEST_ASSERT_MESSAGE(element.value == array[i], error);
    }

    vec_delete(v);
}

TEST_GROUP_RUNNER(Constructors)
{
    printf("\e[34m----- Constructor -----\e[0m\n");
    RUN_TEST_CASE(Constructors, Default);
    RUN_TEST_CASE(Constructors, WithSize);
    RUN_TEST_CASE(Constructors, Init);
    RUN_TEST_CASE(Constructors, FromArray);
}
