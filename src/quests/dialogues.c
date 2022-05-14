/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create dialogues
*/

#include "../../includes/rpg.h"

void get_dialogues(game_ *game)
{
    int fd = open("dialogue.txt", O_RDONLY);
    int len = get_file_len("dialogue.txt");
    char *file = malloc(sizeof(char) * len + 1);

    if (fd == -1) {
        write(2, "invalid file\n", 13);
    }
    read(fd, file, len);
    file[len] = '\0';
    game->dialogues->data_base = my_split_tab(file, '\n');
    free(file);
}

void draw_dialogues(game_ *game)
{
    update_dialogue(game);
    sfRenderWindow_drawSprite(game->window, game->dialogues->box->sprite,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->dialogues->text->text,
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->dialogues->name->sprite,
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->dialogues->speaker->sprite,
    sfFalse);
}

void set_button_dialogues(game_ *game)
{
    game->dialogues->box = create_button((sfVector2f){330, 605},
    (sfVector2f){1.5, 1.5}, "pictures/menu/dialogues.png");
    game->dialogues->name = create_button((sfVector2f){1120, 910},
    (sfVector2f){4, 4}, "pictures/env/all_mob.png");
    game->dialogues->name->rect = change_rect
    (game->dialogues->name->rect, 105, 25);
    sfSprite_setTextureRect(game->dialogues->name->sprite,
    game->dialogues->name->rect);
    game->dialogues->name->rect.left = 345;
    game->dialogues->speaker = create_button((sfVector2f){1180, 640},
    (sfVector2f){4, 4}, "pictures/env/all_mob.png");
    game->dialogues->speaker->rect = change_rect
    (game->dialogues->speaker->rect, 75, 75);
    game->dialogues->speaker->rect.left = 527;
    sfSprite_setTextureRect(game->dialogues->speaker->sprite,
    game->dialogues->speaker->rect);
    game->dialogues->text = create_text(game->dialogues->data_base[1],
    (sfVector2f){2, 2}, (sfVector2f){400, 630}, "font/Stardew_Valley.ttf");
}

void create_dialogues(game_ *game)
{
    game->dialogues = malloc(sizeof(dialogues_));
    game->dialogues->line = 0;
    get_dialogues(game);
    set_button_dialogues(game);
    game->boole->on_dialogue = 0;
    if (game->x_start == -250 && game->y_start == -445) {
        game->dialogues->quest = "#first_dialogue";
    } else {
        game->dialogues->quest = "#afk";
    }
    game->dialogues->name->rect.left = 1000;
    game->dialogues->speaker->rect.left = 1000;
}

void dialogues_event(game_ *game)
{
    if (game->mouse.x > 1035 && game->mouse.x < 1065 && game->mouse.y > 975 &&
    game->mouse.y < 1010 && game->event.type == sfEvtMouseButtonReleased) {
        if (game->dialogues->data_base[game->dialogues->line + 2][0] == '#') {
            game->boole->on_dialogue = 1;
            game->dialogues->line = 0;
        } else
            game->dialogues->line += 1;
    }
}
