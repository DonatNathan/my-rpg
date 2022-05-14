/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#include "my.h"
#include "map_grid.h"
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "menu.h"
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PROJECT_H_
    #define PROJECT_H_

typedef struct grid_cell {
    int x;
    int y;
    int pos_x;
    int pos_y;
    int size_x;
    int size_y;
    int size;
    int l_pos;
    int g_pos;
    int ground;
    int click;
    int foreground_id;
    int background_id;
    int hitbox_id;
    int mob_id;
    int is_sprite;
    sfRectangleShape *rect;
    struct grid_cell *next_cell;
    struct grid_cell *prev_cell;
    struct sprite *foreground;
    struct sprite *background;
    struct sprite *hitbox;
    struct sprite *mob;
} grid_cell_;

typedef struct paint {
    int scale;
} paint_;

typedef struct animal {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *r_texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    int secs;
    int moved;
    int version;
} animal_;

typedef struct load {
    sfSprite *load;
    sfTexture *t_load;
    sfVector2f pos_load;
    sfIntRect rect;
    int is_load;
} load_;

typedef struct text {
    sfText *text;
    sfVector2f position;
    sfVector2f scale;
    sfFont *font;
    const char *string;
} text_;

typedef struct button {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    text_ *text;
    int save;
} button_;

typedef struct settings {
    button_ *back;
    button_ *button;
    int in_settings;
    text_ *all;
    text_ *max;
    text_ *mid;
    text_ *min;
    text_ *big;
    text_ *little;
    button_ *bar_music;
    button_ *bar_sounds;
    button_ *music;
    button_ *sounds;
} settings_;

typedef struct saves {
    button_ *first;
    button_ *second;
    button_ *third;
} saves_;

typedef struct menu {
    settings_ *settings;
    button_ *back;
    button_ *secret;
    load_ *load1;
    load_ *load2;
    load_ *load3;
    button_ *exit;
    button_ *new;
    button_ *load;
    button_ *logo;
    button_ *params;
    button_ *sounds;
    button_ *help;
    animal_ *parrot;
    animal_ *coin;
    int on_parrot;
    int on_load;
    saves_ *saves;
    text_ *score;
} menu_;

typedef struct sprite {
    int ok;
    int page;
    int id;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    struct sprite *next;
    struct sprite *first;
} sprite_;

typedef struct gen_control {
    button_ *up;
    button_ *down;
    button_ *zoom_up;
    button_ *zoom_down;
    sprite_ *list;
    sprite_ *selected;
    int sprites_on;
    int selected_;
} gen_control_;

typedef struct cursor {
    sfSprite *sprite;
    sfTexture *basic;
    sfTexture *clicked;
    sfVector2f position;
} cursor_;

typedef struct load_map {
    char *back_full;
    char *fore_full;
    char *hit_full;
    char *mob_full;
    int y_size;
    int x_size;
} load_map_;

typedef struct stats {
    int life;
    int attack;
    float speed;
} stats_;

typedef struct layer {
    char ***map;
    char ***map_2;
    char ***map_3;
    char ***map_4;
    sfSprite ***map_layer_1;
    sfSprite ***map_layer_2;
    sfSprite ***map_layer_3;
    sfSprite ***map_layer_4;
    char ***id_background;
    char ***id_foreground;
    char ***id_hitbox;
    char ***id_mob;
} layer_;

typedef struct player {
    int log;
    int rock;
    text_ *nb_log;
    text_ *nb_rock;
    text_ *nb_kills;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    sfSprite *rep;
    int secs;
    int movement;
    int gold;
    int life;
    int m_up;
    int m_down;
    int m_left;
    int m_right;
    layer_ *layer;
    stats_ *stats;
    char *pseudo;
    int y_start;
    int x_start;
    sfVector2f pos_r;
    int kills;
} player_;

typedef struct sounds {
    sfMusic *ocean;
    sfMusic *summer_day;
    sfSound *click;
    sfSound *coin;
    sfSound *parrot;
    sfSound *item;
    sfSound *trash;
} sounds_;

typedef struct bonus {
    int all;
    int life;
    int attack;
    int gold;
    int speed;
} bonus_;

typedef struct chained_skill {
    struct chained_skill *first;
    struct chained_skill *prev;
    sfSprite *skill;
    sfVector2f pos_skill;
    sfVector2f pos_skill2;
    int type;
    int value;
    int active;
    struct chained_skill *next;
    int price;
    sfText *infos;
    sfText *cost;
    sfVector2f pos_infos;
    sfVector2f scale;
    sfVector2f pos_cost;
} chained_skill_;

typedef struct skill_tree {
    sfSprite *back;
    sfTexture *t_back;
    sfTexture *tree;
    chained_skill_ *first_skill;
    int x;
    int y;
} skill_tree_;

typedef struct item {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    int type;
    int stats;
    int on_inv;
    struct item *next;
    struct item *prev;
    int line;
    int col;
    int is_get;
} item_;

typedef struct life {
    button_ *hearth;
    struct life *next;
} life_;

typedef struct slots {
    button_ *slot;
    struct slots *next;
} slots_;

typedef struct inventory {
    int page;
    char ***inv;
    button_ *back;
    button_ *back_quit;
    button_ *back_map;
    button_ *back_girl;
    button_ *back_stats;
    button_ *back_potion;
    button_ *back_craft;
    button_ *back_pad;
    int on_item;
    button_ *bar;
    button_ *select;
    text_ *gold;
    skill_tree_ *tree;
    life_ *life;
    int x_hearth;
    slots_ *slots;
    button_ *quit;
    text_ *text_quit;
    text_ *text_settings;
    button_ *settings;
} inventory_;

typedef struct clock {
    sfClock *clock;
    sfTime time;
    int secs;
    int ancien_sec;
    int hours;
    int days;
    int saison;
    int check_secs;
    button_ *infos;
    sfSprite *light;
    button_ *arrow;
    text_ *day;
    text_ *hour;
    sfColor color;
    int x;
    int y;
} clock_;

typedef struct boole {
    int on_button;
    int on_inv;
    int on_quit;
    int on_map;
    int on_girl;
    int on_stats;
    int on_craft;
    int on_potion;
    int on_pad;
    int on_tree;
    int on_best;
    int on_hint;
    int on_fight;
    int on_attack;
    int is_friend;
    int is_quit;
    int is_dead;
    int on_dialogue;
    int on_quests;
    int on_htp;
    int new_quests;
    int draw_particles;
} boole_;

typedef struct enemy {
    sfSprite *sprite;
    int pv;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    sfIntRect rect;
    sfClock *clock;
    int temp_id;
    int id;
    int y;
    int x;
    int start;
    int max;
    sfTime time;
    int secs;
    struct enemy *next;
} enemy_;

typedef struct fight {
    enemy_ *enemy;
    int mob_id;
    button_ *back;
    button_ *leave;
    button_ *attack;
    button_ *heal;
    text_ *t_leave;
    text_ *t_heal;
    text_ *t_attack;
} fight_;

typedef struct bestiary {
    enemy_ *enemy_1;
    enemy_ *enemy_2;
    button_ *back;
    int on_best;
    int page;
    text_ *page_l;
    text_ *page_r;
    button_ *arrow_l;
    button_ *arrow_r;
    text_ *name_l;
    text_ *name_r;
    text_ *pv_l;
    text_ *pv_r;
    text_ *dmg_l;
    text_ *dmg_r;
    char **mob_stats;
} bestiary_;

typedef struct death {
    button_ *quit;
    text_ *t_quit;
    button_ *respwan;
    text_ *t_respawn;
    button_ *back;
} death_;

typedef struct how_to_play {
    sfSprite *htp;
    sfTexture *htp_1;
    sfTexture *htp_2;
    sfTexture *htp_3;
    sfTexture *htp_4;
    sfTexture *htp_5;
    sfTexture *htp_6;
    sfTexture *htp_7;
    sfVector2f scale;
    sfVector2f position;
    int page;
} how_to_play_t;

typedef struct quests {
    int id_mob;
    int state;
    char *name;
    char *description;
    int step;
    int read;
    struct quests *next;
    char *loot;
    text_ *quest;
    button_ *back;
    char **array;
} quests_;

typedef struct dialogues {
    button_ *box;
    text_ *text;
    button_ *speaker;
    button_ *name;
    char **data_base;
    int pnj;
    char *quest;
    int line;
} dialogues_;

typedef struct framebuffer {
    int width;
    int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct particles {
    sfSprite *sprite;
    sfTexture *texture;
    framebuffer_t *framebuffer;
    sfVector2u position;
    sfColor color;
    int size;
} particles_t;

typedef struct game {
    particles_t *particles;
    how_to_play_t *hwtp;
    quests_ *quests;
    int number;
    dialogues_ *dialogues;
    load_map_ *load_map;
    death_ *death;
    char *map;
    int y_start;
    int x_start;
    sfSprite *rep;
    gen_control_ *gen_control;
    gen_control_ *gen_control_mob;
    sfRenderWindow *window;
    sfEvent event;
    cursor_ *cursor;
    player_ *player;
    menu_ *menu;
    sounds_ *sounds;
    inventory_ *inv;
    bestiary_ *best;
    fight_ *fight;
    clock_ *clock;
    item_ *first_item;
    sfVector2i mouse;
    int layer;
    int speed;
    grid_cell_ *wall_1;
    grid_cell_ *wall_2;
    layer_ *layer_;
    sfSprite ***background;
    sfSprite ***foreground;
    sfSprite ***hitbox;
    bonus_ *bonus;
    boole_ *boole;
    int hint;
    text_ *who;
    enemy_ *first;
    char *pseudo;
    int map_number;
    button_ *loading;
    int type;
    char **saves;
} game_;

void check_event_game(game_ *game);
int check_glob_gestion(int argc, char **argv);
sfIntRect change_rect(sfIntRect rect, float x, float y);
void launch_game(game_ *game, int spawn_point, int map_number, int type);
void create_player(game_ *game, char *pseudo);
void update_player(game_ *game, player_ *player);
void create_inventory(game_ *game);
void update_inventory(game_ *game);
void draw_items(game_ *game, item_ *item, int movement, int status);
void add_items(game_ *game, item_ *item, int top);
void add_item_to_inv(game_ *game, char ***inv, item_ *item);
void check_on_item(game_ *game, item_ *item, player_ *player);
void update_inv(game_ *game);
void check_event_items(game_ *game);
void move_item_to_bar(item_ *item, game_ *game);
void move_select(game_ *game);
void open_close_inv(game_ *game);
void cancel_item(item_ *item, game_ *game);
void drop_item(item_ *item, game_ *game);
void delete_item(item_ *item, game_ *game);
void update_bar(game_ *game);
void create_ath(game_ *game);
void update_time(game_ *game);
void is_in_loop_tree(game_ *game);
chained_skill_ *get_last_skill(game_ *game, int cmpt, int level);
chained_skill_ *check_prev(game_ *game, int cmpt);
void draw_skill_tree(game_ *game, chained_skill_ *skill);
void create_tree(game_ *game);
void set_string_skills(game_ *game, chained_skill_ *skill);
chained_skill_ *create_skill(game_ *game, int cmpt, int level);
void enable_bonus(game_ *game, chained_skill_ *skill);
void create_bonus(game_ *game);
void draw_hearth(game_ *game, life_ *hearth, int nb);
void create_life(game_ *game);
void add_hearth(life_ *hearth, int x, game_ *game);
void change_window(game_ *game);
void open_other_pages(game_ *game);
void clear_all(game_ *game);
void update_enemy(enemy_ *enemy, game_ *game);
void get_last_e(enemy_ *enemy, sfVector2f position,
sfIntRect rect, int max);
void create_bestiary(game_ *game);
void update_bestiary(game_ *game);
void open_close_best(game_ *game);
int move_page_best_left(game_ *game);
int move_page_best_right(game_ *game);
int get_file_len(char *files_name);
void init_bestiary(game_ *game);
void open_close_fight(game_ *game);
void create_fight(game_ *game);
void update_fight(game_ *game);
enemy_ *create_enemy(sfVector2f position, sfIntRect rect, int max, int id);
void draw_slots(game_ *game, slots_ *slot);
void create_slots(game_ *game);
void set_boole(game_ *game);
enemy_ *init_fight_mob(game_ *game, int k);
void move_enemy(enemy_ *enemy, int movement, game_ *game);
void update_enemy_f(enemy_ *enemy, game_ *game);
void init_game_boole(game_ *game);
void get_mob(char *files_name, game_ *game);
void set_game(game_ *game, int type);
int save_game(game_ *game, int type);
void save_skills(game_ *game, int fd);
void save_clock(game_ *game, int fd);
int destroy_mob(int y, int x, enemy_ *enemy);
int detect_fight(game_ *game);
void tp_all(game_ *game);
void go_mid(game_ *game);
void go_top(game_ *game);
void go_bottom(game_ *game);
void go_left(game_ *game);
void go_right(game_ *game);
void init_mob_best_2_1(int k, sfVector2f pos, game_ *game);
void init_mob_best_1_1(int k, sfVector2f pos, game_ *game);
void update_enemy_best(enemy_ *enemy, game_ *game);
void tp_top(game_ *game);
void check_pos(int k, game_ *game, int map_number);
void tp_pos(game_ *game, int type, int death);
void create_all(game_ *game);
void check_event_pause(game_ *game);
void update_clock(clock_ *clock);
void update_loading(game_ *game);
void draw_menu(game_ *game, menu_ *menu);
void draw_parrot_ingame(game_ *game);
void check_parrot_move(menu_ *menu);
void choose_save(game_ *game, int type);
void set_save(game_ *game, char **saves);
void set_new_game(game_ *game);
void spawn_parrot(game_ *game);
void init_map_nbr(game_ *game, int map_number, int k);
void create_dialogues(game_ *game);
void dialogues_event(game_ *game);
void draw_dialogues(game_ *game);
char *insert_return2(char *line);
char *insert_return(char *line);
void update_dialogue(game_ *game);
void create_quests(game_ *game);
void draw_quests(game_ *game, quests_ *quest);
void check_event_quests(game_ *game);
void active_quest(game_ *game, int id, quests_ *quest);
void update_quests(game_ *game);
void do_quests_abigail(quests_ *quest, game_ *game);
void do_quests_alex(quests_ *quest, game_ *game);
void do_quests_levis(quests_ *quest, game_ *game);
void do_quests_clint(quests_ *quest, game_ *game);
void update_materials(game_ *game);
void launch_quest(quests_ *quest, game_ *game, int action);
void change_step(quests_ *quest);
int check_state_quests(quests_ *quest, int id, int is_done);
int check_step_quests(quests_ *quest, int id, int is_done, int step);
int init_fight_pv(game_ *game, int k);
void update_button_fight(game_ *game);
void update_button_leave(game_ *game);
void update_button_heal(game_ *game);
void create_htp(game_ *game);
void creatre_textures_htp(game_ *game);
int update_htp(game_ *game);
void change_page(game_ *game);
void save_materials(game_ *game, int fd);
void save_quests(game_ *game, int fd);
void set_step_state(game_ *game, quests_ *new, int nb);
void my_draw_square(game_ *game, sfVector2u position, sfColor color);
void create_particles(game_ *game);
void check_events_particles(game_ *game);
void draw_particles(game_ *game);
void draw_little(game_ *game, sfVector2u position, sfColor color, int action);

#endif /* PROJECT_H_ */
