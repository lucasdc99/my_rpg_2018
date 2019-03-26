/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** my_free.c
*/

#include "../../../include/my.h"

void my_free2d(char **buffer, int cols)
{
    for (int i = 0; i < cols; i++)
        free(buffer[i]);
    free(buffer);
}

void my_free2d_short(short **buffer, int cols)
{
    for (int i = 0; i < cols; i++)
        free(buffer[i]);
    free(buffer);
}