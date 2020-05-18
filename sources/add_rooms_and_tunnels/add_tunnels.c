/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** collect_tunnels
*/

#include "lemin.h"
#include "utils.h"
#include <stdlib.h>

char ***malloc_tunnel(int size)
{
    char ***new = malloc(sizeof(char *) * (size + 1));

    if (new == NULL)
        return NULL;
    new[size - 1] = malloc(sizeof(char *) * 2);
    if (new[size - 1] == NULL)
        return NULL;
    new[size] = NULL;
    return new;
}

int realloc_tunnels(tunnels_t *tunnels)
{
    char ***new = malloc_tunnel(tunnels->nb_tunnels + 1);

    if (new == NULL || new[tunnels->nb_tunnels] == NULL)
        return 1;
    for (int i = 0; i < tunnels->nb_tunnels; i++) {
        new[i] = tunnels->tunnels[i];
    }
    free(tunnels->tunnels);
    tunnels->tunnels = new;
    return 0;
}

int add_tunnel(tunnels_t *tunnels, char *infos[4])
{
    if (realloc_tunnels(tunnels) == 1)
        return 1;
    tunnels->tunnels[tunnels->nb_tunnels][0] = my_strdup(infos[0]);
    tunnels->tunnels[tunnels->nb_tunnels][1] = my_strdup(infos[1]);
    tunnels->nb_tunnels++;
    return 0;
}
