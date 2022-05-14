/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions create the time gestion
*/

#include "../../includes/rpg.h"

button_ *create_sprite(sfVector2f pos, sfVector2f scale, sfIntRect rect,
char *filepath)
{
    button_ *sprite = malloc(sizeof(button_));

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sprite->position = pos;
    sprite->scale = scale;
    sprite->rect = rect;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setPosition(sprite->sprite, sprite->position);
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return (sprite);
}

void create_light(clock_ *clock)
{
    sfTexture *texture = sfTexture_createFromFile("pictures/ath/white.png",
    NULL);

    clock->color = (sfColor){0, 0, 255, 0};
    clock->light = sfSprite_create();
    sfSprite_setTexture(clock->light, texture, sfFalse);
    sfSprite_setScale(clock->light, (sfVector2f){10, 10});
    sfSprite_setColor(clock->light, clock->color);
    sfSprite_setPosition(clock->light, (sfVector2f){0, 0});
}

void create_ath(game_ *game)
{
    game->clock->secs = 0;
    game->clock->infos = create_sprite((sfVector2f){1700, 10},
    (sfVector2f){3, 3}, (sfIntRect){0, 0, 72, 59}, "pictures/ath/clock.png");
    create_light(game->clock);
    game->clock->arrow = create_sprite((sfVector2f){1750, 15},
    (sfVector2f){3, 3}, (sfIntRect){72, 0, 8, 20}, "pictures/ath/clock.png");
    create_light(game->clock);
    game->inv->gold = create_text(new_put_nbr(game->player->gold),
    (sfVector2f){1, 1}, (sfVector2f){1755, 145}, "font/Stardew_Valley.ttf");
    game->clock->day = create_text(new_put_nbr(game->clock->days),
    (sfVector2f){1, 1}, (sfVector2f){1845, 15}, "font/Stardew_Valley.ttf");
    game->clock->hour = create_text(new_put_nbr(game->clock->secs / 60),
    (sfVector2f){1, 1}, (sfVector2f){1855, 85}, "font/Stardew_Valley.ttf");
    game->clock->ancien_sec = 0;
}
