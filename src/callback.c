/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback
*/

#include "../include/rpg.h"
#include "../include/my.h"

void heroes_menu(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = HEROES;
}

void how_to_play(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = HOW_TO_PLAY;
}

void options(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = OPTIONS;
}

void quit(window_t *win)
{
    sfRenderWindow_close(win->window);
}

void quit_pause(window_t *win)
{
    unpause_game(win);
}