/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void check_if_quit(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->boole->on_quit == 1
        && game->boole->on_inv == 1 && game->boole->on_girl == 1 &&
        game->boole->on_stats == 1 && game->boole->on_map == 1 &&
        game->boole->on_potion == 1 && game->boole->on_craft == 1 &&
        game->boole->on_pad == 1 && game->boole->on_quit == 1
        && game->clock->check_secs != 0) {
            game->boole->on_quit = 0;
            game->clock->check_secs = 0;
    }
}

void check_event_game(game_ *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfMusic_stop(game->sounds->summer_day);
            save_game(game, game->type);
            sfRenderWindow_close(game->window);
        }
        check_if_quit(game);
        open_close_hint(game);
        check_event_cursor(game);
        move_select(game);
        check_event_items(game);
        open_close_inv(game);
        change_window(game);
        open_close_best(game);
        spawn_parrot(game);
        dialogues_event(game);
        check_event_quests(game);
        check_events_particles(game);
    }
}

void get_mob(char *files_name, game_ *game)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * len);
    int fd = open(files_name, O_RDONLY);

    read(fd, temp, len);
    temp[len] = '\0';
    close(fd);
    game->best->mob_stats = my_split_tab(temp, '\n');
}

void init_game(game_ *game, layer_ *layer, load_map_ *load_map
, gen_control_ *gen_control)
{
    create_life(game);
    game->load_map = load_map;
    char *map = my_strcat(game->map, "background.txt");
    get_size(map, game->load_map);
    game->layer_ = layer;
    game->first = create_enemy((sfVector2f){-1000, 1000},
    (sfIntRect){25, 480, 15, 30}, 90, -1);
    init_layer(layer, load_map, gen_control, game);
    tp_all(game);
}

void launch_game(game_ *game, int k, int map_number, int type)
{
    layer_ *layer = malloc(sizeof(layer_));
    gen_control_ *gen_control = malloc(sizeof(gen_control_));
    load_map_ *load_map = malloc(sizeof(load_map_));
    update_loading(game);
    check_pos(k, game, map_number);
    set_game(game, type);
    choose_save(game, type);
    create_quests(game);
    init_game(game, layer, load_map, gen_control);
    game->menu->on_load = 1;
    while (sfRenderWindow_isOpen(game->window)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        game->player->pos_r = sfSprite_getPosition(game->player->rep);
        game->boole->on_button = 1;
        check_event_game(game);
        launch_layer(game, layer, game->player->pos_r, game->player->rep);
        detect_fight(game);
        sfRenderWindow_display(game->window);
        tp_pos(game, type, 0);
    }
}
