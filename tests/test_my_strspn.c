/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_my_strspn
*/

#include <criterion/criterion.h>

int my_strspn(char const *str, char const *chars);

Test(my_strspn, simpleTestOne)
{
    cr_assert_eq(my_strspn("ABCDEFG019874", "ABCD"), 4);
}

Test(my_strspn, simpleTestTwo)
{
    cr_assert_eq(my_strspn("ABCD", "ABCD"), 4);
}
