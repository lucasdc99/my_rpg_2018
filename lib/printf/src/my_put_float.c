/*
** EPITECH PROJECT, 2018
** my_put_float.c
** File description:
** my_put_float.c
*/

#include "../../../include/my.h"

void my_put_float(double f, int precision)
{
    int i;

    i = f;
    my_put_nbr(i);
    f = f - i;
    my_putchar('.');
    for (; precision > 1; precision--) {
        f = f * 10;
        i = f;
        my_put_nbr(i);
        f = f - i;
    }
    f = f * 10;
    i = f;
    my_put_nbr(i);
}