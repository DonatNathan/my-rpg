/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** detect_fight
*/

#include "../../includes/rpg.h"

void do_quests_abigail2(quests_ *quest, game_ *game)
{
    if (quest->step == 3) {
        game->dialogues->quest = "#tuto_monster";
        if (quest->read == 1)
            add_items(game, game->first_item, 0);
        launch_quest(quest, game, 1);
        if (game->player->kills >= 5)
            change_step(quest);
    } if (quest->step == 4) {
        game->dialogues->quest = "#tuto_end";
        launch_quest(quest, game, 2);
    }
}

void do_quests_abigail(quests_ *quest, game_ *game)
{
    if (quest->step == 1) {
        game->dialogues->quest = "#tuto_wood";
        if (quest->read == 1)
            add_items(game, game->first_item, 161);
        launch_quest(quest, game, 1);
        if (game->player->log >= 5)
            change_step(quest);
    } if (quest->step == 2) {
        game->dialogues->quest = "#tuto_ore";
        if (quest->read == 1)
            add_items(game, game->first_item, 145);
        launch_quest(quest, game, 1);
        if (game->player->rock >= 5)
            change_step(quest);
    }
    do_quests_abigail2(quest, game);
}

void do_quests_alex(quests_ *quest, game_ *game)
{
    if (quest->step == 1 && check_state_quests(game->quests, 10, 1) == 0) {
        game->dialogues->quest = "#intro";
        launch_quest(quest, game, 1);
        if (game->player->kills >= 10)
            change_step(quest);
    } if (quest->step == 2) {
        game->dialogues->quest = "#go_wood";
        launch_quest(quest, game, 1);
    } if (quest->step == 2 && check_state_quests(game->quests, 11, 1) == 0) {
        game->dialogues->quest = "#go_ore";
        launch_quest(quest, game, 1);
    } if (quest->step == 3 && check_state_quests(game->quests, 15, 1) == 0) {
        game->dialogues->quest = "#alex_end";
        launch_quest(quest, game, 2);
    }
}

void do_quests_levis(quests_ *quest, game_ *game)
{
    if (quest->step == 1 && check_step_quests(game->quests, 9, 1, 2) == 0) {
        game->dialogues->quest = "#lewis_help";
        launch_quest(quest, game, 1);
        if (game->player->log >= 20)
            change_step(quest);
    } if (quest->step == 2) {
        game->dialogues->quest = "#lewis_end";
        launch_quest(quest, game, 2);
    }
}

void do_quests_clint(quests_ *quest, game_ *game)
{
    if (quest->step == 1 && check_step_quests(game->quests, 9, 1, 3) == 0) {
        game->dialogues->quest = "#clint_help";
        launch_quest(quest, game, 1);
        if (game->player->rock >= 20)
            change_step(quest);
    } if (quest->step == 2) {
        game->dialogues->quest = "#clint_end";
        launch_quest(quest, game, 2);
    }
}
