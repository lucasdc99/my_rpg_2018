/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

void mouse_pressed_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].rect;
        if (button_is_clicked(win->scene[win->actual_page].button[i],
        click_pos)) {
            sfRectangleShape_setFillColor(rect,
            win->scene[win->actual_page].button[i].clicked_color);
        }
    }
}

void mouse_released_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].rect;
        if (button_is_clicked(win->scene[win->actual_page].button[i],
        click_pos)) {
            win->scene[win->actual_page].button[i].callback(win);
            sfRectangleShape_setFillColor(rect,
            win->scene[win->actual_page].button[i].idle_color);
        }
    }
}

void mouse_moved_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].rect;
        if (button_is_hovered(win->scene[win->actual_page].button[i],
        click_pos)) {
            sfRectangleShape_setFillColor(rect,
            win->scene[win->actual_page].button[i].hovered_color);
        } else {
            sfRectangleShape_setFillColor(rect,
            win->scene[win->actual_page].button[i].idle_color);
        }
    }
}

void global_event(window_t *win)
{
    if (win->event.type == sfEvtClosed)
        sfRenderWindow_close(win->window);
    if (win->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(win->window);
    }
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased)
        mouse_released_event(win);
    if (win->event.type == sfEvtMouseMoved)
        mouse_moved_event(win);
}