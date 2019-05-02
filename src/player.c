/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void set_var_player(window_t *win)
{
    win->player->health = 0;
    win->player->actual_health = 0;
    win->player->xp = 0;
    win->player->last_pos = get_pos_float(-100, -100);
    win->player->direction = 1;
    win->player->move_rect = 0;
    win->player->last_page = CASTLE;
    win->inv = NULL;
    win->quests = NULL;
}

int reset_player(window_t *win)
{
    win->no_saves = 1;
    win->player = malloc(sizeof(player_t) * 1);
    if (win->player == NULL)
        return (84);
    win->player->sprite = malloc(sizeof(sprite_t) * 1);
    if (win->player->sprite == NULL)
        return (84);
    win->player->name = NULL;
    win->player->sprite->sprite = NULL;
    win->player->sprite->texture = NULL;
    win->player->strength = 0;
    set_var_player(win);
    save_config_player(win);
    return (0);
}

static void save_page_player(window_t *win, FILE *fp)
{
    char *str = NULL;

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
}

static void save_player_data(window_t *win, FILE *fp)
{
    char *str = NULL;

    str = my_strcat("STRENGTH = ", my_itc(win->player->strength));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    str = my_strcat("POSITION X = ", my_itc(win->player->last_pos.x));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    str = my_strcat("POSITION Y = ", my_itc(win->player->last_pos.y));
    fwrite(str, sizeof(char), my_strlen(str), fp);
    fwrite("\n", sizeof(char), 1, fp);
    save_page_player(win, fp);
}

void save_config_player(window_t *win)
{
    FILE *fp = fopen("ressources/text/config_player", "wb+");
    char *str = NULL;

    str = my_strcat("NAME = ", win->player->name);
    if (str == NULL)
        fwrite("NAME = ", sizeof(char), 7, fp);
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
    save_player_data(win, fp);
    fclose(fp);
}