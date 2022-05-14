/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

int quit_game(game_ *game)
{
    game->boole->on_quit = 1;
    save_game(game, game->type);
    loop_menu(game, game->menu);
    return (0);
}

void check_event_pause(game_ *game)
{
    if (game->mouse.x > game->inv->quit->position.x && game->mouse.x <
    game->inv->quit->position.x + 370 && game->mouse.y > game->inv->quit->
    position.y && game->mouse.y < game->inv->quit->position.y + 140 &&
    game->boole->on_quit == 0) {
        sfText_setColor(game->inv->text_quit->text, sfWhite);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            quit_game(game);
    } else
        sfText_setColor(game->inv->text_quit->text, sfBlack);
    if (game->mouse.x > game->inv->settings->position.x && game->mouse.x <
    game->inv->settings->position.x + 370 && game->mouse.y > game->inv->
    settings->position.y && game->mouse.y < game->inv->settings->position.y +
    140 && game->boole->on_quit == 0) {
        sfText_setColor(game->inv->text_settings->text, sfWhite);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            launch_settings(game, game->menu);
    } else
        sfText_setColor(game->inv->text_settings->text, sfBlack);
}
