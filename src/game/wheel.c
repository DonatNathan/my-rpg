/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events inventory bar
*/

#include "../../includes/rpg.h"

void check_wheel(game_ *game)
{
    if (game->event.mouseWheelScroll.delta < 0) {
        game->inv->select->position.x += 48;
        if (game->inv->select->position.x >= 690 + 576)
            game->inv->select->position.x = 690;
    }
    if (game->event.mouseWheelScroll.delta > 0) {
        game->inv->select->position.x -= 48;
        if (game->inv->select->position.x < 690)
            game->inv->select->position.x = 690 + 528;
    }
}

void check_num2(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum7))
        game->inv->select->position.x = 978;
    if (sfKeyboard_isKeyPressed(sfKeyNum8))
        game->inv->select->position.x = 1026;
    if (sfKeyboard_isKeyPressed(sfKeyNum9))
        game->inv->select->position.x = 1074;
    if (sfKeyboard_isKeyPressed(sfKeyNum0))
        game->inv->select->position.x = 1122;
    if (sfKeyboard_isKeyPressed(sfKeyRBracket))
        game->inv->select->position.x = 1170;
    if (sfKeyboard_isKeyPressed(sfKeyEqual))
        game->inv->select->position.x = 1218;
}

void check_num1(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
        game->inv->select->position.x = 690;
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        game->inv->select->position.x = 738;
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
        game->inv->select->position.x = 786;
    if (sfKeyboard_isKeyPressed(sfKeyNum4))
        game->inv->select->position.x = 834;
    if (sfKeyboard_isKeyPressed(sfKeyNum5))
        game->inv->select->position.x = 882;
    if (sfKeyboard_isKeyPressed(sfKeyNum6))
        game->inv->select->position.x = 930;
    check_num2(game);
}

void move_select(game_ *game)
{
    check_num1(game);
    if (game->event.type == sfEvtMouseWheelScrolled)
        check_wheel(game);
    sfSprite_setPosition(game->inv->select->sprite,
    game->inv->select->position);
}
