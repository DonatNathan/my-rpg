/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create loop
*/

#include "../../includes/rpg.h"

void get_last_slot(slots_ *slot, int line, int col, game_ *game)
{
    if (slot->next != NULL)
        get_last_slot(slot->next, line, col, game);
    else {
        slot->next = malloc(sizeof(slots_));
        slot->next->slot = create_button((sfVector2f)
        {game->inv->back->position.x + 36 + (48 * col),
        game->inv->back->position.y + 100 + (55 * line)},
        (sfVector2f){0.1, 0.1}, "pictures/ath/white.png");
        slot->next->next = NULL;
    }
}

void create_slots(game_ *game)
{
    game->inv->slots->slot = create_button((sfVector2f)
    {game->inv->back->position.x + 36 + (48 * 0),
    game->inv->back->position.y + 100 + (55 * 0)}, (sfVector2f){0.1, 0.1},
    "pictures/ath/white.png");
    game->inv->slots->next = NULL;
    for (int line = 0; line != 3; line += 1) {
        for (int col = 1; col != 13; col += 1) {
            get_last_slot(game->inv->slots, line, col - 1, game);
        }
    }
}

void draw_slots(game_ *game, slots_ *slot)
{
    sfRenderWindow_drawSprite(game->window, slot->slot->sprite, sfFalse);
    if (slot->next)
        draw_slots(game, slot->next);
}
