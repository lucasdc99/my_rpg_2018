/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** show word in array
*/

#include "../../../include/my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
