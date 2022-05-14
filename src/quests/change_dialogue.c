/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create dialogues
*/

#include "../../includes/rpg.h"

void update_dialogue(game_ *game)
{
    if (game->dialogues->line == 0) {
        for (; my_strcmp(game->dialogues->data_base[game->dialogues->line],
        game->dialogues->quest) != 0 && game->dialogues->data_base
        [game->dialogues->line] != NULL; game->dialogues->line += 1);
    }
    sfText_setString(game->dialogues->text->text,
    insert_return(game->dialogues->data_base[game->dialogues->line + 1]));
    game->dialogues->name->rect.top = 1567 + 461 * game->dialogues->pnj;
    game->dialogues->speaker->rect.top = 1515 + 461 * game->dialogues->pnj;
    sfSprite_setTextureRect(game->dialogues->name->sprite,
    game->dialogues->name->rect);
    sfSprite_setTextureRect(game->dialogues->speaker->sprite,
    game->dialogues->speaker->rect);
}

char *insert_return2(char *line)
{
    for (int cmpt = 0; line[cmpt] != '\0'; cmpt += 1) {
        if (line[cmpt] == '=')
            line[cmpt] = '\n';
    }
    return (line);
}

int get_back(int cmpt, int add, char *line)
{
    int back;

    for (back = cmpt - add; line[back] != ' '; back -= 1);
    return (back);
}

char *find_return(char *line, char *new_line)
{
    int add = 0;
    int cmpt;
    int back;
    int pos = 0;

    for (cmpt = 0; line[cmpt - add] != '\0'; cmpt += 1, pos += 1) {
        if (pos == 27) {
            pos = 0;
            back = get_back(cmpt, add, line);
            new_line[back] = '\n';
            add += 1;
        } else
            new_line[cmpt - add] = line[cmpt - add];
    }
    new_line[cmpt - add] = '\0';
    return (new_line);
}

char *insert_return(char *line)
{
    int len = my_strlen(line);
    char *new_line = malloc(sizeof(char) * (len + 1));

    if (len >= 27) {
        new_line = find_return(line, new_line);
        return (new_line);
    } else
        return (line);
}
