/*
** EPITECH PROJECT, 2018
** compute_power_rec
** File description:
** power rec
*/

int my_compute_power_rec(int nb, int p)
{
    int result = 0;

    if ((nb >= 2 && p >= 31) || p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    else
        result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}