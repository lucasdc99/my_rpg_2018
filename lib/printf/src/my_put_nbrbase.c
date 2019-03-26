/*
** EPITECH PROJECT, 2018
** put_nbr_base
** File description:
** put_nbr_base
*/

#include "../../../include/my.h"

int my_putnbr_base(int nbr, char *base)
{
    int len_base;

    len_base = my_strlen(base);
    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    }
    if (nbr == 0)
        return (0);
    else
        my_putnbr_base(nbr / len_base, base);
    my_putchar(base[nbr % len_base]);
    return (0);
}

long my_putnbr_baselong(long nbr, char *base)
{
    int len_base;

    len_base = my_strlen(base);
    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    }
    if (nbr == 0)
        return (0);
    else
        my_putnbr_baselong(nbr / len_base, base);
    my_putchar(base[nbr % len_base]);
    return (0);
}