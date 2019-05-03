/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mouse_events
*/

#include "../include/rpg.h"
#include "../include/my.h"

void mouse_pressed_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].shape;
        if (button_is_clicked(win->scene[win->actual_page].button[i],
        click_pos)) {
            sfRectangleShape_setTextureRect(rect,
            win->scene[win->actual_page].button[i].rect_pressed);
        }
    }
}

static int check_callback(window_t *win, sfRectangleShape *rect, int i)
{
    sfRectangleShape_setTextureRect(rect,
    win->scene[win->actual_page].button[i].rect_idle);
    if (win->scene[win->actual_page].button[i].callback != NULL) {
        if (win->scene[win->actual_page].button[i].callback(win) == 84)
            return (84);
    }
    return (0);
}

int mouse_released_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].shape;
        if (button_is_clicked(win->scene[win->actual_page].button[i],
        click_pos)) {
            if (check_callback(win, rect, i) == 84)
                return (84);
        }
    }
    return (0);
}

void mouse_moved_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;
    int ok = 0;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].shape;
        if (button_is_hovered(win->scene[win->actual_page].button[i],
        click_pos)) {
            sfRectangleShape_setTextureRect(rect,
            win->scene[win->actual_page].button[i].rect_hovered);
            ok = 1;
            if (win->actual_page == COMBAT)
                draw_description(win, i);
        } else {
            sfRectangleShape_setTextureRect(rect,
            win->scene[win->actual_page].button[i].rect_idle);
        }
    }
    if (ok == 0 && win->actual_page == COMBAT)
        sfText_setString(win->text->str, "\n");
}