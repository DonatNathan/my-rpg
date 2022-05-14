/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** go_to
*/

#include "../../includes/rpg.h"

void go_mid(game_ *game)
{
    game->y_start = -250;
    game->x_start = -445;
}

void go_top(game_ *game)
{
    game->y_start = 400;
}

void go_bottom(game_ *game)
{
    game->y_start = -850;
}

void go_left(game_ *game)
{
    game->x_start = 800;
}

void go_right(game_ *game)
{
    game->x_start = -1240;
}
