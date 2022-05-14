/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void display_load_map(char ***map, game_ *game, int movement)
{
    int y = 0;
    int x = 0;

    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            sfRenderWindow_drawRectangleShape(game->window,
            (sfRectangleShape *)map[y][x], sfFalse);
        }
    }
}

void display_layer_(sfSprite ***map, game_ *game, int movement, int y)
{
    int x = 0;
    sfVector2f pos_;
    sfVector2f pos_rep;
    for (x = 0; map[y][x]; x++) {
        if (map[y][x] != NULL) {
            pos_rep = sfSprite_getPosition(game->player->rep);
            pos_ = (sfVector2f){x * 40 + pos_rep.x, y * 40 + pos_rep.y};
            (game->boole->on_hint == 1) ?
            (pos_.y > 560 - 70 && pos_.y < 560 + 50 && pos_.x > 970 - 80
            && pos_.x < 970 + 40) ? sfSprite_setColor(map[y][x],
            (sfColor){0, 0, 255, 150}) : sfSprite_setColor(map[y][x],
            (sfColor){255, 255, 255, 255}) :
            sfSprite_setColor(map[y][x], (sfColor){255, 255, 255, 255});
            sfRenderWindow_drawSprite(game->window, map[y][x], sfFalse);
        }
    }
}

int display_layer_h(sfSprite ***map, game_ *game, sfVector2f pos)
{
    int y = 0;
    int k = 1;

    game->player->m_left = k;
    game->player->m_right = k;
    game->player->m_down = k;
    game->player->m_up = k;
    for (y = 1; map[y]; y++)
        display_layer_hit(map, game, y, pos);
    return (0);
}

int display_layer(sfSprite ***map, game_ *game, int movement)
{
    int y = 1;

    for (y = 1; map[y]; y++) {
        display_layer_(map, game, movement, y);
    }
    return (0);
}

void display_big_tab(char ***map)
{
    int y = 0;
    int x = 0;
    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            my_put_nbr(my_atoi(map[y][x]));
        }
    }
}
