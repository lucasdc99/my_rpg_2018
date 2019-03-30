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
        sfFont_destroy(win->scene[page].button[i].font);
        sfText_destroy(win->scene[page].button[i].text);
        sfRectangleShape_destroy(win->scene[page].button[i].rect);
    }
    free(win->scene[page].button);
    return (win);
}

void destroy_all_music(window_t *win)
{
    sfMusic_destroy(win->button_sound);
}