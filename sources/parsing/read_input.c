/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** read_input
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"

int read_input(anthill_t *anthill)
{
    char *line = NULL;
    size_t n;
    type_t type = NONE;

    while (-1 != getline(&line, &n, stdin)) {
        if (parse_line(line, &type, anthill)) {
            free(line);
            return 1;
        }
    }
    free(line);
    return 0;
}
