/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to move items on inventory
*/

#include "../../includes/rpg.h"

int check_in_slots(game_ *game, slots_ *slot, item_ *item, int is_in)
{
    if (game->mouse.x > slot->slot->position.x && game->mouse.x <
    slot->slot->position.x + 48 && game->mouse.y > slot->slot->position.y &&
    game->mouse.y < slot->slot->position.y + 55 &&
    !game->inv->inv[(game->mouse.y / 55) - 5][(game->mouse.x / 48) - 14]) {
        item->position.x = slot->slot->position.x;
        item->position.y = slot->slot->position.y;
        game->inv->inv[item->line][item->col] = NULL;
        sfSprite_setPosition(item->sprite, item->position);
        item->line = (game->mouse.y / 55) - 5;
        item->col = (game->mouse.x / 48) - 14;
        game->inv->inv[item->line][item->col] = (char *)item;
        is_in = 0;
    }
    if (slot->next)
        is_in = check_in_slots(game, slot->next, item, is_in);
    return (is_in);
}

void cancel_item(item_ *item, game_ *game)
{
    sfSound_play(game->sounds->item);
    if (check_in_slots(game, game->inv->slots, item, 1) == 1) {
        item->on_inv = 1;
        item->position.x = game->player->position.x + 16;
        item->position.y = game->player->position.y + 32 *
        game->player->scale.y;
        sfSprite_setPosition(item->sprite, item->position);
        game->inv->inv[item->line][item->col] = NULL;
    }
}

void drop_item(item_ *item, game_ *game)
{
    sfSound_play(game->sounds->item);
    item->on_inv = 1;
    item->position.x = game->player->position.x + 16;
    item->position.y = game->player->position.y + 32 * game->player->scale.y
    + 10;
    sfSprite_setPosition(item->sprite, item->position);
    game->inv->inv[item->line][item->col] = NULL;
}

void delete_item(item_ *item, game_ *game)
{
    sfSound_play(game->sounds->trash);
    item->position.x = -32;
    sfSprite_setPosition(item->sprite, item->position);
    game->inv->inv[item->line][item->col] = NULL;
}
