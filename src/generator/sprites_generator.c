/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create sprites buttons on generator
*/

#include "../../includes/rpg.h"

void create_up(gen_control_ *gen_control)
{
    gen_control->up->sprite = sfSprite_create();
    gen_control->up->texture = sfTexture_createFromFile\
    ("pictures/menu/up_size.png", NULL);
    gen_control->up->position.x = 1845;
    gen_control->up->position.y = 10;
    gen_control->up->scale.x = 3;
    gen_control->up->scale.y = 3;
    sfSprite_setTexture\
    (gen_control->up->sprite, gen_control->up->texture, sfFalse);
    sfSprite_setPosition(gen_control->up->sprite, gen_control->up->position);
    gen_control->up->rect = change_rect(gen_control->up->rect, 22, 26);
    gen_control->up->rect.top = 418;
    gen_control->up->rect.left = 350;
    sfSprite_setScale(gen_control->up->sprite, gen_control->up->scale);
    sfSprite_setTextureRect(gen_control->up->sprite, gen_control->up->rect);
}

void create_down(gen_control_ *gen_control)
{
    gen_control->down->sprite = sfSprite_create();
    gen_control->down->texture = sfTexture_createFromFile\
    ("pictures/menu/down_size.png", NULL);
    gen_control->down->position.x = 1845;
    gen_control->down->position.y = 100;
    gen_control->down->scale.x = 3;
    gen_control->down->scale.y = 3;
    sfSprite_setTexture\
    (gen_control->down->sprite, gen_control->down->texture, sfFalse);
    sfSprite_setPosition(gen_control->down->sprite,
    gen_control->down->position);
    gen_control->down->rect = change_rect\
    (gen_control->down->rect, 22, 26);
    gen_control->down->rect.top = 418;
    gen_control->down->rect.left = 350;
    sfSprite_setScale(gen_control->down->sprite, gen_control->down->scale);
    sfSprite_setTextureRect(gen_control->down->sprite, \
    gen_control->down->rect);
}

void create_zoom_up(gen_control_ *gen_control)
{
    gen_control->zoom_up->sprite = sfSprite_create();
    gen_control->zoom_up->texture = sfTexture_createFromFile\
    ("pictures/menu/up_size.png", NULL);
    gen_control->zoom_up->position.x = 1845;
    gen_control->zoom_up->position.y = 810;
    gen_control->zoom_up->scale.x = 3;
    gen_control->zoom_up->scale.y = 3;
    sfSprite_setTexture\
    (gen_control->zoom_up->sprite, gen_control->zoom_up->texture, sfFalse);
    sfSprite_setPosition(gen_control->zoom_up->sprite,
    gen_control->zoom_up->position);
    gen_control->zoom_up->rect = change_rect
    (gen_control->zoom_up->rect, 22, 26);
    gen_control->zoom_up->rect.top = 418;
    gen_control->zoom_up->rect.left = 350;
    sfSprite_setScale(gen_control->zoom_up->sprite,
    gen_control->zoom_up->scale);
    sfSprite_setTextureRect(gen_control->zoom_up->sprite,
    gen_control->zoom_up->rect);
}

void create_zoom_down(gen_control_ *gen_control)
{
    gen_control->zoom_down->sprite = sfSprite_create();
    gen_control->zoom_down->texture = sfTexture_createFromFile\
    ("pictures/menu/down_size.png", NULL);
    gen_control->zoom_down->position.x = 1845;
    gen_control->zoom_down->position.y = 900;
    gen_control->zoom_down->scale.x = 3;
    gen_control->zoom_down->scale.y = 3;
    sfSprite_setTexture\
    (gen_control->zoom_down->sprite, gen_control->zoom_down->texture, sfFalse);
    sfSprite_setPosition(gen_control->zoom_down->sprite, \
    gen_control->zoom_down->position);
    gen_control->zoom_down->rect = change_rect\
    (gen_control->zoom_down->rect, 22, 26);
    gen_control->zoom_down->rect.top = 418;
    gen_control->zoom_down->rect.left = 350;
    sfSprite_setScale(gen_control->zoom_down->sprite,
    gen_control->zoom_down->scale);
    sfSprite_setTextureRect(gen_control->zoom_down->sprite,
    gen_control->zoom_down->rect);
}
