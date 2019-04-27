/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_final
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_final(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 3);
    init_sprite(&win->scene[FINAL].sprite[0], "ressources/sbire_map.png", get_pos_float(600, 0));
    init_sprite(&win->scene[FINAL].sprite[1], "ressources/pack/Pixel_Champions/Magical Heroes/Ley-the-Monster-Whisperer.png", get_pos_float(600, 0));
    init_sprite(&win->scene[FINAL].sprite[2], "ressources/pack/Pixel_Champions/Magical Heroes/Oratio-the-Mercenary.png", get_pos_float(600, 0));
    set_next_buttons(&win->scene[FINAL].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[FINAL].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[FINAL].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[FINAL].button[1], get_pos_float(-200, -200), size, win->texture_button);
    sfSprite_setScale(win->scene[FINAL].sprite[1].sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->scene[FINAL].sprite[1].sprite, get_rect(60, 105, 32, 32));
    sfSprite_setPosition(win->scene[FINAL].sprite[1].sprite, get_pos_float(810, 680));
    sfSprite_setScale(win->scene[FINAL].sprite[2].sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->scene[FINAL].sprite[2].sprite, get_rect(60, 56, 32, 32));
    sfSprite_setPosition(win->scene[FINAL].sprite[2].sprite, get_pos_float(1030, 280));
    win->scene[FINAL].sprite[0].depth = -1;
    win->scene[FINAL].sprite[1].depth = 0;
    win->scene[FINAL].sprite[2].depth = 0;
    win->scene[FINAL].button[0].callback = &quit_pause;
    win->scene[FINAL].button[1].callback = &main_menu;
    return (win);
}