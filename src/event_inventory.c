/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event_inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int check_pause(window_t *win)
{
    if (win->states->pause == 0 && win->states->inventory == 0 &&
    win->states->quest == 0) {
        if (pause_game(win) == 84)
            return (84);
    } else if (win->states->inventory == 0 && win->states->quest == 0 &&
    win->states->talking == 0 && win->states->pause == 1) {
        unpause_game(win);
    }
    return (0);
}

int global_event_condition_escape(window_t *win)
{
    if (win->actual_page == MAINMENU)
        quit(win);
    if (win->actual_page >= CASTLE && win->actual_page < COMBAT) {
        if (check_pause(win) == 84)
            return (84);
        if (win->states->quest == 0 && win->states->pause == 1 &&
        win->states->inventory == 1)
            close_inventory(win);
    }
    return (0);
}

static int check_key_pressed(window_t *win)
{
    if (win->actual_page >= CASTLE && win->actual_page < COMBAT)
        check_keyboard_input_ingame(win);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        if (global_event_condition_escape(win) == 84)
            return (84);
    }
    return (0);
}

int global_event(window_t *win)
{
    if (win->event.type == sfEvtClosed)
        quit(win);
    if (win->event.type == sfEvtKeyPressed) {
        if (check_key_pressed(win) == 84)
            return (84);
    }
    if (global_event_condition(win) == 84)
        return (84);
    return (0);
}