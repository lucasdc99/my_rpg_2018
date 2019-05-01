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
    static int actual = 1;

    if (actual == 0)
        choose_hex(win);
    if (actual == 1)
        choose_linail(win);
    if (actual == 2)
        choose_ouzo(win);
    if (actual == 3)
        choose_prime(win);
    if (actual == 4)
        choose_wyvera(win);
    actual++;
    if (actual == 5)
        actual = 0;
}

void choose_hero_reverse(window_t *win)
{
    static int actual = 1;

    if (actual == 0)
        choose_hex(win);
    if (actual == 1)
        choose_linail(win);
    if (actual == 2)
        choose_ouzo(win);
    if (actual == 3)
        choose_prime(win);
    if (actual == 4)
        choose_wyvera(win);
    actual--;
    if (actual < 0)
        actual = 5;
}