/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#include "../../includes/rpg.h"

void save_skills(game_ *game, int fd)
{
    write(fd, "#SKILLS\n", 8);
    write(fd, my_strncat(new_put_nbr(game->bonus->all), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->all)) + 1);
    write(fd, my_strncat(new_put_nbr(game->bonus->attack), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->attack)) + 1);
    write(fd, my_strncat(new_put_nbr(game->bonus->gold), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->gold)) + 1);
    write(fd, my_strncat(new_put_nbr(game->bonus->life), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->life)) + 1);
    write(fd, my_strncat(new_put_nbr(game->bonus->speed), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->speed)) + 1);
}

void save_clock(game_ *game, int fd)
{
    write(fd, "#CLOCK\n", 7);
    write(fd, my_strncat(new_put_nbr(game->clock->hours), "\n", 0),
    my_strlen(new_put_nbr(game->clock->hours)) + 1);
    write(fd, my_strncat(new_put_nbr(game->clock->days), "\n", 0),
    my_strlen(new_put_nbr(game->clock->days)) + 1);
    write(fd, my_strncat(new_put_nbr(game->clock->saison), "\n", 0),
    my_strlen(new_put_nbr(game->clock->saison)) + 1);
}

void save_materials(game_ *game, int fd)
{
    write(fd, "#MATERIALS\n", 11);
    write(fd, my_strncat(new_put_nbr(game->player->kills), "\n", 0),
    my_strlen(new_put_nbr(game->player->kills)) + 1);
    write(fd, my_strncat(new_put_nbr(game->player->log), "\n", 0),
    my_strlen(new_put_nbr(game->player->log)) + 1);
    write(fd, my_strncat(new_put_nbr(game->player->rock), "\n", 0),
    my_strlen(new_put_nbr(game->player->rock)) + 1);
}

void save_quests(game_ *game, int fd)
{
    write(fd, "#QUESTS\n", 8);
    write(fd, my_strncat(new_put_nbr(game->quests->state), "\n", 0),
    my_strlen(new_put_nbr(game->quests->state)) + 1);
    write(fd, my_strncat(new_put_nbr(game->quests->next->state), "\n", 0),
    my_strlen(new_put_nbr(game->quests->next->state)) + 1);
    write(fd, my_strncat(new_put_nbr(game->quests->next->next->state), "\n",
    0), my_strlen(new_put_nbr(game->quests->next->next->state)) + 1);
    write(fd, my_strncat(new_put_nbr(game->quests->next->next->next->state),
    "\n", 0), my_strlen(new_put_nbr(game->quests->next->next->next->state)) +
    1);
    write(fd, my_strncat(new_put_nbr(game->quests->step), "\n", 0),
    my_strlen(new_put_nbr(game->quests->step)) + 1);
    write(fd, my_strncat(new_put_nbr(game->quests->next->step), "\n", 0),
    my_strlen(new_put_nbr(game->quests->next->step)) + 1);
    write(fd, my_strncat(new_put_nbr(game->quests->next->next->step), "\n", 0),
    my_strlen(new_put_nbr(game->quests->next->next->step)) + 1);
    write(fd, my_strncat(new_put_nbr(game->quests->next->next->next->step),
    "\n", 0), my_strlen(new_put_nbr(game->quests->next->next->next->step)) +
    1);
}
