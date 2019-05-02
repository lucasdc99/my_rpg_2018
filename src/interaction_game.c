/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** interaction_game
*/

#include "../include/rpg.h"
#include "../include/my.h"

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

static sfTexture *get_texture_unpause_final(window_t *win)
{
    sfTexture *texture;
    char *str = NULL;

    if (win->actual_page == FINAL) {
        str = "ressources/images/sbire_map.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == BOSS) {
        str = "ressources/images/final_boss.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    return (texture);
}

static sfTexture *get_texture_unpause_houses(window_t *win)
{
    sfTexture *texture = NULL;
    char *str = NULL;

    if (win->actual_page == HOUSE1) {
        str = "ressources/images/house_1.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == HOUSE2) {
        str = "ressources/images/house_2.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == HOUSE3) {
        str = "ressources/images/house_3.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (texture == NULL)
        return (get_texture_unpause_final(win));
    return (texture);
}

static void get_texture_unpause(window_t *win)
{
    sfTexture *texture = NULL;
    char *str = NULL;

    if (win->actual_page == TOWN)
        texture = sfTexture_createFromFile("ressources/images/town.png", NULL);
    if (win->actual_page == CASTLE) {
        str = "ressources/images/castle.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == FOREST) {
        str = "ressources/images/forest.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (texture == NULL)
        texture = get_texture_unpause_houses(win);
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