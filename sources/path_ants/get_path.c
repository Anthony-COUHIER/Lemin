/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_path
*/

#include "lemin.h"
#include <stdlib.h>
#include <stdio.h>

int find_index_type(rooms_t *rooms, type_t type)
{
    int index = -1;

    for (int i = 0; i < rooms->nb_rooms; i++) {
        if (rooms->rooms[i].type == type) {
            index = i;
            break;
        }
    }
    return index;
}

int get_path(next_room_t *path, rooms_t *rooms)
{
    room_t *all = rooms->rooms;

    while (path) {
        for (int i = 0; i < all[path->room_index].nb_tunnels; i++) {
            if (all[all[path->room_index].tunnels[i]].visited)
                continue;
            all[all[path->room_index].tunnels[i]].visited = 1;
            if (add_to_path(all[path->room_index].tunnels[i], path))
                return -1;
            if (all[all[path->room_index].tunnels[i]].type == END)
                return 1;
        }
        path = path->next;
    }
    return 0;
}

int stock_path(paths_t *array, next_room_t *path, rooms_t *rooms, int pos)
{
    while (path->next)
        path = path->next;
    array[pos].path = malloc(sizeof(int) * (path->len + 1));
    if (array[pos].path == NULL)
        return 1;
    array[pos].len = path->len;
    for (int i = array[pos].len; path->prev; i--) {
        array[pos].path[i] = path->room_index;
        rooms->rooms[path->room_index].visited = 2;
        path = path->prev;
    }
    array[pos].path[0] = rooms->index_start;
    return 0;
}

int fill_array(rooms_t *rooms, paths_t *array, int index_start)
{
    int index_end = find_index_type(rooms, END);
    next_room_t *path;
    int result;

    rooms->rooms[index_start].visited = 2;
    for (int i = 0; i < rooms->rooms[index_start].nb_tunnels; i++) {
        path = init_path_move(index_start);
        if (path == NULL)
            return 1;
        if ((result = get_path(path, rooms)) == -1)
            return 1;
        else if (result == 1)
            array[i].valid = 1;
        if (array[i].valid == 1 && stock_path(array, path, rooms, i) == 1)
            return 1;
        reset(rooms, index_start, index_end);
        free_all_move(path);
    }
    return 0;
}

int fill_array_path_ants(anthill_t *anthill, paths_t **array)
{
    int start_index = find_index_type(&anthill->rooms, START);

    if (-1 == start_index){
        return 1;
    }
    *array = init_path_array(&anthill->rooms.rooms[start_index]);
    anthill->rooms.index_start = start_index;
    if (*array == NULL)
        return 1;
    if (fill_array(&anthill->rooms, *array, start_index))
        return 1;
    fill_paths_with_ants(*array, anthill, start_index);
    for (int i = 0; i < anthill->rooms.rooms[start_index].nb_tunnels; i++)
        (*array)[i].live_ants = (*array)[i].ants;
    return 0;
}
