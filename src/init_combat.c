/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_combat
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_combat(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER, FLECHE};
    char *skin = malloc(sizeof(char) * 80);

    set_struct(win, 5, 0, 1);
    win->combat = sfClock_create();
    skin = my_strcat("ressources/pack/Pixel_Champions/Magical Heroes/", win->player->name);
    skin = my_strcat(skin, ".png");
    init_sprite(&win->scene[COMBAT1].sprite[0], skin, get_pos_float(1500, 500));
    set_next_buttons(&win->scene[COMBAT1].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[COMBAT1].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[COMBAT1].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[COMBAT1].button[1], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[COMBAT1].button[2], win->rect_buttons, order_button[2]);
    init_button(&win->scene[COMBAT1].button[2], get_pos_float(1600, 200), get_pos_float(100, 100), win->texture_button);
    set_next_buttons(&win->scene[COMBAT1].button[3], win->rect_buttons, order_button[2]);
    init_button(&win->scene[COMBAT1].button[3], get_pos_float(1600, 300), get_pos_float(100, 100), win->texture_button);
    set_next_buttons(&win->scene[COMBAT1].button[4], win->rect_buttons, order_button[2]);
    init_button(&win->scene[COMBAT1].button[4], get_pos_float(1600, 400), get_pos_float(100, 100), win->texture_button);
    sfSprite_setTextureRect(win->scene[COMBAT1].sprite[0].sprite, get_rect(297, 56, 30, 30));
    sfSprite_setScale(win->scene[COMBAT1].sprite[0].sprite, get_pos_float(4, 4));
    win->scene[COMBAT1].button[0].callback = &quit_pause;
    win->scene[COMBAT1].button[1].callback = &main_menu;
    win->scene[COMBAT1].button[2].callback = &basic_attack;
    win->scene[COMBAT1].button[3].callback = &special_attack;
    win->scene[COMBAT1].button[4].callback = &stats_attack;
    return (win);
}