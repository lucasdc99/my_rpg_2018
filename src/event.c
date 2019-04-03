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
                win->player->speed.y -= 20;
            if (move == 2)
                win->player->speed.x += 20;
            if (move == 3)
                win->player->speed.x -= 20;
            move = 0;
            win->player->sprite->rect.left = 15;
        }
        win->player->sprite->rect.left += 48;
        win->player->sprite->rect.top = 159;
        if (win->player->sprite->rect.left > 111)
            win->player->sprite->rect.left = 15;
        sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(win->player->speed.x, win->player->speed.y));
        win->player->speed.y -= 20;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue || sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        if (move != 1) {
            if (move == 0)
                win->player->speed.y += 20;
            if (move == 2)
                win->player->speed.x += 20;
            if (move == 3)
                win->player->speed.x -= 20;
            move = 1;
            win->player->sprite->rect.left = 15;
        }
        win->player->sprite->rect.left += 48;
        win->player->sprite->rect.top = 15;
        if (win->player->sprite->rect.left > 111)
            win->player->sprite->rect.left = 15;
        sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(win->player->speed.x, win->player->speed.y));
        win->player->speed.y += 20;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue || sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        if (move != 2) {
            if (move == 3)
                win->player->speed.x -= 20;
            if (move == 0)
                win->player->speed.y += 20;
            if (move == 1)
                win->player->speed.y -= 20;
            move = 2;
            win->player->sprite->rect.left = 15;
        }
        win->player->sprite->rect.left += 48;
        win->player->sprite->rect.top = 62;
        if (win->player->sprite->rect.left > 111)
            win->player->sprite->rect.left = 15;
        sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(win->player->speed.x, win->player->speed.y));
        win->player->speed.x -= 20;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        if (move != 3) {
            if (move == 2)
                win->player->speed.x += 20;
            if (move == 0)
                win->player->speed.y += 20;
            if (move == 1)
                win->player->speed.y -= 20;
            move = 3;
            win->player->sprite->rect.left = 15;
        }
        win->player->sprite->rect.left += 48;
        win->player->sprite->rect.top = 110;
        if (win->player->sprite->rect.left > 111)
            win->player->sprite->rect.left = 15;
        sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(win->player->speed.x, win->player->speed.y));
        win->player->speed.x += 20;
    }
}

void check_interaction(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);
    sfVector2f pos_element = sfSprite_getPosition(win->scene[GAME].sprite[0].sprite);

    pos_element.x += 45;
    pos_element.y += 140;
    //printf("%f %f %f %f\n", pos_player.x, pos_player.y, pos_element.x, pos_element.y);
    if (pos_player.x > pos_element.x - 20 && pos_player.x < pos_element.x) {
        if (pos_player.y > pos_element.y - 20 && pos_player.y < pos_element.y + 20)
            win->page = HOUSE;
    }
}

void global_event(window_t *win)
{
    if (win->event.type == sfEvtClosed)
        sfRenderWindow_close(win->window);
    if (win->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(win->window);
        if (win->page == GAME || win->page == HOUSE) {
            move_player(win);
            check_interaction(win);
        }
    }
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased)
        mouse_released_event(win);
    if (win->event.type == sfEvtMouseMoved)
        mouse_moved_event(win);
}