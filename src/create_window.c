/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** create_window
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *create_window(window_t *win)
{
    sfVideoMode mode = {1920, 1080, 32};
    char *name = {"My defender"};

    win->window = sfRenderWindow_create(mode, name, sfClose | sfResize, NULL);
    win->page = MAINMENU;
    win->actual_page = win->page;
    win->scene = malloc(sizeof(scene_t) * 4);
    win->player = malloc(sizeof(player_t) * 1);
    sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    win->vsync = 1;
    sfRenderWindow_setFramerateLimit(win->window, 60);
    win->fps = 60;
    win->volume = 100;
    win->button_sound = sfMusic_createFromFile("ressources/music/button.ogg");
    return (win);
}