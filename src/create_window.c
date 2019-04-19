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
    win->scene = malloc(sizeof(scene_t) * 8);
    win->player = malloc(sizeof(player_t) * 1);
    win->quests = malloc(sizeof(quest_t) * 1);
    win->quests->sprite = malloc(sizeof(sprite_t) * 2);
    win->quests->text = malloc(sizeof(text_t) * 2);
    win->inv = malloc(sizeof(inventory_t) * 1);
    win->inv->sprite = malloc(sizeof(sprite_t) * 1);
    win->music = malloc(sizeof(music_t) * 1);
    win->player->sprite = malloc(sizeof(sprite_t) * 1);
    win->player->sprite->sprite = NULL;
    win->player->sprite->texture = NULL;
    win->inv->items = malloc(sizeof(items_t) * 12);
    win->objects = malloc(sizeof(sprite_t) * win->nb_objects);
    sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    win->vsync = 1;
    sfRenderWindow_setFramerateLimit(win->window, 60);
    win->fps = 60;
    win->player->last_pos = get_pos_float(-100, -100);
    win->player->direction = 1;
    win->inv->items->sword = 0;
    win->player->move_rect = 0;
    win->player->last_page = CASTLE;
    win->music->volume = 100;
    win->music->vol_drag_posx = 800;
    win->music->button_sound = sfMusic_createFromFile("ressources/music/button.ogg");
    win->music->menu_song = sfMusic_createFromFile("ressources/music/main_song.ogg");
    win->texture_button = sfTexture_createFromFile("ressources/buttons/buttons.png", NULL);
    win->rect_buttons = init_pos_button();
    init_sprite(&win->inv->sprite[0], "ressources/inv.png", get_pos_float(1200, 150));
    sfMusic_play(win->music->menu_song);
    win->pause = 0;
    win->inventory = 0;
    init_inventory(win->inv);
    win->move = sfClock_create();
    return (win);
}