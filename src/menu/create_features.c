/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create my menu
*/

#include "../../includes/rpg.h"

void create_coin(menu_ *menu)
{
    menu->coin->sprite = sfSprite_create();
    menu->coin->texture = sfTexture_createFromFile
    ("pictures/menu/coin.png", NULL);
    menu->coin->position.x = 25;
    menu->coin->position.y = 30;
    menu->coin->scale.x = 1;
    menu->coin->scale.y = 1;
    menu->coin->moved = 1;
    menu->coin->version = 0;
    sfSprite_setTexture(menu->coin->sprite, menu->coin->texture, sfFalse);
    sfSprite_setPosition(menu->coin->sprite, menu->coin->position);
    sfSprite_setScale(menu->coin->sprite, menu->coin->scale);
    menu->coin->rect = change_rect(menu->coin->rect, 50, 50);
    menu->coin->rect.top = 0;
    menu->coin->rect.left = 0;
    sfSprite_setTextureRect(menu->coin->sprite, menu->coin->rect);
    menu->coin->clock = sfClock_create();
    menu->score = create_text("0", (sfVector2f){2, 2},
    (sfVector2f){100, 10}, "font/svr.ttf");
}

void create_parrot(menu_ *menu)
{
    menu->parrot->sprite = sfSprite_create();
    menu->parrot->texture = sfTexture_createFromFile
    ("pictures/menu/parrot.png", NULL);
    menu->parrot->r_texture = sfTexture_createFromFile
    ("pictures/menu/r_parrot.png", NULL);
    menu->parrot->position.x = 1920;
    menu->parrot->position.y = 600;
    menu->parrot->scale.x = 3;
    menu->parrot->scale.y = 3;
    menu->parrot->moved = 1;
    menu->parrot->version = 0;
    sfSprite_setTexture(menu->parrot->sprite, menu->parrot->texture, sfFalse);
    sfSprite_setPosition(menu->parrot->sprite, menu->parrot->position);
    sfSprite_setScale(menu->parrot->sprite, menu->parrot->scale);
    menu->parrot->rect = change_rect(menu->parrot->rect, 24, 24);
    menu->parrot->rect.top = 48;
    menu->parrot->rect.left = 48;
    sfSprite_setTextureRect(menu->parrot->sprite, menu->parrot->rect);
    menu->parrot->clock = sfClock_create();
}
