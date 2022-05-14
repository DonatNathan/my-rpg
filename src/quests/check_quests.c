/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** detect_fight
*/

#include "../../includes/rpg.h"

void update_materials(game_ *game)
{
    sfText_setString(game->player->nb_log->text,
    new_put_nbr(game->player->log));
    sfText_setString(game->player->nb_rock->text,
    new_put_nbr(game->player->rock));
    sfRenderWindow_drawText(game->window, game->player->nb_log->text, sfFalse);
    sfRenderWindow_drawText
    (game->window, game->player->nb_rock->text, sfFalse);
    sfText_setString(game->player->nb_kills->text,
    new_put_nbr(game->player->kills));
    sfRenderWindow_drawText(game->window, game->player->nb_kills->text,
    sfFalse);
}

int check_step_quests(quests_ *quest, int id, int is_done, int step)
{
    if (quest->id_mob == id && quest->step == step)
        is_done = 0;
    if (quest->next)
        is_done = check_step_quests(quest->next, id, is_done, step);
    return (is_done);
}

int check_state_quests(quests_ *quest, int id, int is_done)
{
    if (quest->id_mob == id && quest->state == 2)
        is_done = 0;
    if (quest->next)
        is_done = check_state_quests(quest->next, id, is_done);
    return (is_done);
}

void launch_quest(quests_ *quest, game_ *game, int action)
{
    quest->read = 0;
    quest->state = action;
}

void change_step(quests_ *quest)
{
    quest->step += 1;
    quest->read = 1;
}
