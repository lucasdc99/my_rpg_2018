/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_town
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_sprites(window_t *win)
{
    char *name[] = {
        "ressources/town.png",
        "TimeFantasy_TILES_6.24.17/TILESETS/animated/doors.png",
        "TimeFantasy_TILES_6.24.17/TILESETS/animated/doors.png",
        "TimeFantasy_TILES_6.24.17/TILESETS/animated/doors.png",
        "TimeFantasy_TILES_6.24.17/TILESETS/animated/doors.png",
        "ressources/chars.png"};
    int pos_x[] = {0, 646, 212, 1380, 1019, 573};
    int pos_y[] = {0, 645, 645, 645, 37, 683};
    sfIntRect rect[] = {
        get_rect(32, 0, 16, 27), get_rect(32, 0, 16, 27),
        get_rect(32, 0, 16, 27), get_rect(176, 128, 16, 27)};

    for (int i = 0; i < win->scene[TOWN].nb_sprite; i++) {
        init_sprite(&win->scene[TOWN].sprite[i], name[i],
        get_pos_float(pos_x[i], pos_y[i]));
        win->scene[TOWN].sprite[i].depth = 0;
    }
    for (int i = 1; i < win->scene[TOWN].nb_sprite - 1; i++) {
        sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite,
        rect[i - 1]);
        sfSprite_setScale(win->scene[TOWN].sprite[i].sprite,
        get_pos_float(3, 3));
    }
    sfSprite_setTextureRect(win->scene[TOWN].sprite[5].sprite,
    get_rect(35, 7, 27, 41));
    sfSprite_setScale(win->scene[TOWN].sprite[5].sprite,
    get_pos_float(1.5, 1.5));
    win->scene[TOWN].sprite[0].depth = -1;
}

window_t *init_town(window_t *win)
{
    int order_button[] = {REPRENDRE, QUITTER};
    sfVector2f size = get_pos_float(400, 100);

    set_struct(win, 2, 0, 6);
    init_sprites(win);
    set_next_buttons(&win->scene[TOWN].button[0], win->rect_buttons,
    order_button[0]);
    init_button(&win->scene[TOWN].button[0], get_pos_float(-200, -200),
    size, win->texture_button);
    set_next_buttons(&win->scene[TOWN].button[1], win->rect_buttons,
    order_button[1]);
    init_button(&win->scene[TOWN].button[1], get_pos_float(-200, -200),
    size, win->texture_button);
    win->scene[TOWN].button[0].callback = &quit_pause;
    win->scene[TOWN].button[1].callback = &main_menu;
    return (win);
}