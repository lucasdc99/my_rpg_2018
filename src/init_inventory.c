/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

sfVector2f get_inv_pos(inventory_t *inv)
{
    for (int i = 0; i < 12; i++) {
        if (inv->items[i].busy == 0) {
            return (inv->items[i].pos);
        }
    }
    return (get_pos_float(-100, -100));
}

int get_type_from_inv(char *name)
{
    if (name == NULL)
        return (-1);
    if (my_strcmp(name, "Dague") == 0)
        return (SWORD);
    if (my_strcmp(name, "Potion") == 0)
        return (POTION);
    if (my_strcmp(name, "Livre") == 0)
        return (BOOK);
    return (-1);
}

void init_inventory(inventory_t *inv)
{
    inv->items[0].pos = get_pos_float(1600, 255);
    inv->items[1].pos = get_pos_float(1700, 255);
    inv->items[2].pos = get_pos_float(1800, 255);
    inv->items[3].pos = get_pos_float(1600, 355);
    inv->items[4].pos = get_pos_float(1700, 355);
    inv->items[5].pos = get_pos_float(1800, 355);
    inv->items[6].pos = get_pos_float(1600, 455);
    inv->items[7].pos = get_pos_float(1700, 455);
    inv->items[8].pos = get_pos_float(1800, 455);
    inv->items[9].pos = get_pos_float(1600, 555);
    inv->items[10].pos = get_pos_float(1700, 555);
    inv->items[11].pos = get_pos_float(1800, 555);
    for (int i = 0; i < 12; i++)
        inv->items[i].busy = 0;
    inv->text = sfText_create();
    sfText_setPosition(inv->text, get_pos_float(1380, 465));
    sfText_setFont(inv->text, sfFont_createFromFile("ressources/font/berlin.ttf"));
    sfText_setCharacterSize(inv->text, 20);
    sfText_setString(inv->text, "\n");
}