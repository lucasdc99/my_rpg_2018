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
        {CASTLE, &init_game, &draw_scene, &global_event, &destroy_scene},
        {TOWN, &init_house, &draw_scene, &global_event, &destroy_scene},
        {HOUSE1, &init_house1, &draw_scene, &global_event, &destroy_scene},
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
            move_sprites(win, 48);
        }
        if ((win->actual_page >= CASTLE) && win->pause == 0) {
            move_player(win);
            if (win->actual_page == TOWN) {
                open_door(win);
                check_out(win);
            }
            if (win->actual_page == CASTLE)
                check_interaction(win);
            if (win->actual_page == HOUSE1)
                close_door(win);
        }
    }
}