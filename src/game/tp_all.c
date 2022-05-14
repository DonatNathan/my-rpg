/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** tp_all
*/

#include "../../includes/rpg.h"

void tp_rep(game_ *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player->rep);
    pos.x += game->x_start;
    pos.y += game->y_start;
    sfSprite_setPosition(game->player->rep, pos);
}

void tp_layer(sfSprite ***map, game_ *game)
{
    int y = 0;
    int x = 0;
    sfVector2f pos;
    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            pos = sfSprite_getPosition(map[y][x]);
            pos.x += game->x_start;
            pos.y += game->y_start;
            sfSprite_setPosition(map[y][x], pos);
        }
    }
}

void tp_all(game_ *game)
{
    tp_layer(game->layer_->map_layer_1, game);
    tp_layer(game->layer_->map_layer_2, game);
    tp_layer(game->layer_->map_layer_3, game);
    tp_rep(game);
}
