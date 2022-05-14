/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** It's a program that copies charcter in another string
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    int cmpt = 0;
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    dest[my_strlen(src)] = '\0';
    while (src[cmpt] != '\0') {
        dest[cmpt] = src[cmpt];
        cmpt += 1;
    }
    while (dest[cmpt] != '\0') {
        dest[cmpt] = '\0';
        cmpt += 1;
    }
    return (dest);
}

char *my_strncpy(char *dest, char *src, int n)
{
    int cmpt;

    if (n == 0)
        dest = my_strcpy(dest, src);
    else {
        for (cmpt = 0; cmpt < n; cmpt += 1) {
            dest[cmpt] = src[cmpt];
        }
        while (cmpt < my_strlen(dest)) {
            dest[cmpt] = '\0';
            cmpt += 1;
        }
    }
    return (dest);
}
