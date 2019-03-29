/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** destroy
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *destroy_scene(window_t *win)
{
    int page = win->actual_page;

    for (int i = 0; i < win->scene[page].nb_button; i++) {
        sfText_destroy(win->scene[page].button[i].text);
        sfRectangleShape_destroy(win->scene[page].button[i].rect);
    }
    free(win->scene[page].button);
    return (win);
}