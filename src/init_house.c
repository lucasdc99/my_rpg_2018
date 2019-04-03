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
    int fd = open("ressources/text/pos_house", O_RDONLY);
    char buff[660];

    win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
    read(fd, buff, sizeof(buff));
    win->scene[HOUSE].background = malloc(sizeof(background_t) * 222);
    win->scene[HOUSE].background->tab_pos = transform_pos_to_tab(buff);
    load_background(win);
    win->scene[HOUSE].nb_text = 0;
    win->scene[HOUSE].nb_button = 0;
    win->scene[HOUSE].nb_sprite = 0;
    return (win);
}