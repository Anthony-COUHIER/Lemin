/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_strspn
*/

int my_strspn(char const *str, char const *chars)
{
    int i, j;

    for (i = 0; str[i]; i++) {
        for (j = 0; chars[j]; j++) {
            if (str[i] == chars[j]) {
                j = -1;
                break;
            }
        }
        if (-1 != j) {
            break;
        }
    }
    return i;
}
