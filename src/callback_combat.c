/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_combat
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void check_life(window_t *win, int damage)
{
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite,
    get_rect(297, 56, 30, 30));
    win->enemy->health -= damage;
    if (win->enemy->health <= 0) {
        sfSprite_setPosition(win->player->sprite->sprite,
        win->player->last_pos);
        win->page = FINAL;
    } else {
        sfText_setString(win->enemy->text->str, my_itc(win->enemy->health));
        win->turn = 1;
    }
}

static void do_attack(window_t *win, int type)
{
    sfIntRect rect;

    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT].sprite[0].sprite);
        if (type == 1)
            rect.top = 8;
        rect.left += 50;
        if (rect.left >= 400)
            rect.left = 297;
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

void basic_attack(window_t *win)
{
    if (win->turn == 1)
        return;
    my_wait(win, 10);
    do_attack(win, 2);
    check_life(win, 20);
}

void special_attack(window_t *win)
{
    if (win->turn == 1)
        return;
    my_wait(win, 2);
    do_attack(win, 1);
    check_life(win, 30);
}