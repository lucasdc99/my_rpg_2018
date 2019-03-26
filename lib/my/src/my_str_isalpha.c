/*
** EPITECH PROJECT, 2018
** my_str_is_alpha
** File description:
** my_str_is alpha
*/

#include "../../../include/my.h"

int my_str_isalpha(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (alpha(str, i) == 0))
            return (1);
        else
            return (0);
    }
    return (0);
}