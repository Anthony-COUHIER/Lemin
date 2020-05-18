/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display
*/

#include "lemin.h"
#include "utils.h"
#include <unistd.h>

void display_ants_nb(int ants)
{
    write(1, "#number_of_ants\n", 16);
    my_put_nbr(ants);
    write(1, "\n", 1);
}

void display_room_info(room_t *room)
{
    write(1, room->name, my_strlen(room->name));
    write(1, " ", 1);
    my_put_nbr(room->coords[0]);
    write(1, " ", 1);
    my_put_nbr(room->coords[1]);
    write(1, "\n", 1);
}

void display_rooms(rooms_t *rooms)
{
    write(1, "#rooms\n", 7);

    for (int i = 0; i < rooms->nb_rooms; i++) {
        if (START == rooms->rooms[i].type) {
            write(1, "##start\n", 8);
        } else if (END == rooms->rooms[i].type) {
            write(1, "##end\n", 6);
        }
        display_room_info(&rooms->rooms[i]);
    }
}

void display_tunnels(tunnels_t *tunnels)
{
    write(1, "#tunnels\n", 9);
    for (int i = 0; i < tunnels->nb_tunnels; i++) {
        write(1, tunnels->tunnels[i][0], my_strlen(tunnels->tunnels[i][0]));
        write(1, "-", 1);
        write(1, tunnels->tunnels[i][1], my_strlen(tunnels->tunnels[i][1]));
        write(1, "\n", 1);
    }
}

void display(anthill_t *anthill)
{
    display_ants_nb(anthill->nb_ants);
    display_rooms(&anthill->rooms);
    display_tunnels(&anthill->tunnels);
}
