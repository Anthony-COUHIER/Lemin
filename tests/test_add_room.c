/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** test_add_room
*/

#include <criterion/criterion.h>
#include "lemin.h"
#include "utils.h"

Test(add_room, anyError)
{
    rooms_t rooms = {0};
    char *info_1[4] = {"start", "12", "4", NULL};

    cr_assert_eq(add_room(&rooms, info_1, START), 0);
}

Test(add_room, errorRoomNameNull)
{
    rooms_t rooms = {0};
    char *info_1[4] = {NULL, "12", "4", NULL};

    cr_assert_eq(add_room(&rooms, info_1, START), 1);
}
