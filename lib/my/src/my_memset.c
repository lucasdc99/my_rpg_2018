/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** my_memset.c
*/

#include "../../../include/my.h"

void my_memset(char *tab, int value, int size)
{
    int indice = 0;

    while (tab && indice < size) {
        tab[indice] = value;
        indice++;
    }
}

void my_memsetdouble(double *tab, int value , int size)
{
    int indice = 0;

    while (tab && indice < size) {
        tab[indice] = value;
        indice++;
    }
}