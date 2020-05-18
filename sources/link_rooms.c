/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** add_tunnel
*/

#include "lemin.h"
#include "utils.h"
#include <stdlib.h>

int realloc_room_tunnels(room_t *room)
{
    int *new = malloc(sizeof(int) * (room->nb_tunnels + 1));

    if (!new) {
        return 1;
    }
    for (int i = 0; i < room->nb_tunnels; i++) {
        new[i] = room->tunnels[i];
    }
    free(room->tunnels);
    room->tunnels = new;
    room->nb_tunnels++;
    return 0;
}

int find_room_index(char *name, rooms_t *rooms)
{
    int index = -1;

    for (int i = 0; -1 == index && i < rooms->nb_rooms; i++) {
        if (!my_strcmp(name, rooms->rooms[i].name)) {
            index = i;
        }
    }
    return index;
}

int link_rooms(rooms_t *rooms, tunnels_t *tunnels)
{
    int room1, room2;

    for (int j = 0; j < tunnels->nb_tunnels; j++) {
        room1 = find_room_index(tunnels->tunnels[j][0], rooms);
        room2 = find_room_index(tunnels->tunnels[j][1], rooms);
        if (realloc_room_tunnels(&rooms->rooms[room1])) {
            return 1;
        }
        if (realloc_room_tunnels(&rooms->rooms[room2])) {
            return 1;
        }
        rooms->rooms[room1].tunnels[rooms->rooms[room1].nb_tunnels - 1] = room2;
        rooms->rooms[room2].tunnels[rooms->rooms[room2].nb_tunnels - 1] = room1;
    }
    return 0;
}
