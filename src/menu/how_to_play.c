/*
** EPITECH PROJECT, 2022
** MY_DEFENDER
** File description:
** It's the file that contain functions to create our game
*/

#include "../../includes/rpg.h"

void creatre_textures_htp(game_ *game)
{
    game->hwtp->htp_1 = sfTexture_createFromFile
    ("pictures/htp/menu_rpg.png", NULL);
    game->hwtp->htp_2 = sfTexture_createFromFile
    ("pictures/htp/save_rpg.png", NULL);
    game->hwtp->htp_3 = sfTexture_createFromFile
    ("pictures/htp/setting_rpg.png", NULL);
    game->hwtp->htp_4 = sfTexture_createFromFile
    ("pictures/htp/mouvement_rpg.png", NULL);
    game->hwtp->htp_5 = sfTexture_createFromFile
    ("pictures/htp/pnj_rpg.png", NULL);
    game->hwtp->htp_6 = sfTexture_createFromFile
    ("pictures/htp/pause_rpg.png", NULL);
    game->hwtp->htp_7 = sfTexture_createFromFile
    ("pictures/htp/tree_rpg.png", NULL);
}

int update_htp(game_ *game)
{
    if (game->hwtp->page == 1)
        sfSprite_setTexture(game->hwtp->htp, game->hwtp->htp_1, sfFalse);
    if (game->hwtp->page == 2)
        sfSprite_setTexture(game->hwtp->htp, game->hwtp->htp_2, sfFalse);
    if (game->hwtp->page == 3)
        sfSprite_setTexture(game->hwtp->htp, game->hwtp->htp_3, sfFalse);
    if (game->hwtp->page == 4)
        sfSprite_setTexture(game->hwtp->htp, game->hwtp->htp_4, sfFalse);
    if (game->hwtp->page == 5)
        sfSprite_setTexture(game->hwtp->htp, game->hwtp->htp_5, sfFalse);
    if (game->hwtp->page == 6)
        sfSprite_setTexture(game->hwtp->htp, game->hwtp->htp_6, sfFalse);
    (game->hwtp->page == 7) ? sfSprite_setTexture(game->hwtp
    ->htp, game->hwtp->htp_7, sfFalse), 2 : 1;
    if (game->boole->on_htp == 1)
        sfRenderWindow_drawSprite(game->window, game->hwtp->htp, sfFalse);
    return (0);
}

void create_htp(game_ *game)
{
    game->hwtp = malloc(sizeof(how_to_play_t));
    game->hwtp->page = 1;
    game->hwtp->htp = sfSprite_create();
    creatre_textures_htp(game);
    game->hwtp->position.x = 300;
    game->hwtp->position.y = 150;
    game->hwtp->scale.x = 0.7;
    game->hwtp->scale.y = 0.7;
    sfSprite_setScale(game->hwtp->htp, game->hwtp->scale);
    sfSprite_setPosition(game->hwtp->htp, game->hwtp->position);
}

void change_page(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && game->boole->on_htp == 1) {
        sfSound_play(game->sounds->click);
        if (game->hwtp->page > 1)
            game->hwtp->page -= 1;
        else
            game->hwtp->page = 7;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && game->boole->on_htp == 1) {
        sfSound_play(game->sounds->click);
        if (game->hwtp->page < 7)
            game->hwtp->page += 1;
        else
            game->hwtp->page = 1;
    }
}
