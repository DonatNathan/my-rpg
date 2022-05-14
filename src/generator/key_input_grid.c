/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** moov_grid
*/

#include "../../includes/rpg.h"

void moov_left_check(grid_cell_ *grid)
{
    if (grid->hitbox->sprite != NULL) {
        grid->hitbox->position.x += 40;
        sfSprite_setPosition(grid->hitbox->sprite,
        grid->hitbox->position);
    }
    if (grid->mob->sprite != NULL) {
        grid->mob->position.x += 40;
        sfSprite_setPosition(grid->mob->sprite,
        grid->mob->position);
    }
}

int moov_left(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x + 40, grid->pos_y};

    grid->pos_x += 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->foreground->sprite != NULL) {
        grid->foreground->position.x += 40;
        sfSprite_setPosition(grid->foreground->sprite,
        grid->foreground->position);
    }
    if (grid->background->sprite != NULL) {
        grid->background->position.x += 40;
        sfSprite_setPosition(grid->background->sprite,
        grid->background->position);
    }
    moov_left_check(grid);
    return ((grid->next_cell != NULL) ? moov_left(grid->next_cell) : 1);
}

void moov_right_check(grid_cell_ *grid)
{
    if (grid->hitbox->sprite != NULL) {
        grid->hitbox->position.x -= 40;
        sfSprite_setPosition(grid->hitbox->sprite,
        grid->hitbox->position);
    }
    if (grid->mob->sprite != NULL) {
        grid->mob->position.x -= 40;
        sfSprite_setPosition(grid->mob->sprite,
        grid->mob->position);
    }
}

int moov_right(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x - 40, grid->pos_y};

    grid->pos_x -= 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->foreground->sprite != NULL) {
        grid->foreground->position.x -= 40;
        sfSprite_setPosition(grid->foreground->sprite,
        grid->foreground->position);
    }
    if (grid->background->sprite != NULL) {
        grid->background->position.x -= 40;
        sfSprite_setPosition(grid->background->sprite,
        grid->background->position);
    }
    moov_right_check(grid);
    return ((grid->next_cell != NULL) ? (moov_right(grid->next_cell)) : 1);
}

int reset_grid(grid_cell_ *grid)
{
    grid->click = 0;
    grid->background->ok = 1721;
    grid->foreground->ok = 1935;
    grid->hitbox->ok = 1935;
    grid->mob->ok = 1935;
    if (grid->next_cell != NULL)
        reset_grid(grid->next_cell);
    return (0);
}
