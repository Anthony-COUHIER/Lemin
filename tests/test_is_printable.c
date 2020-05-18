/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_is_printable
*/

#include <criterion/criterion.h>

int is_printable(char const *str);

Test(is_printable, truePrintableString)
{
    cr_assert_eq(is_printable("Ce test 1 est vrai."), 1);
}

Test(is_printable, wrongPrintableString_lowerCharacther)
{
    cr_assert_eq(is_printable("Ce test 1 est faux.\n"), 0);
}

Test(is_printable, wrongPrintableString_higherCharacter)
{
    char higher_character = 127;
    char string[1] = {0};

    string[0] = higher_character;
    cr_assert_eq(is_printable(string), 0);
}
