/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** test_add_tunnels
*/

#include <criterion/criterion.h>
#include "lemin.h"
#include "utils.h"

Test(add_tunnels, anyError)
{
    tunnels_t tunnels = {0, NULL};
    char *info[4] = {"start", "none", NULL, NULL};

    cr_assert_eq(add_tunnel(&tunnels, info), 0);
}
