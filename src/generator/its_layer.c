/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** make_grid
*/

#include "../../includes/rpg.h"

void its_background(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    sfVector2f sprite_pos = {grid->pos_x, grid->pos_y};
    sfVector2f sprite_scale = {2.5, 2.5};

    grid->background->position = sprite_pos;
    grid->background_id = game->gen_control->selected->id;
    grid->background->ok = 1;
    grid->background->sprite =
    sfSprite_copy(game->gen_control->selected->sprite);
    sfSprite_setPosition(grid->background->sprite, sprite_pos);
    sfSprite_setScale(grid->background->sprite, sprite_scale);
}

void its_foreground(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    sfVector2f sprite_pos = {grid->pos_x, grid->pos_y};
    sfVector2f sprite_scale = {2.5, 2.5};

    grid->foreground->position = sprite_pos;
    grid->foreground_id = game->gen_control->selected->id;
    grid->foreground->ok = 1;
    grid->foreground->sprite =
    sfSprite_copy(game->gen_control->selected->sprite);
    sfSprite_setPosition(grid->foreground->sprite, sprite_pos);
    sfSprite_setScale(grid->foreground->sprite, sprite_scale);
}

void its_hitbox(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    sfVector2f sprite_pos = {grid->pos_x, grid->pos_y};
    sfVector2f sprite_scale = {2.5, 2.5};
    sfColor hit = {255, 0, 0, 150};

    grid->hitbox->position = sprite_pos;
    grid->hitbox_id = game->gen_control->selected->id;
    grid->hitbox->ok = 1;
    grid->hitbox->sprite =
    sfSprite_copy(game->gen_control->selected->sprite);
    sfSprite_setPosition(grid->hitbox->sprite, sprite_pos);
    sfSprite_setScale(grid->hitbox->sprite, sprite_scale);
    sfSprite_setColor(grid->hitbox->sprite, hit);
}

void its_mob(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    sfVector2f sprite_pos = {grid->pos_x, grid->pos_y};
    sfVector2f sprite_scale = {2.5, 2.5};

    grid->mob->position = sprite_pos;
    grid->mob_id = game->gen_control_mob->selected->id;
    grid->mob->ok = 1;
    grid->mob->sprite =
    sfSprite_copy(game->gen_control_mob->selected->sprite);
    sfSprite_setPosition(grid->mob->sprite, sprite_pos);
    sfSprite_setScale(grid->mob->sprite, sprite_scale);
}
