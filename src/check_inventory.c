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
        if (move_pos.x >= inv->items[i].pos.x - 10 && move_pos.x <
                inv->items[i].pos.x + 80) {
            if (move_pos.y >= inv->items[i].pos.y - 10 && move_pos.y <
                    inv->items[i].pos.y + 80) {
                pos.x = inv->items[i].pos.x;
                pos.y = inv->items[i].pos.y;
                return (pos);
            }
        }
    }
    return (get_inv_pos(inv));
}

void check_drag_and_drop_inv(window_t *win)
{
    sfVector2i click_pos;
    sfVector2f move_pos;
    sfVector2f pos;
    int actual_pos = 0;

    for (int i = 0; i < win->nb_objects; i++) {
        click_pos = sfMouse_getPositionRenderWindow(win->window);
        move_pos = get_pos_float(click_pos.x, click_pos.y);
        if (win->objects[i].item == 2 && win->objects[i].depth == 2) {
            sfSprite_setPosition(win->objects[i].sprite, get_inv_pos(win->inv));
            actual_pos = get_actual_pos_inv(win->inv, move_pos);
            win->inv->items[actual_pos].name = get_name_from_type(win->objects[i].type);
            if (actual_pos >= 12 && my_strcmp(win->inv->items[actual_pos].name, "Dague") == 0) {
                win->player->strength += 20;
            }
            win->objects[i].item = 1;
            if (is_item_outside_inv(move_pos, win->inv) == 0) {
                pos = get_nearest_item_pos(win->inv, move_pos);
                if (win->inv->items[actual_pos].busy == 0)
                    sfSprite_setPosition(win->objects[i].sprite, pos);
                else
                    sfSprite_setPosition(win->objects[i].sprite, get_inv_pos(win->inv));
                win->inv->items[actual_pos].busy = 1;
            } else {
                sfSprite_setPosition(win->objects[i].sprite, sfSprite_getPosition(win->player->sprite->sprite));
                win->objects[i].depth = 0;
                win->inv->items[actual_pos].name = NULL;
                save_inventory(win);
            }
        }
    }
}

void drag_and_drop_inv(window_t *win)
{
    sfVector2i click_pos;
    sfVector2f move_pos;
    sfVector2f pos_item;
    int actual_pos = 0;
    int item = -1;

    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 2)
            item = i;
    }
    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 1 && win->objects[i].depth == 2) {
            click_pos = sfMouse_getPositionRenderWindow(win->window);
            move_pos = get_pos_float(click_pos.x, click_pos.y);
            pos_item = sfSprite_getPosition(win->objects[i].sprite);
            if (move_pos.x >= pos_item.x - 10 && move_pos.x < pos_item.x + 20) {
                if (move_pos.y >= pos_item.y - 10 && move_pos.y < pos_item.y + 20) {
                    actual_pos = get_actual_pos_inv(win->inv, move_pos);
                    win->objects[i].item = 2;
                    win->inv->items[actual_pos].busy = 0;
                    win->inv->items[actual_pos].name = NULL;
                    item = i;
                }
            }
        }
    }
    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 2)
            item = i;
    }
    click_pos = sfMouse_getPositionRenderWindow(win->window);
    move_pos = get_pos_float(click_pos.x, click_pos.y);
    if (item != -1)
        sfSprite_setPosition(win->objects[item].sprite, move_pos);
}

int get_actual_pos_inv(inventory_t *inv, sfVector2f move_pos)
{
    int not_busy = -1;

    for (int i = 0; i < 15; i++) {
        if (inv->items[i].busy == 0 && not_busy == -1)
            not_busy = i;
        if (move_pos.x >= inv->items[i].pos.x - 10 && move_pos.x <
                inv->items[i].pos.x + 80) {
            if (move_pos.y >= inv->items[i].pos.y - 10 && move_pos.y <
                    inv->items[i].pos.y + 80) {
                return (i);
            }
        }
    }
    printf("%d\n", not_busy);
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