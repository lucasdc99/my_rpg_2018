/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** concatenate str
*/

#include "../../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int length;
    int i;
    char *tmp;

    if (src == NULL || dest == NULL)
        return (NULL);
    length = my_strlen(dest);
    tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    for (int j = 0; j < my_strlen(dest); j++)
        tmp[j] = dest[j];
    for (i = 0; i < my_strlen(src); i++)
        tmp[length + i] = src[i];
    tmp[length + i] = '\0';
    return (tmp);
}