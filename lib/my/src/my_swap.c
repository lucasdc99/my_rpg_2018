/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}