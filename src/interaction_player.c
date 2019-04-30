/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

void close_inventory(window_t *win)
{
    win->pause = 0;
    win->inventory = 0;
    if (win->actual_page == TOWN) {
        for (int i = 1; i < win->scene[TOWN].nb_sprite; i++)
            win->scene[TOWN].sprite[i].depth = 0;
    }
}

void open_quest(window_t *win)
{
    win->quest = 1;
    win->pause = 1;
    if (win->actual_page == TOWN) {
        for (int i = 1; i < win->scene[TOWN].nb_sprite; i++)
            win->scene[TOWN].sprite[i].depth = -1;
    }
    sfMusic_play(win->music->open_menus);
}

void close_quest(window_t *win)
{
    win->quest = 0;
    win->pause = 0;
    if (win->actual_page == TOWN) {
        for (int i = 1; i < win->scene[TOWN].nb_sprite; i++)
            win->scene[TOWN].sprite[i].depth = 0;
    }
}