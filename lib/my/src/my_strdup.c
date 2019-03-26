/*
** EPITECH PROJECT, 2018
** mystrdup
** File description:
** Day 08 task 01
*/

#include <stdlib.h>
#include "../../../include/my.h"

char *my_strdup(char const *src)
{
    int i;
    int length = my_strlen(src);
    char *str = malloc(sizeof(char) * (length + 1));

    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
