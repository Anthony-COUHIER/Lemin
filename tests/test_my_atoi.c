/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** test_my_atoi.c
*/

#include <criterion/criterion.h>

int my_atoi(char const *str);

Test(my_atoi, positiveNumber)
{
    cr_assert_eq(my_atoi("117"), 117);
}

Test(my_atoi, negativeNumber)
{
    cr_assert_eq(my_atoi("-343"), -343);
}

Test(my_atoi, wrongDigitLower)
{
    cr_assert_eq(my_atoi("256+4567"), 0);
}

Test(my_atoi, wrongDigitHighter)
{
    cr_assert_eq(my_atoi("356oui3"), 0);
}
