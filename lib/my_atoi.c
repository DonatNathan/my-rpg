/*
** EPITECH PROJECT, 2022
** MY_ATOI
** File description:
** Transform string into int
*/

#include <stdlib.h>

int puissance(int y)
{
    int compteur = 0;
    int resultat = 1;

    while (compteur <= y) {
        resultat = resultat * 10;
        compteur = compteur + 1;
    }
    return resultat;
}

int my_atoi(char *str)
{
    int number = 0;

    for (int cmpt = 0; str[cmpt] != '\0' && str[cmpt] >= 0 + '0' &&
            str[cmpt] <= 9 + '0' && str[cmpt] != '\n'; cmpt += 1) {
        number *= 10;
        number += (str[cmpt] - 48);
    }
    return (number);
}

char *my_itoa(int nb)
{
    int len = 0;
    char *str;
    int tmp;

    tmp = nb;
    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}
