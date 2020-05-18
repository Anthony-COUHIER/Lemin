/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_is_digit
*/

#include <criterion/criterion.h>

int is_digit(char const *str);

Test(is_digit, trueDigitString)
{
    cr_assert_eq(is_digit("1234567890"), 1);
}

Test(is_digit, wrongDigitString_lowerCharacter)
{
    cr_assert_eq(is_digit("12+4567890"), 0);
}

Test(is_digit, wrongDigitString_higherCharacter)
{
    cr_assert_eq(is_digit("1245678l90"), 0);
}
