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
    for (int i = 0; i < 15; i++) {
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
    if (my_strcmp(name, "Armure") == 0)
        return (ARMOR);
    if (my_strcmp(name, "Casque") == 0)
        return (HELMET);
    return (-1);
}

void init_inventory(inventory_t *inv)
{
    int pos_x[] = {1600, 1700, 1800};
    int pos_y[] = {255, 355, 455, 555};

    init_sprite(&inv->sprite[0], "ressources/inv.png",
    get_pos_float(1200, 150));
    for (int i = 0; i < 12; i++)
        inv->items[i].pos = get_pos_float(pos_x[i % 3], pos_y[i / 3]);
    inv->items[12].pos = get_pos_float(1260, 260);
    inv->items[13].pos = get_pos_float(1260, 380);
    inv->items[14].pos = get_pos_float(1260, 500);
    for (int i = 0; i < 15; i++) {
        inv->items[i].busy = 0;
    }
    inv->text = sfText_create();
    sfText_setPosition(inv->text, get_pos_float(1380, 465));
    sfText_setFont(inv->text,
    sfFont_createFromFile("ressources/font/berlin.ttf"));
    sfText_setCharacterSize(inv->text, 20);
    sfText_setString(inv->text, "\n");
}