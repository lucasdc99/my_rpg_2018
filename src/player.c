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
    char *str = NULL;

    str = my_strcat("NAME = ", win->player->name);
    if (str == NULL)
        fwrite("Name = ", sizeof(char), 7, fp);
    else
        fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    str = my_strcat("HEALTH = ", my_itc(win->player->health));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    str = my_strcat("ACTUAL HEALTH = ", my_itc(win->player->actual_health));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    str = my_strcat("XP = ", my_itc(win->player->xp));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    str = my_strcat("STRENGTH = ", my_itc(win->player->strength));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    str = my_strcat("POSITION X = ", my_itc(win->player->last_pos.x));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    str = my_strcat("POSITION Y = ", my_itc(win->player->last_pos.y));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    if (win->actual_page >= CASTLE && win->actual_page < BOSS) {
        str = my_strcat("PAGE = ", my_itc(win->actual_page));
        fwrite(str, sizeof(char), my_strlen(str), fp);
        fwrite("\n", sizeof(char), 1, fp);
    } else if (win->actual_page >= BOSS) {
        str = my_strcat("PAGE = ", my_itc(TOWN));
        fwrite(str, sizeof(char), my_strlen(str), fp);
        fwrite("\n", sizeof(char), 1, fp);
    } else {
        str = my_strcat("PAGE = ", my_itc(CASTLE));
        fwrite(str, sizeof(char), my_strlen(str), fp);
        fwrite("\n", sizeof(char), 1, fp);
    }
    fclose(fp);
}