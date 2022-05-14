/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to do the gestion of params
*/

#include "../../includes/rpg.h"

void display_command(void)
{
    my_printf("-h : Display the menu \"Help\" (if you read that, you know how \
to do this ^^)\n");
    my_printf("-p <username> : Launch the game with your pseudo\n");
    my_printf("    Use the pseudo \"Jessica\" to have a bonus\n\n");
    my_printf("=> How to play ingame ?\n\n");
    my_printf("Movements : ZQSD (Top, Left, Bottom, Right)\n");
    my_printf("Escape : Open/Close pause menu\n");
    my_printf("I : Open/Close Inventory\nM : Open/Close Map\n");
    my_printf("P : Show/Hidden collisions\nC : Open/Close quests menu\n");
    my_printf("E : Interact with PNJ\n\n");
}

void display_help(void)
{
    my_printf("########## WELCOME IN OUR RPG ##########\n\n");
    my_printf("=> Synopsis :\n\n");
    my_printf("You are a pirate stranded on a desert island.\nSo we have to \
find a way to survive and get out of here.\nBut you notice while exploring \
the island that it is not that deserted...\n\n");
    my_printf("=> How to launch game ?\n\n");
    display_command();
    my_printf("Good luck pirate !\n\n");
    my_printf("  ______________________________________\n");
    my_printf(" /                                      \\\n");
    my_printf(" |      Vivien | Corentin | Nathan      |\n");
    my_printf(" \\______________________________________/\n\n");
}

int check_h(int argc, char **argv)
{
    if (my_strcmp(argv[1], "-h") == 0) {
        if (argc != 2) {
            write(2, "Too many arguments with -h option\n", 34);
            return (84);
        } else
            display_help();
    }
    return (0);
}

int check_p(int argc, char **argv)
{
    if (my_strcmp(argv[1], "-p") == 0) {
        if (argc != 3) {
            write(2, "Too few arguments with -p option\n", 33);
            return (84);
        }
    }
    return (0);
}

int check_glob_gestion(int argc, char **argv)
{
    if (argc < 2 || argc > 3) {
        write(2, "Invalid number of arguments\n", 28);
        return (84);
    }
    if (my_strcmp(argv[1], "-h") != 0 && my_strcmp(argv[1], "-p") != 0) {
        write (2, "Invalid argument\n", 17);
        return (84);
    }
    if (check_h(argc, argv) == 84)
        return (84);
    if (check_p(argc, argv) == 84)
        return (84);
    return (0);
}
