/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strtok
*/

#include "utils.h"

char *my_strtok(char *str, const char *delim)
{
    static char *backup;

    return my_strtok_r(str, delim, &backup);
}
