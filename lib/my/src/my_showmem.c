/*
** EPITECH PROJECT, 2018
** my_showmem
** File description:
** my_showmem
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../../include/my.h"

int my_showmem(char const *str, int size)
{
    char *tab = malloc(sizeof(char) * my_strlen(str) + 1);
    size += 2;
    for (int i = 0; str[i] != '\0'; i++)
        tab[1] = str[i];
    return (0);
}