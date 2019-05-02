/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int handle_skip_textbox(window_t *win, int actual_quest)
{
    if (win->quest == 0 && win->inventory == 0 &&
    win->pause == 1 && win->talking == 1)
        display_text_in_textbox(win->quests);
    if (win->quests->quete_done != actual_quest) {
        actual_quest = win->quests->quete_done;
        win->quests->sprite[1].depth = -1;
        sfText_setString(win->text->str, "\n");
        if (win->quests->quete_done >= 6) {
            actual_quest = 5;
            win->quests->quete_done = 5;
        }
        win->talking = 0;
        win->pause = 0;
    }
    return (actual_quest);
}

static void handle_inventory_key(window_t *win)
{
    if (win->inventory == 0 && win->pause == 0 && win->quest == 0)
        open_inventory(win);
    else if (win->quest == 0 && win->pause == 1 && win->inventory == 1)
        close_inventory(win);
}

void check_keyboard_input_ingame(window_t *win)
{
    static int actual_quest = 0;

    if (sfKeyboard_isKeyPressed(sfKeyI))
        handle_inventory_key(win);
    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        if (win->quest == 0 && win->inventory == 0 && win->pause == 0) {
            open_quest(win);
            sfText_setString(win->text->str, "\n");
        }
        else if (win->inventory == 0 && win->pause == 1 && win->quest == 1) {
            close_quest(win);
            sfText_setString(win->text->str, "\n");
        }
    }
    if (actual_quest == 0 || actual_quest == 5)
        actual_quest = win->quests->quete_done;
    if (sfKeyboard_isKeyPressed(sfKeyReturn))
        actual_quest = handle_skip_textbox(win, actual_quest);
}

void check_mouse_left(window_t *win)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (win->actual_page == OPTIONS)
            drag_button(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT &&
        win->inventory == 1) {
            drag_and_drop_inv(win);
        }
    }
}

void global_event_condition(window_t *win)
{
    check_mouse_left(win);
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased) {
        mouse_released_event(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT &&
        win->inventory == 1) {
            check_drag_and_drop_inv(win);
        }
    }
    if (win->event.type == sfEvtMouseMoved) {
        mouse_moved_event(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT &&
        win->inventory == 1) {
            set_text_inv(win);
        }
    }
}

void global_event_condition_escape(window_t *win)
{
    if (win->actual_page == MAINMENU)
        quit(win);
    if (win->actual_page >= CASTLE && win->actual_page < COMBAT) {
        if (win->pause == 0 && win->inventory == 0 && win->quest == 0)
            pause_game(win);
        else if (win->inventory == 0 && win->quest == 0 &&
        win->talking == 0 && win->pause == 1)
            unpause_game(win);
        if (win->quest == 0 && win->pause == 1 && win->inventory == 1)
            close_inventory(win);
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