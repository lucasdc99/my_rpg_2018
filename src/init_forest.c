/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_forest
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int initialisation_sprite_forest_two(window_t *win)
{
    char *path = {"ressources/images/"};
    int pos_x[] = {0, 30, 55, 125, 545, 335, 632, 505, 220, 265, 25,
        485, 1112, 1625, 1180, 1575, 1635};
    int pos_y[] = {0, 245, 10, 95, 3, 210, 342, 595, 465, 640, 775,
        810, 610, 45, 40, 255, 700};
    char *name[] = {"forest.png", "tree.png", "tree.png", "tree.png",
        "tree.png", "tree2.png", "tree2.png", "tree.png", "tree.png",
        "tree.png", "tree2.png", "tree.png", "tombe.png", "tree.png",
        "tree2.png", "tree2.png", "tree.png"};

    for (int i = 0; i < 17; i++) {
        if (init_sprite(&win->scene[FOREST].sprite[i], my_strcat(path, name[i]),
        get_pos_float(pos_x[i], pos_y[i])) == 84)
            return (84);
    }
    return (0);
}

static void depth_sprite_forest(window_t *win)
{
    win->scene[FOREST].sprite[0].depth = -1;
    for (int i = 1; i < win->scene[FOREST].nb_sprite; i++)
        win->scene[FOREST].sprite[i].depth = 1;
    win->scene[FOREST].button[0].callback = &quit_pause;
    win->scene[FOREST].button[1].callback = &main_menu;
}

window_t *init_forest(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    if (set_struct(win, 2, 0, 17) == 84)
        return (NULL);
    set_next_buttons(&win->scene[FOREST].button[0], win->rect_buttons,
    order_button[0]);
    if (init_button(&win->scene[FOREST].button[0], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (NULL);
    set_next_buttons(&win->scene[FOREST].button[1], win->rect_buttons,
    order_button[1]);
    if (init_button(&win->scene[FOREST].button[1], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (NULL);
    if (initialisation_sprite_forest_two(win) == 84)
        return (NULL);
    depth_sprite_forest(win);
    return (win);
}