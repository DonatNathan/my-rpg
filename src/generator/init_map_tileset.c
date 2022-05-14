/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void init_map(char ***map, load_map_ *load_map)
{
    int y = 0;
    int x = 0;
    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            init_map_square(map, y, x);
        }
    }
}

void init_mob(load_map_ *load_map, game_ *game, layer_ *layer)
{
    int y = 0;
    int x = 0;
    for (y = 0; layer->id_mob[y]; y++) {
        for (x = 0; layer->id_mob[y][x]; x++) {
            init_map_mob(y, x, layer, game);
        }
    }
}

void add_copy_sprite(sfSprite ***map, char ***id_background,
int i, sprite_ *sprite)
{
    int j = 0;
    sfVector2f sprite_scale = {2.5, 2.5};
    sfVector2f pos;

    for (j = 0; map[i][j]; j++) {
        if (sprite->id == my_atoi(id_background[i][j])) {
            pos.x = 40 * j, pos.y = 40 * i;
            sfSprite_setScale(sprite->sprite, sprite_scale);
            map[i][j] = sfSprite_copy(sprite->sprite);
            sfSprite_setPosition((sfSprite *)map[i][j], pos);
        }
    }
}
