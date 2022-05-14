/*
** EPITECH PROJECT, 2022
** STR_TO_ARRAY
** File description:
** Change str into an array
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

int get_line(char *str, char stop)
{
    int nb = 0;

    for (int cmpt = 0; str[cmpt] != '\0'; cmpt += 1)
        if (str[cmpt] == stop)
            nb += 1;
    nb += 1;
    return (nb);
}

int get_len(char *str, int i, char stop)
{
    int nb = 0;

    for (int cmpt = i; str[cmpt] != stop; cmpt += 1)
        nb += 1;
    nb += 1;
    return (nb);
}

char **str_to_array(char *map, char stop)
{
    int line = 0;
    int column;
    char **new_map = malloc(sizeof(char *) * (get_line(map, stop) + 1));

    for (int cmpt = 0; map[cmpt] != '\0'; cmpt += 1) {
        new_map[line] = malloc(sizeof(char) * (get_len(map, cmpt, stop) + 1));
        for (column = 0; map[cmpt] != stop && map[cmpt] != '\0'; column += 1) {
            new_map[line][column] = map[cmpt];
            cmpt += 1;
        }
        new_map[line][column] = map[cmpt];
        new_map[line][column + 1] = '\0';
        line += 1;
    }
    new_map[line] = NULL;
    return (new_map);
}
