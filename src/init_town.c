/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_town
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void set_sprites(window_t *win)
{
    sfIntRect rect[] = {
        get_rect(32, 0, 16, 27), get_rect(32, 0, 16, 27),
        get_rect(32, 0, 16, 27), get_rect(176, 128, 16, 27)};

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

static int init_sprites(window_t *win)
{
    char *name[] = {
        "ressources/images/town.png",
        "ressources/images/doors.png",
        "ressources/images/doors.png",
        "ressources/images/doors.png",
        "ressources/images/doors.png",
        "ressources/images/chars.png"};
    int pos_x[] = {0, 646, 212, 1380, 1019, 573};
    int pos_y[] = {0, 645, 645, 645, 37, 683};

    for (int i = 0; i < win->scene[TOWN].nb_sprite; i++) {
        if (init_sprite(&win->scene[TOWN].sprite[i], name[i],
        get_pos_float(pos_x[i], pos_y[i])) == 84)
            return (84);
        win->scene[TOWN].sprite[i].depth = 0;
    }
    set_sprites(win);
    return (0);
}

window_t *init_town(window_t *win)
{
    int order_button[] = {REPRENDRE, QUITTER};
    sfVector2f size = get_pos_float(400, 100);

    if (set_struct(win, 2, 0, 6) == 84)
        return (NULL);
    if (init_sprites(win) == 84)
        return (NULL);
    set_next_buttons(&win->scene[TOWN].button[0], win->rect_buttons,
    order_button[0]);
    if (init_button(&win->scene[TOWN].button[0], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (NULL);
    set_next_buttons(&win->scene[TOWN].button[1], win->rect_buttons,
    order_button[1]);
    if (init_button(&win->scene[TOWN].button[1], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (NULL);
    win->scene[TOWN].button[0].callback = &quit_pause;
    win->scene[TOWN].button[1].callback = &main_menu;
    if (sfMusic_getStatus(win->music->boss_song) == sfPlaying)
        sfMusic_stop(win->music->boss_song);
    if (sfMusic_getStatus(win->music->town_song) == sfStopped)
        sfMusic_play(win->music->town_song);
    return (win);
}