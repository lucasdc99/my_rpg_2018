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
    char *str = NULL;

    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite,
    get_rect(297, 56, 30, 30));
    if (win->enemy->actual_health - damage <= 0) {
        win->enemy->health = 0;
        sfSprite_setPosition(win->player->sprite->sprite,
        win->player->last_pos);
        if (win->quests->combat == 3)
            win->page = END;
        else
            win->page = FINAL;
    } else {
        for (int i = 0; i < damage; i++) {
            draw_scene(win);
            win->enemy->actual_health--;
            str = my_strcat(my_itc(win->enemy->actual_health), "/");
            str = my_strcat(str, my_itc(win->enemy->health));
            sfText_setString(win->enemy->text->str, str);
        }
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
        win->scene[COMBAT].sprite[6].sprite, NULL);
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
    sfText_setString(win->text->str, "\n");    
    my_wait(win, 10);
    sfMusic_play(win->music->basic_attack);
    do_attack(win, 2);
    check_life(win, 20 + (win->player->strength / 10));
}

void special_attack(window_t *win)
{
    char *str = NULL;
    int tmp = 0;

    if (win->turn == 1)
        return;
    sfText_setString(win->text->str, "\n");
    my_wait(win, 2);
    sfMusic_play(win->music->special_attack);
    do_attack(win, 1);
    tmp = win->player->strength / 10;
    for (int i = 0; i < tmp; i++) {
        draw_scene(win);
        win->player->health--;
        if (win->player->health < win->player->actual_health)
            win->player->actual_health = win->player->health;
        str = my_strcat(my_itc(win->player->actual_health), "/");
        str = my_strcat(str, my_itc(win->player->health));
        sfText_setString(win->scene[COMBAT].text[0].str, str);
    }
    check_life(win, 30 + (win->player->strength / 10));
}