/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_boss
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_buttons(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_next_buttons(&win->scene[BOSS].button[0], win->rect_buttons,
    order_button[0]);
    init_button(&win->scene[BOSS].button[0], get_pos_float(-200, -200),
    size, win->texture_button);
    set_next_buttons(&win->scene[BOSS].button[1], win->rect_buttons,
    order_button[1]);
    init_button(&win->scene[BOSS].button[1], get_pos_float(-200, -200),
    size, win->texture_button);
    win->scene[BOSS].button[0].callback = &quit_pause;
    win->scene[BOSS].button[1].callback = &main_menu;
}

window_t *init_boss(window_t *win)
{
    set_struct(win, 2, 0, 2);
    init_sprite(&win->scene[BOSS].sprite[0], "ressources/final_boss.png",
    get_pos_float(600, 0));
    init_sprite(&win->scene[BOSS].sprite[1],
    "ressources/pack/Pixel_Champions/Magical Heroes/Glenys-the-Demonswordsman.png",
    get_pos_float(920, 80));
    init_buttons(win);
    sfSprite_setScale(win->scene[BOSS].sprite[1].sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->scene[BOSS].sprite[1].sprite,
    get_rect(12, 9, 32, 32));
    win->scene[BOSS].sprite[0].depth = -1;
    return (win);
}