/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** blur_background
*/

#include "../include/rpg.h"
#include "../include/my.h"

static sfTexture *get_texture_final(window_t *win)
{
    sfTexture *texture = NULL;
    char *str = NULL;

    if (win->actual_page == FINAL) {
        str = "ressources/images/sbire_map_blur.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == BOSS) {
        str = "ressources/images/final_boss_blur.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    return (texture);
}

static sfTexture *get_texture_pause_houses(window_t *win)
{
    sfTexture *texture = NULL;
    char *str = NULL;

    if (win->actual_page == HOUSE1) {
        str = "ressources/images/house_1_blur.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == HOUSE2) {
        str = "ressources/images/house_2_blur.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == HOUSE3) {
        str = "ressources/images/house_3_blur.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (texture == NULL)
        return (get_texture_final(win));
    return (texture);
}

static sfTexture *get_texture_pause_final(window_t *win)
{
    sfTexture *texture = NULL;
    char *str = NULL;

    if (win->actual_page == TOWN) {
        str = "ressources/images/town_blur.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == CASTLE) {
        str = "ressources/images/castle_blur.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (win->actual_page == FOREST) {
        str = "ressources/images/forest_blur.png";
        texture = sfTexture_createFromFile(str, NULL);
    }
    if (texture == NULL)
        texture = get_texture_pause_houses(win);
    return (texture);
}

int get_texture_pause(window_t *win)
{
    sfTexture *texture = get_texture_pause_final(win);

    if (texture == NULL)
        return (84);
    sfSprite_setTexture(win->scene[win->actual_page].sprite[0].sprite,
    texture, sfTrue);
    return (0);
}