/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to choose my game
*/

#include "../../includes/rpg.h"

void do_respawn(game_ *game)
{
    game->player->stats->life = (game->bonus->life + 3) / 2;
    game->boole->is_dead = 1;
    tp_pos(game, game->type, 1);
}

int check_respawn(game_ *game)
{
    sfVector2f p_respawn = sfSprite_getPosition(game->death->respwan->sprite);
    sfVector2f p_quit = sfSprite_getPosition(game->death->quit->sprite);

    if (game->mouse.x > p_respawn.x && game->mouse.x < p_respawn.x + 380 &&
    game->mouse.y > p_respawn.y && game->mouse.y < p_respawn.y + 150) {
        sfText_setColor(game->death->t_respawn->text, sfWhite);
        if (game->event.type == sfEvtMouseButtonReleased) {
            do_respawn(game);
        }
    } else if (game->mouse.x > p_quit.x && game->mouse.x < p_quit.x + 380 &&
    game->mouse.y > p_quit.y && game->mouse.y < p_quit.y + 150) {
        sfText_setColor(game->death->t_quit->text, sfWhite);
        (game->event.type == sfEvtMouseButtonReleased) ? (quit_game(game)) : 1;
    } else {
        sfText_setColor(game->death->t_quit->text, sfBlack);
        sfText_setColor(game->death->t_respawn->text, sfBlack);
    }
    return (0);
}

void create_death_menu(game_ *game)
{
    game->death = malloc(sizeof(death_));
    game->death->back = create_button((sfVector2f){0, 0},
    (sfVector2f){1.6, 1.7}, "pictures/menu/over.png");
    game->death->quit = create_button((sfVector2f){800, 800},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->death->respwan = create_button((sfVector2f){800, 600},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->death->t_quit = create_text("QUIT", (sfVector2f){3, 3},
    (sfVector2f){900, 820}, "font/Stardew_Valley.ttf");
    game->death->t_respawn = create_text("RESPAWN", (sfVector2f){3, 3},
    (sfVector2f){840, 620}, "font/Stardew_Valley.ttf");
}
