/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_forest
*/

#include "../include/rpg.h"
#include "../include/my.h"

void initialisation_sprite_forest(window_t *win)
{
    init_sprite(&win->scene[FOREST].sprite[0], "ressources/forest.png", get_pos_float(0, 0));
    init_sprite(&win->scene[FOREST].sprite[1], "ressources/sprite_contraste/tree.png", get_pos_float(30, 245));
    init_sprite(&win->scene[FOREST].sprite[2], "ressources/sprite_contraste/tree.png", get_pos_float(55, 10));
    init_sprite(&win->scene[FOREST].sprite[3], "ressources/sprite_contraste/tree.png", get_pos_float(125, 95));
    init_sprite(&win->scene[FOREST].sprite[4], "ressources/sprite_contraste/tree.png", get_pos_float(545, 3));
    init_sprite(&win->scene[FOREST].sprite[5], "ressources/tree2.png", get_pos_float(335, 210));
    init_sprite(&win->scene[FOREST].sprite[6], "ressources/tree2.png", get_pos_float(632, 342));
    init_sprite(&win->scene[FOREST].sprite[7], "ressources/sprite_contraste/tree.png", get_pos_float(505, 595));
    init_sprite(&win->scene[FOREST].sprite[8], "ressources/sprite_contraste/tree.png", get_pos_float(220, 465));
    init_sprite(&win->scene[FOREST].sprite[9], "ressources/sprite_contraste/tree.png", get_pos_float(265, 640));
    init_sprite(&win->scene[FOREST].sprite[10], "ressources/tree2.png", get_pos_float(25, 775));
    init_sprite(&win->scene[FOREST].sprite[11], "ressources/sprite_contraste/tree.png", get_pos_float(485, 810));
    init_sprite(&win->scene[FOREST].sprite[12], "ressources/sprite_contraste/tombe.png", get_pos_float(1112, 615));
}

void depth_sprite_forest(window_t *win)
{
    win->scene[FOREST].sprite[0].depth = -1;
    win->scene[FOREST].sprite[1].depth = 1;
    win->scene[FOREST].sprite[2].depth = 1;
    win->scene[FOREST].sprite[3].depth = 1;
    win->scene[FOREST].sprite[4].depth = 1;
    win->scene[FOREST].sprite[5].depth = 1;
    win->scene[FOREST].sprite[6].depth = 1;
    win->scene[FOREST].sprite[7].depth = 1;
    win->scene[FOREST].sprite[8].depth = 1;
    win->scene[FOREST].sprite[9].depth = 1;
    win->scene[FOREST].sprite[10].depth = 1;
    win->scene[FOREST].sprite[11].depth = 1;
    win->scene[FOREST].sprite[12].depth = 1;
}

window_t *init_forest(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 13);
    set_next_buttons(&win->scene[FOREST].button[0], win->rect_buttons,
    order_button[0]);
    init_button(&win->scene[FOREST].button[0], get_pos_float(-200, -200),
    size, win->texture_button);
    set_next_buttons(&win->scene[FOREST].button[1], win->rect_buttons,
    order_button[1]);
    init_button(&win->scene[FOREST].button[1], get_pos_float(-200, -200),
    size, win->texture_button);
    initialisation_sprite_forest(win);
    depth_sprite_forest(win);
    win->scene[FOREST].button[0].callback = &quit_pause;
    win->scene[FOREST].button[1].callback = &main_menu;
    return (win);
}