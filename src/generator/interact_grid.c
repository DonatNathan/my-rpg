/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** interact_grid
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../includes/rpg.h"

int move_map_key(game_ *game, grid_cell_ *grid, gen_control_ *gen_control)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        (gen_control->sprites_on == 0) ? (moov_up_gen(gen_control->list)) :
        (moov_up(grid));
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        (gen_control->sprites_on == 0) ? (moov_down_gen(gen_control->list)) :
        (moov_down(grid));
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        (gen_control->sprites_on == 0) ? (moov_right_gen(gen_control->list)) :
        (moov_left(grid));
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        (gen_control->sprites_on == 0) ? (moov_left_gen(gen_control->list)) :
        (moov_right(grid));
    }
    return (0);
}

int move_wall(game_ *game, grid_cell_ *wall_1, grid_cell_ *wall_2)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        moov_up_(wall_1);
        moov_up_(wall_2);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        moov_down_(wall_1);
        moov_down_(wall_2);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        moov_left_(wall_1);
        moov_left_(wall_2);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        moov_right_(wall_1);
        moov_right_(wall_2);
    }
    return (0);
}

int check_map_key_input(game_ *game, grid_cell_ *grid)
{
    move_map_key(game, grid, game->gen_control);
    move_map_key(game, grid, game->gen_control_mob);
    (sfKeyboard_isKeyPressed(sfKeyR)) ? (reset_grid(grid)) : 1;
    (sfKeyboard_isKeyPressed(sfKeyEnter)) ? (save_all(game, grid)) : 1;
    (sfKeyboard_isKeyPressed(sfKeyUp)) ? (game->layer = 1) : 1;
    (sfKeyboard_isKeyPressed(sfKeyDown)) ? (game->layer = 0) : 1;
    (sfKeyboard_isKeyPressed(sfKeyRight)) ? (game->layer = 2) : 1;
    (sfKeyboard_isKeyPressed(sfKeyLeft)) ? (game->layer = 3) : 1;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        loop_menu(game, game->menu);
    return (0);
}

void check_map_mouse_input(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        left_click_grid(game, grid, paint);
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
        right_click_grid(game, grid, paint, game->gen_control);
}
