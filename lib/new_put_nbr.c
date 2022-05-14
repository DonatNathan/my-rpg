/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** It's a program that take a string an return the result as an integer
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *calculs_str(int count, int nb, char *resultat, int cmpt_str)
{
    int result;

    while (count >= 0) {
        count = count - 1;
        result = nb / puissance(count);
        result = result % 10;
        resultat[cmpt_str] = result + 48;
        cmpt_str += 1;
    }
    return (resultat);
}

int get_len_nb(int nb)
{
    int len = 0;

    if (nb < 0) {
        nb *= -1;
        len += 1;
    }
    while (nb >= 1) {
        nb /= 10;
        len += 1;
    }
    return (len);
}

int check_count(int digits, int count)
{
    while (digits != 0) {
        digits = digits / 10;
        count = count + 1;
    }
    return (count);
}

char *set_end(char *result, int len, int is_neg)
{
    result[len] = '\0';
    return (result);
}

char *new_put_nbr(int nb)
{
    int len = get_len_nb(nb);
    int count = -1;
    int digits = nb;
    int cmpt_str = 0;
    int is_neg = 1;
    char *result = malloc(sizeof(char) * (len + 1));

    if (nb == 0)
        return ("0");
    if (nb < 0) {
        result[0] = '-';
        nb *= -1;
        digits *= -1;
        cmpt_str = 1;
        is_neg = 0;
    }
    result = calculs_str(check_count(digits, count), nb, result, cmpt_str);
    result = set_end(result, len, is_neg);
    return (result);
}
