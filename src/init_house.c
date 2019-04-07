/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_house
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_house(window_t *win)
{
    int fd = open("ressources/text/pos_house", O_RDONLY);
    char buff[660];
    int order_button[] = {REPRENDRE, QUITTER};
    sfVector2f size = get_pos_float(400, 100);

    read(fd, buff, sizeof(buff));
    win->scene[HOUSE].background = malloc(sizeof(background_t) * 222);
    win->scene[HOUSE].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[HOUSE].button = malloc(sizeof(button_t) * 2);
    win->scene[HOUSE].nb_text = 0;
    win->scene[HOUSE].nb_button = 2;
    win->scene[HOUSE].nb_sprite = 1;
    win->scene[HOUSE].background->tab_pos = transform_pos_to_tab(buff);
    load_background(win);
    init_sprite(&win->scene[HOUSE].sprite[0], "ressources/inventaire_de_merde.png", get_pos_float(-600, -300));
    set_next_buttons(&win->scene[HOUSE].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[HOUSE].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[HOUSE].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[HOUSE].button[1], get_pos_float(-200, -200), size, win->texture_button);
    win->scene[HOUSE].button[0].callback = &quit_pause;
    win->scene[HOUSE].button[1].callback = &main_menu;
    return (win);
}