/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions create the time gestion
*/

#include "../../includes/rpg.h"

void change_date(game_ *game)
{
    if (game->clock->days == 91 && game->clock->saison != 1)
        game->clock->saison = 1;
    if (game->clock->days == 182 && game->clock->saison != 2)
        game->clock->saison = 2;
    if (game->clock->days == 273 && game->clock->saison != 3)
        game->clock->saison = 3;
    if (game->clock->secs % 60 == 0 && game->clock->secs !=
    game->clock->ancien_sec) {
        game->clock->hours += 1;
        game->clock->ancien_sec = game->clock->secs;
    }
    if (game->clock->hours >= 24) {
        game->clock->days += 1;
        game->clock->ancien_sec = game->clock->secs;
        game->clock->hours = 0;
    }
}

void check_hour2(game_ *game)
{
    if (game->clock->hours >= 6 && game->clock->hours < 7 &&
    game->clock->color.a > 0) {
        sfSprite_setRotation(game->clock->arrow->sprite, 190);
        sfSprite_setPosition(game->clock->arrow->sprite,
        (sfVector2f){1770, 120});
        game->clock->color.a -= 1;
    }
    if (game->clock->secs == 1380)
        sfClock_restart(game->clock->clock);
    if (game->clock->days > 364) {
        game->clock->days = 0;
        game->clock->saison = 0;
    }
}

void check_hour(game_ *game)
{
    if (game->clock->hours >= 20 && game->clock->hours < 21 &&
    game->clock->color.a < 100) {
        sfSprite_setPosition(game->clock->arrow->sprite,
        (sfVector2f){1712, 55});
        sfSprite_setRotation(game->clock->arrow->sprite, 295);
        game->clock->color.a += 1;
    }
    if (game->clock->hours > 21 || game->clock->hours < 6) {
        sfSprite_setRotation(game->clock->arrow->sprite, 350);
        sfSprite_setPosition(game->clock->arrow->sprite,
        (sfVector2f){1750, 20});
    }
    if (game->clock->hours > 7 && game->clock->hours < 20) {
        sfSprite_setRotation(game->clock->arrow->sprite, 245);
        sfSprite_setPosition(game->clock->arrow->sprite,
        (sfVector2f){1724, 102});
    }
    check_hour2(game);
}

void update_time(game_ *game)
{
    game->clock->time = sfClock_getElapsedTime(game->clock->clock);
    game->clock->secs = game->clock->time.microseconds / 100000;
    sfRenderWindow_drawSprite(game->window, game->clock->infos->sprite,
    sfFalse);
    check_hour(game);
    sfSprite_setColor(game->clock->light, game->clock->color);
    change_date(game);
    sfRenderWindow_drawSprite(game->window, game->clock->arrow->sprite,
    sfFalse);
    sfText_setString(game->inv->gold->text, new_put_nbr(game->player->gold));
    sfText_setString(game->clock->day->text,
    new_put_nbr(game->clock->days + 1));
    sfText_setString(game->clock->hour->text,
    new_put_nbr(game->clock->hours));
    sfRenderWindow_drawText(game->window, game->inv->gold->text, sfFalse);
    sfRenderWindow_drawText(game->window, game->clock->day->text, sfFalse);
    sfRenderWindow_drawText(game->window, game->clock->hour->text, sfFalse);
}
