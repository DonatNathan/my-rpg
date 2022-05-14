/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

void check_help(game_ *game, menu_ *menu, int what)
{
    if (game->mouse.x > menu->help->position.x && game->mouse.x <
    menu->help->position.x + menu->help->rect.width *
    menu->help->scale.x && game->mouse.y > menu->help->
    position.y && game->mouse.y < menu->help->position.y + menu->
    help->rect.height * menu->help->scale.y &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        game->boole->on_htp = 1;
        menu->help->rect.left = 372;
        if (game->event.type == sfEvtMouseButtonReleased && what == 0) {
            sfSound_play(game->sounds->click);
        }
        if (game->event.type == sfEvtMouseButtonReleased && what == 1) {
            sfSound_play(game->sounds->click);
        }
    } else
        menu->help->rect.left = 350;
    sfSprite_setTextureRect(menu->help->sprite,
    menu->help->rect);
    change_page(game);
}

void check_event_settings(game_ *game, menu_ *menu)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        if (game->event.type == sfEvtClosed) {
            sfMusic_stop(game->sounds->summer_day);
            sfRenderWindow_close(game->window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            menu->settings->in_settings = 1;
        check_settings(game, menu, 1);
        check_event_buttons(game, menu);
        check_event_cursor(game);
        change_volume(game, menu, menu->settings->music, 0);
        change_volume(game, menu, menu->settings->sounds, 1);
    }
}

void check_settings(game_ *game, menu_ *menu, int what)
{
    if (game->mouse.x > menu->settings->button->position.x && game->mouse.x <
    menu->settings->button->position.x + menu->settings->button->rect.width *
    menu->settings->button->scale.x && game->mouse.y > menu->settings->button->
    position.y && game->mouse.y < menu->settings->button->position.y + menu->
    settings->button->rect.height * menu->settings->button->scale.y) {
        game->boole->on_button = 0;
        menu->settings->button->rect.left = 50;
        if (game->event.type == sfEvtMouseButtonReleased && what == 0) {
            sfSound_play(game->sounds->click);
            launch_settings(game, menu);
        } if (game->event.type == sfEvtMouseButtonReleased && what == 1) {
            sfSound_play(game->sounds->click);
            menu->settings->in_settings = 1;
        }
    } else
        menu->settings->button->rect.left = 0;
    sfSprite_setTextureRect(menu->settings->button->sprite,
    menu->settings->button->rect);
}

void launch_settings(game_ *game, menu_ *menu)
{
    menu->settings->in_settings = 0;
    while (sfRenderWindow_isOpen(game->window) && menu->settings->in_settings
    == 0) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        menu->back->rect.top = 540;
        game->boole->on_button = 1;
        sfRenderWindow_clear(game->window, sfBlack);
        check_event_settings(game, menu);
        draw_settings(game, menu);
        sfRenderWindow_display(game->window);
    }
}

void check_action(game_ *game, button_ *button, menu_ *menu, int action)
{
    if (action == 0)
        choose_music(game, button, menu);
    if (action == 1)
        choose_sound(game, button, menu);
}
