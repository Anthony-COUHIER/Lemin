/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** put_ants
*/

#include "lemin.h"
#include <stdio.h>

void fill_paths_with_ants(paths_t *array, anthill_t *anthill, int start_index)
{
    int min;
    int nbr_ants = anthill->nb_ants;
    int index = 0;

    while (nbr_ants) {
        min = array[index].len + array[index].ants;
        for (int i = 0; i < anthill->rooms.rooms[start_index].nb_tunnels; i++) {
            if (array[i].valid != 1)
                continue;
            if ((array[i].len + array[i].ants) < min) {
                min = array[i].len + array[i].ants;
                index = i;
            }
        }
        array[index].ants++;
        nbr_ants--;
    }
}
