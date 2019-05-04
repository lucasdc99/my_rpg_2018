/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** draw_sprites
*/

#include "../include/rpg.h"
#include "../include/my.h"

void draw_sprites_depth(window_t *win)
{
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == -1) {
            sfRenderWindow_drawSprite(win->window,
            win->scene[win->actual_page].sprite[i].sprite, NULL);
        }
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == 0 &&
        (win->states->pause == 0 || win->states->inventory == 1 ||
        win->states->talking == 1)) {
            sfRenderWindow_drawSprite(win->window,
            win->scene[win->actual_page].sprite[i].sprite, NULL);
        }
    }
}

void draw_sprites(window_t *win)
{
    draw_sprites_depth(win);
    if (win->actual_page >= CASTLE && win->actual_page < COMBAT) {
        if (win->states->pause == 0 || win->states->inventory == 1 ||
        win->states->talking == 1) {
            sfRenderWindow_drawSprite(win->window,
            win->player->sprite->sprite, NULL);
        }
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == 1 &&
        (win->states->pause == 0 || win->states->inventory == 1 ||
        win->states->talking == 1)) {
            sfRenderWindow_drawSprite(win->window,
            win->scene[win->actual_page].sprite[i].sprite, NULL);
        }
    }
}