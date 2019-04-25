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
    init_sprite(&sprite[HELMET], "ressources/pack/rpg-pack/decorations/helmet.png", get_pos_float(500, 400));
    init_sprite(&sprite[ARMOR], "ressources/pack/rpg-pack/decorations/armor.png", get_pos_float(600, 400));
    init_sprite(&sprite[SWORD], "ressources/pack/rpg-pack/decorations/sword.png", get_pos_float(400, 400));
    for (int i = 0; i < 15; i++) {
        if (get_type_from_inv(inv->items[i].name) == SWORD) {
            sfSprite_setPosition(sprite[SWORD].sprite, inv->items[i].pos);
            sprite[SWORD].depth = 2;
        }
        if (get_type_from_inv(inv->items[i].name) == ARMOR) {
            sfSprite_setPosition(sprite[ARMOR].sprite, inv->items[i].pos);
            sprite[ARMOR].depth = 2;
        }
        if (get_type_from_inv(inv->items[i].name) == HELMET) {
            sfSprite_setPosition(sprite[HELMET].sprite, inv->items[i].pos);
            sprite[HELMET].depth = 2;
        }
    }
    sprite[HELMET].item = 1;
    sprite[ARMOR].item = 1;
    sprite[SWORD].item = 1;
    sprite[HELMET].type = HELMET;
    sprite[ARMOR].type = ARMOR;
    sprite[SWORD].type = SWORD;
    sfSprite_setScale(sprite[HELMET].sprite, get_pos_float(2, 2));
    sfSprite_setScale(sprite[ARMOR].sprite, get_pos_float(2, 2));
    sfSprite_setScale(sprite[SWORD].sprite, get_pos_float(2, 2));
}