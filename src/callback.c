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
    win->page = MAINMENU;
}

void play_game(window_t *win)
{
    win->page = GAME;
}

void how_to_play(window_t *win)
{
    win->page = HOW_TO_PLAY;
}

void options(window_t *win)
{
    win->page = OPTIONS;
}

void quit(window_t *win)
{
    exit(0);
}