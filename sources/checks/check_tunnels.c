/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** check_tunnels
*/

#include "lemin.h"
#include "utils.h"

int tunnel_error(tunnels_t *tunnels, int i, int room1_exist, int room2_exist);

int check_tunnels(tunnels_t *tunnels, rooms_t *rooms)
{
    int room1_exist, room2_exist;

    for (int i = 0; i < tunnels->nb_tunnels; i++) {
        room1_exist = 0;
        room2_exist = 0;
        for (int j = 0; j < rooms->nb_rooms; j++) {
            if (!my_strcmp(tunnels->tunnels[i][0], rooms->rooms[j].name))
                room1_exist++;
            if (!my_strcmp(tunnels->tunnels[i][1], rooms->rooms[j].name))
                room2_exist++;
        }
        if (tunnel_error(tunnels, i, room1_exist, room2_exist)) {
            return 1;
        }
    }
    return 0;
}

int tunnel_error(tunnels_t *tunnels, int i, int room1_exist, int room2_exist)
{
    if (!my_strcmp(tunnels->tunnels[i][0], tunnels->tunnels[i][1])) {
        tunnels->nb_tunnels--;
        realloc_tunnels(tunnels);
        return 1;
    }
    if (room1_exist != 1 || room2_exist != 1) {
        tunnels->nb_tunnels--;
        realloc_tunnels(tunnels);
        return 1;
    }
    return 0;
}
