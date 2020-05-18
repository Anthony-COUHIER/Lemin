/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_rooms
*/

#include "lemin.h"
#include "utils.h"

int check_overlay(anthill_t *anthill, int i)
{
    for (int j = i + 1; j < anthill->rooms.nb_rooms; j++) {
        if (
        anthill->rooms.rooms[j].coords[0] == anthill->rooms.rooms[i].coords[0]
        &&
        anthill->rooms.rooms[j].coords[1] == anthill->rooms.rooms[i].coords[1]
        )
        return 1;
    }
    return 0;
}

int check_name(rooms_t *rooms, int i)
{
    for (int j = i + 1; j < rooms->nb_rooms; j++)
        if (!my_strcmp(rooms->rooms[i].name, rooms->rooms[j].name))
            return 1;
    return 0;
}

int check_rooms(anthill_t *anthill, int check_type)
{
    int start_rooms = 0;
    int end_rooms = 0;

    for (int i = 0; i < anthill->rooms.nb_rooms; i++) {
        if (check_overlay(anthill, i) || check_name(&anthill->rooms, i))
            return 1;
        if (anthill->rooms.rooms[i].type == START)
            start_rooms++;
        else if (anthill->rooms.rooms[i].type == END)
            end_rooms++;
    }
    if (check_type && (start_rooms != 1 || end_rooms != 1))
        return 1;
    return 0;
}
