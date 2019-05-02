/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_window
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int malloc_struct_end(window_t *win)
{
    win->inv->text = malloc(sizeof(text_t) * 1);
    if (win->inv->text == NULL)
        return (84);
    win->text = malloc(sizeof(text_t) * 1);
    if (win->text == NULL)
        return (84);
    win->music = malloc(sizeof(music_t) * 1);
    if (win->music == NULL)
        return (84);
    win->objects = malloc(sizeof(sprite_t) * win->nb_objects);
    if (win->objects == NULL)
        return (84);
    win->positions = malloc(sizeof(pos_t) * 1);
    if (win->positions == NULL)
        return (84);
    return (0);
}

static int malloc_struct_game(window_t *win)
{
    win->enemy = malloc(sizeof(enemy_t) * 1);
    if (win->enemy == NULL)
        return (84);
    win->enemy->sprite = malloc(sizeof(sprite_t) * 1);
    if (win->enemy->sprite == NULL)
        return (84);
    win->enemy->text = malloc(sizeof(text_t) * 1);
    if (win->enemy->text == NULL)
        return (84);
    win->inv = malloc(sizeof(inventory_t) * 1);
    if (win->inv == NULL)
        return (84);
    win->inv->sprite = malloc(sizeof(sprite_t) * 1);
    if (win->inv->sprite == NULL)
        return (84);
    win->inv->items = malloc(sizeof(items_t) * 15);
    if (win->inv->items == NULL)
        return (84);
    return (malloc_struct_end(win));
}

static int malloc_struct(window_t *win)
{
    win->scene = malloc(sizeof(scene_t) * 14);
    if (win->scene == NULL)
        return (84);
    win->quests = malloc(sizeof(quest_t) * 1);
    if (win->quests == NULL)
        return (84);
    win->quests->sprite = malloc(sizeof(sprite_t) * 8);
    if (win->quests->sprite == NULL)
        return (84);
    win->quests->text = malloc(sizeof(text_t) * 7);
    if (win->quests->text == NULL)
        return (84);
    win->player = malloc(sizeof(player_t) * 1);
    if (win->player == NULL)
        return (84);
    win->player->sprite = malloc(sizeof(sprite_t) * 1);
    if (win->player->sprite == NULL)
        return (84);
    return (malloc_struct_game(win));
}

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
    if (init_text(win->text, "\n", get_pos_float(1150, 950),
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