/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_house_1
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void initialisation_sprite_house_one(window_t *win)
{
    init_sprite(&win->scene[HOUSE1].sprite[0], "ressources/house_1.png",
    get_pos_float(0, 0));
    sfSprite_setPosition(win->scene[HOUSE1].sprite[0].sprite,
    get_pos_float(670, 300));
    init_sprite(&win->scene[HOUSE1].sprite[1], "ressources/chars.png",
    get_pos_float(1120, 435));
    init_sprite(&win->scene[HOUSE1].sprite[2],
    "ressources/sprite_contraste/table_basse.png",
    get_pos_float(961, 511));
    sfSprite_setTextureRect(win->scene[HOUSE1].sprite[1].sprite,
    get_rect(129, 54, 32, 43));
    sfSprite_setScale(win->scene[HOUSE1].sprite[1].sprite,
    get_pos_float(1.5, 1.5));
}

window_t *init_house_1(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 3);
    set_next_buttons(&win->scene[HOUSE1].button[0], win->rect_buttons,
    order_button[0]);
    init_button(&win->scene[HOUSE1].button[0], get_pos_float(-200, -200),
    size, win->texture_button);
    set_next_buttons(&win->scene[HOUSE1].button[1], win->rect_buttons,
    order_button[1]);
    init_button(&win->scene[HOUSE1].button[1], get_pos_float(-200, -200),
    size, win->texture_button);
    initialisation_sprite_house_one(win);
    win->scene[HOUSE1].sprite[0].depth = -1;
    win->scene[HOUSE1].sprite[2].depth = 1;
    win->scene[HOUSE1].button[0].callback = &quit_pause;
    win->scene[HOUSE1].button[1].callback = &main_menu;
    return (win);
}