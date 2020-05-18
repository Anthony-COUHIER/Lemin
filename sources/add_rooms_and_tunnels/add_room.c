/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** get_new_rooms
*/

#include <stdlib.h>
#include "lemin.h"
#include "utils.h"

room_t *realloc_rooms(int nb_rooms, room_t *old)
{
    room_t *new_room = malloc(sizeof(room_t) * ((nb_rooms + 1) + 1));

    if (new_room == NULL)
        return NULL;
    else if (old == NULL)
        return new_room;
    for (int i = 0; i < nb_rooms; i++)
        new_room[i] = old[i];
    free(old);
    return new_room;
}

int add_room(rooms_t *rooms, char *infos[4], type_t type)
{
    room_t *new_room = realloc_rooms(rooms->nb_rooms, rooms->rooms);

    if (new_room == NULL)
        return 1;
    new_room[rooms->nb_rooms].type = type;
    new_room[rooms->nb_rooms].name = my_strdup(infos[0]);
    if (new_room[rooms->nb_rooms].name == NULL)
        return 1;
    new_room[rooms->nb_rooms].coords[0] = my_atoi(infos[1]);
    new_room[rooms->nb_rooms].coords[1] = my_atoi(infos[2]);
    new_room[rooms->nb_rooms].nb_tunnels = 0;
    new_room[rooms->nb_rooms].tunnels = 0;
    new_room[rooms->nb_rooms].visited = 0;
    new_room[rooms->nb_rooms].distance = 0;
    new_room[rooms->nb_rooms].ant = 0;
    rooms->rooms = new_room;
    rooms->nb_rooms++;
    return 0;
}
