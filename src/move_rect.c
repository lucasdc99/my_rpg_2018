/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_rect
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int do_first_part(window_t *win, int *i, int part)
{
    if (i[0] < 255 && part == 0) {
        sfText_setFillColor(win->scene[CASTLE].text[0].str,
        sfColor_fromRGBA(255, 255, 255, ++i[0]));
    } else
        part = 1;
    if (i[0] > 0 && part == 1) {
        sfText_setFillColor(win->scene[CASTLE].text[0].str,
        sfColor_fromRGBA(255, 255, 255, --i[0]));
    } else if (part != 0)
        part = 2;
    return (part);
}

void animation_begin(window_t *win)
{
    static int i = 0;
    static int part = 0;

    if (part < 2) {
        part = do_first_part(win, &i, part);
    } else if (part == 2) {
        win->states->no_saves = 0;
        sfText_setString(win->text->str, "Appuyez sur O\n");
        sfText_setPosition(win->text->str, get_pos_float(10, 950));
        part = 3;
    }
    if (part == 3 && win->states->no_saves == 1) {
        part = 0;
        i = 0;
    }
}

void animation_torch(window_t *win, int offset)
{
    int top = offset * (win->states->seconds % 4);

    win->scene[CASTLE].sprite[5].rect.top = top;
    win->scene[CASTLE].sprite[6].rect.top = top;
    sfSprite_setTextureRect(win->scene[CASTLE].sprite[5].sprite,
    win->scene[CASTLE].sprite[5].rect);
    sfSprite_setTextureRect(win->scene[CASTLE].sprite[6].sprite,
    win->scene[CASTLE].sprite[6].rect);
}

void animation_end(window_t *win)
{
    int left = 0;

    if (win->actual_page == END) {
        win->move_time = sfClock_getElapsedTime(win->move);
        win->states->seconds = win->move_time.microseconds / 150000.0;
        if (win->player->health > 0) {
            left = 1416 * (win->states->seconds % 10);
            win->scene[END].sprite[0].rect.left = left;
        } else {
            left = 881 * (win->states->seconds % 12);
            win->scene[END].sprite[0].rect.left = left;
        }
        sfSprite_setTextureRect(win->scene[END].sprite[0].sprite,
        win->scene[END].sprite[0].rect);
    }
}

void animation_choose_heroes(window_t *win)
{
    int left = 0;

    if (win->actual_page == HEROES) {
        win->move_time = sfClock_getElapsedTime(win->move);
        win->states->seconds = win->move_time.microseconds / 1000000.0;
        left = 48 * (win->states->seconds % 2);
        win->scene[HEROES].sprite[0].rect.left = left;
        sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite,
        win->scene[HEROES].sprite[0].rect);
    }
}