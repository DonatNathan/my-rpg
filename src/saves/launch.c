/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to choose my game
*/

#include "../../includes/rpg.h"

void read_file(game_ *game, int fd, char *filepath)
{
    int len = get_file_len(filepath);
    char *file = malloc(sizeof(char) * len + 1);
    char **saves;

    read(fd, file, len);
    file[len] = '\0';
    if (my_strlen(file) == 1) {
        set_new_game(game);
        free(file);
    } else {
        saves = my_split_tab(file, '\n');
        set_save(game, saves);
        free(file);
    }
}

void get_save(game_ *game, char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "readding save failed\n", 21);
    } else
        read_file(game, fd, filepath);
}

void choose_save(game_ *game, int type)
{
    if (type == 0)
        set_new_game(game);
    else {
        if (type == 1)
            get_save(game, "save1.txt");
        if (type == 2)
            get_save(game, "save2.txt");
        if (type == 3)
            get_save(game, "save3.txt");
    }
}
