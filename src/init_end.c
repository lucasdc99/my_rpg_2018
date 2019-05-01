/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_end
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_end(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);

    set_struct(win, 1, 1, 1);
    init_sprite(&win->scene[END].sprite[0], "ressources/victory.png", get_pos_float(252, 0));
    win->scene[END].sprite[0].rect = get_rect(0, 0, 1428, 1080);
    if (win->player->health <= 0) {
        init_text(&win->scene[END].text[0], "Vous etes morts en fait",
        get_pos_float(900, 700));
    } else
        init_text(&win->scene[END].text[0], "GG", get_pos_float(900, 700));
    win->no_saves = 1;
    set_next_buttons(&win->scene[END].button[0], win->rect_buttons, QUITTER);
    init_button(&win->scene[END].button[0], get_pos_float(900, 900), size,
    win->texture_button);
    win->scene[END].button[0].callback = &main_menu;
    if (sfMusic_getStatus(win->music->boss_battle) == sfPlaying)
        sfMusic_stop(win->music->boss_battle);
    return (win);
}