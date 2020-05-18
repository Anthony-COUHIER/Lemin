/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_put_nbr(int number)
{
    char tmp;

    if (number > 9)
        my_put_nbr(number / 10);
    else if (number < 0) {
        number = number * -1;
        write(1, "-", 1);
        my_put_nbr(number / 10);
    }
    tmp = number % 10 + '0';
    write(1, &tmp, 1);
}
