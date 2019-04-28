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
    if (win->page >= CASTLE) {
        win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
        if (win->player->last_pos.x <= 20)
            win->player->last_pos.x = 100;
        if (win->player->last_pos.y <= 20)
            win->player->last_pos.y = 100;
        save_config_player(win);
        save_inventory(win);
        save_quests(win);
    }
    win->pause = 0;
    sfMusic_play(win->music->button_sound);
    if (sfMusic_getStatus(win->music->menu_song) == sfStopped)
        sfMusic_play(win->music->menu_song);
    win->page = MAINMENU;
}