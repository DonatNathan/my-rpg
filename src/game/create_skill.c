/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create a skill
*/

#include "../../includes/rpg.h"

void set_stats_skill2(game_ *game, int cmpt, int level,
chained_skill_ *new_skill)
{
    if (cmpt == 3) {
        new_skill->value = 1 * (level + 1);
        sfSprite_setTextureRect(new_skill->skill,
        (sfIntRect){268, 0, 67, 68});
    } if (cmpt == -1) {
        new_skill->value = 100;
        sfSprite_setTextureRect(new_skill->skill,
        (sfIntRect){335, 0, 67, 68});
    }
}

void set_stats_skill(game_ *game, int cmpt, int level, \
chained_skill_ *new_skill)
{
    if (cmpt == 0) {
        new_skill->value = 1;
        sfSprite_setTextureRect(new_skill->skill,
        (sfIntRect){201, 68, 67, 68});
    } if (cmpt == 1) {
        new_skill->value = 1;
        sfSprite_setTextureRect(new_skill->skill,
        (sfIntRect){268, 68, 67, 68});
    } if (cmpt == 2) {
        new_skill->value = 1;
        sfSprite_setTextureRect(new_skill->skill,
        (sfIntRect){335, 68, 67, 68});
    }
    set_stats_skill2(game, cmpt, level, new_skill);
    sfSprite_setTexture(new_skill->skill, game->inv->tree->tree, sfFalse);
}

void create_infos_skill(game_ *game, chained_skill_ *new_skill)
{
    sfFont *font = sfFont_createFromFile("font/Stardew_Valley.ttf");

    new_skill->infos = sfText_create();
    new_skill->cost = sfText_create();
    new_skill->scale.x = 1;
    new_skill->scale.y = 1;
    new_skill->pos_infos.x = new_skill->pos_skill.x + 100;
    new_skill->pos_infos.y = new_skill->pos_skill.y + 10;
    new_skill->pos_cost.x = new_skill->pos_skill.x - 150;
    new_skill->pos_cost.y = new_skill->pos_skill.y + 10;
    sfText_setFont(new_skill->infos, font);
    sfText_setScale(new_skill->infos, new_skill->scale);
    sfText_setPosition(new_skill->infos, new_skill->pos_infos);
    sfText_setFont(new_skill->cost, font);
    sfText_setScale(new_skill->cost, new_skill->scale);
    sfText_setPosition(new_skill->cost, new_skill->pos_cost);
    sfText_setColor(new_skill->cost, sfYellow);
}

void set_skill(game_ *game, chained_skill_ *new_skill)
{
    new_skill->first = game->inv->tree->first_skill;
    new_skill->skill = sfSprite_create();
    new_skill->next = NULL;
    new_skill->pos_skill.x = game->inv->tree->x;
    new_skill->pos_skill.y = game->inv->tree->y;
    new_skill->pos_skill2.x = new_skill->pos_skill.x - 14;
    new_skill->pos_skill2.y = new_skill->pos_skill.y - 14;
    new_skill->active = 1;
}

chained_skill_ *create_skill(game_ *game, int cmpt, int level)
{
    chained_skill_ *new_skill = malloc(sizeof(chained_skill_));
    chained_skill_ *first = malloc(sizeof(chained_skill_));
    sfColor unactive = {255, 255, 255, 150};

    if (cmpt == -1) {
        new_skill->prev = first;
        new_skill->prev->active = 0;
    } else
        new_skill->prev = check_prev(game, cmpt);
    set_skill(game, new_skill);
    if (level == -1)
        new_skill->price = 1000;
    else
        new_skill->price = 100 * (level + 1);
    set_stats_skill(game, cmpt, level, new_skill);
    sfSprite_setPosition(new_skill->skill, new_skill->pos_skill);
    new_skill->type = cmpt;
    sfSprite_setColor(new_skill->skill, unactive);
    create_infos_skill(game, new_skill);
    return (new_skill);
}
