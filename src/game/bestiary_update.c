/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** bestiary_update
*/

#include "../../includes/rpg.h"

void draw_bestiary(game_ *game)
{
    sfRenderWindow_drawText(game->window, game->best->page_l->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->best->page_r->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->best->name_l->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->best->name_r->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->best->pv_l->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->best->pv_r->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->best->dmg_l->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->best->dmg_r->text,
    sfFalse);
    sfRenderWindow_drawSprite
    (game->window, game->best->arrow_l->sprite, sfFalse);
    sfRenderWindow_drawSprite
    (game->window, game->best->arrow_r->sprite, sfFalse);
}

void update_bestiary_text(game_ *game, char **tab, char **tab_2)
{
    sfText_setString(game->best->name_l->text, tab[1]);
    sfText_setString(game->best->name_r->text, tab_2[1]);
    sfText_setString(game->best->dmg_l->text, tab_2[3]);
    sfText_setString(game->best->dmg_r->text, tab_2[3]);
    sfText_setString(game->best->pv_l->text, tab[2]);
    sfText_setString(game->best->pv_r->text, tab_2[2]);
    sfText_setString(game->best->page_l->text,
    new_put_nbr(game->best->page));
    sfText_setString(game->best->page_r->text,
    new_put_nbr(game->best->page + 1));
}

void update_bestiary(game_ *game)
{
    char **tab = my_split_tabn(game->best->mob_stats[game->best->page], '/');
    char **tab_2 = my_split_tabn(game->best->mob_stats[game->best->page + 1],
    '/');

    game->clock->check_secs = game->clock->time.microseconds / 5000;
    if (game->boole->on_best == 0) {
        update_bestiary_text(game, tab, tab_2);
        sfRenderWindow_drawSprite
        (game->window, game->best->back->sprite, sfFalse);
        draw_bestiary(game);
        update_enemy_best(game->best->enemy_1, game);
        update_enemy_best(game->best->enemy_2, game);
    }
}
