/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strstr
*/

#include <stddef.h>

char *my_strstr(char *haystack, char *needle)
{
    int i;

    while (*haystack) {
        i = 0;
        while (haystack[i] && needle[i] && haystack[i] == needle[i]) {
            i++;
        }
        if (!needle[i])
            return haystack;
        haystack++;
    }
    return NULL;
}
