/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_heroes
*/

#include "../include/rpg.h"
#include "../include/my.h"

int init_buttons_other(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_win = sfRenderWindow_getSize(win->window);
    sfVector2f pos_win;

    pos_win.x = (size_win.x - size.x - 10);
    pos_win.y = (size_win.y - (size.y + 50) * 2);
    set_next_buttons(&win->scene[HEROES].button[2], win->rect_buttons, JOUER);
    if (init_button(&win->scene[HEROES].button[2], pos_win, size,
    win->texture_button) == 84)
        return (84);
    pos_win.y += size.y + 10;
    set_next_buttons(&win->scene[HEROES].button[3], win->rect_buttons, QUITTER);
    if (init_button(&win->scene[HEROES].button[3], pos_win, size,
    win->texture_button) == 84)
        return (84);
    win->scene[HEROES].button[0].callback = &choose_hero;
    win->scene[HEROES].button[1].callback = &choose_hero_reverse;
    win->scene[HEROES].button[2].callback = &play_game;
    win->scene[HEROES].button[3].callback = &main_menu;
    return (0);
}

int choose_hero(window_t *win)
{
    win->player->hero++;
    if (win->player->hero >= 5)
        win->player->hero = 0;
    if (win->player->hero == 0) {
        if (choose_hex(win) == 84)
            return (84);
    }
    if (win->player->hero == 1)
        choose_linail(win);
    if (win->player->hero == 2)
        choose_ouzo(win);
    if (win->player->hero == 3)
        choose_prime(win);
    if (win->player->hero == 4)
        choose_wyvera(win);
    return (0);
}

int choose_hero_reverse(window_t *win)
{
    win->player->hero--;
    if (win->player->hero < 0)
        win->player->hero = 4;
    if (win->player->hero == 0)
        choose_hex(win);
    if (win->player->hero == 1)
        choose_linail(win);
    if (win->player->hero == 2)
        choose_ouzo(win);
    if (win->player->hero == 3)
        choose_prime(win);
    if (win->player->hero == 4)
        choose_wyvera(win);
    return (0);
}