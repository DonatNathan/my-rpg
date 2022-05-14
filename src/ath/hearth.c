/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create hearths
*/

#include "../../includes/rpg.h"

void draw_hearth(game_ *game, life_ *hearth, int nb)
{
    if (nb > 0) {
        sfSprite_setColor(hearth->hearth->sprite,
        (sfColor){255, 255, 255, 255});
    } else
        sfSprite_setColor(hearth->hearth->sprite, (sfColor){0, 255, 255, 200});
    nb -= 1;
    sfRenderWindow_drawSprite(game->window, hearth->hearth->sprite, sfFalse);
    if (hearth->next != NULL)
        draw_hearth(game, hearth->next, nb);
}

void add_hearth(life_ *hearth, int x, game_ *game)
{
    if (hearth->next != NULL)
        add_hearth(hearth->next, x, game);
    else {
        hearth->next = malloc(sizeof(life_));
        hearth->next->hearth = create_button((sfVector2f){x, 10},
        (sfVector2f){0.15, 0.15}, "pictures/ath/hearth.png");
        hearth->next->next = NULL;
        game->inv->x_hearth += 45;
    }
}

void create_life(game_ *game)
{
    game->inv->x_hearth = 10;
    game->inv->life = malloc(sizeof(life_));
    game->inv->life->hearth = create_button((sfVector2f){10, 10},
    (sfVector2f){0.15, 0.15}, "pictures/ath/hearth.png");
    game->inv->x_hearth += 45;
    game->inv->life->next = NULL;
    for (int cmpt = 1; cmpt < (game->bonus->life + 3);
    cmpt += 1)
        add_hearth(game->inv->life, game->inv->x_hearth, game);
}
