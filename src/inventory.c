/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

int check_existing_inventory(window_t *win, char *name)
{
    for (int i = 0; i < 15; i++) {
        if (win->inv->items[i].name != NULL &&
        my_strcmp(win->inv->items[i].name, name) == 0) {
            return (1);
        }
    }
    return (0);
}

void save_inventory(window_t *win)
{
    FILE *fp = fopen("ressources/text/inventory", "wb+");

    for (int i = 0; i < 15; i++) {
        if (win->inv->items[i].name == NULL)
            fprintf(fp, "(null)\n");
        else
            fprintf(fp, "%s\n", win->inv->items[i].name);
    }
    fclose(fp);
}