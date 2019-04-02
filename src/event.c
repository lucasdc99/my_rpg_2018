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

void move_player(window_t *win)
{
    static int move = 0;

    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue || sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        if (move != 0) {
            if (move == 1)
                win->test2 -= 20;
            if (move == 2)
                win->test += 20;
            if (move == 3)
                win->test -= 20;
            move = 0;
            win->scene[GAME].sprite[0].rect.left = 15;
        }
        win->scene[GAME].sprite[0].rect.left += 48;
        win->scene[GAME].sprite[0].rect.top = 159;
        if (win->scene[GAME].sprite[0].rect.left > 111)
            win->scene[GAME].sprite[0].rect.left = 15;
        sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
        sfSprite_setPosition(win->scene[win->actual_page].sprite[0].sprite, get_pos_float(win->test, win->test2));
        win->test2 -= 20;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue || sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        if (move != 1) {
            if (move == 0)
                win->test2 += 20;
            if (move == 2)
                win->test += 20;
            if (move == 3)
                win->test -= 20;
            move = 1;
            win->scene[GAME].sprite[0].rect.left = 15;
        }
        win->scene[GAME].sprite[0].rect.left += 48;
        win->scene[GAME].sprite[0].rect.top = 15;
        if (win->scene[GAME].sprite[0].rect.left > 111)
            win->scene[GAME].sprite[0].rect.left = 15;
        sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
        sfSprite_setPosition(win->scene[win->actual_page].sprite[0].sprite, get_pos_float(win->test, win->test2));
        win->test2 += 20;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue || sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        if (move != 2) {
            if (move == 3)
                win->test -= 20;
            if (move == 0)
                win->test2 += 20;
            if (move == 1)
                win->test2 -= 20;
            move = 2;
            win->scene[GAME].sprite[0].rect.left = 15;
        }
        win->scene[GAME].sprite[0].rect.left += 48;
        win->scene[GAME].sprite[0].rect.top = 62;
        if (win->scene[GAME].sprite[0].rect.left > 111)
            win->scene[GAME].sprite[0].rect.left = 15;
        sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
        sfSprite_setPosition(win->scene[win->actual_page].sprite[0].sprite, get_pos_float(win->test, win->test2));
        win->test -= 20;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        if (move != 3) {
            if (move == 2)
                win->test += 20;
            if (move == 0)
                win->test2 += 20;
            if (move == 1)
                win->test2 -= 20;
            move = 3;
            win->scene[GAME].sprite[0].rect.left = 15;
        }
        win->scene[GAME].sprite[0].rect.left += 48;
        win->scene[GAME].sprite[0].rect.top = 110;
        if (win->scene[GAME].sprite[0].rect.left > 111)
            win->scene[GAME].sprite[0].rect.left = 15;
        sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
        sfSprite_setPosition(win->scene[win->actual_page].sprite[0].sprite, get_pos_float(win->test, win->test2));
        win->test += 20;
    }
}

void global_event(window_t *win)
{
    if (win->event.type == sfEvtClosed)
        sfRenderWindow_close(win->window);
    if (win->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(win->window);
        if (win->page == GAME)
            move_player(win);
}
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased)
        mouse_released_event(win);
    if (win->event.type == sfEvtMouseMoved)
        mouse_moved_event(win);
}