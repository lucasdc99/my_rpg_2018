/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** draw
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *draw_scene(window_t *win)
{
    sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
    printf("okay1\n");
    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
    printf("okay2\n");
        sfRenderWindow_drawRectangleShape(win->window,
        win->scene[win->actual_page].button[i].rect, NULL);
    printf("okay3\n");
        sfRenderWindow_drawText(win->window,
        win->scene[win->actual_page].button[i].text, NULL);
    }
    printf("okay4\n");
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, win->scene[win->actual_page].sprite[i].sprite, NULL);
    }
    sfRenderWindow_display(win->window);
    return (win);
}