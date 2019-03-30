/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** choose_player
*/

#include "../include/rpg.h"
#include "../include/my.h"

void choose_glenys(window_t *win)
{
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Glenys-the-Demonswordsman.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}

void choose_hex(window_t *win)
{
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Hex-the-Time-Witch.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}

void choose_ley(window_t *win)
{
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Ley-the-Monster-Whisperer.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}

void choose_linail(window_t *win)
{
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Linail-the-High-Priestess.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}

void choose_oratio(window_t *win)
{
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Oratio-the-Mercenary.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}

void choose_ouzo(window_t *win)
{
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Ouzo-the-Wolf-Bard.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}

void choose_prime(window_t *win)
{
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Prime-the-Great-Sage.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}

void choose_wyvera(window_t *win)
{
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Wyvera-the-Queen-Dragoon.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
}