/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_rect
*/

#include "../include/rpg.h"
#include "../include/my.h"

void move_sprites(window_t *win, int offset)
{
    win->scene[HEROES].sprite[0].rect.left = offset * (win->seconds % 2);
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
}

void animation_mainmenu(window_t *win, int offset)
{
    win->scene[MAINMENU].sprite[0].rect.left = offset * (win->seconds % 7);
    sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite, win->scene[MAINMENU].sprite[0].rect);

}