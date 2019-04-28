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