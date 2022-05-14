/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the file that contain function to create particles
*/

#include "../../includes/rpg.h"

void check_events_particles(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyK) && game->clock->check_secs != 0 &&
    game->boole->draw_particles == 1) {
        game->boole->draw_particles = 0;
        game->clock->check_secs = 0;
    } else if (sfKeyboard_isKeyPressed(sfKeyK) && game->clock->check_secs != 0
    && game->boole->draw_particles == 0) {
        game->boole->draw_particles = 1;
        game->clock->check_secs = 0;
    }
}

void my_draw_square(game_ *game, sfVector2u position, sfColor color)
{
    int cmpt_x;
    int cmpt_y;
    int size = game->particles->size;

    for (cmpt_x = position.x; cmpt_x < position.x + size; cmpt_x += 10) {
        for (cmpt_y = position.y; cmpt_y < position.y + size;
        cmpt_y += 10) {
            (rand() % 5 == 1) ? draw_little(game, (sfVector2u){cmpt_x, cmpt_y},
            color, 0) : draw_little(game, (sfVector2u){cmpt_x, cmpt_y},
            color, 1);
        }
    }
}

void draw_particles(game_ *game)
{
    if (game->clock->check_secs % 100 == 0) {
        my_draw_square(game, game->particles->position,
        game->particles->color);
    }
    sfTexture_updateFromPixels(game->particles->texture,
    game->particles->framebuffer->pixels, 120, 120, 0, 0);
    sfRenderWindow_drawSprite(game->window, game->particles->sprite, sfFalse);
}
