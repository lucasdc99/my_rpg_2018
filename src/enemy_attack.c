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
        win->scene[COMBAT].sprite[7].sprite, NULL);
        sfRenderWindow_drawSprite(win->window,
        win->enemy->sprite->sprite, NULL);
        sfRenderWindow_display(win->window);
        my_wait(win, 1);
    }
}

static void do_animation_enemy(window_t *win, int damage)
{
    char *str = NULL;

    for (int i = 0; i < damage; i++) {
        draw_scene(win);
        win->player->actual_health--;
        str = my_strcat(my_itc(win->player->actual_health), "/");
        str = my_strcat(str, my_itc(win->player->health));
        sfText_setString(win->scene[COMBAT].text[0].str, str);
    }
}

static void do_regeneration(window_t *win)
{
    char *str = NULL;

    if (win->player->actual_health + 5 <= win->player->health) {
        for (int i = 0; i < win->seconds % 10; i++) {
            draw_scene(win);
            win->player->actual_health++;
            str = my_strcat(my_itc(win->player->actual_health), "/");
            str = my_strcat(str, my_itc(win->player->health));
            sfText_setString(win->scene[COMBAT].text[0].str, str);
        }
    }
}

static int check_fail(window_t *win)
{
    int tmp = 0;
    sfUint32 *unicode;

    win->move_time = sfClock_getElapsedTime(win->move);
    win->seconds = win->move_time.microseconds / 100000.0;
    if ((win->seconds % 15) != 0) {
        tmp = 20 + (win->enemy->strength / 10);
    } else {
        str_to_unicode("Rat_é", &unicode);
        sfText_setUnicodeString(win->text->str, unicode);
        sfText_setPosition(win->text->str, get_pos_float(500, 900));
    }
    return (tmp);
}

void enemy_attack(window_t *win)
{
    int tmp = 0;

    sfText_setString(win->text->str, "\n");
    my_wait(win, 10);
    sfMusic_play(win->music->enemy_attack);
    do_attack(win);
    sfSprite_setTextureRect(win->enemy->sprite->sprite,
    get_rect(297, 56, 30, 30));
    tmp = check_fail(win);
    if (win->player->actual_health - tmp <= 0) {
        win->player->health = 0;
        win->player->actual_health = 0;
        sfText_setString(win->text->str, "\n");
        win->page = END;
    } else
        do_animation_enemy(win, tmp);
    my_wait(win, 3);
    if (win->objects[ARMOR].equiped == 1)
        do_regeneration(win);
    win->turn = 0;
}