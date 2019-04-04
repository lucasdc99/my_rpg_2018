/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** get
*/

#include "../include/rpg.h"
#include "../include/my.h"

sfIntRect get_rect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}

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