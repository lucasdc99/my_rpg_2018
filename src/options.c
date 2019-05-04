/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** options
*/

#include "../include/rpg.h"
#include "../include/my.h"

void set_fps(window_t *win)
{
    sfIntRect tmp;
    sfIntRect tmp_two;

    if (win->states->fps == 60) {
        tmp = win->scene[OPTIONS].button[2].rect_idle;
        tmp_two = win->scene[OPTIONS].button[2].rect_pressed;
        win->scene[OPTIONS].button[2].rect_idle = tmp_two;
        win->scene[OPTIONS].button[2].rect_pressed = tmp;
    } else {
        tmp = win->scene[OPTIONS].button[1].rect_idle;
        tmp_two = win->scene[OPTIONS].button[1].rect_pressed;
        win->scene[OPTIONS].button[1].rect_idle = tmp_two;
        win->scene[OPTIONS].button[1].rect_pressed = tmp;
    }
    sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[1].shape,
    win->scene[OPTIONS].button[1].rect_idle);
    sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[2].shape,
    win->scene[OPTIONS].button[2].rect_idle);
}

int change_vsync(window_t *win)
{
    sfTexture *texture = NULL;

    sfMusic_play(win->music->button_sound);
    if (win->states->vsync == 0) {
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox.png",
        NULL);
        if (texture == NULL)
            return (84);
        win->states->vsync = 1;
        sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
    } else {
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox2.png",
        NULL);
        if (texture == NULL)
            return (84);
        win->states->vsync = 0;
        sfRenderWindow_setVerticalSyncEnabled(win->window, sfFalse);
    }
    sfRectangleShape_setTexture(win->scene[OPTIONS].button[3].shape,
    texture, sfTrue);
    return (0);
}

static void swap_rect(window_t *win)
{
    sfIntRect tmp;
    sfIntRect tmp_two;

    tmp = win->scene[OPTIONS].button[1].rect_idle;
    tmp_two = win->scene[OPTIONS].button[1].rect_pressed;
    win->scene[OPTIONS].button[1].rect_idle = tmp_two;
    win->scene[OPTIONS].button[1].rect_pressed = tmp;
    tmp = win->scene[OPTIONS].button[2].rect_pressed;
    tmp_two = win->scene[OPTIONS].button[2].rect_idle;
    win->scene[OPTIONS].button[2].rect_pressed = tmp_two;
    win->scene[OPTIONS].button[2].rect_idle = tmp;
}

int change_fps(window_t *win)
{

    sfMusic_play(win->music->button_sound);
    swap_rect(win);
    if (win->states->fps == 30) {
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[1].shape,
        win->scene[OPTIONS].button[1].rect_idle);
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[2].shape,
        win->scene[OPTIONS].button[2].rect_idle);
        sfRenderWindow_setFramerateLimit(win->window, 60);
        win->states->fps = 60;
    } else {
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[1].shape,
        win->scene[OPTIONS].button[1].rect_idle);
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[2].shape,
        win->scene[OPTIONS].button[2].rect_idle);
        sfRenderWindow_setFramerateLimit(win->window, 30);
        win->states->fps = 30;
    }
    return (0);
}