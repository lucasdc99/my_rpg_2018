/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** options
*/

#include "../include/rpg.h"
#include "../include/my.h"

int change_vsync(window_t *win)
{
    sfTexture *texture = NULL;

    sfMusic_play(win->music->button_sound);
    if (win->vsync == 0) {
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox.png",
        NULL);
        if (texture == NULL)
            return (84);
    } else {
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox2.png",
        NULL);
        if (texture == NULL)
            return (84);
    }
    sfRectangleShape_setTexture(win->scene[OPTIONS].button[3].shape,
    texture, sfTrue);
    sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    win->vsync = 1;
    return (0);
}

int change_fps(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    if (win->fps == 30) {
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[1].shape,
        win->scene[OPTIONS].button[1].rect_idle);
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[2].shape,
        win->scene[OPTIONS].button[2].rect_pressed);
        sfRenderWindow_setFramerateLimit(win->window, 60);
        win->fps = 60;
    } else {
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[1].shape,
        win->scene[OPTIONS].button[1].rect_idle);
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[2].shape,
        win->scene[OPTIONS].button[2].rect_pressed);
        sfRenderWindow_setFramerateLimit(win->window, 30);
        win->fps = 30;
    }
    return (0);
}