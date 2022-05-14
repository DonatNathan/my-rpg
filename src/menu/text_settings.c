/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

text_ *create_ligne(char *string, sfVector2f position)
{
    text_ *text = malloc(sizeof(text_));
    text->text = sfText_create();
    text->font = sfFont_createFromFile("font/Stardew_Valley.ttf");
    text->scale = (sfVector2f){2, 2};
    text->position = position;
    sfText_setFont(text->text, text->font);
    sfText_setScale(text->text, text->scale);
    sfText_setPosition(text->text, text->position);
    sfText_setString(text->text, string);
    sfText_setColor(text->text, sfBlack);
    return (text);
}

void create_all_ligne(menu_ *menu)
{
    menu->settings->max = create_ligne("120FPS",
    (sfVector2f){menu->settings->back->position.x + 370,
    menu->settings->back->position.y + 100});
    menu->settings->mid = create_ligne("60FPS",
    (sfVector2f){menu->settings->back->position.x + 600,
    menu->settings->back->position.y + 100});
    menu->settings->min = create_ligne("30FPS",
    (sfVector2f){menu->settings->back->position.x + 800,
    menu->settings->back->position.y + 100});
    menu->settings->big = create_ligne("1920x1080",
    (sfVector2f){menu->settings->back->position.x + 230,
    menu->settings->back->position.y + 230});
    menu->settings->little = create_ligne("800x600",
    (sfVector2f){menu->settings->back->position.x + 530,
    menu->settings->back->position.y + 230});
}

void create_texts(menu_ *menu)
{
    menu->settings->all = malloc(sizeof(text_));
    menu->settings->all->text = sfText_create();
    menu->settings->all->position.x = menu->settings->back->position.x + 50;
    menu->settings->all->position.y = menu->settings->back->position.y + 100;
    menu->settings->all->scale = (sfVector2f){2, 2};
    menu->settings->all->font = sfFont_createFromFile
    ("font/Stardew_Valley.ttf");
    sfText_setFont(menu->settings->all->text, menu->settings->all->font);
    sfText_setPosition(menu->settings->all->text,
    menu->settings->all->position);
    sfText_setString(menu->settings->all->text,
    "FRAMERATE : \n\nSIZE : \n\nMUSIC : \n\nSOUNDS : \n");
    sfText_setColor(menu->settings->all->text, sfBlack);
    sfText_setScale(menu->settings->all->text, menu->settings->all->scale);
    create_all_ligne(menu);
}
