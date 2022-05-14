/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void init_layer_1(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, game_ *game)
{
    int highest;
    char *map = my_strcat(game->map, "test.txt");

    get_size_2(map, load_map);
    create_gen(gen_control, 1);
    layer->map = my_malloc_map(load_map->y_size, load_map->x_size);
    layer->map_layer_1 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    layer->id_background = get_map(load_map);
    init_map(layer->map, load_map);
    highest = find_highest(layer->id_background);
    add_tileset(layer->map_layer_1, gen_control->list, layer->id_background,
    highest);
}

void init_layer_2(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, game_ *game)
{
    int highest;
    char *map = my_strcat(game->map, "foreground.txt");

    get_size(map, load_map);
    layer->map_2 = my_malloc_map(load_map->y_size, load_map->x_size);
    layer->map_layer_2 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    layer->id_foreground = get_map_2(load_map);
    init_map(layer->map_2, load_map);
    highest = find_highest(layer->id_foreground);
    add_tileset(layer->map_layer_2, gen_control->list, layer->id_foreground,
    highest);
}

void init_layer_3(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, game_ *game)
{
    int highest;
    char *map = my_strcat(game->map, "hitbox.txt");

    get_size_3(map, load_map);
    create_gen(gen_control, 1);
    layer->map_3 = my_malloc_map(load_map->y_size, load_map->x_size);
    layer->map_layer_3 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    layer->id_hitbox = get_map_3(load_map);
    init_map(layer->map_3, load_map);
    highest = find_highest(layer->id_hitbox);
    add_tileset(layer->map_layer_3, gen_control->list, layer->id_hitbox,
    highest);
}

void init_layer_4(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, game_ *game)
{
    char *map = my_strcat(game->map, "mob.txt");
    get_size_4(map, load_map);
    layer->map_4 = my_malloc_map(load_map->y_size, load_map->x_size);
    layer->map_layer_4 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    layer->id_mob = get_map_4(load_map);
    init_mob(load_map, game, layer);
}

void init_layer(layer_ *layer, load_map_ *load_map, gen_control_ *gen_control
, game_ *game)
{
    load_map->y_size = 40;
    load_map->x_size = 60;
    update_loading(game);
    init_layer_1(layer, load_map, gen_control, game);
    update_loading(game);
    init_layer_2(layer, load_map, gen_control, game);
    update_loading(game);
    init_layer_3(layer, load_map, gen_control, game);
    update_loading(game);
    init_layer_4(layer, load_map, gen_control, game);
}
