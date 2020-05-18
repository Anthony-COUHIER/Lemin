/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** test_my_strdup.c
*/

#include <criterion/criterion.h>
#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *str);

Test(my_strdup, strNull)
{
    char *str = NULL;

    cr_assert_eq(my_strdup(str), NULL);
}

Test(my_strdup, trueStr)
{
    cr_assert_str_eq(my_strdup("bonjour"), "bonjour");
}
