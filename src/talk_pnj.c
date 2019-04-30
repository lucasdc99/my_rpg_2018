/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

void talk_to_old(window_t *win, sfVector2f pos_player)
{
    if (win->quests->sprite[1].depth <= 0) {
        if (is_inside_zone(get_pos_float(550, 700), get_pos_float(600, 780),
        pos_player) == 1) {
            sfText_setString(win->text->str, "Appuyez sur E\n");
            if (sfKeyboard_isKeyPressed(sfKeyE)) {
                sfText_setString(win->text->str, "\n");
                win->pause = 1;
                win->talking = 1;
                display_text_in_textbox(win->quests);
            }
        } else if (is_inside_zone(get_pos_float(700, 700),
        get_pos_float(740, 780), pos_player) == 0) {
            sfText_setString(win->text->str, "\n");
        }
    }
}