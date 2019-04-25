/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_boss
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_boss(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 1);
    init_sprite(&win->scene[BOSS].sprite[0], "ressources/final_boss.png", get_pos_float(600, 0));
    set_next_buttons(&win->scene[BOSS].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[BOSS].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[BOSS].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[BOSS].button[1], get_pos_float(-200, -200), size, win->texture_button);
    win->scene[BOSS].sprite[0].depth = -1;
    win->scene[BOSS].button[0].callback = &quit_pause;
    win->scene[BOSS].button[1].callback = &main_menu;
    return (win);
}