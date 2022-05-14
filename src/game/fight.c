/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** fight
*/

#include "../../includes/rpg.h"

void create_fight(game_ *game)
{
    game->fight = malloc(sizeof(fight_));
    game->fight->enemy = malloc(sizeof(enemy_));
    game->fight->leave = create_button((sfVector2f){380, 650},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->fight->attack = create_button((sfVector2f){780, 650},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->fight->heal = create_button((sfVector2f){1180, 650},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->fight->back = create_button((sfVector2f){300, 130},
    (sfVector2f){1, 1}, "pictures/menu/fight_back.png");
    game->fight->t_attack = create_text("ATTACK", (sfVector2f){3, 3},
    (sfVector2f){840, 660}, "font/Stardew_Valley.ttf");
    game->fight->t_heal = create_text("HEAL", (sfVector2f){3, 3},
    (sfVector2f){1270, 660}, "font/Stardew_Valley.ttf");
    game->fight->t_leave = create_text("RUN", (sfVector2f){3, 3},
    (sfVector2f){500, 660}, "font/Stardew_Valley.ttf");
    game->boole->on_fight = 1;
}

void update_button_leave(game_ *game)
{
    if (game->mouse.x > 360 && game->mouse.x < 360 + 383 &&
        game->mouse.y > 650 && game->mouse.y < 650 + 143 &&
        game->boole->on_fight == 0 &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            game->boole->on_fight = 1;
            game->player->stats->life -= 1;
    }
}

void update_button_fight(game_ *game)
{
    int boole = 0;
    if (game->mouse.x > 780 && game->mouse.x < 780 + 383 &&
        game->mouse.y > 650 && game->mouse.y < 650 + 143 &&
        game->boole->on_fight == 0 &&
        sfMouse_isButtonPressed(sfMouseLeft) && boole == 0) {
            while (sfMouse_isButtonPressed(sfMouseLeft))
                boole = 1;
    }
    if (boole > 0) {
        boole = 0;
        game->fight->enemy->pv -= game->player->stats->attack;
    }
    if (game->fight->enemy->pv <= 0) {
        game->boole->on_fight = 1;
        game->player->stats->life += 1;
        game->player->kills += 1;
        game->player->gold += 10;
    }
}

void update_button_heal(game_ *game)
{
    int boole = 0;
    int k = 0;
    if (game->mouse.x > 1180 && game->mouse.x < 1180 + 383 &&
        game->mouse.y > 650 && game->mouse.y < 650 + 143 &&
        game->boole->on_fight == 0 &&
        sfMouse_isButtonPressed(sfMouseLeft) && boole == 0) {
            while (sfMouse_isButtonPressed(sfMouseLeft))
                boole = 1;
    }
    if (boole > 0) {
        boole = 0;
        k = rand() % 100;
        if (k > 70 && k < 90)
            game->player->stats->life += 1;
        if (k > 90 && k < 100) {
            (game->player->stats->life < 2) ?
            (game->player->stats->life += 2) :
            (game->player->stats->life += 1);
        }
    }
}
