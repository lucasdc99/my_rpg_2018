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

    printf("%d %d\n", click_pos.x, click_pos.y);
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
    int counter = 0; 

        if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue || sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
            //win->test2 -= 32;
            win->test2 -= 10;
            win->scene[MAINMENU].sprite[0].rect.left += 48;
            win->scene[MAINMENU].sprite[0].rect.top = 150;
            if (win->scene[MAINMENU].sprite[0].rect.left >= 150)
                win->scene[MAINMENU].sprite[0].rect.left = 0;
            sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite, win->scene[MAINMENU].sprite[0].rect);
            sfSprite_setPosition(win->scene[win->actual_page].sprite[0].sprite, get_pos_float(win->test, win->test2));
    }
        if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue || sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
            //win->test2 += 32;
            win->test2 += 10;
            win->scene[MAINMENU].sprite[0].rect.left += 48;
            win->scene[MAINMENU].sprite[0].rect.top = 0;
            if (win->scene[MAINMENU].sprite[0].rect.left >= 150)
                win->scene[MAINMENU].sprite[0].rect.left = 0;
            sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite, win->scene[MAINMENU].sprite[0].rect);
            sfSprite_setPosition(win->scene[win->actual_page].sprite[0].sprite, get_pos_float(win->test, win->test2));
    }
        if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue || sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
            //win->test -= 60;
            win->test -= 10;
            win->scene[MAINMENU].sprite[0].rect.left -= 48;
            win->scene[MAINMENU].sprite[0].rect.top = 50;
            if (win->scene[MAINMENU].sprite[0].rect.left >= 150)
                win->scene[MAINMENU].sprite[0].rect.left = 100;
            sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite, win->scene[MAINMENU].sprite[0].rect);
            sfSprite_setPosition(win->scene[win->actual_page].sprite[0].sprite, get_pos_float(win->test, win->test2));
    }
        if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
            win->test += 10;
            //counter++;
            //if (counter == 5) {
            win->scene[MAINMENU].sprite[0].rect.left += 48;
            win->scene[MAINMENU].sprite[0].rect.top = 100;
            if (win->scene[MAINMENU].sprite[0].rect.left >= 150)
                win->scene[MAINMENU].sprite[0].rect.left = 0;
            //}

            //if (win->scene[MAINMENU].sprite[0].rect.left >= 500)
                //win->scene[MAINMENU].sprite[0].rect.left = 0;
            sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite, win->scene[MAINMENU].sprite[0].rect);
            sfSprite_setPosition(win->scene[win->actual_page].sprite[0].sprite, get_pos_float(win->test, win->test2));
            //sfRenderWindow_drawSprite(win->window, win->scene[win->actual_page].sprite[0].sprite, NULL);
    }
}

void global_event(window_t *win)
{
    if (win->event.type == sfEvtClosed)
        sfRenderWindow_close(win->window);
    if (win->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(win->window);
        move_player(win);
}
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased)
        mouse_released_event(win);
    if (win->event.type == sfEvtMouseMoved)
        mouse_moved_event(win);
}