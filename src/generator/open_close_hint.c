/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** open_close_hint
*/

#include "../../includes/rpg.h"

void open_close_hint(game_ *game)
{
    if (game->boole->on_hint == 1 && sfKeyboard_isKeyPressed(sfKeyP) &&
    game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_hint = 0;
    } if (game->boole->on_hint == 0 && game->clock->check_secs != 0 &&
    (sfKeyboard_isKeyPressed(sfKeyP))
    && game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_hint = 1;
    }
}
