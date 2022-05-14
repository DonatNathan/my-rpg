/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** key_input
*/

#include "../../includes/rpg.h"

int moov_up_(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x, grid->pos_y + 40};

    grid->pos_y += 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    return ((grid->next_cell != NULL) ? moov_up_(grid->next_cell) : 1);
}

int moov_down_(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x, grid->pos_y - 40};

    grid->pos_y -= 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    return ((grid->next_cell != NULL) ? moov_down_(grid->next_cell) : 1);
}

int moov_left_(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x + 40, grid->pos_y};

    grid->pos_x += 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    return ((grid->next_cell != NULL) ? moov_left_(grid->next_cell) : 1);
}

int moov_right_(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x - 40, grid->pos_y};

    grid->pos_x -= 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    return ((grid->next_cell != NULL) ? (moov_right_(grid->next_cell)) : 1);
}
