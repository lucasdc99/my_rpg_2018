/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

void close_textbox(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->quests->sprite[1].depth >= 1) {
        if (is_inside_zone(get_pos_float(550, 700), get_pos_float(600, 780),
                pos_player) == 0 && is_inside_zone(get_pos_float(700, 700),
                        get_pos_float(740, 780), pos_player) == 0 &&
                        is_inside_zone(get_pos_float(1120, 750),
                                get_pos_float(1210, 800), pos_player) == 0) {
            win->quests->sprite[1].depth = -1;
            sfText_setString(win->text->str, "\n");
        }
    }
}

void talk_to_old(window_t *win, sfVector2f pos_player)
{
    if (win->quests->sprite[1].depth <= 0) {
        if (is_inside_zone(get_pos_float(550, 700), get_pos_float(600, 780),
                pos_player) == 1) {
            sfText_setString(win->text->str, "Appuyez sur E\n");
            if (sfKeyboard_isKeyPressed(sfKeyE)) {
                sfText_setString(win->text->str, "\n");
                display_text_in_textbox(win->quests, "Bonjour\n");
                win->quests->quete_done++;
            }
        } else if (is_inside_zone(get_pos_float(700, 700),
                get_pos_float(740, 780), pos_player) == 0) {
            sfText_setString(win->text->str, "\n");
        }
    }
}