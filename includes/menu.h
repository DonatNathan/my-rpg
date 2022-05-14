/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics.h>

#ifndef MENU_H_
    #define MENU_H_

    #include "rpg.h"
    #include "map_grid.h"

void malloc_menu(menu_ *menu);
void launch_menu(sfVideoMode mode, sfVector2u size, char *pseudo);
void create_new(menu_ *menu);
void create_exit(menu_ *menu);
void create_load(menu_ *menu);
void create_parrot(menu_ *menu);
void update_animal(animal_ *animal, int x, int y, game_ *game);
void check_button(game_ *game, button_ *button, int who, menu_ *menu);
void create_secret(menu_ *menu);
void check_parrot(game_ *game, menu_ *menu, sfVector2i mouse);
void create_help(menu_ *menu);
void check_square(game_ *game, button_ *button, int who, menu_ *menu);
void create_up(gen_control_ *gen_control);
void create_down(gen_control_ *gen_control);
void create_sprites(sprite_ *sprite, int i);
void create_zoom_down(gen_control_ *gen_control);
void create_zoom_up(gen_control_ *gen_control);
void create_selected(gen_control_ *gen_control);
void create_first_sprite(gen_control_ *gen_control, int i);
void draw_env(game_ *game, sprite_ *sprite);
void interact_sprite(game_ *game, sprite_ *sprite, gen_control_ *gen_control);
void draw_sprites_gen(game_ *game, gen_control_ *gen_control);
void create_gen(gen_control_ *gen_control, int i);
void create_cursor(game_ *game);
void update_cursor(game_ *game);
void check_event_cursor(game_ *game);
void create_settings(game_ *game, menu_ *menu);
void launch_settings(game_ *game, menu_ *menu);
void check_settings(game_ *game, menu_ *menu, int what);
void create_texts(menu_ *menu);
char *my_strcat(char *dest, char const *src);
void loop_menu(game_ *game, menu_ *menu);
void check_event_buttons(game_ *game, menu_ *menu);
void draw_settings(game_ *game, menu_ *menu);
void create_audios(game_ *game);
button_ *create_button(sfVector2f pos, sfVector2f scale,
char *filepath);
void create_saves(menu_ *menu);
void check_saves(game_ *game, button_ *button, int who, menu_ *menu);
void find_button(game_ *game, int who, menu_ *menu);
void check_help(game_ *game, menu_ *menu, int what);
void change_volume(game_ *game, menu_ *menu, button_ *button, int action);
void check_action(game_ *game, button_ *button, menu_ *menu, int action);
void choose_sound(game_ *game, button_ *button, menu_ *menu);
void choose_music(game_ *game, button_ *button, menu_ *menu);
void create_coin(menu_ *menu);
void update_coin(animal_ *coin, game_ *game);
void check_on_coin(game_ *game, animal_ *coin, animal_ *parrot);
text_ *create_text(const char *string, sfVector2f scale,
sfVector2f pos, char *font);
int quit_game(game_ *game);
void create_death_menu(game_ *game);
void death_loop(game_ *game);
int check_respawn(game_ *game);

#endif /* MENU_H_ */
