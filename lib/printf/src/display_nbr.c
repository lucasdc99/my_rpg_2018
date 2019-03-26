/*
** EPITECH PROJECT, 2018
** display_nbr.c
** File description:
** display_nbr.c
*/

#include "../../../include/my.h"

int my_put_nbr_printf(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
    return (0);
}

int my_put_nbr_hexmin(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
    return (0);
}

int my_put_nbr_hexmaj(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
    return (0);
}

int my_put_nbr_unsigned(va_list ap)
{
    my_put_nbru(va_arg(ap, int));
    return (0);
}

int my_put_nbr_float(va_list ap)
{
    my_put_float(va_arg(ap, double), 6);
    return (0);
}