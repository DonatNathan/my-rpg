/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** set_game
*/

#include "../../includes/rpg.h"

void init_game_boole(game_ *game)
{
    game->boole->on_tree = 1;
    game->boole->on_quit = 1;
    game->boole->on_map = 1;
    game->boole->on_pad = 1;
    game->boole->on_girl = 1;
    game->boole->on_stats = 1;
    game->boole->on_potion = 1;
    game->boole->on_craft = 1;
    game->boole->on_hint = 0;
}

void create_all(game_ *game)
{
    create_inventory(game);
    create_ath(game);
    create_tree(game);
    create_bestiary(game);
    create_fight(game);
}

void set_game(game_ *game, int type)
{
    create_player(game, game->pseudo);
    game->player->rep = sfSprite_create();
    create_bonus(game);
    game->player->movement = 4;
    game->first_item = NULL;
    sfMusic_stop(game->sounds->ocean);
    sfMusic_play(game->sounds->summer_day);
    create_all(game);
    get_mob("bestiary.txt", game);
    init_bestiary(game);
    init_game_boole(game);
    game->player->rep = sfSprite_create();
    add_items(game, game->first_item, 48);
    game->boole->is_friend = 1;
    game->type = type;
    create_death_menu(game);
    create_particles(game);
}
