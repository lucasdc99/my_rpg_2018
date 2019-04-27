/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display
*/

#include "../include/rpg.h"
#include "../include/my.h"

ptr_func *init_func(void)
{
    static ptr_func ptr_choose[] = {
        {MAINMENU, &init_menu, &draw_scene, &global_event, &destroy_scene},
        {HEROES, &init_choose_heroes, &draw_scene, &global_event, &destroy_scene},
        {HOW_TO_PLAY, &init_how_to_play, &draw_scene, &global_event, &destroy_scene},
        {OPTIONS, &init_options, &draw_scene, &global_event, &destroy_scene},
        {CASTLE, &init_castle, &draw_scene, &global_event, &destroy_scene},
        {TOWN, &init_town, &draw_scene, &global_event, &destroy_scene},
        {HOUSE1, &init_house_1, &draw_scene, &global_event, &destroy_scene},
        {HOUSE2, &init_house_2, &draw_scene, &global_event, &destroy_scene},
        {HOUSE3, &init_house_3, &draw_scene, &global_event, &destroy_scene},
        {FOREST, &init_forest, &draw_scene, &global_event, &destroy_scene},
        {FINAL, &init_final, &draw_scene, &global_event, &destroy_scene},
        {BOSS, &init_boss, &draw_scene, &global_event, &destroy_scene},
        {COMBAT, &init_combat, &draw_scene, &global_event, &destroy_scene},
        {END, &init_end, &draw_scene, &global_event, &destroy_scene},
    };
    return (ptr_choose);
}

void display(window_t *win)
{
    ptr_func *ptr_choose = init_func();
    win = ptr_choose[win->actual_page].start(win);

    while (sfRenderWindow_isOpen(win->window)) {
        if (win->page != win->actual_page) {
            win = ptr_choose[win->actual_page].end(win);
            win = ptr_choose[win->page].start(win);
            win->actual_page = win->page;
        }
        while (sfRenderWindow_pollEvent(win->window, &win->event))
            ptr_choose[win->actual_page].event(win);
        win = ptr_choose[win->actual_page].draw(win);
        if (win->actual_page == MAINMENU) {
            win->move_time = sfClock_getElapsedTime(win->move);
            win->seconds = win->move_time.microseconds / 130000.0;
            animation_mainmenu(win, 1920);
        }
        if (win->actual_page == HEROES) {
            win->move_time = sfClock_getElapsedTime(win->move);
            win->seconds = win->move_time.microseconds / 1000000.0;
            animation_choose_heroes(win, 48);
        }
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT && win->pause == 0 && win->no_saves == 0) {
            move_player(win);
            if (win->actual_page == TOWN) {
                go_castle(win);
            }
            if (win->actual_page == CASTLE) {
                go_town(win);
                go_forest(win);
                win->move_time = sfClock_getElapsedTime(win->move);
                win->seconds = win->move_time.microseconds / 400000.0;
                animation_torch(win, 20);
            }
            if (win->actual_page == FOREST)
                go_castle(win);
            if (win->actual_page == FINAL)
                leave_final(win);
        }
        if (win->turn == 1 && win->actual_page == COMBAT) {
            sfClock_restart(win->combat_clock);
            win->combat_time = sfClock_getElapsedTime(win->combat_clock);
            win->seconds = win->combat_time.microseconds / 1000000.0;
            while (win->seconds < 2) {
                win->combat_time = sfClock_getElapsedTime(win->combat_clock);
                win->seconds = win->combat_time.microseconds / 100000.0;
            }
            enemy_attack(win);
            win->turn = 0;
        }
    }
}