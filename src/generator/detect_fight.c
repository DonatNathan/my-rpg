/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** detect_fight
*/

#include "../../includes/rpg.h"

int detect_item(game_ *game, int x, int y, sfVector2f pos_)
{
    if (my_atoi(game->layer_->id_mob[y][x]) == 100) {
        game->player->log += 1;
        destroy_mob(pos_.y / 40, pos_.x / 40, game->first);
        game->layer_->id_mob[y][x][0] = '0';
        return (1);
    }
    if (my_atoi(game->layer_->id_mob[y][x]) == 200) {
        game->player->rock += 1;
        destroy_mob(pos_.y / 40, pos_.x / 40, game->first);
        game->layer_->id_mob[y][x][0] = '0';
        return (1);
    }
    return (0);
}

int check_human(game_ *game, sfVector2f pos_, int x, int y)
{
    if (detect_item(game, x, y, pos_) == 1)
        return (1);
    if (my_atoi(game->layer_->id_mob[y][x]) < 8) {
        destroy_mob(pos_.y / 40, pos_.x / 40, game->first);
        game->boole->on_fight = 0;
        game->fight->enemy =
        init_fight_mob(game, my_atoi(game->layer_->id_mob[y][x]));
        game->fight->enemy->pv =
        init_fight_pv(game, my_atoi(game->layer_->id_mob[y][x]));
        update_fight(game);
        game->layer_->id_mob[y][x][0] = '0';
    } else if (sfKeyboard_isKeyPressed(sfKeyE) &&
    game->boole->on_dialogue == 1 && my_atoi(game->layer_->id_mob[y][x]) < 100)
        active_quest(game, my_atoi(game->layer_->id_mob[y][x]), game->quests);
    return (0);
}

void detect_fight_(game_ *game, int y)
{
    int x = 0;
    sfVector2f pos_;
    sfVector2f pos_rep;
    for (x = 0; game->layer_->id_mob[y][x]; x++) {
        pos_rep = sfSprite_getPosition(game->player->rep);
        pos_ = (sfVector2f){x * 40 + pos_rep.x, y * 40 + pos_rep.y};
        if (pos_.y > 560 - 70 && pos_.y < 560 + 50 && pos_.x > 970 - 80
        && pos_.x < 970 + 40 && my_atoi(game->layer_->id_mob[y][x]) != 0
        && game->boole->on_fight == 1)
            check_human(game, pos_, x, y);
    }
}

int detect_fight(game_ *game)
{
    int y = 0;

    for (y = 0; game->layer_->id_mob[y]; y++) {
        detect_fight_(game, y);
    }
    if (game->player->stats->life < 1)
        death_loop(game);
    return (0);
}
