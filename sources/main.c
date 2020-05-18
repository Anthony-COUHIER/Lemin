/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** main
*/

#include <stdlib.h>
#include "lemin.h"

int main(void)
{
    anthill_t anthill = {0};
    paths_t *array = NULL;

    read_input(&anthill);
    link_rooms(&anthill.rooms, &anthill.tunnels);
    fill_array_path_ants(&anthill, &array);
    display_all(&anthill, array);
    free_all(&anthill.rooms, &anthill.tunnels, array);
    return 0;
}
