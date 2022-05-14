/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** init_enemy_best
*/

#include "../../includes/rpg.h"

void init_mob_best_2_2(int k, sfVector2f pos, game_ *game)
{
    switch (k) {
        case (4):
            game->best->enemy_2 =
            create_enemy(pos, (sfIntRect){22, 480, 16, 32}, 100, 4);
            break;
        case (5):
            game->best->enemy_2 =
            create_enemy(pos, (sfIntRect){27, 695, 16, 16}, 105, 5);
            break;
        case (6):
            game->best->enemy_2 =
            create_enemy(pos, (sfIntRect){27, 775, 16, 16}, 105, 6);
            break;
        case (7):
            game->best->enemy_2 =
            create_enemy(pos, (sfIntRect){22, 871, 16, 32}, 100, 7);
            break;
    }
}

void init_mob_best_2_1(int k, sfVector2f pos, game_ *game)
{
    switch (k) {
        case (1):
            game->best->enemy_2 =
            create_enemy(pos, (sfIntRect){22, 50, 16, 16}, 100, 1);
            break;
        case (2):
            game->best->enemy_2 =
            create_enemy(pos, (sfIntRect){22, 145, 16, 16}, 100, 2);
            break;
        case (3):
            game->best->enemy_2 =
            create_enemy(pos, (sfIntRect){22, 334, 16, 32}, 100, 3);
            break;
        default:
            init_mob_best_2_2(k, pos, game);
    }
}

void init_mob_best_1_2(int k, sfVector2f pos, game_ *game)
{
    switch (k) {
        case (4):
            game->best->enemy_1 =
            create_enemy(pos, (sfIntRect){22, 480, 16, 32}, 100, 4);
            break;
        case (5):
            game->best->enemy_1 =
            create_enemy(pos, (sfIntRect){27, 695, 16, 16}, 105, 5);
            break;
        case (6):
            game->best->enemy_1 =
            create_enemy(pos, (sfIntRect){27, 775, 16, 16}, 105, 6);
            break;
        case (7):
            game->best->enemy_1 =
            create_enemy(pos, (sfIntRect){22, 871, 16, 32}, 100, 7);
            break;
    }
}

void init_mob_best_1_1(int k, sfVector2f pos, game_ *game)
{
    switch (k) {
        case (1):
            game->best->enemy_1 =
            create_enemy(pos, (sfIntRect){22, 50, 16, 16}, 100, 1);
            break;
        case (2):
            game->best->enemy_1 =
            create_enemy(pos, (sfIntRect){22, 145, 16, 16}, 100, 2);
            break;
        case (3):
            game->best->enemy_1 =
            create_enemy(pos, (sfIntRect){22, 334, 16, 32}, 100, 3);
            break;
        default:
            init_mob_best_1_2(k, pos, game);
    }
}

void update_enemy_best(enemy_ *enemy, game_ *game)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->secs = enemy->time.microseconds / 5000;
    if (enemy->secs > 30) {
        enemy->rect.left += enemy->rect.width;
        sfClock_restart(enemy->clock);
    }
    if (enemy->rect.left > enemy->max - enemy->rect.width)
        enemy->rect.left = enemy->start;
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfRenderWindow_drawSprite(game->window, enemy->sprite, sfFalse);
    if (enemy->next != NULL)
        update_enemy_best(enemy->next, game);
}
