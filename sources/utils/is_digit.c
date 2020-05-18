/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** is_digit
*/

int is_digit(char const *str)
{
    if (!str) {
        return 0;
    }
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}
