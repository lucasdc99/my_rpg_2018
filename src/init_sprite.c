/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_sprite
*/

#include "../include/rpg.h"
#include "../include/my.h"

int init_sprite(sprite_t *sprite, char *filename, sfVector2f position)
{
    if (sprite == NULL || filename == NULL)
        return (84);
    sprite->sprite = sfSprite_create();
    if (sprite->sprite == NULL)
        return (84);
    sprite->texture = sfTexture_createFromFile(filename, NULL);
    if (sprite->texture == NULL)
        return (84);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->pos = position;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sprite->depth = 0;
    sprite->item = 0;
    return (0);
}