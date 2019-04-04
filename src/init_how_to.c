/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_how_to
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_how_to_play(window_t *win)
{
    sfVector2f size = get_pos_float(500, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window = get_pos_float(10, 10);
    int fd = open("ressources/text/help", O_RDONLY);
    char buff[460];

    read(fd, buff, sizeof(buff));
    win->scene[HOW_TO_PLAY].button = malloc(sizeof(button_t) * 1);
    win->scene[HOW_TO_PLAY].text = malloc(sizeof(text_t) * 2);
    win->scene[HOW_TO_PLAY].nb_text = 2;
    win->scene[HOW_TO_PLAY].nb_button = 1;
    win->scene[HOW_TO_PLAY].nb_sprite = 0;
    pos_window.y = 50;
    pos_window.x = (size_window.x - size.x + 250) / 2;
    init_text(&win->scene[HOW_TO_PLAY].text[0], "How to Play", pos_window);
    pos_window.x = 100;
    pos_window.y += 150;
    init_text(&win->scene[HOW_TO_PLAY].text[1], buff, pos_window);
    win->scene[HOW_TO_PLAY].button[0].callback = &main_menu;
    pos_window.x = (size_window.x - size.x - 20);
    pos_window.y = 900;
    set_next_buttons(&win->scene[HOW_TO_PLAY].button[0], win->rect_buttons, RETOUR);
    init_button(&win->scene[HOW_TO_PLAY].button[0], pos_window, size, win->texture_button);
    pos_window.x += 30;
    return (win);
}