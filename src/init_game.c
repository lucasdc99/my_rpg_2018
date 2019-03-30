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
    char **text = transform_2d("Glenys\nHex\nLey\nLinail\nOratio\nOuzo\nPrime\nWyvera\nBACK TO MAIN MENU\n");

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 8;
    win->scene[GAME].button = malloc(sizeof(button_t) * 9);
    win->scene[GAME].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[GAME].text = malloc(sizeof(text_t) * 7);
    win->scene[GAME].nb_text = 7;
    win->scene[GAME].nb_button = 9;
    win->scene[GAME].nb_sprite = 1;
    init_text(&win->scene[GAME].text[0], "Choose Player", get_pos_float(pos_window.x, 10));
    init_text(&win->scene[GAME].text[1], win->player->name, get_pos_float(pos_window.x / 2, 100));
    init_text(&win->scene[GAME].text[2], "Life: ", get_pos_float((pos_window.x - 100) / 2, (size_window.y - 450)));
    init_text(&win->scene[GAME].text[3], my_itc(win->player->health), get_pos_float((pos_window.x + 250) / 2, (size_window.y - 450)));
    init_text(&win->scene[GAME].text[4], "Strength: ", get_pos_float((pos_window.x - 200) / 2, (size_window.y - 350)));
    init_text(&win->scene[GAME].text[5], my_itc(win->player->health), get_pos_float((pos_window.x + 250) / 2, (size_window.y - 350)));
    init_text(&win->scene[GAME].text[6], "Description", get_pos_float((pos_window.x - 200) / 2, (size_window.y - 250)));
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        if (i == win->scene[GAME].nb_button - 1) {
            pos_window.x = (size_window.x - size.x - 10);
            pos_window.y = (size_window.y - size.y - 10);
        }
        init_button(&win->scene[GAME].button[i], pos_window, size);
        init_button_text(&win->scene[GAME].button[i], text[i], pos_window);
        pos_window.y += size.y + 10;
    }
    win->scene[GAME].button[0].callback = &choose_glenys;
    win->scene[GAME].button[1].callback = &choose_hex;
    win->scene[GAME].button[2].callback = &choose_ley;
    win->scene[GAME].button[3].callback = &choose_linail;
    win->scene[GAME].button[4].callback = &choose_oratio;
    win->scene[GAME].button[5].callback = &choose_ouzo;
    win->scene[GAME].button[6].callback = &choose_prime;
    win->scene[GAME].button[7].callback = &choose_wyvera;
    win->scene[GAME].button[8].callback = &main_menu;
    win->scene[GAME].button[0].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[0].rect, win->scene[GAME].button[0].idle_color);
    init_sprite(&win->scene[GAME].sprite[0], "ressources/pack/Pixel_Champions/Magical Heroes/Glenys-the-Demonswordsman.png", get_pos_float(100, 100));
    win->scene[GAME].sprite[0].rect.top = 100;
    win->scene[GAME].sprite[0].rect.left = 0;
    win->scene[GAME].sprite[0].rect.width = 50;
    win->scene[GAME].sprite[0].rect.height = 50;
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    return (win);
}