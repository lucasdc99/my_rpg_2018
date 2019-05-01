/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** choose_heroes
*/

#include "../include/rpg.h"
#include "../include/my.h"

void choose_hex(window_t *win)
{
    char *name = {"ressources/images/sprites/Hex.png"};

    win->player->name = "Hex";
    win->player->health = 70;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    sfMusic_play(win->music->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile(name,
    NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite,
    get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].rect);
}

void choose_linail(window_t *win)
{
    char *name = {"ressources/images/sprites/Linail.png"};

    win->player->name = "Linail";
    win->player->health = 110;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    sfMusic_play(win->music->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile(name,
    NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite,
    get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].rect);
}

void choose_ouzo(window_t *win)
{
    char *name = {"ressources/images/sprites/Ouzo.png"};

    win->player->name = "Ouzo";
    win->player->health = 70;
    win->player->strength = 120;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    sfMusic_play(win->music->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile(name,
    NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite,
    get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].rect);
}

void choose_prime(window_t *win)
{
    char *name = {"ressources/images/sprites/Prime.png"};

    win->player->name = "Prime";
    win->player->health = 150;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    sfMusic_play(win->music->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile(name,
    NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite,
    get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].rect);
}

void choose_wyvera(window_t *win)
{
    char *name = {"ressources/images/sprites/Wyvera.png"};

    win->player->name = "Wyvera";
    win->player->health = 110;
    win->player->strength = 90;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    sfMusic_play(win->music->button_sound);
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile(name,
    NULL);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite,
    get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].rect);
}