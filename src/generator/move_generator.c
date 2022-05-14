/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** interact_grid
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../includes/rpg.h"

int moov_up_gen(sprite_ *sprite)
{
    sprite->position.y += 40;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    if (sprite->next != NULL)
        moov_up_gen(sprite->next);
    return (0);
}

int moov_down_gen(sprite_ *sprite)
{
    sprite->position.y -= 40;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    if (sprite->next != NULL)
        moov_down_gen(sprite->next);
    return (0);
}

int moov_right_gen(sprite_ *sprite)
{
    sprite->position.x += 40;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    if (sprite->next != NULL)
        moov_right_gen(sprite->next);
    return (0);
}

int moov_left_gen(sprite_ *sprite)
{
    sprite->position.x -= 40;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    if (sprite->next != NULL)
        moov_left_gen(sprite->next);
    return (0);
}
