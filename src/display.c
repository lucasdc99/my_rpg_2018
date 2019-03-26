/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** display
*/

#include "../include/rpg.h"
#include "../include/my.h"

ptr_func *init_func(void)
{
    static ptr_func ptr_choose[] = {
        {MAINMENU, &init_menu, &draw_scene, &global_event, &destroy_scene}
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
    }
}