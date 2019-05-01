/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_combat
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_buttons(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int order_button[] = {REPRENDRE, QUITTER, FLECHE, FLECHE, FLECHE};
    int pos_x[] = {-200, -200, 1600, 1600, 1600};
    int pos_y[] = {-200, -200, 200, 300, 400};

    for (int i = 0; i < win->scene[COMBAT].nb_button; i++) {
        set_next_buttons(&win->scene[COMBAT].button[i], win->rect_buttons,
        order_button[i]);
        init_button(&win->scene[COMBAT].button[i],
        get_pos_float(pos_x[i], pos_y[i]),
        size, win->texture_button);
    }
    for (int i = 2; i < win->scene[COMBAT].nb_button; i++) {
        sfRectangleShape_setSize(win->scene[COMBAT].button[i].shape,
        get_pos_float(100, 100));
    }
    win->scene[COMBAT].button[0].callback = &quit_pause;
    win->scene[COMBAT].button[1].callback = &main_menu;
    win->scene[COMBAT].button[2].callback = &basic_attack;
    win->scene[COMBAT].button[3].callback = &special_attack;
    win->scene[COMBAT].button[4].callback = &stats_attack;
}

static void init_sprites(window_t *win)
{
    char *skin = NULL;

    skin = my_strcat("ressources/images/sprites/", win->player->name);
    skin = my_strcat(skin, ".png");
    init_sprite(&win->scene[COMBAT].sprite[0], skin, get_pos_float(1500, 500));
    init_sprite(&win->scene[COMBAT].sprite[1], "ressources/heart.png",
    get_pos_float(1450, 20));
    init_sprite(&win->scene[COMBAT].sprite[2], "ressources/background_fight.png",
    get_pos_float(0, 0));
    init_sprite(&win->scene[COMBAT].sprite[3], "ressources/test_fight.png",
    get_pos_float(0, 0));
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite,
    get_rect(297, 56, 30, 30));
    sfSprite_setScale(win->scene[COMBAT].sprite[0].sprite,
    get_pos_float(4, 4));
    sfSprite_setScale(win->scene[COMBAT].sprite[1].sprite,
    get_pos_float(0.2, 0.2));
    win->scene[COMBAT].nb_sprite = 3;
    win->scene[COMBAT].sprite[0].depth = 1;
    win->scene[COMBAT].sprite[1].depth = 1;
    win->scene[COMBAT].sprite[2].depth = 0;
    win->scene[COMBAT].sprite[3].depth = -1;
}

window_t *init_combat(window_t *win)
{
    char *str = NULL;

    set_struct(win, 5, 2, 4);
    win->combat_clock = sfClock_create();
    init_buttons(win);
    init_sprites(win);
    str = my_strcat(my_itc(win->player->actual_health), "/");
    str = my_strcat(str, my_itc(win->player->health));
    init_text(&win->scene[COMBAT].text[0], str, get_pos_float(1500, 10));
    init_text(&win->scene[COMBAT].text[1], my_itc(win->player->strength),
    get_pos_float(1500, 100));
    init_enemy(win);
    return (win);
}