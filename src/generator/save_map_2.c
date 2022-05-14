/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** save_map_2
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../includes/rpg.h"

void save_mob_id_2(game_ *game, grid_cell_ *grid, FILE *file)
{
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 3632 &&
    (grid->mob_id) <= 4967)
        fwrite("4", 1, my_strlen("4"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 5206 &&
    (grid->mob_id) <= 5690)
        fwrite("5", 1, my_strlen("5"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 5932 &&
    (grid->mob_id) <= 6416)
        fwrite("6", 1, my_strlen("6"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 6536 &&
    (grid->mob_id) <= 8355)
        fwrite("7", 1, my_strlen("7"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 8356)
        fwrite("15", 1, my_strlen("15"), file);
}

void save_mob_id(game_ *game, grid_cell_ *grid, FILE *file)
{
    if ((grid->mob_id) == 1945)
        fwrite("0", 1, my_strlen("0"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) == 3)
        fwrite("100", 1, my_strlen("100"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) == 4)
        fwrite("200", 1, my_strlen("200"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 123 &&
    (grid->mob_id) <= 608)
        fwrite("1", 1, my_strlen("1"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 123 &&
    (grid->mob_id) <= 608)
        fwrite("1", 1, my_strlen("1"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 849 &&
    (grid->mob_id) <= 1455)
        fwrite("2", 1, my_strlen("2"), file);
    if ((grid->mob_id) != 1945 && (grid->mob_id) >= 2543 &&
    (grid->mob_id) <= 3394)
        fwrite("3", 1, my_strlen("3"), file);
}

void save_mob(game_ *game, grid_cell_ *grid, FILE *file)
{
    fwrite("[", 1, my_strlen("["), file);
    save_mob_id(game, grid, file);
    save_mob_id_2(game, grid, file);
    fwrite("]", 1, my_strlen("]"), file);
    if (grid->g_pos % grid->size_x == 0 && grid->g_pos
        != grid->size_x * grid->size_y)
        fwrite("\n", 1, my_strlen("\n"), file);
    if (grid->g_pos == grid->size_x * grid->size_y) {
        fwrite("\n", 1, my_strlen("\n"), file);
        fwrite("\0", 1, my_strlen("\0"), file);
    }
    if (grid->next_cell != NULL)
        save_mob(game, grid->next_cell, file);
}

void save_hitbox(game_ *game, grid_cell_ *grid, FILE *file)
{
    fwrite("[", 1, my_strlen("["), file);
    fwrite(new_put_nbr(grid->hitbox_id), 1,
    my_strlen(new_put_nbr(grid->hitbox_id)), file);
    fwrite("]", 1, my_strlen("]"), file);
    if (grid->g_pos % grid->size_x == 0 && grid->g_pos
        != grid->size_x * grid->size_y)
        fwrite("\n", 1, my_strlen("\n"), file);
    if (grid->g_pos == grid->size_x * grid->size_y) {
        fwrite("\n", 1, my_strlen("\n"), file);
        fwrite("\0", 1, my_strlen("\0"), file);
    }
    if (grid->next_cell != NULL)
        save_hitbox(game, grid->next_cell, file);
}
