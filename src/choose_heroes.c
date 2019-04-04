/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** choose_heroes
*/

#include "../include/rpg.h"
#include "../include/my.h"

void choose_glenys(window_t *win)
{
    win->player->name = "Glenys-the-Demonswordsman";
    win->player->health = 150;
    win->player->strength = 150;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Glenys-the-Demonswordsman.png", NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    // for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
    //     win->scene[HEROES].button[i].idle_color = sfRed;
    //     sfRectangleShape_setFillColor(win->scene[HEROES].button[i].shape, win->scene[HEROES].button[i].idle_color);
    // }
    // win->scene[HEROES].button[0].idle_color = sfYellow;
    // sfRectangleShape_setFillColor(win->scene[HEROES].button[0].shape, win->scene[HEROES].button[0].idle_color);
}

void choose_hex(window_t *win)
{
    win->player->name = "Hex-the-Time-Witch";
    win->player->health = 70;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Hex-the-Time-Witch.png", NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    // for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
    //     win->scene[HEROES].button[i].idle_color = sfRed;
    //     sfRectangleShape_setFillColor(win->scene[HEROES].button[i].shape, win->scene[HEROES].button[i].idle_color);
    // }
    // win->scene[HEROES].button[1].idle_color = sfYellow;
    // sfRectangleShape_setFillColor(win->scene[HEROES].button[1].shape, win->scene[HEROES].button[1].idle_color);
}

void choose_ley(window_t *win)
{
    win->player->name = "Ley-the-Monster-Whisperer";
    win->player->health = 80;
    win->player->strength = 90;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Ley-the-Monster-Whisperer.png", NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    // for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
    //     win->scene[HEROES].button[i].idle_color = sfRed;
    //     sfRectangleShape_setFillColor(win->scene[HEROES].button[i].shape, win->scene[HEROES].button[i].idle_color);
    // }
    // win->scene[HEROES].button[2].idle_color = sfYellow;
    // sfRectangleShape_setFillColor(win->scene[HEROES].button[2].shape, win->scene[HEROES].button[2].idle_color);
}

void choose_linail(window_t *win)
{
    win->player->name = "Linail-the-High-Priestess";
    win->player->health = 110;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Linail-the-High-Priestess.png", NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    // for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
    //     win->scene[HEROES].button[i].idle_color = sfRed;
    //     sfRectangleShape_setFillColor(win->scene[HEROES].button[i].shape, win->scene[HEROES].button[i].idle_color);
    // }
    // win->scene[HEROES].button[3].idle_color = sfYellow;
    // sfRectangleShape_setFillColor(win->scene[HEROES].button[3].shape, win->scene[HEROES].button[3].idle_color);
}

void choose_oratio(window_t *win)
{
    win->player->name = "Oratio-the-Mercenary";
    win->player->health = 100;
    win->player->strength = 100;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Oratio-the-Mercenary.png", NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    // for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
    //     win->scene[HEROES].button[i].idle_color = sfRed;
    //     sfRectangleShape_setFillColor(win->scene[HEROES].button[i].shape, win->scene[HEROES].button[i].idle_color);
    // }
    // win->scene[HEROES].button[4].idle_color = sfYellow;
    // sfRectangleShape_setFillColor(win->scene[HEROES].button[4].shape, win->scene[HEROES].button[4].idle_color);
}

void choose_ouzo(window_t *win)
{
    win->player->name = "Ouzo-the-Wolf-Bard";
    win->player->health = 70;
    win->player->strength = 120;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Ouzo-the-Wolf-Bard.png", NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    // for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
    //     win->scene[HEROES].button[i].idle_color = sfRed;
    //     sfRectangleShape_setFillColor(win->scene[HEROES].button[i].shape, win->scene[HEROES].button[i].idle_color);
    // }
    // win->scene[HEROES].button[5].idle_color = sfYellow;
    // sfRectangleShape_setFillColor(win->scene[HEROES].button[5].shape, win->scene[HEROES].button[5].idle_color);
}

void choose_prime(window_t *win)
{
    win->player->name = "Prime-the-Great-Sage";
    win->player->health = 150;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Prime-the-Great-Sage.png", NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    // for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
    //     win->scene[HEROES].button[i].idle_color = sfRed;
    //     sfRectangleShape_setFillColor(win->scene[HEROES].button[i].shape, win->scene[HEROES].button[i].idle_color);
    // }
    // win->scene[HEROES].button[6].idle_color = sfYellow;
    // sfRectangleShape_setFillColor(win->scene[HEROES].button[6].shape, win->scene[HEROES].button[6].idle_color);
}

void choose_wyvera(window_t *win)
{
    win->player->name = "Wyvera-the-Queen-Dragoon";
    win->player->health = 110;
    win->player->strength = 90;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str, my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str, my_itc(win->player->strength));
    sfMusic_play(win->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile("ressources/pack/Pixel_Champions/Magical Heroes/Wyvera-the-Queen-Dragoon.png", NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite, get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite, win->scene[HEROES].sprite[0].rect);
    // for (int i = 0; i < win->scene[HEROES].nb_button; i++) {
    //     win->scene[HEROES].button[i].idle_color = sfRed;
    //     sfRectangleShape_setFillColor(win->scene[HEROES].button[i].shape, win->scene[HEROES].button[i].idle_color);
    // }
    // win->scene[HEROES].button[7].idle_color = sfYellow;
    // sfRectangleShape_setFillColor(win->scene[HEROES].button[7].shape, win->scene[HEROES].button[7].idle_color);
}