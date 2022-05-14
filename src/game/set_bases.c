/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain fucntions to create bases of our program
*/

#include "../../includes/rpg.h"

void set_boole(game_ *game)
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
