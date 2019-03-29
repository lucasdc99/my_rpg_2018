/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_game
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_game(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;
    char **text = transform_2d("GAME\nGAME\nGAME\nBACK TO MAIN MENU\n");

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 4;
    win->scene[GAME].button = malloc(sizeof(button_t) * 4);
    win->scene[GAME].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[GAME].nb_button = 4;
    win->scene[GAME].nb_sprite = 1;
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        init_button(&win->scene[GAME].button[i], pos_window, size);
        init_button_text(&win->scene[GAME].button[i], text[i], pos_window);
        pos_window.y += size.y + 20;
    }
    win->scene[GAME].button[0].callback = &quit;
    win->scene[GAME].button[1].callback = &quit;
    win->scene[GAME].button[2].callback = &quit;
    win->scene[GAME].button[3].callback = &main_menu;
    init_sprite(&win->scene[GAME].sprite[0], "ressources/generic-rpg-pack_v0.3_(alpha-release)_vacaroxa/rpg-pack/atlas.png", get_pos_float(100, 100));
    return (win);
}