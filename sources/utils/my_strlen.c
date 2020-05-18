/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return i;
}
