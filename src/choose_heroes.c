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
    char *name = {"ressources/images/Hex.png"};
    char *desc_file = {"ressources/text/description/Hex_des"};
    char *buffer = get_buffer(desc_file);

    win->player->name = "Hex";
    win->player->health = 70;
    win->player->actual_health = 70;
    win->player->strength = 70;
    set_description_text(win, buffer);
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
    char *name = {"ressources/images/Linail.png"};
    char *desc_file = {"ressources/text/description/Linail_des"};
    char *buffer = get_buffer(desc_file);

    win->player->name = "Linail";
    win->player->health = 110;
    win->player->actual_health = 110;
    win->player->strength = 70;
    set_description_text(win, buffer);
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
    char *name = {"ressources/images/Ouzo.png"};
    char *desc_file = {"ressources/text/description/Ouzo_des"};
    char *buffer = get_buffer(desc_file);

    win->player->name = "Ouzo";
    win->player->health = 70;
    win->player->actual_health = 70;
    win->player->strength = 120;
    set_description_text(win, buffer);
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
    char *name = {"ressources/images/Prime.png"};
    char *desc_file = {"ressources/text/description/Prime_des"};
    char *buffer = get_buffer(desc_file);

    win->player->name = "Prime";
    win->player->health = 150;
    win->player->actual_health = 150;
    win->player->strength = 70;
    set_description_text(win, buffer);
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
    char *name = {"ressources/images/Wyvera.png"};
    char *desc_file = {"ressources/text/description/Wyvera_des"};
    char *buffer = get_buffer(desc_file);

    win->player->name = "Wyvera";
    win->player->health = 110;
    win->player->actual_health = 110;
    win->player->strength = 90;
    set_description_text(win, buffer);
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