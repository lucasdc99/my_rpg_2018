/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** callback
*/

#include "../include/rpg.h"
#include "../include/my.h"

void main_menu(window_t *win)
{
    sfMusic_play(win->button_sound);
    win->page = MAINMENU;
}

void play_game(window_t *win)
{
    win->move = sfClock_create();
    sfMusic_play(win->button_sound);
    win->page = GAME;
}

void how_to_play(window_t *win)
{
    sfMusic_play(win->button_sound);
    win->page = HOW_TO_PLAY;
}

void options(window_t *win)
{
    sfMusic_play(win->button_sound);
    win->page = OPTIONS;
}

void quit(window_t *win)
{
    sfRenderWindow_close(win->window);
}