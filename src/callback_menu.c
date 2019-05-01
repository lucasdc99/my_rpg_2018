/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_menu
*/

#include "../include/rpg.h"
#include "../include/my.h"

void main_menu(window_t *win)
{
    sfVector2f pos;
    int tmp = 0;

    if (win->page >= CASTLE) {
        pos = sfSprite_getPosition(win->player->sprite->sprite);
        win->player->last_pos = pos;
        if (win->player->last_pos.x <= 20)
            win->player->last_pos.x = 100;
        if (win->player->last_pos.y <= 20)
            win->player->last_pos.y = 100;
        if (win->actual_page >= FINAL) {
            win->player->last_pos.x = 1020.0;
            win->player->last_pos.y = 200.0;
        }
        save_config_player(win);
        save_inventory(win);
        save_quests(win);
        tmp = win->quests->quete_done;
        win->quests->quete_done = 15;
        display_text_in_textbox(win->quests);
        win->quests->sprite[1].depth = -1;
        win->quests->quete_done = tmp;
    }
    win->pause = 0;
    sfMusic_play(win->music->button_sound);
    if (sfMusic_getStatus(win->music->menu_song) == sfStopped)
        sfMusic_play(win->music->menu_song);
    if (sfMusic_getStatus(win->music->town_song) == sfPlaying)
        sfMusic_stop(win->music->town_song);
    if (sfMusic_getStatus(win->music->boss_final) == sfPlaying)
        sfMusic_stop(win->music->boss_final);
    win->page = MAINMENU;
}