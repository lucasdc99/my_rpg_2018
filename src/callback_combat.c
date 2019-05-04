/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_combat
*/

#include "../include/rpg.h"
#include "../include/my.h"

void do_animation(window_t *win, int damage)
{
    char *str = NULL;

    for (int i = 0; i < damage; i++) {
        draw_scene(win);
        win->enemy->actual_health--;
        str = my_strcat(my_itc(win->enemy->actual_health), "/");
        str = my_strcat(str, my_itc(win->enemy->health));
        sfText_setString(win->enemy->text->str, str);
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
        win->scene[COMBAT].sprite[7].sprite, NULL);
        sfRenderWindow_drawSprite(win->window,
        win->scene[COMBAT].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        my_wait(win, 1);
    }
}

int basic_attack(window_t *win)
{
    if (win->states->turn == 1 || win->states->turn == 2 ||
    win->page == END || win->page == FINAL)
        return (-1);
    win->states->turn = 2;
    sfText_setString(win->text->str, "Attaque Basique\n");
    sfMusic_play(win->music->basic_attack);
    do_attack(win, 2);
    check_life(win, 20 + (win->player->strength / 10));
    return (0);
}

static void decrease_life(window_t *win, int tmp)
{
    char *str = NULL;

    for (int i = 0; i < tmp; i++) {
        draw_scene(win);
        win->player->health--;
        if (win->player->health < win->player->actual_health)
            win->player->actual_health = win->player->health;
        str = my_strcat(my_itc(win->player->actual_health), "/");
        str = my_strcat(str, my_itc(win->player->health));
        sfText_setString(win->scene[COMBAT].text[0].str, str);
    }
}

int special_attack(window_t *win)
{
    int tmp = 0;

    if (win->states->turn == 1 || win->states->turn == 2 ||
    win->page == END || win->page == FINAL)
        return (-1);
    win->states->turn = 2;
    sfText_setString(win->text->str, "Attaque Speciale\n");
    sfMusic_play(win->music->special_attack);
    do_attack(win, 1);
    tmp = win->player->strength / 10;
    decrease_life(win, tmp);
    check_life(win, 30 + (win->player->strength / 10));
    return (0);
}