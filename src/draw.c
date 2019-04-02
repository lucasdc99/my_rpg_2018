/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** draw
*/

#include "../include/rpg.h"
#include "../include/my.h"

void draw_background(window_t *win)
{
    for (int i = 0; i < 220; i++) {
        sfRenderWindow_drawSprite(win->window,
        win->scene[GAME].background[i].sprite, NULL);
    }
}

window_t *draw_scene(window_t *win)
{
    sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        sfRenderWindow_drawRectangleShape(win->window,
        win->scene[win->actual_page].button[i].rect, NULL);
        sfRenderWindow_drawText(win->window,
        win->scene[win->actual_page].button[i].text, NULL);
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_text; i++) {
        sfRenderWindow_drawText(win->window,
        win->scene[win->actual_page].text[i].str, NULL);
    }
    if (win->actual_page == GAME)
        draw_background(win);
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, win->scene[win->actual_page].sprite[i].sprite, NULL);
    }
    sfRenderWindow_display(win->window);
    return (win);
}