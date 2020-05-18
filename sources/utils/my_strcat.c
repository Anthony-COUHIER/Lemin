/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strcat
*/

#include "utils.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strcat(char const *str1, char const *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *dest = malloc(len + 1);
    int i, j;

    if (!dest) {
        return NULL;
    }
    dest[len] = 0;
    for (i = 0; str1[i]; i++) {
        dest[i] = str1[i];
    }
    for (j = 0; str2[j]; j++) {
        dest[i + j] = str2[j];
    }
    return dest;
}
