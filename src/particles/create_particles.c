/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the file that contain function to create particles
*/

#include "../../includes/rpg.h"

void create_framebuffer(game_ *game, int width, int height)
{
    game->particles->framebuffer = malloc(sizeof(framebuffer_t));
    game->particles->framebuffer->pixels = malloc((sizeof(sfUint8)) *
    (width * height * 4));
    game->particles->framebuffer->height = height;
    game->particles->framebuffer->width = width;
}

void create_particles(game_ *game)
{
    game->particles = malloc(sizeof(particles_t));
    game->particles->sprite = sfSprite_create();
    game->particles->texture = sfTexture_create(120, 120);
    game->particles->size = 120;
    sfSprite_setPosition(game->particles->sprite, (sfVector2f){1150, 350});
    game->particles->color = sfWhite;
    game->boole->draw_particles = 1;
    sfSprite_setTexture(game->particles->sprite, game->particles->texture,
    sfFalse);
    game->particles->position = (sfVector2u){0, 0};
    create_framebuffer(game, 120, 120);
}

void my_put_pixel(game_ *game, int x, int y, sfColor color)
{
    game->particles->framebuffer->pixels[game->particles->framebuffer->width
    * y * 4 + x * 4] = color.r;
    game->particles->framebuffer->pixels[game->particles->framebuffer->width
    * y * 4 + x * 4 + 1] = color.g;
    game->particles->framebuffer->pixels[game->particles->framebuffer->width
    * y * 4 + x * 4 + 2] = color.b;
    game->particles->framebuffer->pixels[game->particles->framebuffer->width
    * y * 4 + x * 4 + 3] = color.a;
}

void destroy_pixel(game_ *game, int x, int y, sfColor color)
{
    game->particles->framebuffer->pixels[game->particles->framebuffer->width
    * y * 4 + x * 4] = color.r;
    game->particles->framebuffer->pixels[game->particles->framebuffer->width
    * y * 4 + x * 4 + 1] = color.g;
    game->particles->framebuffer->pixels[game->particles->framebuffer->width
    * y * 4 + x * 4 + 2] = color.b;
    game->particles->framebuffer->pixels[game->particles->framebuffer->width
    * y * 4 + x * 4 + 3] = 0;
}

void draw_little(game_ *game, sfVector2u position, sfColor color, int action)
{
    int cmpt_x;
    int cmpt_y;
    int size = game->particles->size;

    for (cmpt_x = position.x; cmpt_x < position.x + size / 10; cmpt_x += 1) {
        for (cmpt_y = position.y; cmpt_y < position.y + size / 10;
        cmpt_y += 1) {
            (action == 0) ? my_put_pixel(game, cmpt_x, cmpt_y, color) :
            destroy_pixel(game, cmpt_x, cmpt_y, color);
        }
    }
}
