/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to draw my game
*/

#include "../../includes/rpg.h"

void draw_saves(game_ *game, menu_ *menu)
{
    sfRenderWindow_drawSprite(game->window, menu->saves->first->sprite,
    sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->saves->second->sprite,
    sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->saves->third->sprite,
    sfFalse);
    sfRenderWindow_drawText(game->window, menu->saves->first->text->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, menu->saves->second->text->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, menu->saves->third->text->text,
    sfFalse);
}

void draw_menu(game_ *game, menu_ *menu)
{
    sfRenderWindow_drawSprite(game->window, menu->back->sprite, sfFalse);
    if (menu->on_load == 1) {
        sfRenderWindow_drawSprite(game->window, menu->logo->sprite, sfFalse);
        sfRenderWindow_drawSprite(game->window, menu->new->sprite, sfFalse);
        sfRenderWindow_drawSprite(game->window, menu->exit->sprite, sfFalse);
        sfRenderWindow_drawSprite(game->window, menu->load->sprite, sfFalse);
    } else
        draw_saves(game, game->menu);
    update_coin(menu->coin, game);
    update_animal(menu->parrot, 48, 48, game);
    update_htp(game);
    sfRenderWindow_drawSprite(game->window, menu->help->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window,
    menu->settings->button->sprite, sfFalse);
    update_cursor(game);
}

void update_loading(game_ *game)
{
    sfRenderWindow_drawSprite(game->window, game->loading->sprite, sfFalse);
    sfRenderWindow_display(game->window);
    game->loading->rect.left += 1200;
    if (game->loading->rect.left > 2400)
        game->loading->rect.left = 0;
    sfSprite_setTextureRect(game->loading->sprite, game->loading->rect);
}
