/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** put number
*/

#include "my.h"

void my_put_nbr(int nb)
{
    int count = -1;
    int digits = nb;
    int result;

    if (nb < 0) {
        nb = nb - nb * 2;
        my_putchar(45);
    }
    if (nb == 0)
        my_putchar(48);
    for (; digits != 0; count += 1)
        digits = digits / 10;
    while (count >= 0) {
        count = count - 1;
        result = nb / puissance(count);
        result = result % 10 + 48;
        my_putchar((char)result);
    }
}
