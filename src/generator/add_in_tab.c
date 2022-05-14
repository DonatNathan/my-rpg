/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** add_in_tab
*/

#include "../../includes/rpg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_id_int_tab_2(char ***tab, char *id, int k, int j)
{
    int r = 0;

    for (; tab[k][j]; j++) {
        for (r = 0; id[r] != '\0'; r++) {
            tab[k][j][r] = id[r];
        }
        tab[k][j][r] = '\0';
    }
}

void add_id_in_tab(char ***tab, char *id, int y, int x)
{
    int k = y;
    int j = x;

    for (; tab[k]; k++) {
        add_id_int_tab_2(tab, id, k, j);
    }
}
