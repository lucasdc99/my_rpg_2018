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

void mouse_released_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].shape;
        if (button_is_clicked(win->scene[win->actual_page].button[i],
        click_pos)) {
            sfRectangleShape_setTextureRect(rect,
            win->scene[win->actual_page].button[i].rect_idle);
            if (win->scene[win->actual_page].button[i].callback != NULL)
                win->scene[win->actual_page].button[i].callback(win);
        }
    }
}

static void draw_description(window_t *win, int i)
{
    sfUint32 *tmp;
    int hit = 0;
    char *str = NULL;

    sfText_setPosition(win->text->str, get_pos_float(600, 900));
    if (i == 0) {
        hit = 20 + (win->player->strength / 10);
        str = my_strcat("Attaque Basique: -", my_itc(hit));
        str = my_strcat(str, " PV");
        str_to_unicode(str, &tmp);
        sfText_setUnicodeString(win->text->str, tmp);
    }
    if (i == 1) {
        hit = 30 + (win->player->strength / 10);
        str = my_strcat("Attaque Sp_éciale: -", my_itc(hit));
        str = my_strcat(str, " PV (_érosion)");
        str_to_unicode(str, &tmp);
        sfText_setUnicodeString(win->text->str, tmp);
    }
    if (i == 2) {
        hit = 30 + (win->player->strength / 10);
        str = my_strcat("R_ég_énaration: +", my_itc(hit));
        str = my_strcat(str, " PV");
        str_to_unicode(str, &tmp);
        sfText_setUnicodeString(win->text->str, tmp);
    }
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
    if (ok == 0)
        sfText_setString(win->text->str, "\n");
}