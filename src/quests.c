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

    fwrite(my_itc(win->quests->quete_done), sizeof(char),
    my_strlen(my_itc(win->quests->quete_done)), fp);
    fwrite("\n", sizeof(char), 1, fp);
    fwrite(my_itc(win->quests->combat), sizeof(char),
    my_strlen(my_itc(win->quests->combat)), fp);
    fwrite("\n", sizeof(char), 1, fp);
    fclose(fp);
}