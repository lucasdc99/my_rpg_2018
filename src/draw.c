/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** draw
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *draw_scene(window_t *win)
{
    sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, win->scene[win->actual_page].sprite[i].sprite, NULL);
    }
    if (win->actual_page == CASTLE || win->actual_page == TOWN)
        sfRenderWindow_drawSprite(win->window, win->player->sprite->sprite, NULL);
    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        sfRenderWindow_drawRectangleShape(win->window,
        win->scene[win->actual_page].button[i].shape, NULL);
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_text; i++) {
        sfRenderWindow_drawText(win->window,
        win->scene[win->actual_page].text[i].str, NULL);
    }
    sfRenderWindow_display(win->window);
    return (win);
}