/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_choose_heroes
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_choose_heroes(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;
    char **text = transform_2d("Glenys\nHex\nLey\nLinail\nOratio\nOuzo\nPrime\nWyvera\nCONFIRM\nBACK TO MAIN MENU\n");

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 8;
    win->scene[HEROES].button = malloc(sizeof(button_t) * 10);
    win->scene[HEROES].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[HEROES].text = malloc(sizeof(text_t) * 7);
    win->scene[HEROES].nb_text = 7;
    win->scene[HEROES].nb_button = 10;
    win->scene[HEROES].nb_sprite = 1;
    init_text(&win->scene[HEROES].text[0], "Choose Player", get_pos_float(pos_window.x + 40, 10));
    init_text(&win->scene[HEROES].text[1], win->player->name, get_pos_float(pos_window.x / 2, 100));
    init_text(&win->scene[HEROES].text[2], "Life: ", get_pos_float((pos_window.x - 100) / 2, (size_window.y - 450)));
    init_text(&win->scene[HEROES].text[3], my_itc(win->player->health), get_pos_float((pos_window.x + 250) / 2, (size_window.y - 450)));
    init_text(&win->scene[HEROES].text[4], "Strength: ", get_pos_float((pos_window.x - 200) / 2, (size_window.y - 350)));
    init_text(&win->scene[HEROES].text[5], my_itc(win->player->health), get_pos_float((pos_window.x + 250) / 2, (size_window.y - 350)));
    init_text(&win->scene[HEROES].text[6], "Description", get_pos_float((pos_window.x - 200) / 2, (size_window.y - 250)));
    for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
        if (i == win->scene[HEROES].nb_button - 2) {
            pos_window.x = (size_window.x - size.x - 10);
            pos_window.y = (size_window.y - (size.y + 50) * 2);
        }
        init_button(&win->scene[HEROES].button[i], pos_window, size);
        init_button_text(&win->scene[HEROES].button[i], text[i], get_pos_text_button(win->scene[HEROES].button[i], text[i]));
        pos_window.y += size.y + 10;
    }
    win->scene[HEROES].button[0].callback = &choose_glenys;
    win->scene[HEROES].button[1].callback = &choose_hex;
    win->scene[HEROES].button[2].callback = &choose_ley;
    win->scene[HEROES].button[3].callback = &choose_linail;
    win->scene[HEROES].button[4].callback = &choose_oratio;
    win->scene[HEROES].button[5].callback = &choose_ouzo;
    win->scene[HEROES].button[6].callback = &choose_prime;
    win->scene[HEROES].button[7].callback = &choose_wyvera;
    win->scene[HEROES].button[8].callback = &play_game;
    win->scene[HEROES].button[9].callback = &main_menu;
    win->scene[HEROES].button[0].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[HEROES].button[0].rect, win->scene[HEROES].button[0].idle_color);
    init_sprite(&win->scene[HEROES].sprite[0], "ressources/pack/Pixel_Champions/Magical Heroes/Glenys-the-Demonswordsman.png", get_pos_float(100, 100));
    win->scene[HEROES].sprite[0].rect.top = 100;
    win->scene[HEROES].sprite[0].rect.left = 0;
    win->scene[HEROES].sprite[0].rect.width = 50;
    win->scene[HEROES].sprite[0].rect.height = 50;
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    return (win);
}