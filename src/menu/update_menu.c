/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to update my menu
*/

#include "../../includes/rpg.h"

void find_button(game_ *game, int who, menu_ *menu)
{
    if (who == 1) {
        game->boole->is_quit = 0;
        launch_game(game, 0, 1, 0);
    } if (who == 2)
        menu->on_load = 0;
    if (who == 3) {
        sfMusic_stop(game->sounds->ocean);
        sfRenderWindow_close(game->window);
    }
    if (who == 4 && menu->on_load == 0) {
        game->boole->is_quit = 0;
        launch_game(game, 0, 1, 1);
    } if (who == 5 && menu->on_load == 0) {
        game->boole->is_quit = 0;
        launch_game(game, 0, 1, 2);
    } if (who == 6 && menu->on_load == 0) {
        game->boole->is_quit = 0;
        launch_game(game, 0, 1, 3);
    }
}

void check_square(game_ *game, button_ *button, int who, menu_ *menu)
{
    if (game->mouse.x > button->position.x && game->mouse.x <
    button->position.x + button->rect.width * button->scale.x && game->mouse.y
    > button->position.y && game->mouse.y < button->position.y +
    button->rect.height * button->scale.y) {
        button->rect.left = 372;
        if (game->event.type == sfEvtMouseButtonReleased)
            find_button(game, who, menu);
    } else
        button->rect.left = 350;
    sfSprite_setTextureRect(button->sprite, button->rect);
}

void check_button(game_ *game, button_ *button, int who, menu_ *menu)
{
    if (game->mouse.x > button->position.x && game->mouse.x <
    button->position.x + button->rect.width * button->scale.x && game->mouse.y
    > button->position.y && game->mouse.y < button->position.y +
    button->rect.height * button->scale.y && menu->on_load == 1) {
        game->boole->on_button = 0;
        button->rect.top = 245;
        if (game->event.type == sfEvtMouseButtonReleased) {
            sfSound_play(game->sounds->click);
            find_button(game, who, menu);
        }
    } else
        button->rect.top = 187;
    sfSprite_setTextureRect(button->sprite, button->rect);
}
