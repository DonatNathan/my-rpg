/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create an enemy
*/

#include "../../includes/rpg.h"

enemy_ *create_enemy(sfVector2f position, sfIntRect rect, int max, int id)
{
    enemy_ *new = malloc(sizeof(enemy_));
    new->id = id;
    new->pv = 1000;
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile("pictures/env/all_mob.png", NULL);
    new->scale = (sfVector2f){3, 3};
    new->position = position;
    new->rect = rect;
    new->clock = sfClock_create();
    new->secs = 0;
    new->next = NULL;
    new->max = max;
    new->start = rect.left;
    sfSprite_setTexture(new->sprite, new->texture, sfFalse);
    sfSprite_setScale(new->sprite, new->scale);
    sfSprite_setPosition(new->sprite, new->position);
    sfSprite_setTextureRect(new->sprite, new->rect);
    return (new);
}

void get_last_e(enemy_ *enemy, sfVector2f position,
sfIntRect rect, int max)
{
    if (enemy->next != NULL) {
        enemy->next->temp_id = enemy->temp_id;
        get_last_e(enemy->next, position, rect, max);
    } else {
        enemy->next = create_enemy(position, rect, max, enemy->temp_id);
    }
}

void move_enemy(enemy_ *enemy, int movement, game_ *game)
{
    if (movement == 0)
        enemy->position.y -= 3 * game->speed + game->player->stats->speed;
    if (movement == 1)
        enemy->position.x -= 3 * game->speed + game->player->stats->speed;
    if (movement == 2)
        enemy->position.y += 3 * game->speed + game->player->stats->speed;
    if (movement == 3)
        enemy->position.x += 3 * game->speed + game->player->stats->speed;
    sfSprite_setPosition(enemy->sprite, enemy->position);
}

void update_enemy(enemy_ *enemy, game_ *game)
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
    move_enemy(enemy, game->player->movement, game);
    if ((game->clock->hours > 5 && game->clock->hours < 20) || (enemy->id > 7))
        sfRenderWindow_drawSprite(game->window, enemy->sprite, sfFalse);
    if (enemy->next != NULL)
        update_enemy(enemy->next, game);
}
