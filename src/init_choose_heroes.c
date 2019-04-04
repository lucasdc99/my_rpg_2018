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

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 8;
    win->scene[HEROES].button = malloc(sizeof(button_t) * 3);
    win->scene[HEROES].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[HEROES].text = malloc(sizeof(text_t) * 7);
    win->scene[HEROES].nb_text = 7;
    win->scene[HEROES].nb_button = 3;
    win->scene[HEROES].nb_sprite = 1;
    init_text(&win->scene[HEROES].text[0], "Choose Player", get_pos_float(pos_window.x + 40, 10));
    init_text(&win->scene[HEROES].text[1], "Glenys-the-Demonswordsman", get_pos_float(pos_window.x / 2, 100));
    init_text(&win->scene[HEROES].text[2], "Life: ", get_pos_float((pos_window.x - 100) / 2, (size_window.y - 450)));
    init_text(&win->scene[HEROES].text[3], my_itc(150), get_pos_float((pos_window.x + 250) / 2, (size_window.y - 450)));
    init_text(&win->scene[HEROES].text[4], "Strength: ", get_pos_float((pos_window.x - 200) / 2, (size_window.y - 350)));
    init_text(&win->scene[HEROES].text[5], my_itc(150), get_pos_float((pos_window.x + 250) / 2, (size_window.y - 350)));
    init_text(&win->scene[HEROES].text[6], "Description", get_pos_float((pos_window.x - 200) / 2, (size_window.y - 250)));
    set_next_buttons(&win->scene[HEROES].button[0], win->rect_buttons, FLECHE);
    init_button(&win->scene[HEROES].button[0], get_pos_float(pos_window.x + 40, (size_window.y / 2)), get_pos_float(size.x / 2, size.y), win->texture_button);
    pos_window.y += size.y + 10;
    pos_window.x = (size_window.x - size.x - 10);
    pos_window.y = (size_window.y - (size.y + 50) * 2);
    set_next_buttons(&win->scene[HEROES].button[win->scene[HEROES].nb_button - 2], win->rect_buttons, JOUER);
    init_button(&win->scene[HEROES].button[win->scene[HEROES].nb_button - 2], pos_window, size, win->texture_button);
    pos_window.y += size.y + 10;
    set_next_buttons(&win->scene[HEROES].button[win->scene[HEROES].nb_button - 1], win->rect_buttons, QUITTER);
    init_button(&win->scene[HEROES].button[win->scene[HEROES].nb_button - 1], pos_window, size, win->texture_button);
    pos_window.y += size.y + 10;
    win->scene[HEROES].button[0].callback = &choose_hero;
    win->scene[HEROES].button[1].callback = &play_game;
    win->scene[HEROES].button[2].callback = &main_menu;
    init_sprite(&win->scene[HEROES].sprite[0], "ressources/pack/Pixel_Champions/Magical Heroes/Glenys-the-Demonswordsman.png", get_pos_float(100, 100));
    win->scene[HEROES].sprite[0].rect.top = 100;
    win->scene[HEROES].sprite[0].rect.left = 0;
    win->scene[HEROES].sprite[0].rect.width = 50;
    win->scene[HEROES].sprite[0].rect.height = 50;
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    return (win);
}