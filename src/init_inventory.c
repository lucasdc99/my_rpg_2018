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
    return (-1);
}

static int set_text(inventory_t *inv, sfFont *font)
{
    for (int i = 0; i < 15; i++)
        inv->items[i].busy = 0;
    if (inv->text == NULL)
        inv->text = malloc(sizeof(text_t) * 1);
    if (inv->text == NULL)
        return (84);
    if (init_text(&inv->text[0], "\n", get_pos_float(1180, 465), font) == 84)
        return (84);
    sfText_setCharacterSize(inv->text->str, 20);
    return (0);
}

int init_inventory(inventory_t *inv, sfFont *font)
{
    int pos_x[] = {1420, 1510, 1600};
    int pos_y[] = {275, 365, 455, 550};

    if (init_sprite(&inv->sprite[0], "ressources/images/inv.png",
    get_pos_float(1000, 150)) == 84)
        return (84);
    for (int i = 0; i < 12; i++)
        inv->items[i].pos = get_pos_float(pos_x[i % 3], pos_y[i / 3]);
    inv->items[12].pos = get_pos_float(1080, 280);
    inv->items[13].pos = get_pos_float(1080, 400);
    inv->items[14].pos = get_pos_float(1080, 520);
    if (set_text(inv, font) == 84)
        return (84);
    return (0);
}