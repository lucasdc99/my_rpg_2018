/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quests
*/

#include "../include/rpg.h"
#include "../include/my.h"

void save_quests(window_t *win)
{
    FILE *fp = fopen("ressources/text/quests", "wb+");

    fprintf(fp, "%d\n", win->quests->quete_done);
    fclose(fp);
}