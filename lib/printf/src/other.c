/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** other.c
*/

#include "../../../include/my.h"

int float_precision(va_list ap, int precision)
{
    my_put_float(va_arg(ap, double), precision);
    return (precision + 2);
}