/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** my_revstr
*/

#include "../../../include/my.h"

char *my_revstr(char *str)
{
    int i;
    int end;
    char stock;

    i = 0;
    end = my_length(str) - 1;
    while (i < (my_strlen(str) / 2)) {
        stock = str[i];
        str[i] = str[end];
        str[end] = stock;
        i = i + 1;
        end = end - 1;
    }
    return (str);
}