/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void get_texture_pause(window_t *win)
{
    sfTexture *texture;

    if (win->actual_page == TOWN)
        texture = sfTexture_createFromFile("ressources/town_blur.png", NULL);
    if (win->actual_page == CASTLE)
        texture = sfTexture_createFromFile("ressources/castle_blur.png", NULL);
    if (win->actual_page == FOREST)
        texture = sfTexture_createFromFile("ressources/forest_blur.png", NULL);
    if (win->actual_page == FINAL) {
        texture = sfTexture_createFromFile("ressources/sbire_map_blur.png",
        NULL);
    }
    if (win->actual_page == BOSS) {
        texture = sfTexture_createFromFile("ressources/final_boss_blur.png",
        NULL);
    }
    sfSprite_setTexture(win->scene[win->actual_page].sprite[0].sprite,
    texture, sfTrue);
}

void pause_game(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 4;
    win->pause = 1;
    get_texture_pause(win);
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape,
    get_pos_float(pos_window.x, pos_window.y));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape,
    get_pos_float(pos_window.x, pos_window.y + 200));
}

static void get_texture_unpause(window_t *win)
{
    sfTexture *texture;

    if (win->actual_page == TOWN)
        texture = sfTexture_createFromFile("ressources/town.png", NULL);
    if (win->actual_page == CASTLE)
        texture = sfTexture_createFromFile("ressources/castle.png", NULL);
    if (win->actual_page == FOREST)
        texture = sfTexture_createFromFile("ressources/forest.png", NULL);
    if (win->actual_page == FINAL)
        texture = sfTexture_createFromFile("ressources/sbire_map.png", NULL);
    if (win->actual_page == BOSS)
        texture = sfTexture_createFromFile("ressources/final_boss.png", NULL);
    sfSprite_setTexture(win->scene[win->actual_page].sprite[0].sprite,
    texture, sfTrue);
}

void unpause_game(window_t *win)
{
    win->pause = 0;
    get_texture_unpause(win);
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape,
    get_pos_float(-600, -300));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape,
    get_pos_float(-600, -100));
}