/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** add_tileset
*/

#include "../../includes/rpg.h"

int find_highest(char ***id_ground)
{
    int y = 0;
    int x = 0;
    int max = 0;

    for (; id_ground[y]; y++) {
        for (x = 0; id_ground[y][x]; x++) {
            (my_atoi(id_ground[y][x]) > max) ? (max = my_atoi(id_ground[y][x]))
            : 1;
        }
    }
    return (max);
}

int add_tileset(sfSprite ***map, sprite_ *sprite, char ***id_background,
int highest)
{
    int i = 0;

    for (; map[i]; i++)
        add_copy_sprite(map, id_background, i, sprite);
    if (sprite->id > highest)
        return (0);
    if (sprite->next != NULL)
        add_tileset(map, sprite->next, id_background, highest);
    return (0);
}
