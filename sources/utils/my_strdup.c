/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strdup
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *tmp;
    int size = 0;

    if (str == NULL)
        return NULL;
    while (str[size] != '\0')
        size++;
    if (!(tmp = malloc(sizeof(char) * size + 1)))
        return NULL;
    for (int i = 0; str[i]; i++)
        tmp[i] = str[i];
    tmp[size] = '\0';
    return tmp;
}
