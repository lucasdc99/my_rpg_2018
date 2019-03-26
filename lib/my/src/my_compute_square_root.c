/*
** EPITECH PROJECT, 2018
** square compute
** File description:
** find square
*/

int my_compute_square_root(int nb)
{
    long maxint = 2147483647;
    int x = nb;
    int y = 1;
    int e = 1;

    if (nb >= maxint || nb <= 0)
        return (0);
    if (nb == 1)
        return (0);
    while (x - y > e) {
        x = (x + y) / 2;
        y = nb / x;
    }
    return (x);
}
