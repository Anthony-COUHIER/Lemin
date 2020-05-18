/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** free_all
*/

#include <stdlib.h>
#include "lemin.h"

void free_tunnels(tunnels_t *tunnels)
{
    for (int i = 0; i < tunnels->nb_tunnels; i++) {
        free(tunnels->tunnels[i][0]);
        free(tunnels->tunnels[i][1]);
        free(tunnels->tunnels[i]);
    }
    free(tunnels->tunnels);
}

void free_rooms(rooms_t * rooms)
{
    for (int i = 0; i < rooms->nb_rooms; i++) {
        free(rooms->rooms[i].name);
        free(rooms->rooms[i].tunnels);
    }
    free(rooms->rooms);
}

void free_array(rooms_t *rooms, paths_t *array, int start_index)
{
    for (int i = 0; i < rooms->rooms[start_index].nb_tunnels; i++)
        free(array[i].path);
    free(array);
}

void free_all(rooms_t *rooms, tunnels_t *tunnels, paths_t *array)
{
    if (array) {
        free_array(rooms, array, rooms->index_start);
    }
    free_tunnels(tunnels);
    free_rooms(rooms);
}

void free_all_move(next_room_t *path)
{
    next_room_t *tmp;

    while (path->next) {
        tmp = path;
        path = path->next;
        free(tmp);
    }
    free(path);
}
