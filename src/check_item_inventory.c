/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

int is_item_outside_inv(sfVector2f move_pos, inventory_t *inv)
{
    sfVector2f pos_inv = sfSprite_getPosition(inv->sprite->sprite);
    const sfTexture *texture = sfSprite_getTexture(inv->sprite->sprite);
    sfVector2u size_inv = sfTexture_getSize(texture);

    if (move_pos.x < pos_inv.x || move_pos.x > pos_inv.x + size_inv.x)
        return (1);
    if (move_pos.y < pos_inv.y || move_pos.y > pos_inv.y + size_inv.y)
        return (1);
    return (0);
}

void check_pickup_sword(window_t *win, sfVector2f pos_player)
{
    if (win->objects[SWORD].depth == 0) {
        if (is_inside_zone(get_pos_float(700, 700),
        get_pos_float(740, 780), pos_player) == 1) {
            sfText_setString(win->text->str, "Appuyez sur E\n");
            if (sfKeyboard_isKeyPressed(sfKeyE))
                pick_sword(win);
        } else if (is_inside_zone(get_pos_float(550, 700),
        get_pos_float(600, 780), pos_player) == 0) {
            sfText_setString(win->text->str, "\n");
        }
    }
}

void check_pickup_armor(window_t *win, sfVector2f pos_player)
{
    if (win->objects[ARMOR].depth == 0) {
        if (is_inside_zone(get_pos_float(1120, 750),
        get_pos_float(1220, 860), pos_player) == 1) {
            sfText_setString(win->text->str, "Appuyez sur E\n");
            if (sfKeyboard_isKeyPressed(sfKeyE))
                pick_armor(win);
        } else if (is_inside_zone(get_pos_float(550, 700),
        get_pos_float(600, 780), pos_player) == 0) {
            sfText_setString(win->text->str, "\n");
        }
    }
}

void check_item_pickup(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->actual_page == TOWN) {
        if (win->quests->quete_done == 0)
            talk_to_old(win, pos_player);
        if (win->quests->quete_done == 1)
            check_pickup_sword(win, pos_player);
    }
    if (win->actual_page == FOREST) {
        if (win->quests->quete_done == 2 && win->quests->sprite[1].depth <= 0)
            check_pickup_armor(win, pos_player);
    }
}