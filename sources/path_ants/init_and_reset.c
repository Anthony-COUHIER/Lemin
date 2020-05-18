/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** reset
*/

#include "lemin.h"
#include "stdlib.h"

next_room_t *init_path_move(int index_start)
{
    next_room_t *new = malloc(sizeof(next_room_t));

    if (new == NULL)
        return NULL;
    new->next = NULL;
    new->len = 0;
    new->prev = NULL;
    new->room_index = index_start;
    return new;
}

void reset(rooms_t *rooms, int index_start, int index_end)
{
    for (int i = 0; i < rooms->nb_rooms; i++) {
        if (rooms->rooms[i].visited != 2)
            rooms->rooms[i].visited = 0;
    }
    rooms->rooms[index_start].visited = 1;
    rooms->rooms[index_end].visited = 0;
}

paths_t *init_path_array(room_t *rooms)
{
    paths_t *array = NULL;

    if (!rooms->nb_tunnels)
        return NULL;
    array = malloc(sizeof(paths_t) * rooms->nb_tunnels);
    if (!array)
        return NULL;
    if (!array)
        return NULL;
    for (int i = 0; i < rooms->nb_tunnels; i++) {
        array[i].ants = 0;
        array[i].dead_ants = 0;
        array[i].len = 0;
        array[i].path = NULL;
        array[i].valid = 0;
    }
    return array;
}

int add_to_path(int index, next_room_t *head)
{
    next_room_t *new = malloc(sizeof(next_room_t));
    next_room_t *tmp = head;

    if (new == NULL)
        return 1;
    new->next = NULL;
    new->room_index = index;
    new->len = head->len + 1;
    new->prev = head;

    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return 0;
}
