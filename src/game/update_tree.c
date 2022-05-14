/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to set the tree skill
*/

#include "../../includes/rpg.h"

void set_string_skills(game_ *game, chained_skill_ *skill)
{
    if (skill->type == 1)
        sfText_setString(skill->infos, new_put_nbr(skill->value));
    if (skill->type == 2)
        sfText_setString(skill->infos, new_put_nbr(skill->value));
    if (skill->type == 3)
        sfText_setString(skill->infos, new_put_nbr(skill->value));
    if (skill->type == -1)
        sfText_setString(skill->infos, new_put_nbr(skill->value));
    if (skill->type == 0)
        sfText_setString(skill->infos, new_put_nbr(skill->value));
    sfText_setString(skill->cost, \
    my_strcat(new_put_nbr(skill->price), " GOLD"));
}

void draw_skill_tree(game_ *game, chained_skill_ *skill)
{
    if (game->mouse.x > skill->pos_skill.x && game->mouse.x <
    skill->pos_skill.x + 100 && game->mouse.y > skill->pos_skill.y
    && game->mouse.y < skill->pos_skill.y + 100 && skill->active == 1) {
        set_string_skills(game, skill);
        sfRenderWindow_drawText(game->window, skill->infos, sfFalse);
        sfRenderWindow_drawText(game->window, skill->cost, sfFalse);
    }
    sfRenderWindow_drawSprite(game->window, skill->skill, sfFalse);
    if (skill->next != NULL) {
        draw_skill_tree(game, skill->next);
    }
}
