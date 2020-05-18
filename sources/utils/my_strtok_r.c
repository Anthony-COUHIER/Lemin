/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strtok_r
*/

#include <stddef.h>
#include "utils.h"

char *my_strtok_r(char *str, const char *delim, char **backup)
{
    char *end;

    if (!str) {
        str = *backup;
    } if (!*str) {
        *backup = str;
        return NULL;
    }
    str += my_strspn(str, delim);
    if (!*str) {
        *backup = str;
        return NULL;
    }
    end = str + my_strcspn(str, delim);
    if (!*end) {
        *backup = end;
        return str;
    }
    *end = 0;
    *backup = end + 1;
    return str;
}
