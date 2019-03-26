/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** my_strncpy
*/

#include "../../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    if (n > my_strlen(src))
        dest[n] = '\0';
    return (dest);
}
