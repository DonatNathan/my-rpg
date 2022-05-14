/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

void choose_music2(game_ *game, button_ *button, menu_ *menu)
{
    if (button->position.x > menu->settings->back->position.x + 280 + 320 &&
    button->position.x < menu->settings->back->position.x + 280 + 430) {
        sfMusic_setVolume(game->sounds->ocean, 75);
        sfMusic_setVolume(game->sounds->summer_day, 75);
    }
    if (button->position.x > menu->settings->back->position.x + 280 + 430) {
        sfMusic_setVolume(game->sounds->ocean, 100);
        sfMusic_setVolume(game->sounds->summer_day, 100);
    }
}

void choose_music(game_ *game, button_ *button, menu_ *menu)
{
    if (button->position.x < menu->settings->back->position.x + 280 + 100) {
        sfMusic_setVolume(game->sounds->ocean, 0);
        sfMusic_setVolume(game->sounds->summer_day, 0);
    }
    if (button->position.x > menu->settings->back->position.x + 280 + 100 &&
    button->position.x < menu->settings->back->position.x + 280 + 210) {
        sfMusic_setVolume(game->sounds->ocean, 25);
        sfMusic_setVolume(game->sounds->summer_day, 25);
    }
    if (button->position.x > menu->settings->back->position.x + 280 + 210 &&
    button->position.x < menu->settings->back->position.x + 280 + 320) {
        sfMusic_setVolume(game->sounds->ocean, 50);
        sfMusic_setVolume(game->sounds->summer_day, 50);
    }
    choose_music2(game, button, menu);
}

void choose_sound2(game_ *game, button_ *button, menu_ *menu)
{
    if (button->position.x > menu->settings->back->position.x + 280 + 320 &&
    button->position.x < menu->settings->back->position.x + 280 + 430) {
        sfSound_setVolume(game->sounds->click, 75);
        sfSound_setVolume(game->sounds->parrot, 75);
        sfSound_setVolume(game->sounds->coin, 75);
    }
    if (button->position.x > menu->settings->back->position.x + 280 + 430) {
        sfSound_setVolume(game->sounds->click, 100);
        sfSound_setVolume(game->sounds->parrot, 100);
        sfSound_setVolume(game->sounds->coin, 100);
    }
}

void choose_sound(game_ *game, button_ *button, menu_ *menu)
{
    if (button->position.x < menu->settings->back->position.x + 280 + 100) {
        sfSound_setVolume(game->sounds->click, 0);
        sfSound_setVolume(game->sounds->parrot, 0);
        sfSound_setVolume(game->sounds->coin, 0);
    }
    if (button->position.x > menu->settings->back->position.x + 280 + 100 &&
    button->position.x < menu->settings->back->position.x + 280 + 210) {
        sfSound_setVolume(game->sounds->click, 25);
        sfSound_setVolume(game->sounds->parrot, 25);
        sfSound_setVolume(game->sounds->coin, 25);
    }
    if (button->position.x > menu->settings->back->position.x + 280 + 210 &&
    button->position.x < menu->settings->back->position.x + 280 + 320) {
        sfSound_setVolume(game->sounds->click, 50);
        sfSound_setVolume(game->sounds->parrot, 50);
        sfSound_setVolume(game->sounds->coin, 50);
    }
    choose_sound2(game, button, menu);
}

void change_volume(game_ *game, menu_ *menu, button_ *button, int action)
{
    if (game->mouse.x > button->position.x && game->mouse.x <
    button->position.x + 577 * button->scale.x && game->mouse.y >
    button->position.y && game->mouse.y < button->position.y + 433 *
    button->scale.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && game->mouse.x <=
        menu->settings->back->position.x + 720 + 577 * (button->scale.x / 2)
        && game->mouse.x > menu->settings->back->position.x + 280) {
            button->position.x = game->mouse.x - 577 * (button->scale.x / 2);
            sfSprite_setPosition(button->sprite, button->position);
            check_action(game, button, menu, action);
        }
    }
}
