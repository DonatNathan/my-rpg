/*
** EPITECH PROJECT, 2021
** MY_PUTCHAR
** File description:
** It's a program that display a character
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
