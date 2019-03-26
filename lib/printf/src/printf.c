/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf.c
*/

#include "../../../include/my.h"

void fill_ptr_fct(void)
{
    ptr_fct[0] = &my_put_nbr_printf;
    ptr_fct[1] = &my_put_nbr_printf;
    ptr_fct[2] = &my_putstr_printf;
    ptr_fct[3] = &my_putchar_printf;
    ptr_fct[4] = &my_put_nbr_hexmin;
    ptr_fct[5] = &my_put_nbr_hexmaj;
    ptr_fct[6] = &my_put_nbr_unsigned;
    ptr_fct[7] = &my_putstr_printable;
    ptr_fct[8] = &my_put_nbr_float;
    ptr_fct[9] = &my_put_nbr_float;
    ptr_fct[10] = &my_put_nbr_float;
    ptr_fct[11] = &my_put_nbr_float;
    ptr_fct[12] = &my_put_nbr_float;
    ptr_fct[13] = &my_put_pointer;
    ptr_fct[14] = &my_put_nbr_bin;
    ptr_fct[15] = &my_put_percent;
    ptr_fct[16] = &my_put_octal;
    ptr_fct[17] = &put_nothing;
}

void fill_tab(char *flags)
{
    flags[0] = 'd';
    flags[1] = 'i';
    flags[2] = 's';
    flags[3] = 'c';
    flags[4] = 'x';
    flags[5] = 'X';
    flags[6] = 'u';
    flags[7] = 'S';
    flags[8] = 'f';
    flags[9] = 'e';
    flags[10] = 'E';
    flags[11] = 'g';
    flags[12] = 'G';
    flags[13] = 'p';
    flags[14] = 'b';
    flags[15] = '%';
    flags[16] = 'o';
    flags[17] = '\0';
}

int find_tab(char *format, int *i, va_list ap, char *flags)
{
    int count = 0;

    for (int k = 0; k < 18; k++) {
        if (format[*i + 1] == flags[k]) {
            count += ptr_fct[k](ap);
        }
    }
    return (count);
}

int find_flags(char *format, va_list ap, char *flags)
{
    int count = 0;
    int nb = 0;
    int j = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            if (format[i + 1] == '.') {
                nb = (format[i + 2] - 48);
                count += float_precision(ap, nb);
                return (find_flags(&format[i + 4], ap, flags));
            }
            count += find_tab(format, &i, ap, flags);
            i++;
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    return (count);
}

int my_printf(char *format, ...)
{
    va_list ap;
    char flags[19];
    int count = 0;

    va_start(ap, format);
    fill_tab(flags);
    fill_ptr_fct();
    count = find_flags(format, ap, flags);
    va_end(ap);
    return (count);
}