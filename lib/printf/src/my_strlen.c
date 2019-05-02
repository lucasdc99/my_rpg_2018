/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** length of str
*/

#include "../../../include/my.h"

int my_strlen(char const *str)
{
    int i;

    if (str == NULL)
        return (0);
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}