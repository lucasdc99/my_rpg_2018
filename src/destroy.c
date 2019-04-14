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
        sfRectangleShape_destroy(win->scene[page].button[i].shape);
    }
    for (int i = 0; i < win->scene[page].nb_sprite; i++) {
        sfSprite_destroy(win->scene[page].sprite[i].sprite);
        sfTexture_destroy(win->scene[page].sprite[i].texture);
    }
    for (int i = 0; i < win->scene[page].nb_text; i++) {
        sfText_destroy(win->scene[page].text[i].str);
    }
    if (win->scene[page].nb_button > 0)
        free(win->scene[page].button);
    if (win->scene[page].nb_sprite > 0)
        free(win->scene[page].sprite);
    if (win->scene[page].nb_text > 0)
        free(win->scene[page].text);
    return (win);
}

void destroy_all(window_t *win)
{
    sfMusic_destroy(win->music->menu_song);
    sfMusic_destroy(win->music->button_sound);
    free(win->music);
    if (win->player->sprite->texture != NULL)
        sfTexture_destroy(win->player->sprite->texture);
    if (win->player->sprite->sprite != NULL)
        sfSprite_destroy(win->player->sprite->sprite);
    free(win->player->sprite);
    free(win->player);
    free(win->scene);
    free(win);
}