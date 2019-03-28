/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** init_menu
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_menu(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 4;
    win->scene[MAINMENU].button = malloc(sizeof(button_t) * 1);
    win->scene[MAINMENU].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[MAINMENU].button = init_button(win->scene[MAINMENU].button, pos_window, size);
    win->scene[MAINMENU].button = init_button_text(win->scene[MAINMENU].button, "PLAY", pos_window);
    win->scene[MAINMENU].button->callback = &main_menu;
    win->scene[MAINMENU].nb_button = 1;
    win->scene[MAINMENU].nb_sprite = 1;
    win->scene[MAINMENU].sprite =  init_sprite(win->scene[MAINMENU].sprite, "ressources/generic-rpg-pack_v0.3_(alpha-release)_vacaroxa/rpg-pack/atlas.png", get_pos_float(100, 100));
    return (win);
}