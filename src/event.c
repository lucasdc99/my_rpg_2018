/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

void check_keyboard_input_ingame(window_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        if (win->inventory == 0 && win->pause == 0 && win->quest == 0)
            open_inventory(win);
        else if (win->quest == 0 && win->pause == 1 && win->inventory == 1)
            close_inventory(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        if (win->quest == 0 && win->inventory == 0 && win->pause == 0)
            open_quest(win);
        else if (win->inventory == 0 && win->pause == 1 && win->quest == 1)
            close_quest(win);
    }
}

void global_event_condition(window_t *win)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (win->actual_page == OPTIONS)
            drag_button(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT && win->inventory == 1)
            drag_and_drop_inv(win);
    }
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased) {
        mouse_released_event(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT && win->inventory == 1)
            check_drag_and_drop_inv(win);
    }
    if (win->event.type == sfEvtMouseMoved) {
        mouse_moved_event(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT && win->inventory == 1)
            set_text_inv(win);
    }
}

void global_event_condition_escape(window_t *win)
{
    if (win->actual_page == MAINMENU)
        quit(win);
    if (win->actual_page >= CASTLE && win->actual_page < COMBAT) {
        if (win->pause == 0 && win->inventory == 0 && win->quest == 0)
            pause_game(win);
        else if (win->inventory == 0 && win->quest == 0 && win->pause == 1)
            unpause_game(win);
    }
}

void global_event(window_t *win)
{
    if (win->event.type == sfEvtClosed)
        quit(win);
    if (win->event.type == sfEvtKeyPressed) {
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT)
            check_keyboard_input_ingame(win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            global_event_condition_escape(win);
    }
    global_event_condition(win);
}