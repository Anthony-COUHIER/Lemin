/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_my_strcspn
*/

#include <criterion/criterion.h>

int my_strcspn(char const *str, char const *chars);

Test(my_strcspn, anySimilarity)
{
    cr_assert_eq(my_strcspn("Coucou", "123"), 6);
}

Test(my_strcspn, oneSimilarity)
{
    cr_assert_eq(my_strcspn("Coucou", "u"), 2);
}
