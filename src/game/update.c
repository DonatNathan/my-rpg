/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void update_inv(game_ *game)
{
    update_inventory(game);
    if (game->boole->on_quit == 0) {
        sfRenderWindow_drawSprite(game->window, game->inv->settings->sprite,
        sfFalse);
        sfRenderWindow_drawSprite(game->window, game->inv->quit->sprite,
        sfFalse);
        sfRenderWindow_drawText(game->window, game->inv->text_settings->text,
        sfFalse);
        sfRenderWindow_drawText(game->window, game->inv->text_quit->text,
        sfFalse);
    } if (game->boole->on_tree == 0)
        is_in_loop_tree(game);
    if (game->boole->on_potion == 0)
        update_materials(game);
    check_event_pause(game);
    update_time(game);
    draw_hearth(game, game->inv->life, game->player->stats->life);
    update_bestiary(game);
    update_fight(game);
    update_quests(game);
}

void update_bar(game_ *game)
{
    if (game->boole->on_inv == 1) {
        sfRenderWindow_drawSprite
        (game->window, game->inv->bar->sprite, sfFalse);
        draw_items(game, game->first_item, game->player->movement, 1);
        sfRenderWindow_drawSprite(game->window, game->inv->select->sprite,
        sfFalse);
    }
}

void clear_all(game_ *game)
{
    game->boole->on_inv = 1;
    game->boole->on_quit = 1;
    game->boole->on_map = 1;
    game->boole->on_pad = 1;
    game->boole->on_potion = 1;
    game->boole->on_craft = 1;
    game->boole->on_stats = 1;
    game->boole->on_girl = 1;
}

void check_cross(game_ *game)
{
    if ((game->boole->on_inv == 0 || game->boole->on_quit == 0 ||
    game->boole->on_map == 0 || game->boole->on_girl == 0 ||
    game->boole->on_stats == 0 || game->boole->on_craft == 0 ||
    game->boole->on_potion == 0 || game->boole->on_pad == 0) &&
    game->clock->check_secs != 0 &&
    (sfKeyboard_isKeyPressed(sfKeyI) || sfKeyboard_isKeyPressed(sfKeyEscape) ||
    (game->mouse.x > 1285 && game->mouse.x < 1318 && game->mouse.y > 200 &&
    game->mouse.y < 233 && sfMouse_isButtonPressed(sfMouseLeft))) &&
    game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        clear_all(game);
        move_item_to_bar(game->first_item, game);
    }
}

void open_close_inv(game_ *game)
{
    if (game->boole->on_inv == 1 && sfKeyboard_isKeyPressed(sfKeyI) &&
    game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_best = 1;
        game->boole->on_inv = 0;
        move_item_to_bar(game->first_item, game);
    }
    check_cross(game);
    open_other_pages(game);
    if (game->boole->on_tree == 1 && game->mouse.x > 1310 && game->mouse.x <
    1350 && game->mouse.y > 280 &&
    game->mouse.y < 313 && sfMouse_isButtonPressed(sfMouseLeft)) {
        game->clock->check_secs = 0;
        game->boole->on_tree = 0;
    }
}
