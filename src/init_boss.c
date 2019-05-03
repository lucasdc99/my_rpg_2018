/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_boss
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int init_buttons(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_next_buttons(&win->scene[BOSS].button[0], win->rect_buttons,
    order_button[0]);
    if (init_button(&win->scene[BOSS].button[0], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (84);
    set_next_buttons(&win->scene[BOSS].button[1], win->rect_buttons,
    order_button[1]);
    if (init_button(&win->scene[BOSS].button[1], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (84);
    win->scene[BOSS].button[0].callback = &quit_pause;
    win->scene[BOSS].button[1].callback = &main_menu;
    return (0);
}

window_t *init_boss(window_t *win)
{
    if (set_struct(win, 2, 0, 18) == 84)
        return (NULL);
    if (init_sprite(&win->scene[BOSS].sprite[0],
    "ressources/images/final_boss.png", get_pos_float(600, 0)) == 84)
        return (NULL);
    if (init_sprite(&win->scene[BOSS].sprite[1],
    "ressources/images/Glenys.png",
    get_pos_float(920, 80)) == 84)
        return (NULL);
    if (initialisation_depth_sprite_boss(win) == 84)
        return (NULL);
    if (init_buttons(win) == 84)
        return (NULL);
    sfSprite_setScale(win->scene[BOSS].sprite[1].sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->scene[BOSS].sprite[1].sprite,
    get_rect(12, 9, 32, 32));
    win->scene[BOSS].sprite[0].depth = -1;
    for (int i = 2; i < win->scene[BOSS].nb_sprite; i++)
        win->scene[BOSS].sprite[i].depth = 1;
    return (win);
}