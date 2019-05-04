/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** talk_pnj
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void set_text(window_t *win)
{
    sfText_setString(win->text->str, "Appuyez sur E\n");
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        sfText_setString(win->text->str, "\n");
        win->states->pause = 1;
        win->states->talking = 1;
        sfText_setString(win->text->str,
        "Appuyez sur Enter pour continuer");
        display_text_in_textbox(win->quests);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfText_setString(win->text->str, "\n");
    }
}

void talk_to_old(window_t *win, sfVector2f pos_player)
{
    if (win->quests->sprite[1].depth <= 0) {
        if (is_inside_zone(get_pos_float(550, 700), get_pos_float(600, 780),
        pos_player) == 1) {
            set_text(win);
        } else if (is_inside_zone(get_pos_float(700, 700),
        get_pos_float(740, 780), pos_player) == 0) {
            sfText_setString(win->text->str, "\n");
        }
    }
}