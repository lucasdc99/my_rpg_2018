/*
** EPITECH PROJECT, 2018
** showstr
** File description:
** my_showstr
*/

#include "../../../include/my.h"

int my_showstr(char const *str)
{
    char *tab = malloc(sizeof(char) * my_strlen(str) + 1);

    for (int i = 0; str[i] != '\0'; i++)
        tab[i] = str[i];
    return (0);
}