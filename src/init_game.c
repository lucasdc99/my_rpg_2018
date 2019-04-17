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
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 8);
    set_next_buttons(&win->scene[CASTLE].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[CASTLE].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[CASTLE].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[CASTLE].button[1], get_pos_float(-200, -200), size, win->texture_button);
    init_sprite(&win->scene[CASTLE].sprite[0], "ressources/castle.png", get_pos_float(0, 0));
    init_sprite(&win->scene[CASTLE].sprite[1], "ressources/tree.png", get_pos_float(304, 560));
    init_sprite(&win->scene[CASTLE].sprite[2], "ressources/tree.png", get_pos_float(80, 458));
    init_sprite(&win->scene[CASTLE].sprite[3], "ressources/tree.png", get_pos_float(1350, 508));
    init_sprite(&win->scene[CASTLE].sprite[4], "ressources/tree2.png", get_pos_float(1520, 500));
    init_sprite(&win->scene[CASTLE].sprite[5], "ressources/pack/rpg-pack/decorations/generic-rpg-loot02.png", get_pos_float(500, 400));
    init_sprite(&win->scene[CASTLE].sprite[6], "ressources/pack/rpg-pack/decorations/generic-rpg-loot03.png", get_pos_float(600, 400));
    init_sprite(&win->scene[CASTLE].sprite[7], "ressources/pack/rpg-pack/decorations/sword.png", get_pos_float(400, 400));
    for (int i = 0; i < 12; i++) {
        if (get_type_from_inv(win->inv->items[i].name) == SWORD) {
            sfSprite_setPosition(win->scene[CASTLE].sprite[7].sprite, win->inv->items[i].pos);
            win->scene[CASTLE].sprite[7].depth = 2;
        }
        if (get_type_from_inv(win->inv->items[i].name) == POTION) {
            sfSprite_setPosition(win->scene[CASTLE].sprite[6].sprite, win->inv->items[i].pos);
            win->scene[CASTLE].sprite[6].depth = 2;
        }
        if (get_type_from_inv(win->inv->items[i].name) == BOOK) {
            sfSprite_setPosition(win->scene[CASTLE].sprite[5].sprite, win->inv->items[i].pos);
            win->scene[CASTLE].sprite[5].depth = 2;
        }
    }
    for (int i = 1; i < 5; i++)
        win->scene[CASTLE].sprite[i].depth = 1;
    win->scene[CASTLE].sprite[5].item = 1;
    win->scene[CASTLE].sprite[6].item = 1;
    win->scene[CASTLE].sprite[7].item = 1;
    win->scene[CASTLE].sprite[5].type = BOOK;
    win->scene[CASTLE].sprite[6].type = POTION;
    win->scene[CASTLE].sprite[7].type = SWORD;
    sfSprite_setScale(win->scene[CASTLE].sprite[5].sprite, get_pos_float(2, 2));
    sfSprite_setScale(win->scene[CASTLE].sprite[6].sprite, get_pos_float(2, 2));
    sfSprite_setScale(win->scene[CASTLE].sprite[7].sprite, get_pos_float(2, 2));
    win->scene[CASTLE].button[0].callback = &quit_pause;
    win->scene[CASTLE].button[1].callback = &main_menu;
    return (win);
}