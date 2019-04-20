/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_castle
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_castle(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 7);
    set_next_buttons(&win->scene[CASTLE].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[CASTLE].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[CASTLE].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[CASTLE].button[1], get_pos_float(-200, -200), size, win->texture_button);
    init_sprite(&win->scene[CASTLE].sprite[0], "ressources/castle.png", get_pos_float(0, 0));
    init_sprite(&win->scene[CASTLE].sprite[1], "ressources/tree.png", get_pos_float(307, 560));
    init_sprite(&win->scene[CASTLE].sprite[2], "ressources/tree.png", get_pos_float(81, 461));
    init_sprite(&win->scene[CASTLE].sprite[3], "ressources/tree.png", get_pos_float(1350, 508));
    init_sprite(&win->scene[CASTLE].sprite[4], "ressources/tree2.png", get_pos_float(1520, 500));
    init_sprite(&win->scene[CASTLE].sprite[5], "TimeFantasy_TILES_6.24.17/TILESETS/animated/torch.png", get_pos_float(421, 263));
    init_sprite(&win->scene[CASTLE].sprite[6], "TimeFantasy_TILES_6.24.17/TILESETS/animated/torch.png", get_pos_float(1473, 263));
    win->scene[CASTLE].sprite[5].rect = get_rect(19, 0, 11, 20);
    win->scene[CASTLE].sprite[6].rect = get_rect(19, 0, 11, 20);
    sfSprite_setTextureRect(win->scene[CASTLE].sprite[5].sprite, win->scene[CASTLE].sprite[5].rect);
    sfSprite_setTextureRect(win->scene[CASTLE].sprite[6].sprite, win->scene[CASTLE].sprite[6].rect);
    sfSprite_setScale(win->scene[CASTLE].sprite[5].sprite, get_pos_float(2, 2));
    sfSprite_setScale(win->scene[CASTLE].sprite[6].sprite, get_pos_float(2, 2));
    for (int i = 1; i < 7; i++)
        win->scene[CASTLE].sprite[i].depth = 1;
    win->scene[CASTLE].sprite[0].depth = -1;
    win->scene[CASTLE].button[0].callback = &quit_pause;
    win->scene[CASTLE].button[1].callback = &main_menu;
    return (win);
}