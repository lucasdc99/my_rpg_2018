/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** set_pos
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int check_error_tab(window_t *win)
{
    if (win->positions->tab_castle == NULL ||
    win->positions->tab_town == NULL || win->positions->tab_house1 == NULL ||
    win->positions->tab_house2 == NULL || win->positions->tab_house3 == NULL ||
    win->positions->tab_forest == NULL || win->positions->tab_final == NULL ||
    win->positions->tab_boss == NULL) {
        return (84);
    }
    return (0);
}

static int set_pos_tab(window_t *win)
{
    win->positions->tab_castle =
    transform_2d(open_buff("ressources/text/pos_castle"), '\n');
    win->positions->tab_town =
    transform_2d(open_buff("ressources/text/pos_town"), '\n');
    win->positions->tab_house1 =
    transform_2d(open_buff("ressources/text/pos_house1"), '\n');
    win->positions->tab_house2 =
    transform_2d(open_buff("ressources/text/pos_house2"), '\n');
    win->positions->tab_house3 =
    transform_2d(open_buff("ressources/text/pos_house3"), '\n');
    win->positions->tab_forest =
    transform_2d(open_buff("ressources/text/pos_forest"), '\n');
    win->positions->tab_final =
    transform_2d(open_buff("ressources/text/pos_final"), '\n');
    win->positions->tab_boss =
    transform_2d(open_buff("ressources/text/pos_boss"), '\n');
    return (check_error_tab(win));
}

static char **switcher_tab(window_t *win)
{
    if (win->actual_page == CASTLE)
        return (win->positions->tab_castle);
    if (win->actual_page == TOWN)
        return (win->positions->tab_town);
    if (win->actual_page == HOUSE1)
        return (win->positions->tab_house1);
    if (win->actual_page == HOUSE2)
        return (win->positions->tab_house2);
    if (win->actual_page == HOUSE3)
        return (win->positions->tab_house3);
    if (win->actual_page == FOREST)
        return (win->positions->tab_forest);
    if (win->actual_page == FINAL)
        return (win->positions->tab_final);
    if (win->actual_page == BOSS)
        return (win->positions->tab_boss);
    return (NULL);
}

static int choose_move(char **tab, int move, sfVector2i scale, sfVector2i pos)
{
    if (move == UP) {
        if (pos.y - 1 >= 0 && tab[pos.y - 1][pos.x] == '2') {
            return (1);
        }
    }
    if (move == LEFT) {
        if (pos.x - 1 >= 0 && tab[pos.y][pos.x - 1] == '2')
            return (1);
    }
    if (move == DOWN) {
        if (pos.y + 1 < scale.y - 1 && tab[pos.y + 1][pos.x] == '2')
            return (1);
    }
    if (move == RIGHT) {
        if (pos.x + 1 < scale.x - 2 && tab[pos.y][pos.x + 1] == '2')
            return (1);
    }
    return (84);
}

int check_dead_zone(window_t *win, int move)
{
    sfVector2u size_win = sfRenderWindow_getSize(win->window);
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);
    sfVector2i scale = {size_win.x / 16, size_win.y / 15};
    sfVector2i pos = {pos_player.x / 16, pos_player.y / 15};
    static int ok = 0;
    char **tab = NULL;

    if (ok == 0) {
        if (set_pos_tab(win) == 84)
            return (84);
        ok = 1;
    }
    tab = switcher_tab(win);
    if (tab == NULL)
        return (0);
    return (choose_move(tab, move, scale, pos));
}