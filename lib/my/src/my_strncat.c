/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** my_strncat
*/

#include "../../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int length = my_strlen(dest);
    int i;

    for (i = 0; i < my_strlen(src) && i < nb; i++)
        dest[length + i] = src[i];
    dest[length + i] = '\0';
    return (dest);
}