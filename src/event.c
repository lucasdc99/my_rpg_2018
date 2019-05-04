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
    if (win->states->quest == 0 && win->states->inventory == 0 &&
    win->states->pause == 1 && win->states->talking == 1) {
        display_text_in_textbox(win->quests);
    }
    if (win->quests->quete_done != actual_quest) {
        actual_quest = win->quests->quete_done;
        win->quests->sprite[1].depth = -1;
        sfText_setString(win->text->str, "\n");
        if (win->quests->quete_done >= 6) {
            actual_quest = 5;
            win->quests->quete_done = 5;
        }
        win->states->talking = 0;
        win->states->pause = 0;
    }
    return (actual_quest);
}

static void handle_inventory_key(window_t *win)
{
    if (win->states->inventory == 0 && win->states->pause == 0 &&
    win->states->quest == 0)
        open_inventory(win);
    else if (win->states->quest == 0 && win->states->pause == 1 &&
    win->states->inventory == 1)
        close_inventory(win);
}

void check_keyboard_input_ingame(window_t *win)
{
    static int actual_quest = 0;

    if (sfKeyboard_isKeyPressed(sfKeyI))
        handle_inventory_key(win);
    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        if (win->states->quest == 0 && win->states->inventory == 0 &&
        win->states->pause == 0) {
            open_quest(win);
            sfText_setString(win->text->str, "\n");
        }
        else if (win->states->inventory == 0 && win->states->pause == 1 &&
        win->states->quest == 1) {
            close_quest(win);
            sfText_setString(win->text->str, "\n");
        }
    }
    if (actual_quest == 0 || actual_quest == 5)
        actual_quest = win->quests->quete_done;
    if (sfKeyboard_isKeyPressed(sfKeyReturn))
        actual_quest = handle_skip_textbox(win, actual_quest);
}

static int check_mouse_left(window_t *win)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (drag_button(win) == 84)
            return (84);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT &&
        win->states->inventory == 1) {
            drag_and_drop_inv(win);
        }
    }
    return (0);
}

int global_event_condition(window_t *win)
{
    if (check_mouse_left(win) == 84)
        return (84);
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased) {
        if (mouse_released_event(win) == 84)
            return (84);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT &&
        win->states->inventory == 1) {
            check_drag_and_drop_inv(win);
        }
    }
    if (win->event.type == sfEvtMouseMoved) {
        mouse_moved_event(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT &&
        win->states->inventory == 1) {
            set_text_inv(win);
        }
    }
    return (0);
}