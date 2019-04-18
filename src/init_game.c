/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_game
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_game(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 5);
    set_next_buttons(&win->scene[CASTLE].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[CASTLE].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[CASTLE].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[CASTLE].button[1], get_pos_float(-200, -200), size, win->texture_button);
    init_sprite(&win->scene[CASTLE].sprite[0], "ressources/castle.png", get_pos_float(0, 0));
    init_sprite(&win->scene[CASTLE].sprite[1], "ressources/tree.png", get_pos_float(304, 560));
    init_sprite(&win->scene[CASTLE].sprite[2], "ressources/tree.png", get_pos_float(80, 458));
    init_sprite(&win->scene[CASTLE].sprite[3], "ressources/tree.png", get_pos_float(1350, 508));
    init_sprite(&win->scene[CASTLE].sprite[4], "ressources/tree2.png", get_pos_float(1520, 500));
    for (int i = 1; i < 5; i++)
        win->scene[CASTLE].sprite[i].depth = 1;
    win->scene[CASTLE].button[0].callback = &quit_pause;
    win->scene[CASTLE].button[1].callback = &main_menu;
    return (win);
}