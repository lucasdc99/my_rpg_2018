/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** useful
*/

#include "../include/rpg.h"
#include "../include/my.h"

int is_inside_zone(sfVector2f limit1, sfVector2f limit2, sfVector2f pos)
{
    if (pos.x >= limit1.x && pos.x <= limit2.x) {
        if (pos.y >= limit1.y && pos.y <= limit2.y)
            return (1);
    }
    return (0);
}

void set_struct(window_t *win, int button, int text, int sprite)
{
    if (button > 0)
        win->scene[win->page].button = malloc(sizeof(button_t) * button);
    if (text > 0)
        win->scene[win->page].text = malloc(sizeof(text_t) * text);
    if (sprite > 0)
        win->scene[win->page].sprite = malloc(sizeof(sprite_t) * sprite);
    win->scene[win->page].nb_text = text;
    win->scene[win->page].nb_button = button;
    win->scene[win->page].nb_sprite = sprite;
}