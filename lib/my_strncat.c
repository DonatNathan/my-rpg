/*
** EPITECH PROJECT, 2021
** MY_STRNCAT
** File description:
** It's a program that concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int cmpt;
    char *result = malloc(sizeof(char) *
    (my_strlen(src) + my_strlen(dest) + 1));

    for (cmpt = 0; dest[cmpt] != '\0'; cmpt += 1)
        result[cmpt] = dest[cmpt];
    for (int i = 0; src[i] != '\0'; cmpt += 1, i += 1) {
        result[cmpt] = src[i];
    }
    result[cmpt] = '\0';
    return (result);
}

char *my_strcat_(char *dest, char src)
{
    int size = my_strlen(dest);

    dest[size] = src;
    dest[size + 1] = '\0';
    return (dest);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int size = my_strlen(dest);
    int cmpt;

    if (nb == 0)
        dest = my_strcat(dest, src);
    else {
        for (cmpt = 0; cmpt <= nb && src[cmpt] != '\0'; cmpt += 1)
            dest[size + cmpt] = src[cmpt];
        dest[size + cmpt] = '\0';
    }
    return (dest);
}
