/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** parse_line.c
*/

#include <stddef.h>
#include "utils.h"
#include "lemin.h"

int parse_line(char *line, type_t *type, anthill_t *anthill)
{
    char *comment = my_strstr(line, "#");
    static int first_pass = 1;
    int is_command = (line == my_strstr(line, "##"));
    char *infos[4] = {NULL};

    if (!is_command && comment)
        *comment = '\0';
    my_strtok(line, "\n");
    remove_end_spaces(line);
    if (first_pass && line[0])
        return get_ants_number(line, &first_pass, anthill) ? 1 : 0;
    if (is_command)
        set_type(line, type);
    if (!is_command && line[0] && line[0] != '\n')
        if (get_line_infos(line, type, infos, anthill))
            return 1;
    return 0;
}

int get_ants_number(char *line, int *first_pass, anthill_t *anthill)
{
    if (is_digit(line)) {
        anthill->nb_ants = my_atoi(line);
        *first_pass = 0;
        return 0;
    } else {
        return 1;
    }
}

void set_type(char *line, type_t *type)
{
    if (!my_strcmp("##start", line)) {
        *type = START;
    } else if (!my_strcmp("##end", line)) {
        *type = END;
    }
}

void fill_info(char *line, char *infos[4], int test, int *in_tunnel)
{
    if (!test) {
        infos[0] = my_strtok(line, " ");
        infos[1] = my_strtok(NULL, " ");
        infos[2] = my_strtok(NULL, " ");
        infos[3] = my_strtok(NULL, "");
    } else {
        *in_tunnel = 1;
        infos[0] = NULL;
        infos[1] = my_strtok(line, "-");
        infos[2] = my_strtok(NULL, "");
        infos[3] = my_strstr(infos[2], "-");
    }
}

int get_line_infos(char *line, type_t *type, char *infos[4], anthill_t *anthill)
{
    static int in_tunnel = 0;

    if (!in_tunnel && my_strstr(line, " ")) {
        fill_info(line, infos, 0, &in_tunnel);
        if (!is_digit(infos[1]) || !is_digit(infos[2]) || infos[3])
            return 1;
    } else if (my_strstr(line, "-")) {
        fill_info(line, infos, 1, &in_tunnel);
        if (infos[3])
            return 1;
    } else {
        return 1;
    }
    if (add_room_or_tunnel(infos, *type, anthill))
        return 1;
    if (check_rooms(anthill, 0)
    || check_tunnels(&anthill->tunnels, &anthill->rooms))
        return 1;
    *type = NONE;
    return 0;
}
