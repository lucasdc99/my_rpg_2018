/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h for lib
*/

#ifndef RPG_H_
#define RPG_H_
#define VALUE_FIRST 674

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum type {
    ARMOR,
    SWORD,
};

enum type_button {
    JOUER,
    PARAM,
    QUITTER,
    REPRENDRE,
    RETOUR,
    NOUVEAU,
    SAUVEGARDER,
    FLECHE_REVERSE,
    CURSEUR,
    PAUSE,
    TUTORIEL,
    FLECHE,
};

enum page {
    MAINMENU,
    HEROES,
    HOW_TO_PLAY,
    OPTIONS,
    CASTLE,
    TOWN,
    HOUSE1,
    HOUSE2,
    HOUSE3,
    FOREST,
    FINAL,
    BOSS,
    COMBAT,
    END,
};

typedef struct s_pos {
    char **tab_castle;
    char **tab_town;
    char **tab_house1;
    char **tab_house2;
    char **tab_house3;
    char **tab_forest;
    char **tab_final;
    char **tab_boss;
} pos_t;

typedef struct s_text {
    sfText *str;
    sfVector2f pos_text;
} text_t;

typedef struct s_music {
    sfMusic *menu_song;
    sfMusic *button_sound;
    sfMusic *town_song;
    sfMusic *boss_song;
    sfMusic *door_close;
    sfMusic *door_open;
    sfMusic *stone_door;
    sfMusic *boss_battle;
    sfMusic *boss_final;
    sfMusic *special_attack;
    sfMusic *heal;
    sfMusic *enemy_attack;
    sfMusic *basic_attack;
    sfMusic *open_menus;
    int vol_pos;
    int drag_value;
    int vol_register;
    int volume;
} music_t;

typedef struct s_sprite {
    int depth;
    int item;
    int type;
    int equiped;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} sprite_t;

typedef struct s_items {
    char *name;
    sfVector2f pos;
    int busy;
} items_t;

typedef struct s_enemy {
    int health;
    int actual_health;
    int strength;
    sprite_t *sprite;
    text_t *text;
} enemy_t;

typedef struct s_player {
    sfVector2f last_pos;
    sprite_t *sprite;
    char *name;
    int health;
    int actual_health;
    int xp;
    int strength;
    sfVector2f speed;
    int direction;
    int move_rect;
    int last_page;
    int hero;
} player_t;

typedef struct s_scene {
    sprite_t *sprite;
    text_t *text;
    struct s_button *button;
    int nb_text;
    int nb_sprite;
    int nb_button;
} scene_t;

typedef struct s_quest {
    sprite_t *sprite;
    text_t *text;
    int quete_done;
    int combat;
} quest_t;

typedef struct s_inventory {
    text_t *text;
    sprite_t *sprite;
    sfSprite *player;
    items_t *items;
} inventory_t;

typedef struct s_window {
    sfTexture *texture_button;
    sfRenderWindow *window;
    sfEvent event;
    sfFont *font_berlin;
    sfFont *font_title;
    scene_t *scene;
    player_t *player;
    enemy_t *enemy;
    music_t *music;
    pos_t *positions;
    enum page page;
    enum page actual_page;
    int vsync;
    int fps;
    int error;
    sfClock *move;
    sfClock *combat_clock;
    sfTime move_time;
    sfTime combat_time;
    sfIntRect *rect_buttons;
    int seconds;
    int pause;
    int inventory;
    int talking;
    int quest;
    int no_saves;
    int turn;
    sprite_t *objects;
    int nb_objects;
    inventory_t *inv;
    quest_t *quests;
    text_t *text;
} window_t;

typedef struct s_button {
    sfRectangleShape *shape;
    void (*callback)(struct s_window *window);
    sfIntRect rect_idle;
    sfIntRect rect_hovered;
    sfIntRect rect_pressed;
} button_t;

typedef struct ptr_func
{
    enum page step;
    window_t *(*start)(window_t *);
    window_t *(*draw)(window_t *);
    void (*event)(window_t *);
    window_t *(*end)(window_t *);
} ptr_func;

// PLAYER MOVES
void move_player_right(window_t *win);
void move_player_up(window_t *win);
void move_player_left(window_t *win);
void move_player_down(window_t *win);
void move_player(window_t *win);
void check_combat_zone(window_t *win);
int check_dead_zone(window_t *win, int move);

// CHANGE SCENE
void go_forest(window_t *win);
void go_castle(window_t *win);
void go_town(window_t *win);
void close_door(window_t *win);
void open_door(window_t *win);
void go_boss(window_t *win);
void leave_final(window_t *win);
void start_combat(window_t *, sfVector2f);
void go_final(window_t *win);

// INITIALISATION SCENES
window_t *init_forest(window_t *win);
window_t *init_town(window_t *win);
window_t *init_menu(window_t *win);
window_t *init_choose_heroes(window_t *win);
window_t *init_options(window_t *win);
window_t *init_castle(window_t *win);
window_t *init_how_to_play(window_t *win);
window_t *init_final(window_t *win);
window_t *init_combat(window_t *win);
window_t *init_boss(window_t *win);
window_t *init_house_1(window_t *win);
window_t *init_house_2(window_t *win);
window_t *init_house_3(window_t *win);
window_t *init_end(window_t *win);

// INITIALISATION ELEMENTS
void init_player(player_t *player);
void init_objects(sprite_t *sprite, inventory_t *inv);
void init_inventory(inventory_t *inv, sfFont *font);
void init_text(text_t *text, char *display, sfVector2f pos, sfFont *font);
void init_sprite(sprite_t *sprite, char *filename, sfVector2f position);
void init_button(button_t *, sfVector2f, sfVector2f, sfTexture *);
void init_quests(quest_t *quest, sfFont *font);
void init_music(music_t *music);
void init_enemy(window_t *win);

// CSFML BASICS
window_t *create_window(window_t *win);
int display(window_t *win);
void global_event(window_t *win);
ptr_func *init_func(void);

// CALLBACK
void change_music(window_t *win);
void change_fps(window_t *win);
void change_vsync(window_t *win);
void quit_pause(window_t *win);
void main_menu(window_t *win);
void heroes_menu(window_t *win);
void how_to_play(window_t *win);
void play_game(window_t *win);
void options(window_t *win);
void quit(window_t *win);
void choose_hero(window_t *win);
void choose_hero_reverse(window_t *win);
void unpause_game(window_t *win);
void basic_attack(window_t *win);
void special_attack(window_t *win);
void stats_attack(window_t *win);
void check_enemy_turn(window_t *win);
void enemy_attack(window_t *win);
void get_texture_pause(window_t *win);

// USEFUL
sfVector2f get_pos_float(float x, float y);
sfVector2i get_pos_int(int x, int y);
char *get_buffer(char *filename);
sfIntRect get_rect(int left, int top, int width, int height);
void set_next_buttons(button_t *button, sfIntRect *rect, int type);
void set_struct(window_t *win, int button, int text, int sprite);
char **transform_2d(char *tmp, char sep);
char *get_next_line(int fd);
int is_inside_zone(sfVector2f limit1, sfVector2f limit2, sfVector2f pos);
void display_text_in_textbox(quest_t *quest);
void drag_button(window_t *win);
void my_wait(window_t *win, int seconds);
char *open_buff(char *filename);
void str_to_unicode(char *str, sfUint32 *unistr[]);

// DESTROY
void destroy_all(window_t *win);
window_t *destroy_scene(window_t *win);

// DRAW
window_t *draw_scene(window_t *win);
void draw_sprites(window_t *win);

// BUTTONS HANDLING
int button_is_clicked(button_t button, sfVector2i click_position);
int button_is_hovered(button_t button, sfVector2i mouse_position);
sfIntRect *init_pos_button(void);

// HERO CHOOSE
void choose_hex(window_t *win);
void choose_linail(window_t *win);
void choose_ouzo(window_t *win);
void choose_prime(window_t *win);
void choose_wyvera(window_t *win);
void set_description_text(window_t *win, char *buffer);

// ANIMATIONS
void animation_mainmenu(window_t *win);
void animation_choose_heroes(window_t *win);
void animation_torch(window_t *win, int offset);
void animation_begin(window_t *win);
void animate_player_walk(window_t *win);
void animation_end(window_t *win);

// SAVES
void save_inventory(window_t *win);
void save_config_player(window_t *win);
void save_quests(window_t *win);

// PARSING
inventory_t *parser_inv(inventory_t *inv, char *filename);
player_t *parser_player(player_t *player, char *filename);
quest_t *parser_quests(quest_t *quest, char *filename);

// INVENTORY HANDLING
sfVector2f get_inv_pos(inventory_t *inv);
int get_type_from_inv(char *name);
int is_item_outside_inv(sfVector2f move_pos, inventory_t *inv);
int check_existing_inventory(window_t *win, char *name);
int get_actual_pos_inv(inventory_t *inv, sfVector2f move_pos);
char *get_name_from_type(int type);
void open_inventory(window_t *win);
void check_desequip_stuff(window_t *win, int actual_pos);
void check_equip_stuff(window_t *win, int actual_pos);

// PLAYER HANDLING
int set_player(window_t *win);
void reset_player(window_t *win);

// DETECTION EVENTS
void check_item_pickup(window_t *win);
void pick_armor(window_t *win);
void pick_sword(window_t *win);
void check_keyboard_input_ingame(window_t *win);
void global_event_condition(window_t *win);

// CHECK ITEM INVENTORY
int is_item_outside_inv(sfVector2f move_pos, inventory_t *inv);
void check_pickup_sword(window_t *win, sfVector2f pos_player);
void check_pickup_armor(window_t *win, sfVector2f pos_player);
void check_item_pickup(window_t *win);

// CHECK INVENTORY
sfVector2f get_nearest_item_pos(inventory_t *inv, sfVector2f move_pos);
void check_drag_and_drop_inv(window_t *win);
void drag_and_drop_inv(window_t *win);
int get_actual_pos_inv(inventory_t *inv, sfVector2f move_pos);
char *get_name_from_type(int type);
void set_text_basic(window_t *win);

// INTERACTION PLAYER
void close_inventory(window_t *win);
void open_quest(window_t *win);
void close_quest(window_t *win);

// INTERACTION GAME
void pause_game(window_t *win);

// TALK PNJ
void talk_to_old(window_t *win, sfVector2f pos_player);

// MOUSE EVENTS
void mouse_pressed_event(window_t *win);
void mouse_released_event(window_t *win);
void mouse_moved_event(window_t *win);

// SET TXT
void set_text_inv(window_t *win);
void draw_description(window_t *win, int i);

// OPTIONS
void set_vsync(window_t *win);

#endif