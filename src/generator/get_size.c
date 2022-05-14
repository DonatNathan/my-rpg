/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** read_map
*/

#include "../../includes/rpg.h"

int get_file_len(char *files_name)
{
    int len = 0;
    char buff[1];
    int test = 1;

    int fd = open(files_name, O_RDONLY);
    for (test = 1; test != 0; len++)
        test = read(fd, buff, 1);
    close(fd);
    return (len);
}

void get_size(char *files_name, load_map_ *load_map)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * (len + 1));
    int fd = open(files_name, O_RDONLY);

    read(fd, temp, len);
    close(fd);
    temp[len] = '\0';
    load_map->back_full = temp;
}

void get_size_2(char *files_name, load_map_ *load_map)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * (len + 1));
    int fd = open(files_name, O_RDONLY);

    read(fd, temp, len);
    close(fd);
    temp[len] = '\0';
    load_map->fore_full = temp;
}

void get_size_3(char *files_name, load_map_ *load_map)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * (len + 1));
    int fd = open(files_name, O_RDONLY);

    read(fd, temp, len);
    close(fd);
    temp[len] = '\0';
    load_map->hit_full = temp;
}

void get_size_4(char *files_name, load_map_ *load_map)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * (len + 1));
    int fd = open(files_name, O_RDONLY);

    read(fd, temp, len);
    close(fd);
    temp[len] = '\0';
    load_map->mob_full = temp;
}
