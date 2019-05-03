/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_window
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_variable_game(window_t *win)
{
    win->pause = 0;
    win->turn = 0;
    win->talking = 0;
    win->quests->combat = 0;
    win->move = sfClock_create();
    win->no_saves = 0;
}

static int init_win_variable(window_t *win)
{
    char *name = {"ressources/buttons/buttons.png"};

    win->inventory = 0;
    win->font_berlin = sfFont_createFromFile("ressources/font/berlin.ttf");
    if (win->font_berlin == NULL)
        return (84);
    win->font_title = sfFont_createFromFile("ressources/font/font.ttf");
    if (win->font_title == NULL)
        return (84);
    win->texture_button = sfTexture_createFromFile(name, NULL);
    if (win->texture_button == NULL)
        return (84);
    win->rect_buttons = init_pos_button();
    if (win->rect_buttons == NULL)
        return (84);
    if (init_text(win->text, "\n", get_pos_float(10, 950),
    win->font_berlin) == 84)
        return (84);
    init_variable_game(win);
    return (0);
}

window_t *create_window(window_t *win)
{
    sfVideoMode mode = {1920, 1080, 32};
    char *name = {"TEKZERK"};

    win->window = sfRenderWindow_create(mode, name, sfClose, NULL);
    if (win->window == NULL)
        return (NULL);
    win->page = MAINMENU;
    win->actual_page = win->page;
    win->nb_objects = 2;
    if (malloc_struct(win) == 84)
        return (NULL);
    sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    win->vsync = 1;
    sfRenderWindow_setFramerateLimit(win->window, 60);
    win->fps = 60;
    if (init_win_variable(win) == 84)
        return (NULL);
    return (win);
}