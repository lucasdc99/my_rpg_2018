/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include <unistd.h>
#include "../../../include/my.h"

void print_nbr(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int output = 0;

    if (nb == -2147483648) {
        print_nbr();
        return (nb);
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        output = output + 1;
    }
    if (nb > 9)
        output = output + my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return (output);
}

int my_put_nbru(unsigned int nb)
{
    unsigned int output = 0;

    if (nb == -2147483648) {
        print_nbr();
        return (nb);
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
        output = output + 1;
    }
    if (nb > 9)
        output = output + my_put_nbru(nb / 10);
    my_putchar(nb % 10 + 48);
    return (output);
}