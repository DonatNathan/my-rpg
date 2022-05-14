/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create my menu
*/

#include "../../includes/rpg.h"

void create_loads(menu_ *menu)
{
    menu->load1->load = sfSprite_create();
    menu->load2->load = sfSprite_create();
    menu->load3->load = sfSprite_create();
}

void create_back(menu_ *menu)
{
    menu->back->sprite = sfSprite_create();
    menu->back->texture = sfTexture_createFromFile\
    ("pictures/menu/back.png", NULL);
    menu->back->scale.x = 2;
    menu->back->scale.y = 2;
    sfSprite_setScale(menu->back->sprite, menu->back->scale);
    menu->back->rect = change_rect(menu->back->rect, 1500, 520);
    sfSprite_setTextureRect(menu->back->sprite, menu->back->rect);
    sfSprite_setTexture(menu->back->sprite, menu->back->texture, sfFalse);
}

void create_logo(menu_ *menu)
{
    menu->on_parrot = 1;
    menu->logo->sprite = sfSprite_create();
    menu->logo->texture = sfTexture_createFromFile\
    ("pictures/menu/buttons.png", NULL);
    menu->logo->position.x = 550;
    menu->logo->position.y = 100;
    menu->logo->scale.x = 2;
    menu->logo->scale.y = 2;
    menu->logo->rect = change_rect(menu->logo->rect, 400, 187);
    sfSprite_setTexture\
    (menu->logo->sprite, menu->logo->texture, sfFalse);
    sfSprite_setTextureRect(menu->logo->sprite, menu->logo->rect);
    sfSprite_setPosition(menu->logo->sprite, menu->logo->position);
    sfSprite_setScale(menu->logo->sprite, menu->logo->scale);
}

void create_menu(menu_ *menu)
{
    create_logo(menu);
    create_back(menu);
    create_loads(menu);
    create_new(menu);
    create_exit(menu);
    create_load(menu);
    create_parrot(menu);
    create_coin(menu);
    create_secret(menu);
    create_help(menu);
    create_saves(menu);
}

void malloc_menu(menu_ *menu)
{
    menu->back = malloc(sizeof(button_));
    menu->secret = malloc(sizeof(button_));
    menu->help = malloc(sizeof(button_));
    menu->load1 = malloc(sizeof(load_));
    menu->load2 = malloc(sizeof(load_));
    menu->load3 = malloc(sizeof(load_));
    menu->help = malloc(sizeof(button_));
    menu->exit = malloc(sizeof(button_));
    menu->new = malloc(sizeof(button_));
    menu->load = malloc(sizeof(button_));
    menu->params = malloc(sizeof(button_));
    menu->sounds = malloc(sizeof(button_));
    menu->logo = malloc(sizeof(button_));
    menu->parrot = malloc(sizeof(animal_));
    menu->coin = malloc(sizeof(animal_));
    create_menu(menu);
}
