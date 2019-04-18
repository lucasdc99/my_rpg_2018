/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

void save_inventory(window_t *win)
{
    FILE *fp = fopen("ressources/text/inventory", "wb+");

    for (int i = 0; i < 12; i++) {
        fprintf(fp, "%s\n", win->inv->items[i].name);
    }
    fclose(fp);
}