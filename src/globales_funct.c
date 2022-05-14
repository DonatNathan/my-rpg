/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** It's the file that contain globales functions
*/

#include "../includes/rpg.h"

sfIntRect change_rect(sfIntRect rect, float x, float y)
{
    rect.top = 0;
    rect.left = 0;
    rect.width = x;
    rect.height = y;
    return (rect);
}
