/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_objects
*/

#include "../include/rpg.h"
#include "../include/my.h"

void init_objects(sprite_t *sprite, inventory_t *inv)
{
    init_sprite(&sprite[BOOK], "ressources/pack/rpg-pack/decorations/generic-rpg-loot02.png", get_pos_float(500, 400));
    init_sprite(&sprite[POTION], "ressources/pack/rpg-pack/decorations/generic-rpg-loot03.png", get_pos_float(600, 400));
    init_sprite(&sprite[SWORD], "ressources/pack/rpg-pack/decorations/sword.png", get_pos_float(400, 400));
    for (int i = 0; i < 12; i++) {
        if (get_type_from_inv(inv->items[i].name) == SWORD) {
            sfSprite_setPosition(sprite[SWORD].sprite, inv->items[i].pos);
            sprite[SWORD].depth = 2;
        }
        if (get_type_from_inv(inv->items[i].name) == POTION) {
            sfSprite_setPosition(sprite[POTION].sprite, inv->items[i].pos);
            sprite[POTION].depth = 2;
        }
        if (get_type_from_inv(inv->items[i].name) == BOOK) {
            sfSprite_setPosition(sprite[BOOK].sprite, inv->items[i].pos);
            sprite[BOOK].depth = 2;
        }
    }
    sprite[BOOK].item = 1;
    sprite[POTION].item = 1;
    sprite[SWORD].item = 1;
    sprite[BOOK].type = BOOK;
    sprite[POTION].type = POTION;
    sprite[SWORD].type = SWORD;
    sfSprite_setScale(sprite[BOOK].sprite, get_pos_float(2, 2));
    sfSprite_setScale(sprite[POTION].sprite, get_pos_float(2, 2));
    sfSprite_setScale(sprite[SWORD].sprite, get_pos_float(2, 2));
}