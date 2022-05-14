/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to choose my game
*/

#include "../../includes/rpg.h"

void set_new_game2(game_ *game)
{
    game->player->log = 0;
    game->player->rock = 0;
    game->player->kills = 0;
    game->boole->new_quests = 0;
}

void set_new_game(game_ *game)
{
    game->clock->saison = 0;
    game->clock->days = 0;
    game->clock->hours = 12;
    game->bonus->all = 0;
    game->bonus->gold = 0;
    game->bonus->life = 0;
    game->bonus->speed = 0;
    game->bonus->attack = 0;
    if (my_strcmp(game->pseudo, "Jessica") == 0)
        game->player->gold = 10000;
    else
        game->player->gold = 10;
    game->player->stats->life = 3;
    game->player->stats->attack = 10;
    game->player->stats->speed = 0;
    if (game->boole->is_quit == 0) {
        game->x_start = -250;
        game->y_start = -445;
    }
    set_new_game2(game);
}

void set_save_map(game_ *game, char **saves)
{
    if (saves[8][0] == '-') {
        saves[8] += 1;
        game->x_start = my_atoi(saves[8]) * (-1);
    } else
        game->x_start = my_atoi(saves[8]);
    if (saves[9][0] == '-') {
        saves[9] += 1;
        game->y_start = my_atoi(saves[9]) * (-1);
    } else
        game->y_start = my_atoi(saves[9]);
}

void set_save2(game_ *game, char **saves)
{
    game->player->stats->attack = my_atoi(saves[3]);
    game->player->stats->life = my_atoi(saves[4]);
    game->player->stats->speed = my_atoi(saves[5]);
    game->player->rock = my_atoi(saves[25]);
    game->player->log = my_atoi(saves[24]);
    game->player->kills = my_atoi(saves[23]);
}

void set_save(game_ *game, char **saves)
{
    game->saves = saves;
    game->boole->new_quests = 1;
    game->clock->saison = my_atoi(saves[21]);
    game->clock->days = my_atoi(saves[20]);
    game->clock->hours = my_atoi(saves[19]);
    game->bonus->all = my_atoi(saves[13]);
    game->bonus->attack = my_atoi(saves[14]);
    game->bonus->gold = my_atoi(saves[15]);
    game->bonus->life = my_atoi(saves[16]);
    game->bonus->speed = my_atoi(saves[17]);
    game->player->gold = my_atoi(saves[1]);
    set_save2(game, saves);
    (game->clock->hours > 6 && game->clock->hours < 20) ?
    (game->clock->color.a = 0) : (game->clock->color.a = 100);
    if (game->boole->is_quit == 0) {
        set_save_map(game, saves);
        init_map_nbr(game, my_atoi(saves[10]), my_atoi(saves[11]));
    }
}
