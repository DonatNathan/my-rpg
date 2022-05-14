/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to set the tree skill
*/

#include "../../includes/rpg.h"

void set_texture_tree(game_ *game)
{
    game->inv->tree->tree = sfTexture_createFromFile\
    ("pictures/menu/buf.png", NULL);
}

void create_bonus(game_ *game)
{
    game->bonus = malloc(sizeof(bonus_));
}

void set_all_skills(game_ *game)
{
    for (int level = 0; level < 7; level += 1) {
        for (int cmpt = 0; cmpt < 4; cmpt += 1) {
            game->inv->tree->x += 300;
            get_last_skill(game, cmpt, level);
        }
        game->inv->tree->y += 100;
        game->inv->tree->x = 150;
    }
}

void create_tree(game_ *game)
{
    game->inv->tree = malloc(sizeof(skill_tree_));
    game->inv->tree->back = sfSprite_create();
    game->inv->tree->t_back = sfTexture_createFromFile\
    ("pictures/menu/menu.png", NULL);
    set_texture_tree(game);
    sfSprite_setTexture(game->inv->tree->back, game->inv->tree->t_back,
    sfFalse);
    sfSprite_setTextureRect(game->inv->tree->back,
    (sfIntRect){960, 0, 320, 204});
    sfSprite_setScale(game->inv->tree->back, (sfVector2f){6, 5.72});
    game->inv->tree->x = 900;
    game->inv->tree->y = 450;
    game->inv->tree->first_skill = create_skill(game, -1, -1);
    game->inv->tree->x = 150;
    game->inv->tree->y = 200;
    set_all_skills(game);
}

void enable_bonus(game_ *game, chained_skill_ *skill)
{
    skill->active = 0;
    sfSprite_setColor(skill->skill, (sfColor){255, 255, 255, 255});
    game->player->gold -= skill->price;
    if (skill->type == 0) {
        game->bonus->speed += skill->value;
        game->player->stats->speed += skill->value;
    }
    if (skill->type == 1) {
        game->bonus->life += skill->value;
        game->player->stats->life += skill->value;
        add_hearth(game->inv->life, game->inv->x_hearth, game);
    }
    if (skill->type == 2) {
        game->bonus->attack += skill->value;
        game->player->stats->attack += skill->value;
    }
    if (skill->type == 3)
        game->bonus->gold += skill->value;
    if (skill->type == -1)
        game->bonus->all += skill->value;
}
