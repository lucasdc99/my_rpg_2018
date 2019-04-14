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
    char *skin = malloc(sizeof(char) * 80);
    int order_button[] = {REPRENDRE, QUITTER};

    set_struct(win, 2, 0, 3);
    win->player->sprite->rect.top = 15;
    win->player->sprite->rect.left = 15;
    win->player->sprite->rect.width = 18;
    win->player->sprite->rect.height = 18;
    set_next_buttons(&win->scene[GAME].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[GAME].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[GAME].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[GAME].button[1], get_pos_float(-200, -200), size, win->texture_button);
    skin = my_strcat("ressources/pack/Pixel_Champions/Magical Heroes/", win->player->name);
    skin = my_strcat(skin, ".png");
    init_sprite(win->player->sprite, skin, get_pos_float(win->player->speed.x, win->player->speed.y));
    sfSprite_setScale(win->player->sprite->sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
    init_sprite(&win->scene[GAME].sprite[0], "ressources/castle.png", get_pos_float(0, 0));
    init_sprite(&win->scene[GAME].sprite[1], "ressources/inv.png", get_pos_float(-600, -600));
    init_sprite(&win->scene[GAME].sprite[2], "ressources/pack/rpg-pack/decorations/sword.png", get_pos_float(400, 400));
    sfSprite_setScale(win->scene[GAME].sprite[2].sprite, get_pos_float(2, 2));
    check_dead_zone(win, -1);
    if (win->player->last_pos.x >= 0)
        sfSprite_setPosition(win->player->sprite->sprite, win->player->last_pos);
    else
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(500, 500));
    win->scene[GAME].button[0].callback = &quit_pause;
    win->scene[GAME].button[1].callback = &main_menu;
    return (win);
}