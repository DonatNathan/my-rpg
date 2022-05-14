/*
** EPITECH PROJECT, 2022
** $
** File description:
** delete_tiles
*/

#include "../../includes/rpg.h"

void delete_foreground(game_ *game, grid_cell_ *grid)
{
    if (game->layer == 1) {
        (grid->foreground->ok == 1) ? grid->foreground->sprite = NULL,
        grid->foreground->ok = 0, grid->foreground_id = 1945 : 1;
    }
}

void delete_background(game_ *game, grid_cell_ *grid)
{
    if (game->layer == 0) {
        (grid->background->ok == 1) ? grid->background->sprite = NULL,
        grid->background->ok = 0, grid->background_id = 1721 : 1;
    }
}

void delete_hitbox(game_ *game, grid_cell_ *grid)
{
    if (game->layer == 2) {
        (grid->hitbox->ok == 1) ? grid->hitbox->sprite = NULL,
        grid->hitbox->ok = 0, grid->hitbox_id = 1945 : 1;
    }
}

void delete_mob(game_ *game, grid_cell_ *grid)
{
    if (game->layer == 3) {
        (grid->mob->ok == 1) ? grid->mob->sprite = NULL,
        grid->mob->ok = 0, grid->mob_id = 1945 : 1;
    }
}
