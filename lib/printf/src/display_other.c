/*
** EPITECH PROJECT, 2018
** display other.c
** File description:
** display other.c
*/

#include "../../../include/my.h"

int my_put_pointer(va_list ap)
{
    my_putstr("0x");
    my_putnbr_baselong(va_arg(ap, long), "0123456789abcdef");
    return (0);
}

int my_put_nbr_bin(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
    return (0);
}

int my_put_percent(va_list ap)
{
    my_putchar('%');
    return (1);
}

int my_put_octal(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01234567");
    return (0);
}

int put_nothing(va_list ap)
{
    return (0);
}