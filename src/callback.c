/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback
*/

#include "../include/rpg.h"
#include "../include/my.h"

int heroes_menu(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = HEROES;
    return (0);
}

int how_to_play(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = HOW_TO_PLAY;
    return (0);
}

int options(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = OPTIONS;
    return (0);
}

int quit(window_t *win)
{
    sfRenderWindow_close(win->window);
    return (0);
}

int quit_pause(window_t *win)
{
    unpause_game(win);
    return (0);
}