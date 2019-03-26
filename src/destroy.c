/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
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
    }
    free(win->scene[page].button);
    return (win);
}