/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_house
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_house(window_t *win)
{
    win->scene[HOUSE].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[HOUSE].nb_text = 0;
    win->scene[HOUSE].nb_button = 0;
    win->scene[HOUSE].nb_sprite = 1;
    init_sprite(&win->scene[HOUSE].sprite[0], "ressources/pack/rpg-pack/decorations/generic-rpg-house-inn.png", get_pos_float(200, 200));
    sfSprite_setScale(win->scene[HOUSE].sprite[0].sprite, get_pos_float(2, 2));
    return (win);
}