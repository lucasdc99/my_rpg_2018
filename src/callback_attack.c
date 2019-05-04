/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_attack
*/

#include "../include/rpg.h"
#include "../include/my.h"

void check_life(window_t *win, int damage)
{
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite,
    get_rect(297, 56, 30, 30));
    if (win->enemy->actual_health - damage <= 0) {
        win->enemy->health = 0;
        sfText_setString(win->text->str, "\n");
        sfSprite_setPosition(win->player->sprite->sprite,
        win->player->last_pos);
        if (win->quests->combat == 3)
            win->page = END;
        else
            win->page = FINAL;
        win->states->turn = 0;
    } else {
        do_animation(win, damage);
        win->states->turn = 1;
    }
}

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
        win->scene[COMBAT].sprite[7].sprite, NULL);
        sfRenderWindow_drawSprite(win->window,
        win->scene[COMBAT].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        my_wait(win, 1);
    }
}

static void increase_health(window_t *win)
{
    char *str = NULL;

    win->player->actual_health++;
    if (win->player->actual_health > win->player->health)
        win->player->actual_health = win->player->health;
    str = my_strcat(my_itc(win->player->actual_health), "/");
    str = my_strcat(str, my_itc(win->player->health));
    sfText_setString(win->scene[COMBAT].text[0].str, str);
}

int stats_attack(window_t *win)
{
    int tmp = 0;

    if (win->states->turn == 1 || win->states->turn == 2 ||
    win->page == END || win->page == FINAL)
        return (-1);
    win->states->turn = 2;
    sfText_setString(win->text->str, "\n");
    sfMusic_play(win->music->heal);
    do_attack(win);
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite,
    get_rect(297, 56, 30, 30));
    tmp = 30 + (win->player->strength / 10);
    for (int i = 0; i < tmp; i++) {
        draw_scene(win);
        increase_health(win);
    }
    win->states->turn = 1;
    return (0);
}

void check_enemy_turn(window_t *win)
{
    if (win->states->turn == 1 && win->actual_page == COMBAT) {
        my_wait(win, 2);
        enemy_attack(win);
        win->states->turn = 0;
    }
}