/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** fight_update
*/

#include "../../includes/rpg.h"

void take_dmg(game_ *game)
{
    if (game->clock->check_secs % 200 == 0)
        game->player->stats->life -= 1;
}

void update_button(game_ *game)
{
    update_button_leave(game);
    update_button_fight(game);
    update_button_heal(game);
}

void update_fight(game_ *game)
{
    game->clock->check_secs = game->clock->time.microseconds / 5000;
    if (game->boole->on_fight == 0) {
        take_dmg(game);
        update_button(game);
        sfRenderWindow_drawSprite
        (game->window, game->fight->back->sprite, sfFalse);
        sfRenderWindow_drawSprite
        (game->window, game->fight->leave->sprite, sfFalse);
        sfRenderWindow_drawSprite
        (game->window, game->fight->attack->sprite, sfFalse);
        sfRenderWindow_drawSprite
        (game->window, game->fight->heal->sprite, sfFalse);
        sfRenderWindow_drawText(game->window, game->fight->t_attack->text,
        sfFalse);
        sfRenderWindow_drawText(game->window, game->fight->t_heal->text,
        sfFalse);
        sfRenderWindow_drawText(game->window, game->fight->t_leave->text,
        sfFalse);
        update_enemy_f(game->fight->enemy, game);
    }
}
