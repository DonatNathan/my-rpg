/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to move items on inventory
*/

#include "../../includes/rpg.h"

void move_item_to_bar(item_ *item, game_ *game)
{
    if (item->line == 0 && item->on_inv == 0) {
        if (game->boole->on_inv == 1)
            item->position.y = 975;
        else
            item->position.y = game->inv->back->position.y + 103;
        sfSprite_setPosition(item->sprite, item->position);
    }
    if (item->next != NULL)
        move_item_to_bar(item->next, game);
}

void check_cible(game_ *game, item_ *item)
{
    if (game->mouse.x > game->inv->back->position.x + 660 && game->mouse.x <
    game->inv->back->position.x + 710 && game->mouse.y >
    game->inv->back->position.y + 300 && game->mouse.y <
    game->inv->back->position.y + 370)
        delete_item(item, game);
    else if (game->mouse.x < game->inv->back->position.x || game->mouse.x >
    game->inv->back->position.x + 710 || game->mouse.y < game->inv->back->
    position.y || game->mouse.y > game->inv->back->position.y + 500)
        drop_item(item, game);
    else
        cancel_item(item, game);
}

void get_item(game_ *game, item_ *item)
{
    if (game->mouse.x > item->position.x && game->mouse.x < item->position.x
    + 32 && game->mouse.y > item->position.y && game->mouse.y <
    item->position.y + 32 && item->on_inv == 0 && game->boole->on_inv == 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && (game->inv->on_item == 1 ||
        item->is_get == 0)) {
            game->inv->on_item = 0;
            item->is_get = 0;
            item->position.x = game->mouse.x - 16;
            item->position.y = game->mouse.y - 16;
            sfSprite_setPosition(item->sprite, item->position);
        }
        if (game->event.type == sfEvtMouseButtonReleased) {
            game->inv->on_item = 1;
            item->is_get = 1;
            check_cible(game, item);
        }
    }
    if (item->next != NULL)
        get_item(game, item->next);
}

void check_event_items(game_ *game)
{
    get_item(game, game->first_item);
    check_on_item(game, game->first_item, game->player);
}
