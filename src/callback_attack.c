/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_attack
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void do_attack(window_t *win)
{
    sfIntRect rect;

    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT].sprite[0].sprite);
        rect.top = 150;
        if (i == 7)
            rect.left += 50;
        sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window,
        win->scene[COMBAT].sprite[1].sprite, NULL);
        sfRenderWindow_drawSprite(win->window,
        win->scene[COMBAT].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        my_wait(win, 1);
    }
}

void stats_attack(window_t *win)
{
    if (win->turn == 1)
        return;
    do_attack(win);
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite,
    get_rect(297, 56, 30, 30));
    if ((win->player->actual_health + 30 + win->player->strength / 10) <= win->player->health)
        win->player->actual_health += 30 + (win->player->strength / 10);
    sfText_setString(win->scene[COMBAT].text[0].str,
    my_itc(win->player->actual_health));
    win->turn = 1;
}