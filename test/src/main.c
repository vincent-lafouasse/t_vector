/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:09 by poss              #+#    #+#             */
/*   Updated: 2023/12/18 22:57:10 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vector.h"
#include "unity_fixture.h"

#include <stdio.h>

static void runAllTests()
{
    RUN_TEST_GROUP(Constructors);
}

int main(int ac, const char** av)
{
    UnityBegin("Vector");
    return (UnityMain(ac, av, runAllTests));
}
