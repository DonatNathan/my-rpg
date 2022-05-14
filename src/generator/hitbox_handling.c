/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** hitbox_handling
*/

#include "../../includes/rpg.h"

void is_wall(sfSprite ***map, int y, int x, game_ *game)
{
    sfVector2f pos_ = sfSprite_getPosition(map[y][x]);
    if (pos_.y >= 560 - 40 && pos_.y <= 560 && pos_.x >= 970 - 20 &&
    pos_.x <= 970 + 20)
        game->player->m_up = 0;
    if (pos_.y >= 560 + 20 && pos_.y <= 560 + 40 && pos_.x >= 970 - 20 &&
    pos_.x <= 970 + 20)
        game->player->m_down = 0;
    if (pos_.y >= 560 - 20 && pos_.y <= 560 + 20 && pos_.x >= 970 - 60 &&
    pos_.x <= 970 - 40)
        game->player->m_left = 0;
    if (pos_.y >= 560 - 20 && pos_.y <= 560 + 20 && pos_.x >= 970 + 20 &&
    pos_.x <= 970 + 40)
        game->player->m_right = 0;
}

void is_not_wall(sfSprite ***map, int y, int x, game_ *game)
{
    sfVector2f pos_ = sfSprite_getPosition(map[y][x]);
    if (pos_.y > 560 - 40 && pos_.y < 560 && pos_.x > 970 - 20 &&
    pos_.x < 970 + 20)
        game->player->m_up = 1;
    if (pos_.y > 560 + 20 && pos_.y < 560 + 40 && pos_.x > 970 - 20 &&
    pos_.x < 970 + 20)
        game->player->m_down = 1;
    if (pos_.y > 560 - 20 && pos_.y < 560 + 20 && pos_.x > 970 - 60 &&
    pos_.x < 970 - 40)
        game->player->m_left = 1;
    if (pos_.y > 560 - 20 && pos_.y < 560 + 20 && pos_.x > 970 + 20 &&
    pos_.x < 970 + 40)
        game->player->m_right = 1;
}

void check_hitbox(sfSprite ***map, int y, int x, game_ *game)
{
    if (game->layer_->id_hitbox[y][x] != NULL) {
        if (my_atoi(game->layer_->id_hitbox[y][x]) != 1945) {
            is_wall(map, y, x, game);
        } else {
            is_not_wall(map, y, x, game);
        }
    }
}

void render_hitbox(sfSprite ***map, int y, int x, game_ *game)
{
    sfVector2f pos_ = sfSprite_getPosition(map[y][x]);
    if (game->boole->on_hint == 0) {
        if ((pos_.y > 560 - 40 && pos_.y < 560 && pos_.x > 970 - 20 &&
            pos_.x < 970 + 20) || (pos_.y > 560 + 20 && pos_.y < 560 + 40
            && pos_.x > 970 - 20 && pos_.x < 970 + 20) || (pos_.y >
            560 - 20 && pos_.y < 560 + 20 && pos_.x > 970 - 60 && pos_.x <
            970 - 40) || (pos_.y > 560 - 20 && pos_.y < 560 + 20 && pos_.x >
            970 + 20 && pos_.x < 970 + 40))
                sfRenderWindow_drawSprite(game->window, map[y][x], sfFalse);
    }
    if (game->boole->on_hint == 1) {
        sfRenderWindow_drawSprite(game->window, map[y][x], sfFalse);
    }
}

void display_layer_hit(sfSprite ***map, game_ *game, int y,
sfVector2f pos)
{
    int x = 0;
    for (x = 0; map[y][x]; x++) {
        if (map[y][x] != NULL) {
            check_hitbox(map, y, x, game);
            render_hitbox(map, y, x, game);
            sfSprite_setColor(map[y][x], (sfColor){255, 0, 0, 100});
        }
    }
}
