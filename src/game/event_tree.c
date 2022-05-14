/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to check event on skill's tree
*/

#include "../../includes/rpg.h"

chained_skill_ *check_prev(game_ *game, int cmpt)
{
    chained_skill_ *temp = game->inv->tree->first_skill;
    chained_skill_ *last_type = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
        if (temp->type == cmpt)
            last_type = temp;
    }
    if (last_type == NULL)
        return (game->inv->tree->first_skill);
    else
        return (last_type);
}

chained_skill_ *get_last_skill(game_ *game, int cmpt, int level)
{
    chained_skill_ *temp = game->inv->tree->first_skill;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = create_skill(game, cmpt, level);
    return (temp->next);
}

void check_mouse_tree(game_ *game, chained_skill_ *skill)
{
    sfVector2f scale = {1.5, 1.5};
    sfVector2f scale_basic = {1, 1};

    if (game->mouse.x > skill->pos_skill.x && game->mouse.x <
    skill->pos_skill.x + 100 && game->mouse.y > skill->pos_skill.y &&
    game->mouse.y < skill->pos_skill.y + 100 && skill->active == 1) {
        sfSprite_setPosition(skill->skill, skill->pos_skill2);
        sfSprite_setScale(skill->skill, scale);
        if (game->event.type == sfEvtMouseButtonReleased && game->player->gold
        >= skill->price && skill->prev->active == 0) {
            sfSound_play(game->sounds->click);
            enable_bonus(game, skill);
        }
    } else {
        sfSprite_setPosition(skill->skill, skill->pos_skill);
        sfSprite_setScale(skill->skill, scale_basic);
    }
    if (skill->next != NULL)
        check_mouse_tree(game, skill->next);
}

void event_tree(game_ *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyT) ||
    sfKeyboard_isKeyPressed(sfKeyEscape)) && game->clock->check_secs != 0) {
        game->boole->on_tree = 1;
        game->clock->check_secs = 0;
    }
    check_mouse_tree(game, game->inv->tree->first_skill);
}

void is_in_loop_tree(game_ *game)
{
    sfRenderWindow_drawSprite(game->window, game->inv->tree->back, sfFalse);
    draw_skill_tree(game, game->inv->tree->first_skill);
    event_tree(game);
}
