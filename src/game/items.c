/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create items
*/

#include "../../includes/rpg.h"

void move_items(item_ *item, int value, int movement, game_ *game)
{
    switch (movement) {
        case (0):
            item->position.y -= value * game->speed +
            game->player->stats->speed;
            break;
        case (1):
            item->position.x -= value * game->speed +
            game->player->stats->speed;
            break;
        case (2):
            item->position.y += value * game->speed +
            game->player->stats->speed;
            break;
        case (3):
            item->position.x += value * game->speed +
            game->player->stats->speed;
            break;
    }
}

void draw_items(game_ *game, item_ *item, int movement, int status)
{
    if (item->on_inv == 1)
        move_items(item, 3, movement, game);
    sfSprite_setPosition(item->sprite, item->position);
    if ((status == 0 && item->on_inv == 0) || (status == 1 && item->on_inv
    == 1) || (status == 0 && item->on_inv == 1 && (item->position.x + 32 <
    game->inv->back->position.x || item->position.x > game->inv->back->
    position.x + 710 || item->position.y + 32 < game->inv->back->position.y ||
    item->position.y > game->inv->back->position.y + 500)) || (status == 1 &&
    item->line == 0))
        sfRenderWindow_drawSprite(game->window, item->sprite, sfFalse);
    if (item->next != NULL)
        draw_items(game, item->next, movement, status);
}

void set_rect_item(item_ *item, int top, int left, item_ *prev)
{
    item->rect.left = left;
    item->rect.top = top;
    sfSprite_setTextureRect(item->sprite, item->rect);
    item->prev = prev;
}

item_ *create_item(int type, int stats, char *filename, sfVector2f position)
{
    item_ *item = malloc(sizeof(item_));

    item->sprite = sfSprite_create();
    item->texture = sfTexture_createFromFile(filename, NULL);
    item->stats = stats;
    item->type = type;
    item->position = position;
    item->scale = (sfVector2f){2, 2};
    item->rect = change_rect(item->rect, 16, 16);
    item->next = NULL;
    item->on_inv = 1;
    item->line = 0;
    item->col = 0;
    item->is_get = 1;
    sfSprite_setTextureRect(item->sprite, item->rect);
    sfSprite_setTexture(item->sprite, item->texture, sfFalse);
    sfSprite_setScale(item->sprite, item->scale);
    sfSprite_setPosition(item->sprite, item->position);
    return (item);
}

void add_items(game_ *game, item_ *item, int top)
{
    if (item == NULL) {
        game->first_item = create_item(1, 3, "pictures/items/weapons.png",
        (sfVector2f){960, 580});
        set_rect_item(game->first_item, top, 96, NULL);
    } else if (item->next != NULL) {
        add_items(game, item->next, top);
    } else {
        item->next = create_item(1, 3, "pictures/items/weapons.png",
        (sfVector2f){game->player->position.x, game->player->position.y + 50});
        set_rect_item(item->next, top, 0, item);
    }
}
