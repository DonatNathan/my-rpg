/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** load_pos
*/

#include "../../includes/rpg.h"

void init_map_nbr(game_ *game, int map_number, int k)
{
    game->map_number = map_number;
    char *map = my_strcat("map/", my_itoa(game->map_number));
    game->map = my_strcat(map, "/");
    game->number = k;
}

void check_pos(int k, game_ *game, int map_number)
{
    init_map_nbr(game, map_number, k);
    switch (k) {
        case (0):
            go_mid(game);
            break;
        case (1):
            go_top(game);
            break;
        case (2):
            go_bottom(game);
            break;
        case (3):
            go_left(game);
            break;
        case (4):
            go_right(game);
            break;
    }
}

void tp_pos(game_ *game, int type, int death)
{
    if (type == 0)
        type = 3;
    game->boole->is_quit = 1;
    if (death == 1) {
        save_game(game, game->type);
        launch_game(game, 0, game->map_number, type);
    } if (game->y_start < -860) {
        save_game(game, game->type);
        launch_game(game, 1, game->map_number - 10, type);
    } if (game->y_start > 440) {
        save_game(game, game->type);
        launch_game(game, 2, game->map_number + 10, type);
    } if (game->x_start < -1280) {
        save_game(game, game->type);
        launch_game(game, 3, game->map_number + 2, type);
    } if (game->x_start > 840) {
        save_game(game, game->type);
        launch_game(game, 4, game->map_number - 2, type);
    }
}
