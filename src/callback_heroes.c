/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_heroes
*/

#include "../include/rpg.h"
#include "../include/my.h"

void choose_hero(window_t *win)
{
    win->player->hero++;
    if (win->player->hero >= 5)
        win->player->hero = 0;
    if (win->player->hero == 0)
        choose_hex(win);
    if (win->player->hero == 1)
        choose_linail(win);
    if (win->player->hero == 2)
        choose_ouzo(win);
    if (win->player->hero == 3)
        choose_prime(win);
    if (win->player->hero == 4)
        choose_wyvera(win);
}

void choose_hero_reverse(window_t *win)
{
    win->player->hero--;
    if (win->player->hero < 0)
        win->player->hero = 4;
    if (win->player->hero == 0)
        choose_hex(win);
    if (win->player->hero == 1)
        choose_linail(win);
    if (win->player->hero == 2)
        choose_ouzo(win);
    if (win->player->hero == 3)
        choose_prime(win);
    if (win->player->hero == 4)
        choose_wyvera(win);
}