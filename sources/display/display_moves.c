/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display_moves
*/

#include "lemin.h"
#include "utils.h"
#include <unistd.h>

void display_move(room_t *room, int space)
{
    if (space)
        write(1, " ", 1);
    write(1, "P", 1);
    my_put_nbr(room->ant);
    write(1, "-", 1);
    write(1, room->name, my_strlen(room->name));
}

void display_moves(anthill_t *anthill, paths_t *array, int start_index)
{
    int end_ants = 0;
    int space = 0;
    int nb_tunnel = anthill->rooms.rooms[start_index].nb_tunnels;

    write(1, "#moves\n", 7);
    while (end_ants < anthill->nb_ants) {
        space = 0;
        for (int i = 0; i < nb_tunnel; i++) {
            if (array[i].valid && array[i].dead_ants < array[i].ants) {
                write(1, " ", space);
                put_new_ant_in_path(array, i, &anthill->rooms);
                move_ants_to_end_room(array, &anthill->rooms, i, &end_ants);
                space = 1;
            }
        }
        write(1, "\n", 1);
    }
}
