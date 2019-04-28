/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

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