/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** make_grid
*/

#include "../../includes/rpg.h"

void display_square(game_ *game, grid_cell_ *grid, gen_control_ *gen_control,
paint_ *paint)
{
    if (game->mouse.x > grid->pos_x && game->mouse.x < grid->pos_x +
        (40 * paint->scale) &&
        game->mouse.y > grid->pos_y && game->mouse.y < grid->pos_y +
        (40 * paint->scale)) {
        if (grid->click == 0 && gen_control->sprites_on != 0)
            sfRectangleShape_setFillColor(grid->rect, sfGreen);
    } else {
            sfRectangleShape_setFillColor(grid->rect, sfWhite);
    }
    if (grid->click == 1 && grid->foreground->sprite == NULL &&
    grid->background->sprite == NULL && grid->hitbox->sprite == NULL
    && grid->mob->sprite == NULL)
        sfRectangleShape_setFillColor(grid->rect, sfBlue);
    sfRenderWindow_drawRectangleShape(game->window, grid->rect, sfFalse);
    if (grid->next_cell != NULL)
        display_square(game, grid->next_cell, gen_control, paint);
}

void check_gen_control_disp(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        game->gen_control->sprites_on = 0;
        game->gen_control_mob->sprites_on = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->gen_control->sprites_on = 1;
        game->gen_control_mob->sprites_on = 1;
    }
}

void draw_env(game_ *game, sprite_ *sprite)
{
    sfRenderWindow_drawSprite(game->window, sprite->sprite, sfFalse);
    if (sprite->next != NULL)
        draw_env(game, sprite->next);
}

void display_all(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    display_square(game, grid, game->gen_control, paint);
    display_background(game, grid, paint);
    display_foreground(game, grid, paint);
    display_hitbox(game, grid, paint);
    display_mob(game, grid, paint);
    draw_ath(game);
    if (game->gen_control->sprites_on == 0 && game->layer == 3)
        draw_sprites_gen(game, game->gen_control_mob);
    else
        draw_sprites_gen(game, game->gen_control);
    update_cursor(game);
}
