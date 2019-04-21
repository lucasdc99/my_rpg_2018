/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_window
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *create_window(window_t *win)
{
    sfVideoMode mode = {1920, 1080, 32};
    char *name = {"TEKZERK"};

    win->window = sfRenderWindow_create(mode, name, sfClose | sfResize, NULL);
    win->page = MAINMENU;
    win->actual_page = win->page;
    win->nb_objects = 3;
    win->scene = malloc(sizeof(scene_t) * 10);
    win->quests = malloc(sizeof(quest_t) * 1);
    win->quests->sprite = malloc(sizeof(sprite_t) * 6);
    win->quests->text = malloc(sizeof(text_t) * 5);
    win->player = malloc(sizeof(player_t) * 1);
    win->player->sprite = malloc(sizeof(sprite_t) * 1);
    win->inv = malloc(sizeof(inventory_t) * 1);
    win->inv->sprite = malloc(sizeof(sprite_t) * 1);
    win->inv->items = malloc(sizeof(items_t) * 12);
    win->text = malloc(sizeof(text_t) * 1);
    win->music = malloc(sizeof(music_t) * 1);
    win->objects = malloc(sizeof(sprite_t) * win->nb_objects);
    sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    win->vsync = 1;
    sfRenderWindow_setFramerateLimit(win->window, 60);
    win->fps = 60;
    win->inventory = 0;
    win->texture_button = sfTexture_createFromFile("ressources/buttons/buttons.png", NULL);
    win->rect_buttons = init_pos_button();
    init_text(win->text, "\n", get_pos_float(1450, 950));
    win->pause = 0;
    win->move = sfClock_create();
    win->no_saves = 0;
    return (win);
}