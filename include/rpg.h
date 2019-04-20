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
    BOOK,
    POTION,
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
    SON,
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
    FOREST,
};

typedef struct s_text {
    sfFont *font;
    sfText *str;
    sfVector2f pos_text;
} text_t;

typedef struct s_music {
    sfMusic *menu_song;
    sfMusic *button_sound;
    int vol_drag_posx;
    int drag_value;
    int vol_register;
    int volume;
} music_t;

typedef struct s_sprite {
    int depth;
    int item;
    int type;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} sprite_t;

typedef struct s_items {
    int sword;
    char *name;
    sfVector2f pos;
    int busy;
} items_t;

typedef struct s_player {
    sfVector2f last_pos;
    sprite_t *sprite;
    char *name;
    int health;
    int xp;
    int strength;
    sfVector2f speed;
    int direction;
    int move_rect;
    int last_page;
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
} quest_t;

typedef struct s_inventory {
    sfText *text;
    sprite_t *sprite;
    sfSprite *player;
    items_t *items;
} inventory_t;

typedef struct s_window {
    sfTexture *texture_button;
    sfRenderWindow *window;
    sfEvent event;
    scene_t *scene;
    player_t *player;
    music_t *music;
    enum page page;
    enum page actual_page;
    int vsync;
    int fps;
    sfClock *move;
    sfTime move_time;
    sfIntRect *rect_buttons;
    int seconds;
    int pause;
    int inventory;
    int quest;
    int no_saves;
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
int check_dead_zone(window_t *win, int move);

// CHANGE SCENE
void go_forest(window_t *win);
void go_castle(window_t *win);
void go_town(window_t *win);

// INITIALISATION SCENES
window_t *init_forest(window_t *win);
window_t *init_house1(window_t *win);
window_t *init_town(window_t *win);
window_t *init_menu(window_t *win);
window_t *init_choose_heroes(window_t *win);
window_t *init_options(window_t *win);
window_t *init_castle(window_t *win);
window_t *init_how_to_play(window_t *win);

// INITIALISATION ELEMENTS
void init_player(window_t *win);
void init_objects(sprite_t *sprite, inventory_t *inv);
void init_inventory(inventory_t *inv);
void init_text(text_t *text, char *display, sfVector2f pos);
void init_sprite(sprite_t *sprite, char *filename, sfVector2f position);
void init_button(button_t *, sfVector2f, sfVector2f, sfTexture *);
void init_quests(quest_t *quest);

// CSFML BASICS
window_t *create_window(window_t *win);
void display(window_t *win);
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
void unpause_game(window_t *win);

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
void display_text_in_textbox(quest_t *quest, char *text);

// DESTROY
void destroy_all(window_t *win);
window_t *destroy_scene(window_t *win);

// DRAW
window_t *draw_scene(window_t *win);

// BUTTONS HANDLING
int button_is_clicked(button_t button, sfVector2i click_position);
int button_is_hovered(button_t button, sfVector2i mouse_position);
sfIntRect *init_pos_button(void);

// HERO CHOOSE
void choose_glenys(window_t *win);
void choose_hex(window_t *win);
void choose_ley(window_t *win);
void choose_linail(window_t *win);
void choose_oratio(window_t *win);
void choose_ouzo(window_t *win);
void choose_prime(window_t *win);
void choose_wyvera(window_t *win);

// ANIMATIONS
void animation_mainmenu(window_t *win, int offset);
void animation_choose_heroes(window_t *win, int offset);
void animation_torch(window_t *win, int offset);

// SAVES
void save_inventory(window_t *win);

// PARSING
inventory_t *parser_inv(inventory_t *inv, char *filename);
player_t *parser(player_t *player, char *filename);

// INVENTORY HANDLING
sfVector2f get_inv_pos(inventory_t *inv);
int get_type_from_inv(char *name);
int is_item_outside_inv(sfVector2f move_pos, inventory_t *inv);

// DETECTION EVENTS
void close_textbox(window_t *win);
void check_item_pickup(window_t *win);
void close_door(window_t *win);
void open_door(window_t *win);

#endif