/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_end
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int disp_win_or_lose(window_t *win)
{
    if (win->player->health <= 0) {
        win->scene[END].sprite[0].rect = get_rect(0, 0, 881, 1080);
        if (init_sprite(&win->scene[END].sprite[0],
        "ressources/images/lose.png", get_pos_float(519, 0)) == 84)
            return (84);
        if (init_text(&win->scene[END].text[0], "Mort",
        get_pos_float(905, 20), win->font_berlin) == 84)
            return (84);
    } else {
        win->scene[END].sprite[0].rect = get_rect(0, 0, 1428, 1080);
        if (init_sprite(&win->scene[END].sprite[0],
        "ressources/images/victory.png", get_pos_float(252, 0)) == 84)
            return (84);
        if (init_text(&win->scene[END].text[0], "Victoire",
        get_pos_float(880, 20), win->font_berlin) == 84)
            return (84);
    }
    return (0);
}

static int init_end_button(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    set_next_buttons(&win->scene[END].button[0], win->rect_buttons, QUITTER);
    if (init_button(&win->scene[END].button[0], get_pos_float(1510, 900), size,
    win->texture_button) == 84)
        return (84);
    win->scene[END].button[0].callback = &main_menu;
    if (sfMusic_getStatus(win->music->boss_battle) == sfPlaying)
        sfMusic_stop(win->music->boss_battle);
    return (0);
}

window_t *init_end(window_t *win)
{
    int rest = 0;
    char *str = NULL;

    if (set_struct(win, 1, 2, 1) == 84)
        return (NULL);
    if (disp_win_or_lose(win) == 84)
        return (NULL);
    win->move_time = sfClock_getElapsedTime(win->move);
    win->seconds = win->move_time.microseconds / 1000000;
    if (win->seconds > 60) {
        rest = win->seconds % 60;
        win->seconds /= 60;
    }
    str = my_strcat(my_itc(win->seconds), "min");
    str = my_strcat(str, my_itc(rest));
    str = my_strcat(str, "sec");
    if (init_text(&win->scene[END].text[1], str,
    get_pos_float(890, 200), win->font_berlin) == 84)
        return (NULL);
    win->no_saves = 1;
    if (init_end_button(win) == 84)
        return (NULL);
    return (win);
}