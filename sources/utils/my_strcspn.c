/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strcspn
*/

int my_strcspn(char const *str, char const *chars)
{
    int i, j;

    for (i = 0; str[i]; i++) {
        for (j = 0; chars[j]; j++) {
            if (str[i] == chars[j]) {
                return i;
            }
        }
    }
    return i;
}
