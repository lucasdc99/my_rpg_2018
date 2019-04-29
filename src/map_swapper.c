/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map_swapper
*/

#include "../include/rpg.h"
#include "../include/my.h"

void go_forest(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->actual_page == CASTLE && win->page == CASTLE) {
        if (is_inside_zone(get_pos_float(630, 950), get_pos_float(1280, 1080),
        pos_player) == 1) {
            win->player->last_pos = pos_player;
            win->player->last_pos.y -= 30;
            sfSprite_setPosition(win->player->sprite->sprite,
            get_pos_float(pos_player.x, 50));
            win->page = FOREST;
        }
    }
}

void go_town(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->actual_page == CASTLE && win->page == CASTLE) {
        if (is_inside_zone(get_pos_float(825, 0), get_pos_float(1050, 360),
        pos_player) == 1) {
            win->player->last_pos = pos_player;
            win->player->last_pos.y += 30;
            sfSprite_setPosition(win->player->sprite->sprite,
            get_pos_float(900, 950));
            win->page = TOWN;
        }
    }
    if (win->actual_page == FINAL && win->page == FINAL) {
        if (is_inside_zone(get_pos_float(890, 950), get_pos_float(1100, 1100),
        pos_player) == 1) {
            sfSprite_setPosition(win->player->sprite->sprite,
            win->player->last_pos);
            win->page = TOWN;
        }
    }
}

void go_castle(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->actual_page == TOWN && win->page == TOWN) {
        if (is_inside_zone(get_pos_float(820, 955), get_pos_float(1050, 1080),
        pos_player) == 1) {
            win->page = CASTLE;
            sfSprite_setPosition(win->player->sprite->sprite,
            get_pos_float(900, 380));
        }
    }
    if (win->actual_page == FOREST && win->page == FOREST) {
        if (is_inside_zone(get_pos_float(630, 0), get_pos_float(1280, 20),
        pos_player) == 1) {
            win->page = CASTLE;
            sfSprite_setPosition(win->player->sprite->sprite,
            get_pos_float(900, 900));
        }
    }
}