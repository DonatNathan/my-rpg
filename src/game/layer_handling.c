/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** layer_handling
*/

#include "../../includes/rpg.h"

void move_layer_(layer_ *layer, game_ *game, int y)
{
    int x;

    for (x = 0; layer->map_layer_1[y][x]; x++) {
        if (layer->map_layer_1[y][x] != NULL &&
            layer->map_layer_2[y][x] != NULL &&
            layer->map_layer_3[y][x] != NULL) {
            move_tiles(layer->map_layer_1, game, y, x);
            move_tiles(layer->map_layer_2, game, y, x);
            move_tiles(layer->map_layer_3, game, y, x);
        }
    }
}

void move_layer(layer_ *layer, game_ *game)
{
    int y = 0;

    for (y = 0; layer->map_layer_1[y]; y++) {
        move_layer_(layer, game, y);
    }
}

int launch_layer_if(game_ *game, layer_ *layer, sfVector2f pos, sfSprite *rep)
{
    if (layer->id_foreground[(int)((500 - pos.y + 120) / 40)] != NULL &&
    (layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
    [(int)((950 - pos.x) / 40)] != NULL ||
    layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
    [(int)((950 - pos.x - 10) / 40)] != NULL ||
    layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
    [(int)((950 - pos.x + 10) / 40)] != NULL)) {
        if ((my_atoi(layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
        [(int)((950 - pos.x) / 40)]) != 1945 ||
        my_atoi(layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
        [(int)((950 - pos.x - 80) / 40)]) != 1945)) {
            return (1);
        }
    }
    return (0);
}

void launch_layer(game_ *game, layer_ *layer, sfVector2f pos, sfSprite *rep)
{
    sfRenderWindow_clear(game->window, sfBlack);
    check_event_game(game);
    move_layer(layer, game);
    display_layer(layer->map_layer_1, game, game->player->movement);
    display_layer_h(layer->map_layer_3, game, pos);
    update_enemy(game->first, game);
    if (launch_layer_if(game, layer, pos, rep) == 1) {
        update_bar(game);
        update_player(game, game->player);
        display_layer(layer->map_layer_2, game, game->player->movement);
    } else if (launch_layer_if(game, layer, pos, rep) == 0) {
        display_layer(layer->map_layer_2, game, game->player->movement);
        update_bar(game);
        update_player(game, game->player);
    }
    move_page_best_right(game);
    move_page_best_left(game);
    sfRenderWindow_drawSprite(game->window, game->clock->light, sfFalse);
    update_inv(game);
    move_rep(rep, game->player->movement, game);
}
