/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** animate_player
*/

#include "../include/rpg.h"
#include "../include/my.h"

void animate_player_walk(window_t *win)
{
    if (win->player->sprite->rect.left > 111)
        win->player->sprite->rect.left = 15;
    sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
    if ((win->player->move_rect % 5) == 0)
        win->player->sprite->rect.left += 48;
}