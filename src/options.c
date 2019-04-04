/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** options
*/

#include "../include/rpg.h"
#include "../include/my.h"

void change_vsync(window_t *win)
{
    sfMusic_play(win->button_sound);
    if (win->vsync == 0) {
        sfRectangleShape_setTexture(win->scene[OPTIONS].button[3].rect,
        sfTexture_createFromFile("ressources/buttons/Checkbox.png", NULL), sfTrue);
        sfRenderWindow_setVerticalSyncEnabled(win->window, sfTrue);
        win->vsync = 1;
    } else {
        sfRectangleShape_setTexture(win->scene[OPTIONS].button[3].rect,
        sfTexture_createFromFile("ressources/buttons/Checkbox2.png", NULL), sfTrue);
        sfRenderWindow_setVerticalSyncEnabled(win->window, sfFalse);
        win->vsync = 0;
    }
}

void change_fps(window_t *win)
{
    sfMusic_play(win->button_sound);
    if (win->fps == 30) {
        win->scene[OPTIONS].button[1].idle_color = sfRed;
        win->scene[OPTIONS].button[2].idle_color = sfYellow;
        sfRenderWindow_setFramerateLimit(win->window, 60);
        win->fps = 60;
    } else {
        win->scene[OPTIONS].button[1].idle_color = sfYellow;
        win->scene[OPTIONS].button[2].idle_color = sfRed;
        sfRenderWindow_setFramerateLimit(win->window, 30);
        win->fps = 30;
    }
    sfRectangleShape_setFillColor(win->scene[OPTIONS].button[2].rect,
    win->scene[OPTIONS].button[2].idle_color);
    sfRectangleShape_setFillColor(win->scene[OPTIONS].button[1].rect,
    win->scene[OPTIONS].button[1].idle_color);
}

void change_music(window_t *win)
{
    sfMusic_play(win->button_sound);
    char **music = transform_2d("0%\n25%\n50%\n75%\n100%\n");
    const char *str =
    sfText_getString(win->scene[OPTIONS].button[4].text);
    int i = 0;

    for (; my_strcmp(music[i], str) != 0; i++);
    if (i == 4)
        i = -1;
    i++;
    win->volume = i * 25;
    sfMusic_setVolume(win->button_sound, win->volume);
    sfText_setString(win->scene[OPTIONS].button[4].text, music[i]);
}

void change_music_two(window_t *win)
{
    printf("dqdqz");
}