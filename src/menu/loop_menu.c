/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my menu
*/

#include "../../includes/rpg.h"

void check_all_buttons(game_ *game, menu_ *menu)
{
    check_button(game, menu->new, 1, menu);
    check_button(game, menu->load, 2, menu);
    check_button(game, menu->exit, 3, menu);
    check_saves(game, menu->saves->first, 4, menu);
    check_saves(game, menu->saves->second, 5, menu);
    check_saves(game, menu->saves->third, 6, menu);
    check_parrot(game, menu, game->mouse);
    check_on_coin(game, menu->coin, menu->parrot);
    check_settings(game, menu, 0);
    check_help(game, menu, 0);
    check_event_cursor(game);
}

int check_event_menu(game_ *game, menu_ *menu)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyE)) {
            sfMusic_stop(game->sounds->ocean);
            sfRenderWindow_close(game->window);
        }
        (sfKeyboard_isKeyPressed(sfKeyN)) ? (game->boole->is_quit = 0),
        launch_game(game, 0, 1, 0), 0 : 1;
        (sfKeyboard_isKeyPressed(sfKeyL)) ? menu->on_load = 0, 0 : 1;
        (sfKeyboard_isKeyPressed(sfKeyG)) ? launch_map_generator(game), 0 : 1;
        if (menu->on_load == 0 && sfKeyboard_isKeyPressed(sfKeyEscape))
            menu->on_load = 1;
        if (game->boole->on_htp == 1 && sfKeyboard_isKeyPressed(sfKeyEscape))
            game->boole->on_htp = 0;
        check_all_buttons(game, menu);
    }
    return (0);
}

void loop_menu(game_ *game, menu_ *menu)
{
    game->boole->is_friend = 2;
    sfMusic_play(game->sounds->ocean);
    while (sfRenderWindow_isOpen(game->window)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        menu->back->rect.top = 0;
        game->boole->on_button = 1;
        sfRenderWindow_clear(game->window, sfBlue);
        check_event_menu(game, menu);
        draw_menu(game, menu);
        sfRenderWindow_display(game->window);
    }
}
