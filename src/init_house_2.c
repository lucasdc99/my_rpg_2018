/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_house_2
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int init_buttons(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_next_buttons(&win->scene[HOUSE2].button[0], win->rect_buttons,
    order_button[0]);
    if (init_button(&win->scene[HOUSE2].button[0], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (84);
    set_next_buttons(&win->scene[HOUSE2].button[1], win->rect_buttons,
    order_button[1]);
    if (init_button(&win->scene[HOUSE2].button[1], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (84);
    return (0);
}

window_t *init_house_2(window_t *win)
{
    if (set_struct(win, 2, 0, 1) == 84)
        return (NULL);
    if (init_buttons(win) == 84)
        return (NULL);
    if (init_sprite(&win->scene[HOUSE2].sprite[0],
    "ressources/images/house_2.png", get_pos_float(0, 0)) == 84)
        return (NULL);
    sfSprite_setPosition(win->scene[HOUSE2].sprite[0].sprite,
    get_pos_float(670, 300));
    win->scene[HOUSE2].sprite[0].depth = -1;
    win->scene[HOUSE2].button[0].callback = &quit_pause;
    win->scene[HOUSE2].button[1].callback = &main_menu;
    return (win);
}