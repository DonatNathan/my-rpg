/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** fight_enemy
*/

#include "../../includes/rpg.h"

enemy_ *init_fight_mob(game_ *game, int k)
{
    enemy_ *temp = malloc(sizeof(enemy_));
    sfVector2f pos = {1150, 350};
    switch (k) {
        case (1): temp = create_enemy(pos, (sfIntRect){22, 50, 16, 16}, 100,
            1); game->fight->enemy->pv = 250; return (temp);
        case (2): temp = create_enemy(pos, (sfIntRect){22, 145, 16, 16}, 100,
            2); game->fight->enemy->pv = 40; return (temp);
        case (3): temp = create_enemy(pos, (sfIntRect){22, 334, 16, 32}, 100,
            3); game->fight->enemy->pv = 10; return (temp);
        case (4): temp = create_enemy(pos, (sfIntRect){22, 480, 16, 32}, 100,
            4); game->fight->enemy->pv = 140; return (temp);
        case (5): temp = create_enemy(pos, (sfIntRect){27, 695, 16, 16}, 105,
            5); game->fight->enemy->pv = 40;; return (temp);
        case (6): temp = create_enemy(pos, (sfIntRect){27, 775, 16, 16}, 105,
            6); game->fight->enemy->pv = 500; return (temp);
        case (7): temp = create_enemy(pos, (sfIntRect){22, 871, 16, 32}, 100,
            7); game->fight->enemy->pv = 280; return (temp);
        default:
            return (temp);
    }
}

int init_fight_pv(game_ *game, int k)
{
    switch (k) {
        case (1): return (250);
        case (2): return (40);
        case (3): return (10);
        case (4): return (140);
        case (5): return (40);
        case (6): return (500);
        case (7): return (280);
        default: return (1000);
    }
}

void update_enemy_f(enemy_ *enemy, game_ *game)
{
    draw_particles(game);
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->secs = enemy->time.microseconds / 5000;
    if (enemy->secs > 30) {
        enemy->rect.left += enemy->rect.width;
        sfClock_restart(enemy->clock);
    }
    if (enemy->rect.left > enemy->max - enemy->rect.width)
        enemy->rect.left = enemy->start;
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfSprite_setScale(enemy->sprite, (sfVector2f){7, 7});
    move_enemy(enemy, game->player->movement, game);
    sfRenderWindow_drawSprite(game->window, enemy->sprite, sfFalse);
    if (enemy->next != NULL)
        update_enemy_f(enemy->next, game);
}
