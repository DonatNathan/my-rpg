/*
** EPITECH PROJECT, 2021
** MY_PRINTF
** File description:
** It's the main file of my program my_printf
*/

#include "my.h"
#include <stdarg.h>

void if_percentage(va_list list, char *s, int cmpt_char)
{
    if (s[cmpt_char] == 's')
        my_putstr(va_arg(list, char *));
    if (s[cmpt_char] == 'i' || s[cmpt_char] == 'd')
        my_put_nbr(va_arg(list, int));
    if (s[cmpt_char] == 'c')
        my_putchar((char)va_arg(list, int));
    if (s[cmpt_char] != 's' && s[cmpt_char] != 'i' && s[cmpt_char] != 'd' \
        && s[cmpt_char] != 'c' && s[cmpt_char] != 'S' && s[cmpt_char] != \
        'b' && s[cmpt_char] != 'n' && s[cmpt_char] != 'o' && s[cmpt_char] \
        != 'u' && s[cmpt_char] != 'x' && s[cmpt_char] != 'X')
        my_putchar(s[cmpt_char - 1]);
}

int my_printf(char *s, ...)
{
    va_list list;
    int cmpt_char;

    va_start(list, s);
    for (cmpt_char = 0; s[cmpt_char] != '\0'; cmpt_char += 1) {
        if (s[cmpt_char] == '%') {
            cmpt_char += 1;
            if_percentage(list, s, cmpt_char);
        } else
            my_putchar(s[cmpt_char]);
    }
    va_end(list);
    return (0);
}
