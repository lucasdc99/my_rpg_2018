/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_house
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_house(window_t *win)
{
    int order_button[] = {REPRENDRE, QUITTER};
    sfVector2f size = get_pos_float(400, 100);

    set_struct(win, 2, 0, 5);
    init_sprite(&win->scene[TOWN].sprite[0], "ressources/town.png", get_pos_float(0, 0));
    init_sprite(&win->scene[TOWN].sprite[1], "ressources/inv.png", get_pos_float(-600, -600));
    init_sprite(&win->scene[TOWN].sprite[2], "TimeFantasy_TILES_6.24.17/TILESETS/animated/doors.png", get_pos_float(646, 645));
    init_sprite(&win->scene[TOWN].sprite[3], "TimeFantasy_TILES_6.24.17/TILESETS/animated/doors.png", get_pos_float(207, 645));
    init_sprite(&win->scene[TOWN].sprite[4], "TimeFantasy_TILES_6.24.17/TILESETS/animated/doors.png", get_pos_float(1380, 645));
    set_next_buttons(&win->scene[TOWN].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[TOWN].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[TOWN].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[TOWN].button[1], get_pos_float(-200, -200), size, win->texture_button);
    sfSprite_setTextureRect(win->scene[TOWN].sprite[2].sprite, get_rect(32, 0, 16, 27));
    sfSprite_setTextureRect(win->scene[TOWN].sprite[3].sprite, get_rect(32, 0, 16, 27));
    sfSprite_setTextureRect(win->scene[TOWN].sprite[4].sprite, get_rect(32, 0, 16, 27));
    sfSprite_setScale(win->scene[TOWN].sprite[2].sprite, get_pos_float(3, 3));
    sfSprite_setScale(win->scene[TOWN].sprite[3].sprite, get_pos_float(3, 3));
    sfSprite_setScale(win->scene[TOWN].sprite[4].sprite, get_pos_float(3, 3));
    win->scene[TOWN].button[0].callback = &quit_pause;
    win->scene[TOWN].button[1].callback = &main_menu;
    return (win);
}