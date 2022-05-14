/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create my menu
*/

#include "../../includes/rpg.h"

void create_new(menu_ *menu)
{
    menu->new->sprite = sfSprite_create();
    menu->new->texture = sfTexture_createFromFile\
    ("pictures/menu/buttons.png", NULL);
    menu->new->position.x = 440;
    menu->new->position.y = 800;
    menu->new->scale.x = 3;
    menu->new->scale.y = 3;
    sfSprite_setTexture(menu->new->sprite, menu->new->texture, sfFalse);
    sfSprite_setPosition(menu->new->sprite, menu->new->position);
    sfSprite_setScale(menu->new->sprite, menu->new->scale);
    menu->new->rect = change_rect(menu->new->rect, 74, 58);
    menu->new->rect.top = 187;
    sfSprite_setTextureRect(menu->new->sprite, menu->new->rect);
}

void create_exit(menu_ *menu)
{
    menu->exit->sprite = sfSprite_create();
    menu->exit->texture = sfTexture_createFromFile\
    ("pictures/menu/buttons.png", NULL);
    menu->exit->position.x = menu->new->position.x + 800;
    menu->exit->position.y = 800;
    menu->exit->scale.x = 3;
    menu->exit->scale.y = 3;
    sfSprite_setTexture(menu->exit->sprite, menu->exit->texture, sfFalse);
    sfSprite_setPosition(menu->exit->sprite, menu->exit->position);
    sfSprite_setScale(menu->exit->sprite, menu->exit->scale);
    menu->exit->rect = change_rect(menu->exit->rect, 74, 58);
    menu->exit->rect.top = 187;
    menu->exit->rect.left = 222;
    sfSprite_setTextureRect(menu->exit->sprite, menu->exit->rect);
}

void create_load(menu_ *menu)
{
    menu->load->sprite = sfSprite_create();
    menu->load->texture = sfTexture_createFromFile\
    ("pictures/menu/buttons.png", NULL);
    menu->load->position.x = menu->new->position.x + 400;
    menu->load->position.y = 800;
    menu->load->scale.x = 3;
    menu->load->scale.y = 3;
    sfSprite_setTexture(menu->load->sprite, menu->load->texture, sfFalse);
    sfSprite_setPosition(menu->load->sprite, menu->load->position);
    sfSprite_setScale(menu->load->sprite, menu->load->scale);
    menu->load->rect = change_rect(menu->load->rect, 74, 58);
    menu->load->rect.top = 187;
    menu->load->rect.left = 74;
    sfSprite_setTextureRect(menu->load->sprite, menu->load->rect);
}

void create_help(menu_ *menu)
{
    menu->help->sprite = sfSprite_create();
    menu->help->texture = sfTexture_createFromFile\
    ("pictures/menu/buttons.png", NULL);
    menu->help->position.x = 10;
    menu->help->position.y = 10;
    menu->help->scale.x = 3;
    menu->help->scale.y = 3;
    sfSprite_setTexture(menu->help->sprite, menu->help->texture, sfFalse);
    sfSprite_setPosition(menu->help->sprite, menu->help->position);
    menu->help->rect = change_rect(menu->help->rect, 22, 26);
    menu->help->rect.top = 418;
    menu->help->rect.left = 350;
    sfSprite_setScale(menu->help->sprite, menu->help->scale);
    sfSprite_setTextureRect(menu->help->sprite, menu->help->rect);
}

void create_secret(menu_ *menu)
{
    menu->secret->sprite = sfSprite_create();
    menu->secret->texture = sfTexture_createFromFile\
    ("pictures/menu/pirate.png", NULL);
    sfSprite_setTexture(menu->secret->sprite, menu->secret->texture, sfFalse);
    menu->secret->position.x = 600;
    menu->secret->position.y = 0;
    sfSprite_setPosition(menu->secret->sprite, menu->secret->position);
}
