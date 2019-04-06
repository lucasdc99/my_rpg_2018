/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_sprite
*/

#include "../include/rpg.h"
#include "../include/my.h"

void init_sprite(sprite_t *sprite, char *filename, sfVector2f position)
{
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->pos = position;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
}