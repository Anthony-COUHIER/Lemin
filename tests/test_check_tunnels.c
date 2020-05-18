/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** test1_check_tunnels
*/

#include <criterion/criterion.h>
#include "lemin.h"
#include "utils.h"

Test(check_tunnels, anyError)
{
    tunnels_t tunnels = {0, NULL};
    rooms_t rooms = {0};
    char *info_1[4] = {"start", "12", "4", NULL};
    char *info_2[4] = {"none", "3", "2", NULL};
    char *info_3[4] = {"end", "15", "26", NULL};
    char *info_4[4] = {"start", "none", NULL, NULL};
    char *info_5[4] = {"none", "end", NULL, NULL};
    char *info_6[4] = {"end", "start", NULL, NULL};

    add_room(&rooms, info_1, START);
    add_room(&rooms, info_2, NONE);
    add_room(&rooms, info_3, END);
    add_tunnel(&tunnels, info_4);
    add_tunnel(&tunnels, info_5);
    add_tunnel(&tunnels, info_6);
    cr_assert_eq(check_tunnels(&tunnels, &rooms), 0);
}

Test(check_tunnels, errorInfinityLoop_sameRoomsForOneTunnel)
{
    tunnels_t tunnels = {0, NULL};
    rooms_t rooms = {0};
    char *info_1[4] = {"start", "12", "4", NULL};
    char *info_2[4] = {"none", "3", "2", NULL};
    char *info_3[4] = {"end", "15", "26", NULL};
    char *info_4[4] = {"start", "none", NULL, NULL};
    char *info_5[4] = {"none", "end", NULL, NULL};
    char *info_6[4] = {"start", "start", NULL, NULL};

    add_room(&rooms, info_1, START);
    add_room(&rooms, info_2, NONE);
    add_room(&rooms, info_3, END);
    add_tunnel(&tunnels, info_4);
    add_tunnel(&tunnels, info_5);
    add_tunnel(&tunnels, info_6);
    cr_assert_eq(check_tunnels(&tunnels, &rooms), 1);
}

Test(check_tunnels, errorUnknownRoom_testOne)
{
    tunnels_t tunnels = {0, NULL};
    rooms_t rooms = {0};
    char *info_1[4] = {"start", "12", "4", NULL};
    char *info_2[4] = {"none", "3", "2", NULL};
    char *info_3[4] = {"end", "15", "26", NULL};
    char *info_4[4] = {"start", "none", NULL, NULL};
    char *info_5[4] = {"none", "end", NULL, NULL};
    char *info_6[4] = {"nani", "start", NULL, NULL};

    add_room(&rooms, info_1, START);
    add_room(&rooms, info_2, NONE);
    add_room(&rooms, info_3, END);
    add_tunnel(&tunnels, info_4);
    add_tunnel(&tunnels, info_5);
    add_tunnel(&tunnels, info_6);
    cr_assert_eq(check_tunnels(&tunnels, &rooms), 1);
}

Test(check_tunnels, errorUnknownRoom_testTwo)
{
    tunnels_t tunnels = {0, NULL};
    rooms_t rooms = {0};
    char *info_1[4] = {"start", "12", "4", NULL};
    char *info_2[4] = {"none", "3", "2", NULL};
    char *info_3[4] = {"end", "15", "26", NULL};
    char *info_4[4] = {"start", "none", NULL, NULL};
    char *info_5[4] = {"none", "nani", NULL, NULL};
    char *info_6[4] = {"end", "start", NULL, NULL};

    add_room(&rooms, info_1, START);
    add_room(&rooms, info_2, NONE);
    add_room(&rooms, info_3, END);
    add_tunnel(&tunnels, info_4);
    add_tunnel(&tunnels, info_5);
    add_tunnel(&tunnels, info_6);
    cr_assert_eq(check_tunnels(&tunnels, &rooms), 1);
}
