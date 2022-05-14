/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** mouse_input_grid
*/

#include "../../includes/rpg.h"

void check_back_or_fore(game_ *game, grid_cell_ *grid, paint_ *paint,
gen_control_ *gen_control)
{
    switch (game->layer) {
        case (0): its_background(game, grid, paint);
            break;
        case (1): its_foreground(game, grid, paint);
            break;
        case (2): its_hitbox(game, grid, paint);
            break;
        case (3): its_mob(game, grid, paint);
            break;
    }
}

void left_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    sfVector2f sprite_pos = {grid->pos_x, grid->pos_y};
    grid->foreground->position = sprite_pos;

    if (game->mouse.x > grid->pos_x && game->mouse.x < grid->pos_x + \
        (40 * paint->scale) && game->mouse.y > grid->pos_y && game->mouse.y\
        < grid->pos_y + (40 * paint->scale) && (game->gen_control->sprites_on
        == 1 || game->gen_control_mob->sprites_on == 1)) {
        grid->click = 1;
        if ((game->gen_control->selected != NULL ||
        game->gen_control_mob->selected != NULL) &&
        (game->gen_control->selected_ == 1 ||
        game->gen_control_mob->selected_ == 1)) {
            check_back_or_fore(game, grid, paint, game->gen_control);
        }
    }
    if (grid->next_cell != NULL)
        left_click_grid(game, grid->next_cell, paint);
}

void right_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint,
gen_control_ *gen_control)
{
    if (game->mouse.x > grid->pos_x && game->mouse.x < grid->pos_x + \
        (40 * paint->scale) && game->mouse.y > grid->pos_y && game->mouse.y\
        < grid->pos_y + (40 * paint->scale)) {
        grid->click = 0;
        delete_foreground(game, grid);
        delete_background(game, grid);
        delete_hitbox(game, grid);
        delete_mob(game, grid);
    }
    if (grid->next_cell != NULL)
        right_click_grid(game, grid->next_cell, paint, gen_control);
}
