/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_rect
*/

#include "../include/rpg.h"
#include "../include/my.h"

void move_sprites(window_t *win, int offset)
{
    win->scene[GAME].sprite[0].rect.left = offset * (win->seconds % 2);
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}