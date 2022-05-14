/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** destroy_enemy
*/

#include "../../includes/rpg.h"

int destroy_mob(int y, int x, enemy_ *enemy)
{
    if (enemy->next != NULL) {
        sfVector2f pos = sfSprite_getPosition(enemy->next->sprite);
        if (((int)pos.y / 40 == y) && ((int)pos.x / 40) == x) {
            enemy->next = enemy->next->next;
            return (1);
        }
    }
    if (enemy->next->next != NULL)
        destroy_mob(y, x, enemy->next);
    return (0);
}
