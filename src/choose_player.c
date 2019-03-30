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
    win->player->name = "Glenys";
    win->player->health = 150;
    win->player->strength = 150;
    sfText_setString(win->scene[GAME].text[1].str, win->player->name);
    sfText_setString(win->scene[GAME].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[GAME].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Glenys-the-Demonswordsman.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        win->scene[GAME].button[i].idle_color = sfRed;
        sfRectangleShape_setFillColor(win->scene[GAME].button[i].rect, win->scene[GAME].button[i].idle_color);
    }
    win->scene[GAME].button[0].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[0].rect, win->scene[GAME].button[0].idle_color);
}

void choose_hex(window_t *win)
{
    win->player->name = "Hex";
    win->player->health = 70;
    win->player->strength = 70;
    sfText_setString(win->scene[GAME].text[1].str, win->player->name);
    sfText_setString(win->scene[GAME].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[GAME].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Hex-the-Time-Witch.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        win->scene[GAME].button[i].idle_color = sfRed;
        sfRectangleShape_setFillColor(win->scene[GAME].button[i].rect, win->scene[GAME].button[i].idle_color);
    }
    win->scene[GAME].button[1].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[1].rect, win->scene[GAME].button[1].idle_color);
}

void choose_ley(window_t *win)
{
    win->player->name = "Ley";
    win->player->health = 80;
    win->player->strength = 90;
    sfText_setString(win->scene[GAME].text[1].str, win->player->name);
    sfText_setString(win->scene[GAME].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[GAME].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Ley-the-Monster-Whisperer.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        win->scene[GAME].button[i].idle_color = sfRed;
        sfRectangleShape_setFillColor(win->scene[GAME].button[i].rect, win->scene[GAME].button[i].idle_color);
    }
    win->scene[GAME].button[2].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[2].rect, win->scene[GAME].button[2].idle_color);
}

void choose_linail(window_t *win)
{
    win->player->name = "Linail";
    win->player->health = 110;
    win->player->strength = 70;
    sfText_setString(win->scene[GAME].text[1].str, win->player->name);
    sfText_setString(win->scene[GAME].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[GAME].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Linail-the-High-Priestess.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        win->scene[GAME].button[i].idle_color = sfRed;
        sfRectangleShape_setFillColor(win->scene[GAME].button[i].rect, win->scene[GAME].button[i].idle_color);
    }
    win->scene[GAME].button[3].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[3].rect, win->scene[GAME].button[3].idle_color);
}

void choose_oratio(window_t *win)
{
    win->player->name = "Oratio";
    win->player->health = 100;
    win->player->strength = 100;
    sfText_setString(win->scene[GAME].text[1].str, win->player->name);
    sfText_setString(win->scene[GAME].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[GAME].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Oratio-the-Mercenary.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        win->scene[GAME].button[i].idle_color = sfRed;
        sfRectangleShape_setFillColor(win->scene[GAME].button[i].rect, win->scene[GAME].button[i].idle_color);
    }
    win->scene[GAME].button[4].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[4].rect, win->scene[GAME].button[4].idle_color);
}

void choose_ouzo(window_t *win)
{
    win->player->name = "Ouzo";
    win->player->health = 70;
    win->player->strength = 120;
    sfText_setString(win->scene[GAME].text[1].str, win->player->name);
    sfText_setString(win->scene[GAME].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[GAME].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Ouzo-the-Wolf-Bard.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        win->scene[GAME].button[i].idle_color = sfRed;
        sfRectangleShape_setFillColor(win->scene[GAME].button[i].rect, win->scene[GAME].button[i].idle_color);
    }
    win->scene[GAME].button[5].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[5].rect, win->scene[GAME].button[5].idle_color);
}

void choose_prime(window_t *win)
{
    win->player->name = "Prime";
    win->player->health = 150;
    win->player->strength = 70;
    sfText_setString(win->scene[GAME].text[1].str, win->player->name);
    sfText_setString(win->scene[GAME].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[GAME].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Prime-the-Great-Sage.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        win->scene[GAME].button[i].idle_color = sfRed;
        sfRectangleShape_setFillColor(win->scene[GAME].button[i].rect, win->scene[GAME].button[i].idle_color);
    }
    win->scene[GAME].button[6].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[6].rect, win->scene[GAME].button[6].idle_color);
}

void choose_wyvera(window_t *win)
{
    win->player->name = "Wyvera";
    win->player->health = 110;
    win->player->strength = 90;
    sfText_setString(win->scene[GAME].text[1].str, win->player->name);
    sfText_setString(win->scene[GAME].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[GAME].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[GAME].sprite[0].texture);
    win->scene[GAME].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Wyvera-the-Queen-Dragoon.png", NULL);
    sfSprite_setTexture(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    for (int i = 0; i < win->scene[GAME].nb_button; i++) {
        win->scene[GAME].button[i].idle_color = sfRed;
        sfRectangleShape_setFillColor(win->scene[GAME].button[i].rect, win->scene[GAME].button[i].idle_color);
    }
    win->scene[GAME].button[7].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[GAME].button[7].rect, win->scene[GAME].button[7].idle_color);
}