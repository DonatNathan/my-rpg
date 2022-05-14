/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** launch_menu
*/

#include "../../includes/rpg.h"

void init_menu_value(game_ *game, menu_ *menu)
{
    game->speed = 1;
    menu->on_load = 1;
    game->boole = malloc(sizeof(boole_));
    game->boole->on_quit = 1;
    game->boole->on_htp = 0;
}

void create_loading(game_ *game)
{
    game->loading = create_button((sfVector2f){0, 0}, (sfVector2f){1.6, 1.55},
    "pictures/menu/loading.png");
    game->loading->rect = change_rect(game->loading->rect, 1200, 675);
    game->loading->rect.left = 1200;
    sfSprite_setTextureRect(game->loading->sprite, game->loading->rect);
}

void launch_menu(sfVideoMode mode, sfVector2u size, char *pseudo)
{
    game_ *game = malloc(sizeof(game_));
    menu_ *menu = malloc(sizeof(menu_));

    game->menu = menu;
    game->window = sfRenderWindow_create(mode, "MY_RPG", \
    sfResize | sfClose, NULL);
    game->pseudo = pseudo;
    sfRenderWindow_setFramerateLimit(game->window, 120);
    sfRenderWindow_setSize(game->window, size);
    sfWindow_setMouseCursorVisible((sfWindow *)game->window, sfFalse);
    sfWindow_setKeyRepeatEnabled((sfWindow *)game->window, sfFalse);
    malloc_menu(menu);
    create_cursor(game);
    create_settings(game, menu);
    create_audios(game);
    create_htp(game);
    init_menu_value(game, menu);
    create_loading(game);
    loop_menu(game, menu);
}
