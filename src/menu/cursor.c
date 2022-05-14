/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create my cursor
*/

#include "../../includes/rpg.h"

void check_event_cursor(game_ *game)
{
    if (game->boole->on_button == 0)
        sfSprite_setTexture
        (game->cursor->sprite, game->cursor->clicked, sfFalse);
    else
        sfSprite_setTexture
        (game->cursor->sprite, game->cursor->basic, sfFalse);
}

void update_cursor(game_ *game)
{
    game->cursor->position.x = game->mouse.x;
    game->cursor->position.y = game->mouse.y;
    sfSprite_setPosition(game->cursor->sprite, game->cursor->position);
    sfRenderWindow_drawSprite(game->window, game->cursor->sprite, sfFalse);
}

void create_cursor(game_ *game)
{
    game->cursor = malloc(sizeof(cursor_));
    game->cursor->sprite = sfSprite_create();
    game->cursor->basic = sfTexture_createFromFile
    ("pictures/menu/mouse.png", NULL);
    game->cursor->clicked = sfTexture_createFromFile
    ("pictures/menu/clicked.png", NULL);
    sfSprite_setTexture(game->cursor->sprite, game->cursor->basic, sfFalse);
}
