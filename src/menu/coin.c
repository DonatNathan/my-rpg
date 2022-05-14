/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to update my menu
*/

#include "../../includes/rpg.h"

text_ *create_text(const char *string, sfVector2f scale, sfVector2f pos,
char *font)
{
    text_ *text = malloc(sizeof(text_));
    text->text = sfText_create();
    text->font = sfFont_createFromFile(font);
    text->scale = scale;
    text->position = pos;
    text->string = malloc(sizeof(char) * my_strlen(string));
    text->string = string;
    sfText_setFont(text->text, text->font);
    sfText_setScale(text->text, text->scale);
    sfText_setPosition(text->text, text->position);
    sfText_setString(text->text, text->string);
    sfText_setColor(text->text, sfBlack);
    return (text);
}

void check_on_coin(game_ *game, animal_ *coin, animal_ *parrot)
{
    if (coin->position.x >= parrot->position.x - 72 && coin->position.y >=
    parrot->position.y - 72 && coin->position.x <= parrot->position.x + 72 &&
    coin->position.y <= parrot->position.y + 72) {
        sfSound_play(game->sounds->coin);
        coin->position.x = rand() % 1870;
        coin->position.y = rand() % 1000;
        sfSprite_setPosition(coin->sprite, coin->position);
        coin->version += 1;
        game->menu->score->string = new_put_nbr(coin->version);
        sfText_setString(game->menu->score->text, game->menu->score->string);
    }
}

void update_coin(animal_ *coin, game_ *game)
{
    coin->time = sfClock_getElapsedTime(coin->clock);
    coin->secs = coin->time.microseconds / 5000;
    if (coin->secs > 30) {
        if (coin->rect.left < 250)
            coin->rect.left += 50;
        else
            coin->rect.left = 0;
        sfSprite_setTextureRect(coin->sprite, coin->rect);
        sfClock_restart(coin->clock);
    }
    sfRenderWindow_drawSprite(game->window, coin->sprite, sfFalse);
    sfRenderWindow_drawText(game->window, game->menu->score->text, sfFalse);
}
