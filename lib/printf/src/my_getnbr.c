/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** get nbr
*/

void my_putchar(char c);

int my_strlen2(char const *str)
{
    int incr = 0;

    while (str[incr] == '-' || str[incr] == '+')
        incr++;
    while (str[incr] != 0 && str[incr] >= 48 && str[incr] <= 57)
        incr++;
    return (incr);
}

int my_power_it(int nb, int power)
{
    int begin = 0;
    int rendu = 1;

    if (power >= 0) {
        while (begin < power) {
            begin++;
            rendu *= nb;
        }
        return (rendu);
    }
    else
        return (0);
}

int calc_rendu(int incr, int lenght, char const *str)
{
    int rendu;

    rendu = 0;
    while (str[incr] != 0 && str[incr] >= 48 && str[incr] <= 57) {
        rendu += (str[incr] - 48) * my_power_it(10, lenght);
        lenght--;
        incr++;
    }
    return (rendu);
}

int overflow(char const *str)
{
    char cmp1[] = "2147483647";
    char cmp2[] = "2147483648";
    int incr;
    int incr2;

    incr = 0;
    incr2 = 0;
    if (my_strlen2(str) < my_strlen2(cmp1))
        return (1);
    if (str[0] != '-') {
        while (cmp1[incr] != 0 && str[incr] != 0 && cmp1[incr] == str[incr])
            incr++;
        return (cmp1[incr] - str[incr]);
    } else {
        incr2++;
        while (cmp2[incr] != 0 && str[incr2] != 0 && cmp2[incr] == str[incr2]) {
            incr++;
            incr2++;
        }
        return (cmp2[incr] - str[incr2]);
    }
}

int my_getnbr(char const *str)
{
    int incr = overflow(str);
    int rendu;
    int lenght = my_strlen2(str) - 1;
    int neg = 0;

    if (incr < 0)
        return (0);
    incr = 0;
    while (str[incr] == '-' || str[incr] == '+') {
        if (str[incr] == '-')
            neg++;
        incr++;
    }
    lenght -= incr;
    rendu = calc_rendu(incr, lenght, str);
    if (neg % 2 == 1)
        rendu = -rendu;
    return (rendu);
}