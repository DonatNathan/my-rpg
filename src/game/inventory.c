/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

int set_pos_item(game_ *game, char ***inv, item_ *item, int line)
{
    for (int col = 0; col != 12; col += 1) {
        if (!inv[line][col]) {
            inv[line][col] = (char *)item;
            item->position.x = game->inv->back->position.x
            + 38 + (48 * col);
            item->position.y = game->inv->back->position.y
            + 103 + (55 * line);
            item->line = line;
            item->col = col;
            move_item_to_bar(game->first_item, game);
            return (0);
        }
    }
    return (1);
}

void add_item_to_inv(game_ *game, char ***inv, item_ *item)
{
    int line = 0;

    item->on_inv = 0;
    for (; line != 3; line += 1) {
        if (set_pos_item(game, inv, item, line) == 0)
            return;
    }
}

char ***malloc_inv(void)
{
    char ***temp = malloc(sizeof(char *) * (4));
    int line = 0;
    int col = 0;

    for (; line != 3; line += 1) {
        temp[line] = malloc(sizeof(char *) * 13);
        for (col = 0; col != 12; col += 1) {
            temp[line][col] = NULL;
        }
        temp[line][col] = '\0';
    }
    temp[line] = '\0';
    return (temp);
}

void create_backs(game_ *game)
{
    game->inv->back = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/inv.png");
    game->inv->back_quit = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/quit.png");
    game->inv->back_map = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/map.png");
    game->inv->back_girl = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/girl.png");
    game->inv->back_stats = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/stats.png");
    game->inv->back_potion = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/potion.png");
    game->inv->back_craft = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/crafts.png");
    game->inv->back_pad = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/pad.png");
    game->inv->bar = create_button((sfVector2f){660, 938}, (sfVector2f){1, 1},
    "pictures/menu/bar.png");
}

void create_inventory(game_ *game)
{
    game->inv = malloc(sizeof(inventory_));
    game->inv->slots = malloc(sizeof(slots_));
    game->inv->page = 0;
    create_backs(game);
    create_slots(game);
    game->clock = malloc(sizeof(clock_));
    game->clock->clock = sfClock_create();
    game->inv->inv = malloc_inv();
    game->boole->on_inv = 1;
    game->inv->on_item = 1;
    game->inv->select = create_button((sfVector2f){690, 968},
    (sfVector2f){1, 1}, "pictures/menu/select.png");
    game->inv->text_quit = create_text("MENU", (sfVector2f){3, 3},
    (sfVector2f){880, 520}, "font/Stardew_Valley.ttf");
    game->inv->text_settings = create_text("SETTINGS", (sfVector2f){3, 3},
    (sfVector2f){805, 310}, "font/Stardew_Valley.ttf");
    game->inv->settings = create_button((sfVector2f){780, 300},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->inv->quit = create_button((sfVector2f){780, 510},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
}
