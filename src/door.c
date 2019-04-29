/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** door
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void get_inside_house(window_t *win, sfVector2f pos_door, int i)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (pos_player.y >= pos_door.y - 50 &&
    pos_player.y <= pos_door.y + 20 && win->player->direction == UP) {
        win->player->last_pos = pos_player;
        win->player->last_pos.y += 50;
        pos_player.y -= 50;
        sfSprite_setPosition(win->player->sprite->sprite,
        get_pos_float(880, 730));
        if (i == 1)
            win->page = HOUSE1;
        if (i == 2)
            win->page = HOUSE2;
        if (i == 3)
            win->page = HOUSE3;
    }
}

void open_door(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);
    sfIntRect rect;
    sfVector2f pos_door;

    if (win->quests->quete_done == 3)
        go_final(win);
    for (int i = 1; i < 4; i++) {
        rect = sfSprite_getTextureRect(win->scene[TOWN].sprite[i].sprite);
        pos_door = sfSprite_getPosition(win->scene[TOWN].sprite[i].sprite);
        if (is_inside_zone(get_pos_float(pos_door.x - 20, pos_door.y),
        get_pos_float(pos_door.x + 40, pos_door.y + 100), pos_player) == 1) {
            rect.top = 64;
            sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite, rect);
            get_inside_house(win, pos_door, i);
        } else if (rect.top >= 64) {
            rect.top = 0;
            sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite,
            rect);
        }
    }
}

void close_door(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (is_inside_zone(get_pos_float(880, 750), get_pos_float(935, 850),
    pos_player) == 1) {
        sfSprite_setPosition(win->player->sprite->sprite,
        win->player->last_pos);
        win->page = TOWN;
    }
}