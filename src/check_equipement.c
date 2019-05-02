/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_equipement
*/

#include "../include/rpg.h"
#include "../include/my.h"

void check_equip_stuff(window_t *win, int actual_pos)
{
    int type = -1;

    type = my_strcmp(win->inv->items[actual_pos].name, "Dague");
    if (actual_pos >= 12 && type == 0) {
        if (win->objects[SWORD].equiped == 0) {
            win->player->strength += 20;
            win->objects[SWORD].equiped = 1;
        }
    }
    type = my_strcmp(win->inv->items[actual_pos].name, "Armure");
    if (actual_pos >= 12 && type == 0) {
        if (win->objects[ARMOR].equiped == 0) {
            win->player->health += 20;
            win->player->actual_health += 20;
            win->objects[ARMOR].equiped = 1;
        }
    }
}

void check_desequip_stuff(window_t *win, int actual_pos)
{
    int type = -1;

    type = my_strcmp(win->inv->items[actual_pos].name, "Dague");
    if (actual_pos < 12 && type == 0) {
        if (win->objects[SWORD].equiped == 1) {
            win->player->strength -= 20;
            win->objects[SWORD].equiped = 0;
        }
    }
    type = my_strcmp(win->inv->items[actual_pos].name, "Armure");
    if (actual_pos < 12 && type == 0) {
        if (win->objects[ARMOR].equiped == 1) {
            win->player->health -= 20;
            win->player->actual_health -= 20;
            win->objects[ARMOR].equiped = 0;
        }
    }
}