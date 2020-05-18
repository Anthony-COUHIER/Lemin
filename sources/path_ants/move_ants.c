/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** move_ants.c
*/

#include "lemin.h"
#include "utils.h"
#include <unistd.h>

int get_pos(paths_t *array, rooms_t *rooms, int index)
{
    int pos = 0;

    while (rooms->rooms[array[index].path[pos]].ant) {
        if (rooms->rooms[array[index].path[pos]].type == END)
            break;
        pos++;
    }
    return pos;
}

void move_ants_to_end_room(paths_t *paths, rooms_t *rooms, int i, int *end_ants)
{
    room_t *room = rooms->rooms;
    int pos = get_pos(paths, rooms, i);
    int space = 0;

    while (pos > 0 && paths[i].dead_ants < paths[i].ants) {
        if (room[paths[i].path[pos]].type == END) {
            (*end_ants)++;
            paths[i].dead_ants++;
        }
        room[paths[i].path[pos]].ant = room[paths[i].path[pos - 1]].ant;
        if (paths[i].live_ants == 0)
            room[paths[i].path[pos - 1]].ant = -1;
        if (room[paths[i].path[pos]].ant != -1)
            display_move(&room[paths[i].path[pos]], space);
        space = 1;
        pos--;
    }
}

void put_new_ant_in_path(paths_t *array, int i, rooms_t *rooms)
{
    static int ants = 0;

    if (array[i].live_ants > 0) {
        array[i].live_ants--;
        ants++;
        rooms->rooms[array[i].path[0]].ant = ants;
    }
}