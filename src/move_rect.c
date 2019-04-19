/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_rect
*/

#include "../include/rpg.h"
#include "../include/my.h"

void animation_torch(window_t *win, int offset)
{
    win->scene[CASTLE].sprite[5].rect.top = offset * (win->seconds % 4);
    win->scene[CASTLE].sprite[6].rect.top = offset * (win->seconds % 4);
    sfSprite_setTextureRect(win->scene[CASTLE].sprite[5].sprite, win->scene[CASTLE].sprite[5].rect);
    sfSprite_setTextureRect(win->scene[CASTLE].sprite[6].sprite, win->scene[CASTLE].sprite[6].rect);
}

void animation_choose_heroes(window_t *win, int offset)
{
    win->scene[HEROES].sprite[0].rect.left = offset * (win->seconds % 2);
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
}

void animation_mainmenu(window_t *win, int offset)
{
    win->scene[MAINMENU].sprite[0].rect.left = offset * (win->seconds % 7);
    sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite, win->scene[MAINMENU].sprite[0].rect);
}