/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void init_parrot(game_ *game)
{
    if (game->boole->is_friend == 1) {
        game->clock->check_secs = 0;
        game->boole->is_friend = 0;
        game->menu->parrot->position = (sfVector2f)
        {game->player->position.x + 50, game->player->position.y};
        sfSprite_setPosition
        (game->menu->parrot->sprite, game->menu->parrot->position);
    } else if (game->boole->is_friend == 0) {
        game->clock->check_secs = 0;
        game->boole->is_friend = 1;
    }
}

void spawn_parrot(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && game->clock->check_secs != 0) {
        init_parrot(game);
    }
    if (game->boole->is_friend == 0)
        check_parrot_move(game->menu);
}
