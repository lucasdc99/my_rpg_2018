/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_house1
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_house1(window_t *win)
{
    int order_button[] = {REPRENDRE, QUITTER};
    sfVector2f size = get_pos_float(400, 100);

    set_struct(win, 2, 0, 2);
    //init_sprite(&win->scene[HOUSE1].sprite[0], "ressources/town.png", get_pos_float(0, 0));
    init_sprite(&win->scene[HOUSE1].sprite[0], "ressources/inv.png", get_pos_float(-600, -600));
    init_sprite(&win->scene[HOUSE1].sprite[1], "TimeFantasy_TILES_6.24.17/TILESETS/animated/doors.png", get_pos_float(646, 645));
    set_next_buttons(&win->scene[HOUSE1].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[HOUSE1].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[HOUSE1].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[HOUSE1].button[1], get_pos_float(-200, -200), size, win->texture_button);
    sfSprite_setTextureRect(win->scene[HOUSE1].sprite[1].sprite, get_rect(32, 0, 16, 27));
    sfSprite_setScale(win->scene[HOUSE1].sprite[1].sprite, get_pos_float(3, 3));
    win->scene[HOUSE1].button[0].callback = &quit_pause;
    win->scene[HOUSE1].button[1].callback = &main_menu;
    return (win);
}