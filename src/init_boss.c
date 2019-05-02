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

static int initialisation_depth_sprite_boss_other(window_t *win)
{
    if (init_sprite(&win->scene[BOSS].sprite[6],
    "ressources/images/statue.png", get_pos_float(1200, 625)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[7],
    "ressources/images/statue_shield.png",
    get_pos_float(1202, 833)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[8],
    "ressources/images/colomn.png", get_pos_float(731, 335)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[9],
    "ressources/images/colomn.png", get_pos_float(1048, 337)) == 84)
        return (84);
    return (0);
}

static int initialisation_depth_sprite_boss_one(window_t *win)
{
    if (init_sprite(&win->scene[BOSS].sprite[2],
    "ressources/images/statue.png", get_pos_float(582, 372)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[3],
    "ressources/images/statue_shield.png",
    get_pos_float(590, 621)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[4],
    "ressources/images/statue.png", get_pos_float(585, 830)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[5],
    "ressources/images/statue_shield.png",
    get_pos_float(1205, 376)) == 84)
        return (84);
    if (initialisation_depth_sprite_boss_other(win) == 84)
        return (84);
    return (0);
}

static int initialisation_depth_sprite_boss_basic(window_t *win)
{
    if (init_sprite(&win->scene[BOSS].sprite[14],
    "ressources/images/colomn.png", get_pos_float(727, 933)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[15],
    "ressources/images/colomn.png", get_pos_float(1045, 935)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[16],
    "ressources/images/flambeau.png",
    get_pos_float(773, 219)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[17],
    "ressources/images/flambeau.png",
    get_pos_float(1010, 221)) == 84)
        return (84);
    return (0);
}

static int initialisation_depth_sprite_boss(window_t *win)
{
    if (initialisation_depth_sprite_boss_one(win) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[10],
    "ressources/images/colomn.png", get_pos_float(732, 530)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[11],
    "ressources/images/colomn.png", get_pos_float(1047, 532)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[12],
    "ressources/images/colomn.png", get_pos_float(728, 734)) == 84)
        return (84);
    if (init_sprite(&win->scene[BOSS].sprite[13],
    "ressources/images/colomn.png", get_pos_float(1048, 733)) == 84)
        return (84);
    if (initialisation_depth_sprite_boss_basic(win) == 84)
        return (84);
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