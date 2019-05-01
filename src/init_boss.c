/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_boss
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_buttons(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER};

    set_next_buttons(&win->scene[BOSS].button[0], win->rect_buttons,
    order_button[0]);
    init_button(&win->scene[BOSS].button[0], get_pos_float(-200, -200),
    size, win->texture_button);
    set_next_buttons(&win->scene[BOSS].button[1], win->rect_buttons,
    order_button[1]);
    init_button(&win->scene[BOSS].button[1], get_pos_float(-200, -200),
    size, win->texture_button);
    win->scene[BOSS].button[0].callback = &quit_pause;
    win->scene[BOSS].button[1].callback = &main_menu;
}

static void initialisation_depth_sprite_boss_one(window_t *win)
{
    init_sprite(&win->scene[BOSS].sprite[2],
                "ressources/sprite_contraste/statue.png", get_pos_float(582, 372));
    init_sprite(&win->scene[BOSS].sprite[3],
                "ressources/sprite_contraste/statue_shield.png",
                get_pos_float(590, 621));
    init_sprite(&win->scene[BOSS].sprite[4],
                "ressources/sprite_contraste/statue.png", get_pos_float(585, 830));
    init_sprite(&win->scene[BOSS].sprite[5],
                "ressources/sprite_contraste/statue_shield.png",
                get_pos_float(1205, 376));
    init_sprite(&win->scene[BOSS].sprite[6],
                "ressources/sprite_contraste/statue.png", get_pos_float(1200, 625));
    init_sprite(&win->scene[BOSS].sprite[7],
                "ressources/sprite_contraste/statue_shield.png",
                get_pos_float(1202, 833));
    init_sprite(&win->scene[BOSS].sprite[8],
                "ressources/sprite_contraste/colomn.png", get_pos_float(731, 335));
    init_sprite(&win->scene[BOSS].sprite[9],
                "ressources/sprite_contraste/colomn.png", get_pos_float(1048, 337));
}

static void initialisation_depth_sprite_boss(window_t *win)
{
    initialisation_depth_sprite_boss_one(win);
    init_sprite(&win->scene[BOSS].sprite[10],
            "ressources/sprite_contraste/colomn.png", get_pos_float(732, 530));
    init_sprite(&win->scene[BOSS].sprite[11],
            "ressources/sprite_contraste/colomn.png", get_pos_float(1047, 532));
    init_sprite(&win->scene[BOSS].sprite[12],
            "ressources/sprite_contraste/colomn.png", get_pos_float(728, 734));
    init_sprite(&win->scene[BOSS].sprite[13],
            "ressources/sprite_contraste/colomn.png", get_pos_float(1048, 733));
    init_sprite(&win->scene[BOSS].sprite[14],
            "ressources/sprite_contraste/colomn.png", get_pos_float(727, 933));
    init_sprite(&win->scene[BOSS].sprite[15],
            "ressources/sprite_contraste/colomn.png", get_pos_float(1045, 935));
    init_sprite(&win->scene[BOSS].sprite[16],
            "ressources/sprite_contraste/flambeau.png",
            get_pos_float(773, 219));
    init_sprite(&win->scene[BOSS].sprite[17],
            "ressources/sprite_contraste/flambeau.png",
            get_pos_float(1010, 221));
}

window_t *init_boss(window_t *win)
{
    set_struct(win, 2, 0, 18);
    init_sprite(&win->scene[BOSS].sprite[0], "ressources/final_boss.png",
    get_pos_float(600, 0));
    init_sprite(&win->scene[BOSS].sprite[1],
    "ressources/images/sprites/Glenys-the-Demonswordsman.png",
    get_pos_float(920, 80));
    initialisation_depth_sprite_boss(win);
    init_buttons(win);
    sfSprite_setScale(win->scene[BOSS].sprite[1].sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->scene[BOSS].sprite[1].sprite,
    get_rect(12, 9, 32, 32));
    win->scene[BOSS].sprite[0].depth = -1;
    for (int i = 2; i < win->scene[BOSS].nb_sprite; i++)
        win->scene[BOSS].sprite[i].depth = 1;
    return (win);
}