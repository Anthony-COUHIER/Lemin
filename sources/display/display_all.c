/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display_all
*/

#include "lemin.h"

void display_all(anthill_t *anthill, paths_t *array)
{
    int start_index = anthill->rooms.index_start;
    int path_valid = 0;

    display(anthill);
    if (!anthill->rooms.rooms) {
        return;
    }
    for (int i = 0; i < anthill->rooms.rooms[start_index].nb_tunnels; i++)
        path_valid += (array[i].valid) ? 1 : 0;
    if (path_valid > 0) {
        display_moves(anthill, array, start_index);
    }
}
