/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
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
    int order_button[] = {JOUER, NOUVEAU, TUTORIEL, PARAM, QUITTER};
    int number_str = 1;
    char *get_number = malloc(sizeof(char) * 5);
    char *str = "ressources/pack/background/frame";
    char *path = malloc(sizeof(char) * (my_strlen(str) + 5));

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 4;
    win->scene[MAINMENU].button = malloc(sizeof(button_t) * 5);
    win->scene[MAINMENU].text = malloc(sizeof(text_t) * 1);
    win->scene[MAINMENU].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[MAINMENU].nb_text = 1;
    win->scene[MAINMENU].nb_button = 5;
    win->scene[MAINMENU].nb_sprite = 1;
    init_text(&win->scene[MAINMENU].text[0], "Tekzerk", get_pos_float(pos_window.x - 70, 10));
    sfText_setColor(win->scene[MAINMENU].text[0].str, sfBlack);
    sfText_setCharacterSize(win->scene[MAINMENU].text[0].str, 150);
    win->scene[MAINMENU].text[0].font = sfFont_createFromFile("ressources/font/font.ttf");
    sfText_setFont(win->scene[MAINMENU].text[0].str, win->scene[MAINMENU].text[0].font);

    for (int i = 1; i != 9; i++) {
        get_number = my_strcat(my_itc(number_str), ".png");
        path = my_strcat(str, get_number);
        number_str++;
        get_number = NULL;
    }
    init_sprite(&win->scene[MAINMENU].sprite[0], "ressources/pack/background/frame1.png", get_pos_float(0, 0));
    for (int i = 0; i < win->scene[MAINMENU].nb_button; i++) {
        set_next_buttons(&win->scene[MAINMENU].button[i], win->rect_buttons, order_button[i]);
        init_button(&win->scene[MAINMENU].button[i], get_pos_float(pos_window.x - 600, pos_window.y), size, win->texture_button);
        pos_window.y += size.y + 20;
    }
    win->scene[MAINMENU].button[0].callback = &play_game;
    win->scene[MAINMENU].button[1].callback = &heroes_menu;
    win->scene[MAINMENU].button[2].callback = &how_to_play;
    win->scene[MAINMENU].button[3].callback = &options;
    win->scene[MAINMENU].button[4].callback = &quit;
    return (win);
}