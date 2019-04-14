/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_player
*/

#include "../include/rpg.h"
#include "../include/my.h"

void init_player(window_t *win)
{
    char *skin = malloc(sizeof(char) * 80);

    win->player->sprite->rect.top = 15;
    win->player->sprite->rect.left = 15;
    win->player->sprite->rect.width = 18;
    win->player->sprite->rect.height = 18;
    skin = my_strcat("ressources/pack/Pixel_Champions/Magical Heroes/", win->player->name);
    skin = my_strcat(skin, ".png");
    init_sprite(&win->player->sprite[0], skin, get_pos_float(win->player->speed.x, win->player->speed.y));
    sfSprite_setScale(win->player->sprite->sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
    if (win->player->last_pos.x >= 0)
        sfSprite_setPosition(win->player->sprite->sprite, win->player->last_pos);
    else
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(500, 500));
    check_dead_zone(win, -1);
}