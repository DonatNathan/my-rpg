/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

void draw_sounds(game_ *game, menu_ *menu)
{
    sfRenderWindow_drawSprite
    (game->window, menu->settings->bar_music->sprite, sfFalse);
    sfRenderWindow_drawSprite
    (game->window, menu->settings->bar_sounds->sprite, sfFalse);
    sfRenderWindow_drawSprite
    (game->window, menu->settings->music->sprite, sfFalse);
    sfRenderWindow_drawSprite
    (game->window, menu->settings->sounds->sprite, sfFalse);
}

void draw_settings(game_ *game, menu_ *menu)
{
    sfRenderWindow_drawSprite(game->window, menu->back->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window,
    menu->settings->back->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window,
    menu->settings->button->sprite, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->all->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->all->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->big->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->little->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->max->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->min->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->mid->text, sfFalse);
    draw_sounds(game, menu);
    update_cursor(game);
}

void do_settings(game_ *game, int action)
{
    if (action == 0) {
        sfRenderWindow_setFramerateLimit(game->window, 120);
        game->speed = 1;
    } if (action == 1) {
        sfRenderWindow_setFramerateLimit(game->window, 60);
        game->speed = 2;
    } if (action == 2) {
        sfRenderWindow_setFramerateLimit(game->window, 30);
        game->speed = 4;
    } if (action == 3) {
        sfMusic_stop(game->sounds->ocean);
        sfRenderWindow_close(game->window);
        launch_menu((sfVideoMode){1920, 1080, 120}, (sfVector2u){1920, 1080},
        game->pseudo);
    } if (action == 4 && game->boole->on_quit == 1) {
        sfMusic_stop(game->sounds->ocean);
        sfRenderWindow_close(game->window);
        launch_menu((sfVideoMode){800, 600, 120}, (sfVector2u){800, 600},
        game->pseudo);
    }
}

void is_on_button(game_ *game, text_ *text, int len, int action)
{
    if (game->mouse.x > text->position.x && game->mouse.x < text->position.x +
    len && game->mouse.y > text->position.y && game->mouse.y < text->position.y
    + 60) {
        sfText_setColor(text->text, sfRed);
        game->boole->on_button = 0;
        if (game->event.type == sfEvtMouseButtonReleased) {
            sfSound_play(game->sounds->click);
            do_settings(game, action);
        }
    } else
        sfText_setColor(text->text, sfBlack);
}

void check_event_buttons(game_ *game, menu_ *menu)
{
    is_on_button(game, menu->settings->max, 155, 0);
    is_on_button(game, menu->settings->mid, 135, 1);
    is_on_button(game, menu->settings->min, 130, 2);
    is_on_button(game, menu->settings->big, 230, 3);
    is_on_button(game, menu->settings->little, 190, 4);
}
