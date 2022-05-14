/*
** EPITECH PROJECT, 2022
** my_tab.c
** File description:
** my_tab.c
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int my_count_split(char *argv, char char_)
{
    int i = 0;
    int j = 0;

    for (; argv[i]; i++) {
        if (argv[i] == char_)
            j++;
    }
    return (j + 1);
}

char **my_malloc_tab(int colum, int lines)
{
    char **temp = malloc(sizeof(char *) * (colum + 1));
    int k = 0;

    for (; k != colum; k++)
        temp[k] = malloc(sizeof(char) * lines);
    temp[k] = '\0';
    return (temp);
}

char **my_split_tab(char *argv, char char_)
{
    int k = 0;
    int l = 0;
    int i = 0;
    char **tab = my_malloc_tab(my_count_split(argv, char_), my_strlen(argv));

    for (; argv[k] != '\0'; k++, l++) {
        if (argv[k] == char_) {
            k++;
            tab[i][l] = '\0';
            l = 0;
            i++;
        } else {
            tab[i][l + 1] = '\0';
        }
        tab[i][l] = argv[k];
    }
    return (tab);
}

char **my_split_tabn(char *argv, char char_)
{
    int k = 0;
    int l = 0;
    int i = 0;
    char **tab = my_malloc_tab(my_count_split(argv, char_), my_strlen(argv));

    for (; argv[k] != '\n' && argv[k] != '\0'; k++, l++) {
        if (argv[k] == char_) {
            k++;
            tab[i][l] = '\0';
            l = 0;
            i++;
        } else {
            tab[i][l + 1] = '\0';
        }
        tab[i][l] = argv[k];
    }
    return (tab);
}

char **my_add_tab(char **tab, char *argv)
{
    int k = 0;

    for (; tab[k]; k++);
    tab[k] = argv;
    tab[k + 1] = NULL;
    return (tab);
}
