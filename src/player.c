/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player
*/

#include "../include/rpg.h"
#include "../include/my.h"

void save_config_player(window_t *win)
{
    FILE *fp = fopen("ressources/text/config_player", "wb+");

    fprintf(fp, "NAME = %s\n", win->player->name);
    fprintf(fp, "HEALTH = %d\n", win->player->health);
    fprintf(fp, "XP = %d\n", win->player->xp);
    fprintf(fp, "STRENGTH = %d\n", win->player->strength);
    fprintf(fp, "POSITION X = %f\n", win->player->last_pos.x);
    fprintf(fp, "POSITION Y = %f\n", win->player->last_pos.y);
    if (win->actual_page >= CASTLE && win->actual_page < FINAL)
        fprintf(fp, "PAGE = %d\n", win->actual_page);
    else if (win->actual_page >= FINAL)
        fprintf(fp, "PAGE = %d\n", TOWN);
    else
        fprintf(fp, "PAGE = %d\n", CASTLE);
    fclose(fp);
}