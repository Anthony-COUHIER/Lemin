/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** is_printable
*/

int is_printable(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 32 || str[i] > 126)
            return 0;
    return 1;
}
