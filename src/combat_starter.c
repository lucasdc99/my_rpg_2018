/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** combat_starter
*/

#include "../include/rpg.h"
#include "../include/my.h"

void check_combat_zone(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->actual_page == FINAL) {
        if (is_inside_zone(get_pos_float(800, 680), get_pos_float(1200, 730),
        pos_player) == 1 && win->combat == 0)
            start_combat(win, pos_player);
        if (is_inside_zone(get_pos_float(800, 280), get_pos_float(1200, 330),
        pos_player) == 1 && win->combat == 1)
            start_combat(win, pos_player);    
    }
    if (win->actual_page == BOSS) {
        if (is_inside_zone(get_pos_float(800, 0), get_pos_float(1200, 150),
        pos_player) == 1 && win->combat == 2)
            start_combat(win, pos_player);
    }
}

void start_combat(window_t *win, sfVector2f pos_player)
{
    win->player->last_pos = pos_player;
    win->combat += 1;
    win->page = COMBAT;
}