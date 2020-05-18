/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strcmp
*/

int my_strcmp(char const *str1, char const *str2)
{
    while (*str1) {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
