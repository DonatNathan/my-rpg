/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** bestiary
*/

#include "../../includes/rpg.h"

void init_bestiary(game_ *game)
{
    char **tab = my_split_tab(game->best->mob_stats[1], '/');
    game->best->name_l = create_text(tab[1], (sfVector2f){1, 1},
    (sfVector2f){750, 270}, "font/Stardew_Valley.ttf");
    game->best->pv_l = create_text(tab[2], (sfVector2f){1, 1},
    (sfVector2f){750, 470}, "font/Stardew_Valley.ttf");
    game->best->dmg_l = create_text(tab[3], (sfVector2f){1, 1},
    (sfVector2f){750, 520}, "font/Stardew_Valley.ttf");
    char **tab_2 = my_split_tab(game->best->mob_stats[2], '/');
    game->best->name_r = create_text(tab_2[1], (sfVector2f){1, 1},
    (sfVector2f){1070, 270}, "font/Stardew_Valley.ttf");
    game->best->pv_r = create_text(tab_2[2], (sfVector2f){1, 1},
    (sfVector2f){1070, 470}, "font/Stardew_Valley.ttf");
    game->best->dmg_r = create_text(tab_2[3], (sfVector2f){1, 1},
    (sfVector2f){1070, 520}, "font/Stardew_Valley.ttf");
}

void create_bestiary(game_ *game)
{
    game->best = malloc(sizeof(bestiary_));
    game->best->enemy_1 = malloc(sizeof(enemy_));
    game->best->enemy_2 = malloc(sizeof(enemy_));
    game->best->page = 1;
    init_mob_best_1_1(1, (sfVector2f){1100, 380}, game);
    init_mob_best_2_1(2, (sfVector2f){740, 380}, game);
    game->best->back = create_button((sfVector2f){630, 230},
    (sfVector2f){1, 1}, "pictures/menu/book.png");
    game->best->arrow_l = create_button((sfVector2f){670, 560},
    (sfVector2f){1.5, 1.5}, "pictures/menu/arrow_l.png");
    game->best->arrow_r = create_button((sfVector2f){1240, 560},
    (sfVector2f){1.5, 1.5}, "pictures/menu/arrow_r.png");
    sfSprite_setScale(game->best->back->sprite, (sfVector2f){2, 2});
    game->boole->on_best = 1;
    game->best->page_l = create_text(new_put_nbr(game->best->page),
    (sfVector2f){1, 1}, (sfVector2f){800, 550}, "font/Stardew_Valley.ttf");
    game->best->page_r = create_text(new_put_nbr(game->best->page + 1),
    (sfVector2f){1, 1}, (sfVector2f){1120, 550}, "font/Stardew_Valley.ttf");
    get_mob("bestiary.txt", game);
    init_bestiary(game);
}

void open_close_best(game_ *game)
{
    if (game->boole->on_best == 1 && sfKeyboard_isKeyPressed(sfKeyB) &&
    game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_best = 0;
        game->boole->on_inv = 1;
    }
    if (game->boole->on_best == 0 && game->clock->check_secs != 0 &&
    (sfKeyboard_isKeyPressed(sfKeyB) || sfKeyboard_isKeyPressed(sfKeyEscape))
    && game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_best = 1;
    }
}
