/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function create my saves
*/

#include "../../includes/rpg.h"

void check_saves(game_ *game, button_ *button, int who, menu_ *menu)
{
    if (game->mouse.x > button->position.x && game->mouse.x <
    button->position.x + button->rect.width * button->scale.x &&
    game->mouse.y > button->position.y && game->mouse.y < button->position.y +
    button->rect.height * button->scale.y && menu->on_load == 0) {
        game->boole->on_button = 0;
        button->rect.left = 50;
        sfText_setColor(button->text->text, (sfColor){150, 150, 150, 150});
        if (game->event.type == sfEvtMouseButtonReleased) {
            sfSound_play(game->sounds->click);
            find_button(game, who, menu);
        }
    } else {
        button->rect.left = 0;
        sfText_setColor(button->text->text, sfBlack);
    }
    sfSprite_setTextureRect(button->sprite, button->rect);
}

button_ *create_save(sfVector2f pos, sfVector2f scale,
char *filepath, char *name)
{
    button_ *button = malloc(sizeof(button_));
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(filepath, NULL);
    button->scale = scale;
    button->position = pos;
    button->rect = change_rect(button->rect, 50, 57);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->position);
    sfSprite_setScale(button->sprite, button->scale);
    button->text = malloc(sizeof(text_));
    scale.x = 3;
    scale.y = 3;
    pos.x += 150;
    pos.y += 20;
    button->text = create_text(name, scale, pos, "font/Stardew_Valley.ttf");
    return (button);
}

void create_saves(menu_ *menu)
{
    menu->saves = malloc(sizeof(saves_));
    menu->saves->first = create_save((sfVector2f){700, 230},
    (sfVector2f){11, 3}, "pictures/menu/box.png", "SAVE 1");
    menu->saves->second = create_save((sfVector2f){700, 430},
    (sfVector2f){11, 3}, "pictures/menu/box.png", "SAVE 2");
    menu->saves->third = create_save((sfVector2f){700, 630},
    (sfVector2f){11, 3}, "pictures/menu/box.png", "SAVE 3");
}
