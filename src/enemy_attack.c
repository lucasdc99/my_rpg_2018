/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** enemy_attack
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void do_attack(window_t *win)
{
    sfIntRect rect;

    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->enemy->sprite->sprite);
        rect.left += 50;
        if (rect.left >= 400)
            rect.left = 297;
        sfSprite_setTextureRect(win->enemy->sprite->sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window,
        win->scene[COMBAT].sprite[1].sprite, NULL);
        sfRenderWindow_drawSprite(win->window,
        win->enemy->sprite->sprite, NULL);
        sfRenderWindow_display(win->window);
        my_wait(win, 1);
    }
}

static void enemy_attack(window_t *win)
{
    sfClock_restart(win->combat_clock);
    win->combat_time = sfClock_getElapsedTime(win->combat_clock);
    win->seconds = win->combat_time.microseconds / 1000000.0;
    while (win->seconds < 10) {
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 100000.0;
    }
    do_attack(win);
    sfSprite_setTextureRect(win->enemy->sprite->sprite,
    get_rect(297, 56, 30, 30));
    win->player->health -= 20;
    if (win->player->health <= 0) {
        win->page = END;
    } else {
        sfText_setString(win->scene[COMBAT].text[0].str,
        my_itc(win->player->health));
    }
    win->turn = 0;
}

void check_enemy_turn(window_t *win)
{
    if (win->turn == 1 && win->actual_page == COMBAT) {
        my_wait(win, 2);
        enemy_attack(win);
        win->turn = 0;
    }
}