/*
** EPITECH PROJECT, 2018
** display_str.c
** File description:
** display_str.c
*/

#include "../../../include/my.h"

int my_putstr_printf(va_list ap)
{
    char *str = va_arg(ap, char *);

    my_putstr(str);
    return (my_strlen(str));
}

int my_putchar_printf(va_list ap)
{
    my_putchar(va_arg(ap, int));
    return (1);
}

int my_putstr_printable(va_list ap)
{
    unsigned char *str = va_arg(ap, char *);
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] > 32 && str[i] < 127) {
            my_putchar(str[i]);
        } else {
            if (str[i] < 8) {
                my_putstr("\\00");
                my_putnbr_base(str[i], "01234567");
            } else if (str[i] < 32) {
                my_putstr("\\0");
                my_putnbr_base(str[i], "01234567");
            } else {
                my_putchar('\\');
                my_putnbr_base(str[i], "01234567");
            }
        }
    }
    return (count);
}