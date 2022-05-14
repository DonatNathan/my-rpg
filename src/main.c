/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the main file of my project my_rgp
*/

#include "../includes/rpg.h"

int main(int argc, char **argv)
{
    if (check_glob_gestion(argc, argv) == 84)
        return (84);
    if (my_strcmp(argv[1], "-p") == 0)
        launch_menu((sfVideoMode){1920, 1080, 120}, (sfVector2u){1920, 10180},
        argv[2]);
    return (0);
}
