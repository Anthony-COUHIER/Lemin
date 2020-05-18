/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** remove_end_spaces
*/

void remove_end_spaces(char *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    while (i && ' ' == str[i - 1]) {
        i--;
    }
    str[i] = 0;
}
