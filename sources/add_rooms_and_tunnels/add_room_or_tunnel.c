/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** add_room_or_tunnel
*/

#include <stddef.h>
#include "lemin.h"

int add_room_or_tunnel(char *infos[4], type_t type, anthill_t *anthill)
{
    if (infos[0] == NULL) {
        if (add_tunnel(&anthill->tunnels, infos + 1)) {
            return 1;
        }
    } else {
        if (add_room(&anthill->rooms, infos, type)) {
            return 1;
        }
    }
    return 0;
}
