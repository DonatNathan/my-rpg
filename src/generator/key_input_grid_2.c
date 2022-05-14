/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** key_input_grid_2
*/

#include "../../includes/rpg.h"

void moov_up_check(grid_cell_ *grid)
{
    if (grid->hitbox->sprite != NULL) {
        grid->hitbox->position.y += 40;
        sfSprite_setPosition(grid->hitbox->sprite,
        grid->hitbox->position);
    }
    if (grid->mob->sprite != NULL) {
        grid->mob->position.y += 40;
        sfSprite_setPosition(grid->mob->sprite,
        grid->mob->position);
    }
}

int moov_up(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x, grid->pos_y + 40};

    grid->pos_y += 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->foreground->sprite != NULL) {
        grid->foreground->position.y += 40;
        sfSprite_setPosition(grid->foreground->sprite,
        grid->foreground->position);
    }
    if (grid->background->sprite != NULL) {
        grid->background->position.y += 40;
        sfSprite_setPosition(grid->background->sprite,
        grid->background->position);
    }
    moov_up_check(grid);
    return ((grid->next_cell != NULL) ? moov_up(grid->next_cell) : 1);
}

void moov_down_check(grid_cell_ *grid)
{
    if (grid->hitbox->sprite != NULL) {
        grid->hitbox->position.y -= 40;
        sfSprite_setPosition(grid->hitbox->sprite,
        grid->hitbox->position);
    }
    if (grid->mob->sprite != NULL) {
        grid->mob->position.y -= 40;
        sfSprite_setPosition(grid->mob->sprite,
        grid->mob->position);
    }
}

int moov_down(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x, grid->pos_y - 40};

    grid->pos_y -= 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->foreground->sprite != NULL) {
        grid->foreground->position.y -= 40;
        sfSprite_setPosition(grid->foreground->sprite,
        grid->foreground->position);
    }
    if (grid->background->sprite != NULL) {
        grid->background->position.y -= 40;
        sfSprite_setPosition(grid->background->sprite,
        grid->background->position);
    }
    moov_down_check(grid);
    return ((grid->next_cell != NULL) ? moov_down(grid->next_cell) : 1);
}
