/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

button_ *create_button(sfVector2f pos, sfVector2f scale,
char *filepath)
{
    button_ *button = malloc(sizeof(button_));
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(filepath, NULL);
    button->scale = scale;
    button->position = pos;
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->position);
    sfSprite_setScale(button->sprite, button->scale);
    return (button);
}

void create_sounds(game_ *game, menu_ *menu)
{
    menu->settings->bar_music = create_button((sfVector2f){menu->settings->
    back->position.x + 270, menu->settings->back->position.y + 385},
    (sfVector2f){0.5, 0.15}, "pictures/menu/soundbar.png");
    menu->settings->bar_sounds = create_button((sfVector2f){menu->settings->
    back->position.x + 280, menu->settings->back->position.y + 515},
    (sfVector2f){0.5, 0.15}, "pictures/menu/soundbar.png");
    menu->settings->music = create_button((sfVector2f){menu->settings->
    back->position.x + 710, menu->settings->back->position.y + 355},
    (sfVector2f){0.25, 0.25}, "pictures/menu/parrot_button.png");
    menu->settings->sounds = create_button((sfVector2f){menu->settings->
    back->position.x + 720, menu->settings->back->position.y + 485},
    (sfVector2f){0.25, 0.25}, "pictures/menu/parrot_button.png");
}

void create_button_set(game_ *game, menu_ *menu)
{
    menu->settings->button = malloc(sizeof(button_));
    menu->settings->button->sprite = sfSprite_create();
    menu->settings->button->texture = sfTexture_createFromFile
    ("pictures/menu/empty_box.png", NULL);
    menu->settings->button->position = (sfVector2f){1860, 10};
    menu->settings->button->scale = (sfVector2f){1, 1};
    sfSprite_setScale(menu->settings->button->sprite,
    menu->settings->button->scale);
    sfSprite_setTexture(menu->settings->button->sprite,
    menu->settings->button->texture, sfFalse);
    sfSprite_setPosition(menu->settings->button->sprite,
    menu->settings->button->position);
    menu->settings->button->rect = change_rect
    (menu->settings->button->rect, 50, 57);
    sfSprite_setTextureRect
    (menu->settings->button->sprite, menu->settings->button->rect);
    create_sounds(game, menu);
}

void create_settings(game_ *game, menu_ *menu)
{
    menu->settings = malloc(sizeof(settings_));
    menu->settings->back = malloc(sizeof(button_));
    menu->settings->back->sprite = sfSprite_create();
    menu->settings->back->texture = sfTexture_createFromFile
    ("pictures/menu/menu.png", NULL);
    menu->settings->back->position = (sfVector2f){270, 150};
    sfSprite_setTexture(menu->settings->back->sprite,
    menu->settings->back->texture, sfFalse);
    sfSprite_setPosition(menu->settings->back->sprite,
    menu->settings->back->position);
    menu->settings->back->rect = change_rect
    (menu->settings->back->rect, 320, 180);
    sfSprite_setTextureRect(menu->settings->back->sprite,
    menu->settings->back->rect);
    menu->settings->back->scale = (sfVector2f){4, 4};
    sfSprite_setScale(menu->settings->back->sprite,
    menu->settings->back->scale);
    create_button_set(game, menu);
    create_texts(menu);
}
