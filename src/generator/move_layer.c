/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void move_rep(sfSprite *rep, int movement, game_ *game)
{
    sfVector2f pos = sfSprite_getPosition(rep);

    update_cursor(game);
    if (movement == 0) {
        pos.y -= 3 * game->speed + game->player->stats->speed;
        game->y_start -= 3 * game->speed + game->player->stats->speed;
    }
    if (movement == 1) {
        pos.x -= 3 * game->speed + game->player->stats->speed;
        game->x_start -= 3 * game->speed + game->player->stats->speed;
    }
    if (movement == 2) {
        pos.y += 3 * game->speed + game->player->stats->speed;
        game->y_start += 3 * game->speed + game->player->stats->speed;
    }
    if (movement == 3) {
        pos.x += 3 * game->speed + game->player->stats->speed;
        game->x_start += 3 * game->speed + game->player->stats->speed;
    }
    sfSprite_setPosition(rep, pos);
}

void move_tiles(sfSprite ***map, game_ *game, int y, int x)
{
    sfVector2f pos = sfSprite_getPosition(map[y][x]);

    if (game->player->movement == 0) {
        pos.y -= 3 * game->speed + game->player->stats->speed;
    }
    if (game->player->movement == 1) {
        pos.x -= 3 * game->speed + game->player->stats->speed;
    }
    if (game->player->movement == 2) {
        pos.y += 3 * game->speed + game->player->stats->speed;
    }
    if (game->player->movement == 3) {
        pos.x += 3 * game->speed + game->player->stats->speed;
    }
    sfSprite_setPosition(map[y][x], pos);
}
