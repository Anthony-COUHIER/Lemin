/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019 [SSH: 192.168.159.130]
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

typedef enum type_e
{
    NONE,
    START,
    END
} type_t;

typedef struct room_s
{
    char *name;
    int coords[2];
    int visited;
    int distance;
    type_t type;
    int nb_tunnels;
    int ant;
    int *tunnels;
} room_t;

typedef struct rooms_s
{
    int nb_rooms;
    int index_start;
    room_t *rooms;
} rooms_t;

typedef struct tunnels_s
{
    int nb_tunnels;
    char ***tunnels;
} tunnels_t;

typedef struct anthill_s
{
    int nb_ants;
    rooms_t rooms;
    tunnels_t tunnels;
} anthill_t;

typedef struct next_room_s
{
    int len;
    int room_index;
    struct next_room_s *next;
    struct next_room_s *prev;
} next_room_t;

typedef struct paths_s
{
    int valid;
    int ants;
    int dead_ants;
    int live_ants;
    int len;
    int *path;
} paths_t;

// INPUT READING AND PARSING
int read_input(anthill_t *anthill);
int parse_line(char *line, type_t *type, anthill_t *anthill);
void set_type(char *line, type_t *type);
int get_ants_number(char *line, int *first_pass, anthill_t *anthill);
int get_line_infos(char *line, type_t *type, \
char *infos[4], anthill_t *anthill);

// ADD ROOMS AND TUNNELS
int add_room_or_tunnel(char *infos[4], type_t type, anthill_t *anthill);
int add_room(rooms_t *rooms, char *infos[4], type_t type);
int add_tunnel(tunnels_t *tunnels, char *infos[4]);
int link_rooms(rooms_t *rooms, tunnels_t *tunnels);
void free_all(rooms_t *rooms, tunnels_t *tunnels, paths_t *array);
int realloc_tunnels(tunnels_t *tunnels);

// CHECKS
int check_rooms(anthill_t *anthill, int check_type);
int check_tunnels(tunnels_t *tunnels, rooms_t *all);

// GET PATH
int find_index_type(rooms_t *rooms, type_t type);
int fill_array_path_ants(anthill_t *anthill, paths_t **array);
next_room_t *init_path_move(int index_start);
void reset(rooms_t *rooms, int index_start, int index_end);
paths_t *init_path_array(room_t *rooms);
int add_to_path(int index, next_room_t *prev);
void free_all_move(next_room_t *path);
int get_pos(paths_t *array, rooms_t *rooms, int index);
void move_ants_to_end_room(paths_t *paths, rooms_t *rooms, int i
, int *end_ants);
void put_new_ant_in_path(paths_t *array, int i, rooms_t *rooms);

// DISLAY
void display_all(anthill_t *anthill, paths_t *array);
void display(anthill_t *anthill);
void display_moves(anthill_t *anthill, paths_t *array, int start_index);
void display_move(room_t *room, int space);

// SPLIT ANTS
void fill_paths_with_ants(paths_t *array, anthill_t *anthill, int start_index);

#endif /* !LEMIN_H_ */
