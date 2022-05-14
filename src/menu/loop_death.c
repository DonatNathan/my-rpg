/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to choose my game
*/

#include "../../includes/rpg.h"

void check_event_death(game_ *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfMusic_stop(game->sounds->summer_day);
            save_game(game, game->type);
            sfRenderWindow_close(game->window);
        }
        check_respawn(game);
    }
}

void draw_death(game_ *game)
{
    sfRenderWindow_drawSprite(game->window, game->death->back->sprite,
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->death->quit->sprite,
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->death->respwan->sprite,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->death->t_quit->text, sfFalse);
    sfRenderWindow_drawText(game->window, game->death->t_respawn->text,
    sfFalse);
}

void death_loop(game_ *game)
{
    if (game->player->gold < 10)
        game->player->gold = 0;
    else
        game->player->gold -= 10;
    game->boole->is_dead = 0;
    while (sfRenderWindow_isOpen(game->window) && game->boole->is_dead == 0) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        check_event_death(game);
        draw_death(game);
        update_cursor(game);
        sfRenderWindow_display(game->window);
    }
}
