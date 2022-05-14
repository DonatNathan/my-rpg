/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** detect_fight
*/

#include "../../includes/rpg.h"

void update_quests(game_ *game)
{
    if (game->boole->on_quests == 0) {
        sfRenderWindow_drawSprite(game->window, game->quests->back->sprite,
        sfFalse);
        draw_quests(game, game->quests);
    }
}

void check_quest(game_ *game, int id, quests_ *quest)
{
    game->dialogues->quest = "#not_now";
    if (quest->id_mob == 10)
        do_quests_abigail(quest, game);
    if (quest->id_mob == 9)
        do_quests_alex(quest, game);
    if (quest->id_mob == 11)
        do_quests_levis(quest, game);
    if (quest->id_mob == 16)
        do_quests_clint(quest, game);
    game->dialogues->pnj = quest->id_mob - 8;
}

void active_quest(game_ *game, int id, quests_ *quest)
{
    if (quest->id_mob == id) {
        check_quest(game, id, quest);
        game->boole->on_dialogue = 0;
        game->dialogues->line = 0;
    } else if (quest->next != NULL)
        active_quest(game, id, quest->next);
}

void check_event_quests(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyC) && game->boole->on_quests == 1 &&
    game->clock->check_secs != 0) {
        game->boole->on_quests = 0;
        game->clock->check_secs = 0;
    } else if (sfKeyboard_isKeyPressed(sfKeyC) && game->boole->on_quests == 0
    && game->clock->check_secs != 0) {
        game->boole->on_quests = 1;
        game->clock->check_secs = 0;
    }
}

void set_step_state(game_ *game, quests_ *new, int nb)
{
    if (game->boole->new_quests == 0) {
        new->step = 1;
        new->state = 0;
    } else if (nb < 4) {
        new->step = my_atoi(game->saves[31 + nb]);
        new->state = my_atoi(game->saves[27 + nb]);
    } else {
        new->step = 1;
        new->state = 0;
    }
}
