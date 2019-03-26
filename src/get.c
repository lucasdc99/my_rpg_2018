/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** get
*/

#include "../include/rpg.h"
#include "../include/my.h"

sfVector2f get_pos_float(float x, float y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfVector2i get_pos_int(int x, int y)
{
    sfVector2i vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}