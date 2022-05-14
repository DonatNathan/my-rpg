/*
** EPITECH PROJECT, 2021
** MY_STRCMP
** File description:
** It's a function that compare two string
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int cmpt;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    for (cmpt = 0; cmpt < my_strlen(s1); cmpt += 1) {
        if (s1[cmpt] != s2[cmpt])
            return (1);
    }
    return (0);
}
