/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to check events sprites
*/

#include "../../includes/rpg.h"

void find_button_gen(game_ *game, int who, paint_ *paint)
{
    if (who == 1)
        paint->scale += 1;
    if (who == 2 && paint->scale > 1)
        paint->scale -= 1;
}

void check_gen(game_ *game, button_ *button, int who, paint_ *paint)
{
    if (game->mouse.x > button->position.x && game->mouse.x <
        button->position.x + button->rect.width * button->scale.x &&
        game->mouse.y > button->position.y && game->mouse.y <
        button->position.y + button->rect.height * button->scale.y) {
        button->rect.left = 372;
        if (game->event.type == sfEvtMouseButtonReleased) {
            sfSound_play(game->sounds->click);
            find_button_gen(game, who, paint);
        }
    } else
        button->rect.left = 350;
    sfSprite_setTextureRect(button->sprite, button->rect);
}

void interact_sprite(game_ *game, sprite_ *sprite, gen_control_ *gen_control)
{
    sfColor color = {255, 255, 255, 255};
    sfColor clear = {255, 255, 255, 150};

    if (game->mouse.x > sprite->position.x && game->mouse.x <
    sprite->position.x + sprite->rect.width * sprite->scale.x &&
    game->mouse.y > sprite->position.y && game->mouse.y < sprite->position.y +
    sprite->rect.height * sprite->scale.y) {
        sfSprite_setColor(sprite->sprite, color);
        if (game->event.type == sfEvtMouseButtonReleased &&
        gen_control->sprites_on == 0) {
            gen_control->selected_ = 1;
            gen_control->selected->id = sprite->id;
            sfSprite_setTextureRect(gen_control->selected->sprite,
            sprite->rect);
            gen_control->sprites_on = 1;
        }
    } else
        sfSprite_setColor(sprite->sprite, clear);
    if (sprite->next != NULL)
        interact_sprite(game, sprite->next, gen_control);
}

void check_event_gen(game_ *game, paint_ *paint)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEqual))
            paint->scale += 1;
        if (sfKeyboard_isKeyPressed(sfKeyHyphen) && paint->scale > 1)
            paint->scale -= 1;
        check_gen_control_disp(game);
        check_gen(game, game->gen_control->up, 1, paint);
        check_gen(game, game->gen_control->down, 2, paint);
        check_gen(game, game->gen_control_mob->up, 1, paint);
        check_gen(game, game->gen_control_mob->down, 2, paint);
    }
}

void draw_sprites_gen(game_ *game, gen_control_ *gen_control)
{
    if (gen_control->sprites_on == 0) {
        sfRenderWindow_clear(game->window, sfWhite);
        draw_env(game, gen_control->list);
    }
}
