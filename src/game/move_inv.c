/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void change_window2(game_ *game)
{
    if (game->mouse.x > 890 && game->mouse.x < 935 && game->mouse.y > 210 &&
    game->mouse.y < 260 && sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_all(game);
        game->boole->on_craft = 0;
    } if (game->mouse.x > 935 && game->mouse.x < 985 && game->mouse.y > 210 &&
    game->mouse.y < 260 && sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_all(game);
        game->boole->on_potion = 0;
    } if (game->mouse.x > 985 && game->mouse.x < 1035 && game->mouse.y > 210 &&
    game->mouse.y < 260 && sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_all(game);
        game->boole->on_pad = 0;
    } if (game->mouse.x > 1035 && game->mouse.x < 1080 && game->mouse.y > 210
    && game->mouse.y < 260 && sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_all(game);
        game->boole->on_quit = 0;
    }
}

void change_window(game_ *game)
{
    if (game->mouse.x > 695 && game->mouse.x < 740 && game->mouse.y > 210 &&
    game->mouse.y < 260 && sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_all(game);
        game->boole->on_inv = 0;
    } if (game->mouse.x > 740 && game->mouse.x < 790 && game->mouse.y > 210 &&
    game->mouse.y < 260 && sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_all(game);
        game->boole->on_girl = 0;
    } if (game->mouse.x > 790 && game->mouse.x < 845 && game->mouse.y > 210 &&
    game->mouse.y < 260 && sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_all(game);
        game->boole->on_stats = 0;
    } if (game->mouse.x > 845 && game->mouse.x < 890 && game->mouse.y > 210 &&
    game->mouse.y < 260 && sfMouse_isButtonPressed(sfMouseLeft)) {
        clear_all(game);
        game->boole->on_map = 0;
    }
    change_window2(game);
}

void open_other_pages(game_ *game)
{
    if (game->boole->on_tree == 1 && game->mouse.x > 1310 && game->mouse.x <
    1350 && game->mouse.y > 280 &&
    game->mouse.y < 313 && sfMouse_isButtonPressed(sfMouseLeft)) {
        game->clock->check_secs = 0;
        game->boole->on_tree = 0;
    } if (game->boole->on_map == 1 && sfKeyboard_isKeyPressed(sfKeyM) &&
    game->clock->check_secs != 0) {
        clear_all(game);
        game->clock->check_secs = 0;
        game->boole->on_map = 0;
    }
}

void update_inventory2(game_ *game)
{
    if (game->boole->on_stats == 0)
        sfRenderWindow_drawSprite
        (game->window, game->inv->back_stats->sprite, sfFalse);
    if (game->boole->on_craft == 0)
        sfRenderWindow_drawSprite
        (game->window, game->inv->back_craft->sprite, sfFalse);
    if (game->boole->on_potion == 0)
        sfRenderWindow_drawSprite
        (game->window, game->inv->back_potion->sprite, sfFalse);
    if (game->boole->on_pad == 0)
        sfRenderWindow_drawSprite
        (game->window, game->inv->back_pad->sprite, sfFalse);
}

void update_inventory(game_ *game)
{
    if (game->boole->on_dialogue == 0)
        draw_dialogues(game);
    game->clock->check_secs = game->clock->time.microseconds / 5000;
    if (game->boole->on_inv == 0)
        sfRenderWindow_drawSprite
        (game->window, game->inv->back->sprite, sfFalse);
    if (game->boole->on_quit == 0)
        sfRenderWindow_drawSprite
        (game->window, game->inv->back_quit->sprite, sfFalse);
    if (game->boole->on_map == 0)
        sfRenderWindow_drawSprite
        (game->window, game->inv->back_map->sprite, sfFalse);
    if (game->boole->on_girl == 0)
        sfRenderWindow_drawSprite
        (game->window, game->inv->back_girl->sprite, sfFalse);
    update_inventory2(game);
    if (game->boole->on_inv == 0)
        draw_items(game, game->first_item, game->player->movement, 0);
}
