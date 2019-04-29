/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

sfVector2f get_nearest_item_pos(inventory_t *inv, sfVector2f move_pos)
{
    sfVector2f pos = {10, 10};

    for (int i = 0; i < 15; i++) {
        if (move_pos.x >= inv->items[i].pos.x - 10 &&
        move_pos.x < inv->items[i].pos.x + 80) {
            if (move_pos.y >= inv->items[i].pos.y - 10 &&
            move_pos.y < inv->items[i].pos.y + 80) {
                pos.x = inv->items[i].pos.x;
                pos.y = inv->items[i].pos.y;
                return (pos);
            }
        }
    }
    return (get_inv_pos(inv));
}

static int move_inv(window_t *win, int i)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f move_pos = get_pos_float(click_pos.x, click_pos.y);
    sfVector2f pos_item = sfSprite_getPosition(win->objects[i].sprite);
    int actual_pos = 0;
    int item = -1;

    if (move_pos.x >= pos_item.x - 10 &&
    move_pos.x < pos_item.x + 20) {
        if (move_pos.y >= pos_item.y - 10 &&
        move_pos.y < pos_item.y + 20) {
            actual_pos = get_actual_pos_inv(win->inv, move_pos);
            win->objects[i].item = 2;
            win->inv->items[actual_pos].busy = 0;
            win->inv->items[actual_pos].name = NULL;
            item = i;
        }
    }
    return (item);
}

void drag_and_drop_inv(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f move_pos = get_pos_float(click_pos.x, click_pos.y);
    int item = -1;

    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 2)
            item = i;
    }
    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 1 && win->objects[i].depth == 2)
            item = move_inv(win, i);
    }
    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 2)
            item = i;
    }
    if (item != -1)
        sfSprite_setPosition(win->objects[item].sprite, move_pos);
}

int get_actual_pos_inv(inventory_t *inv, sfVector2f move_pos)
{
    int not_busy = -1;

    for (int i = 0; i < 15; i++) {
        if (inv->items[i].busy == 0 && not_busy == -1)
            not_busy = i;
        if (move_pos.x >= inv->items[i].pos.x - 10 &&
        move_pos.x < inv->items[i].pos.x + 80) {
            if (move_pos.y >= inv->items[i].pos.y - 10 &&
            move_pos.y < inv->items[i].pos.y + 80) {
                return (i);
            }
        }
    }
    return (not_busy);
}

char *get_name_from_type(int type)
{
    if (type == SWORD)
        return ("Dague");
    if (type == ARMOR)
        return ("Armure");
    if (type == HELMET)
        return ("Casque");
    return ("\n");
}