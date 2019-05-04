/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** animate_mainmenu
*/

#include "../include/rpg.h"
#include "../include/my.h"

void animation_mainmenu(window_t *win)
{
    int left = 0;

    if (win->actual_page == MAINMENU) {
        win->move_time = sfClock_getElapsedTime(win->move);
        win->states->seconds = win->move_time.microseconds / 130000.0;
        left = 1920 * (win->states->seconds % 7);
        win->scene[MAINMENU].sprite[0].rect.left = left;
        sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite,
        win->scene[MAINMENU].sprite[0].rect);
    }
}