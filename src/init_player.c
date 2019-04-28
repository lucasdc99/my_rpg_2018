/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_player
*/

#include "../include/rpg.h"
#include "../include/my.h"

void set_player(window_t *win)
{
    check_dead_zone(win, -1);
    win->inv->player = sfSprite_create();
    sfSprite_setTexture(win->inv->player, win->player->sprite->texture,
    sfTrue);
    sfSprite_setScale(win->inv->player, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->inv->player, win->player->sprite->rect);
    sfSprite_setPosition(win->inv->player, get_pos_float(1440, 305));
}

void init_player(player_t *player)
{
    char *skin = malloc(sizeof(char) * 80);

    player->sprite->sprite = NULL;
    player->sprite->texture = NULL;
    player->sprite->rect = get_rect(15, 15, 18, 18);
    player->direction = 1;
    player->move_rect = 0;
    player->last_page = CASTLE;
    skin = my_strcat("ressources/pack/Pixel_Champions/Magical Heroes/",
    player->name);
    skin = my_strcat(skin, ".png");
    init_sprite(&player->sprite[0], skin, get_pos_float(player->speed.x,
    player->speed.y));
    sfSprite_setScale(player->sprite->sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(player->sprite->sprite, player->sprite->rect);
    if (player->last_pos.x >= 0)
        sfSprite_setPosition(player->sprite->sprite, player->last_pos);
    else
        sfSprite_setPosition(player->sprite->sprite, get_pos_float(900, 600));
}