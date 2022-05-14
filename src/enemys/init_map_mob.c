/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** init_map_mob
*/

#include "../../includes/rpg.h"

void init_map_mob_3(int y, int x, layer_ *layer, game_ *game)
{
    sfVector2f pos = {40 * x, 40 * y};
    pos.x += game->x_start;
    pos.y += game->y_start;
    switch (my_atoi(layer->id_mob[y][x])) {
        case (12): game->first->temp_id = 12; get_last_e(game->first, pos,
            (sfIntRect){364, 3252, 16, 32}, 436); break;
        case (13): game->first->temp_id = 13; get_last_e(game->first, pos,
            (sfIntRect){364, 3711, 16, 32}, 436); break;
        case (14): game->first->temp_id = 14; get_last_e(game->first, pos,
            (sfIntRect){364, 4204, 16, 32}, 436); break;
        case (15): game->first->temp_id = 15; get_last_e(game->first, pos,
            (sfIntRect){364, 4690, 16, 32}, 436); break;
        case (16): game->first->temp_id = 15; get_last_e(game->first, pos,
            (sfIntRect){364, 4920, 16, 32}, 436); break;
        case (100): game->first->temp_id = 100; get_last_e(game->first, pos,
            (sfIntRect){30, 0, 16, 16}, 30); break;
        case (200): game->first->temp_id = 200; get_last_e(game->first, pos,
            (sfIntRect){46, 0, 16, 16}, 46); break;
        default: break;
    }
}

void init_map_mob_2(int y, int x, layer_ *layer, game_ *game)
{
    sfVector2f pos = {40 * x, 40 * y};
    pos.x += game->x_start;
    pos.y += game->y_start;

    switch (my_atoi(layer->id_mob[y][x])) {
        case (7): game->first->temp_id = 7; get_last_e(game->first, pos,
            (sfIntRect){22, 871, 16, 32}, 100); break;
        case (8): game->first->temp_id = 8; get_last_e(game->first, pos,
            (sfIntRect){364, 1505, 16, 32}, 436); break;
        case (9): game->first->temp_id = 9; get_last_e(game->first, pos,
            (sfIntRect){364, 1613, 16, 32}, 436); break;
        case (10): game->first->temp_id = 10; get_last_e(game->first, pos,
            (sfIntRect){365, 2200, 16, 32}, 437); break;
        case (11): game->first->temp_id = 11; get_last_e(game->first, pos,
            (sfIntRect){364, 2728, 16, 32}, 436); break;
        default: init_map_mob_3(y, x, layer, game);
    }
}

void init_map_mob(int y, int x, layer_ *layer, game_ *game)
{
    sfVector2f pos = {40 * x, 40 * y};
    pos.x += game->x_start;
    pos.y += game->y_start;

    switch (my_atoi(layer->id_mob[y][x])) {
        case (1): game->first->temp_id = 1; get_last_e(game->first, pos,
            (sfIntRect){22, 50, 16, 16}, 100); break;
        case (2): game->first->temp_id = 2; get_last_e(game->first, pos,
            (sfIntRect){22, 145, 16, 16}, 100); break;
        case (3): game->first->temp_id = 3; get_last_e(game->first, pos,
            (sfIntRect){22, 334, 16, 32}, 100); break;
        case (4): game->first->temp_id = 4; get_last_e(game->first, pos,
            (sfIntRect){22, 480, 16, 32}, 100); break;
        case (5): game->first->temp_id = 5; get_last_e(game->first, pos,
            (sfIntRect){27, 695, 16, 16}, 105); break;
        case (6): game->first->temp_id = 6; get_last_e(game->first, pos,
            (sfIntRect){27, 775, 16, 16}, 105); break;
        default: init_map_mob_2(y, x, layer, game);
    }
}
