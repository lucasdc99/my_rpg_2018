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
        win->scene[COMBAT].sprite[3].sprite, NULL);
        sfRenderWindow_drawSprite(win->window,
        win->scene[COMBAT].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        my_wait(win, 1);
    }
}

void stats_attack(window_t *win)
{
    char *str = NULL;

    if (win->turn == 1)
        return;
    sfMusic_play(win->music->heal);
    do_attack(win);
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite,
    get_rect(297, 56, 30, 30));
    win->player->actual_health += 30 + (win->player->strength / 10);
    if (win->player->actual_health > win->player->health)
        win->player->actual_health = win->player->health;
    str = my_strcat(my_itc(win->player->actual_health), "/");
    str = my_strcat(str, my_itc(win->player->health));
    sfText_setString(win->scene[COMBAT].text[0].str, str);
    win->turn = 1;
}