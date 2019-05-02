/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_window
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void malloc_struct(window_t *win)
{
    win->scene = malloc(sizeof(scene_t) * 14);
    win->quests = malloc(sizeof(quest_t) * 1);
    win->quests->sprite = malloc(sizeof(sprite_t) * 8);
    win->quests->text = malloc(sizeof(text_t) * 7);
    win->player = malloc(sizeof(player_t) * 1);
    win->player->sprite = malloc(sizeof(sprite_t) * 1);
    win->enemy = malloc(sizeof(enemy_t) * 1);
    win->enemy->sprite = malloc(sizeof(sprite_t) * 1);
    win->enemy->text = malloc(sizeof(text_t) * 1);
    win->inv = malloc(sizeof(inventory_t) * 1);
    win->inv->sprite = malloc(sizeof(sprite_t) * 1);
    win->inv->items = malloc(sizeof(items_t) * 15);
    win->inv->text = malloc(sizeof(text_t) * 1);
    win->text = malloc(sizeof(text_t) * 1);
    win->music = malloc(sizeof(music_t) * 1);
    win->objects = malloc(sizeof(sprite_t) * win->nb_objects);
    win->positions = malloc(sizeof(pos_t) * 1);
}

static void init_win_variable(window_t *win)
{
    char *name = {"ressources/buttons/buttons.png"};

    win->inventory = 0;
    win->font_berlin = sfFont_createFromFile("ressources/font/berlin.ttf");
    win->font_title = sfFont_createFromFile("ressources/font/font.ttf");
    win->texture_button = sfTexture_createFromFile(name, NULL);
    win->rect_buttons = init_pos_button();
    init_text(win->text, "\n", get_pos_float(1150, 950), win->font_berlin);
    win->pause = 0;
    win->turn = 0;
    win->talking = 0;
    win->quests->combat = 0;
    win->move = sfClock_create();
    win->no_saves = 0;
    win->error = 0;
}

window_t *create_window(window_t *win)
{
    sfVideoMode mode = {1920, 1080, 32};
    char *name = {"TEKZERK"};

    win->window = sfRenderWindow_create(mode, name, sfClose, NULL);
    win->page = MAINMENU;
    win->actual_page = win->page;
    win->nb_objects = 3;
    malloc_struct(win);
    sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    win->vsync = 1;
    sfRenderWindow_setFramerateLimit(win->window, 60);
    win->fps = 60;
    init_win_variable(win);
    return (win);
}