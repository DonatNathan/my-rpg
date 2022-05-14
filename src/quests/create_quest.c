/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** detect_fight
*/

#include "../../includes/rpg.h"

quests_ *set_quest(game_ *game, char **array, int nb)
{
    quests_ *new = malloc(sizeof(quests_));

    new->next = NULL;
    new->id_mob = my_atoi(array[0 + 5 * nb]);
    new->name = array[1 + 5 * nb];
    new->description = array[2 + 5 * nb];
    set_step_state(game, new, nb);
    new->read = 1;
    new->loot = array[3 + 5 * nb];
    new->quest = create_text(my_strncat(array[1 + 5 * nb], array[2 + 5 * nb],
    0), (sfVector2f){1, 1}, (sfVector2f){game->quests->back->position.x + 60,
    game->quests->back->position.y + 60 + 60 * nb}, "font/Stardew_Valley.ttf");
    return (new);
}

char **read_quests(game_ *game, int fd, char *filepath)
{
    int len = get_file_len(filepath);
    char *file = malloc(sizeof(char) * len + 1);
    char **saves;

    read(fd, file, len);
    file[len] = '\0';
    saves = str_to_array(file, '\n');
    free(file);
    return (saves);
}

void get_last_quest(game_ *game, quests_ *quests, char **array, int nb)
{
    if (quests->next != NULL)
        get_last_quest(game, quests->next, array, nb);
    else
        quests->next = set_quest(game, array, nb);
}

void create_quests(game_ *game)
{
    create_dialogues(game);
    int fd = open("quest.txt", O_RDONLY);
    char **quests = read_quests(game, fd, "quest.txt");
    game->quests = malloc(sizeof(quests_));
    game->quests->description = quests[2];
    game->quests->name = quests[1];
    game->quests->id_mob = my_atoi(quests[0]);
    game->quests->array = quests;
    set_step_state(game, game->quests, 0);
    game->quests->loot = quests[3];
    game->quests->next = NULL;
    game->quests->read = 1;
    game->boole->on_quests = 1;
    game->quests->back = create_button((sfVector2f){1505, 300},
    (sfVector2f){3, 3}, "pictures/menu/book.png");
    game->quests->quest = create_text(my_strncat(quests[1], quests[2], 0),
    (sfVector2f){1, 1}, (sfVector2f){game->quests->back->position.x + 60,
    game->quests->back->position.y + 60}, "font/Stardew_Valley.ttf");
    for (int nb = 1; nb < 8; nb += 1)
        get_last_quest(game, game->quests, quests, nb);
}

void draw_quests(game_ *game, quests_ *quest)
{
    int cmpt;

    for (cmpt = 0; my_strcmp(game->quests->array[cmpt],
    my_strcat(new_put_nbr(quest->id_mob), "\n")) != 0 &&
    game->quests->array[cmpt]; cmpt += 1);
    cmpt += 5 * (quest->step - 1);
    sfText_setString(quest->quest->text,
    my_strcat(game->quests->array[cmpt + 1], game->quests->array[cmpt + 2]));
    if (quest->state == 1)
        sfRenderWindow_drawText(game->window, quest->quest->text, sfFalse);
    if (quest->next != NULL)
        draw_quests(game, quest->next);
}
