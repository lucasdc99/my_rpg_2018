/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h for lib
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

enum page {
    MAINMENU
};

typedef struct s_scene {
    int nb_button;
    struct s_button *button;
} scene_t;

typedef struct s_window {
    sfRenderWindow *window;
    sfEvent event;
    scene_t *scene;
    enum page page;
    enum page actual_page;
    int vsync;
    int fps;
} window_t;

typedef struct s_button {
    sfRectangleShape *rect;
    void (*callback)(struct s_window *window);
    sfFont *font;
    sfText *text;
    sfColor hovered_color;
    sfColor clicked_color;
    sfColor idle_color;
} button_t;

typedef struct ptr_func
{
    enum page step;
    window_t *(*start)(window_t *);
    window_t *(*draw)(window_t *);
    void (*event)(window_t *);
    window_t *(*end)(window_t *);
} ptr_func;

window_t *create_window(window_t *win);

sfVector2f get_pos_float(float x, float y);
sfVector2i get_pos_int(int x, int y);

button_t *init_button(button_t *button, sfVector2f position, sfVector2f size);
button_t *init_button_text(button_t *button, char *text, sfVector2f pos);
window_t *init_menu(window_t *win);
void display(window_t *win);
window_t *draw_scene(window_t *win);
void global_event(window_t *win);
window_t *destroy_scene(window_t *win);
void main_menu(window_t *win);
ptr_func *init_func(void);
int button_is_clicked(button_t button, sfVector2i click_position);
int button_is_hovered(button_t button, sfVector2i mouse_position);

#endif