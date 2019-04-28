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

    if (pos_player.x > 630 && pos_player.x < 1280) {
        if (pos_player.y > 950) {
            win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
            win->player->last_pos.y -= 30;
            sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(pos_player.x, 50));
            win->page = FOREST;
        }
    }
}

void go_town(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (pos_player.x > 825 && pos_player.x < 1050) {
        if (pos_player.y < 360) {
            win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
            win->player->last_pos.y += 30;
            sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(900, 950));
            win->page = TOWN;
        }
    }
}

void go_boss(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (pos_player.x > 910 && pos_player.x < 1000) {
        if (pos_player.y < 100) {
            win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
            win->player->last_pos.y += 30;
            sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(900, 950));
            win->page = BOSS;
        }
    }
}

void go_final(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);
    sfIntRect rect;
    sfVector2f pos_door;

    rect = sfSprite_getTextureRect(win->scene[TOWN].sprite[4].sprite);
    pos_door = sfSprite_getPosition(win->scene[TOWN].sprite[4].sprite);
    if (pos_player.x >= pos_door.x - 20 && pos_player.x <= pos_door.x + 40) {
        if (pos_player.y >= pos_door.y && pos_player.y <= pos_door.y + 100) {
            rect.top = 192;
            sfSprite_setTextureRect(win->scene[TOWN].sprite[4].sprite, rect);
        } else {
            if (rect.top >= 64) {
                rect.top = 128;
                sfSprite_setTextureRect(win->scene[TOWN].sprite[4].sprite, rect);
            }
        }
        if (pos_player.y >= pos_door.y - 50 && pos_player.y <= pos_door.y + 20 && win->player->direction == UP) {
            win->player->last_pos = get_pos_float(1025, 150);
            sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(950, 900));
            win->page = FINAL;
        }
    } else {
        if (rect.top >= 64) {
            rect.top = 128;
            sfSprite_setTextureRect(win->scene[TOWN].sprite[4].sprite, rect);
        }
    }
}

void leave_boss(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (is_inside_zone(get_pos_float(890, 950), get_pos_float(1100, 1100), pos_player) == 1) {
        sfSprite_setPosition(win->player->sprite->sprite, win->player->last_pos);
        win->page = FINAL;
    }
}

void go_castle(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->actual_page == TOWN) {
        if (pos_player.x >= 820 && pos_player.x < 1050) {
            if (pos_player.y >= 955) {
                win->page = CASTLE;
                sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(900, 380));
            }
        }
    }
    if (win->actual_page == FOREST) {
        if (pos_player.x >= 630 && pos_player.x < 1280) {
            if (pos_player.y <= 20) {
                win->page = CASTLE;
                sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(900, 900));
            }
        }
    }
}

void leave_final(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (is_inside_zone(get_pos_float(890, 950), get_pos_float(1100, 1100), pos_player) == 1) {
        sfSprite_setPosition(win->player->sprite->sprite, win->player->last_pos);
        win->page = TOWN;
    }
}
