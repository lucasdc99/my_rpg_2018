/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player_events
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void check_movement(window_t *win)
{
    int ok = 0;

    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && ok == 0) {
        ok = 1;
        move_player_up(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && ok == 0) {
        ok = 1;
        move_player_left(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && ok == 0) {
        ok = 1;
        move_player_down(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && ok == 0) {
        ok = 1;
        move_player_right(win);
    }
}

void move_player(window_t *win)
{
    if (win->actual_page == TOWN)
        open_door(win);
    if (win->actual_page == HOUSE1 || win->actual_page == HOUSE2 ||
    win->actual_page == HOUSE3) {
        close_door(win);
    }
    check_movement(win);
    go_boss(win);
    leave_boss(win);
    check_item_pickup(win);
    go_castle(win);
    go_forest(win);
    go_town(win);
    check_combat_zone(win);
}