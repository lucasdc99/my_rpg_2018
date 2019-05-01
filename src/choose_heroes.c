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
    char *desc_file = {"ressources/text/description/Hex_des"};
    char *buffer = get_buffer(desc_file);
    sfUint32 *tmp;

    win->player->name = "Hex";
    win->player->health = 70;
    win->player->actual_health = 70;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    if (buffer != NULL)
        str_to_unicode(buffer, &tmp);
    sfText_setUnicodeString(win->scene[HEROES].text[7].str, tmp);
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
    char *desc_file = {"ressources/text/description/Linail_des"};
    char *buffer = get_buffer(desc_file);
    sfUint32 *tmp;

    win->player->name = "Linail";
    win->player->health = 110;
    win->player->actual_health = 110;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    if (buffer != NULL)
        str_to_unicode(buffer, &tmp);
    sfText_setUnicodeString(win->scene[HEROES].text[7].str, tmp);
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
    char *desc_file = {"ressources/text/description/Ouzo_des"};
    char *buffer = get_buffer(desc_file);
    sfUint32 *tmp;

    win->player->name = "Ouzo";
    win->player->health = 70;
    win->player->actual_health = 70;
    win->player->strength = 120;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    if (buffer != NULL)
        str_to_unicode(buffer, &tmp);
    sfText_setUnicodeString(win->scene[HEROES].text[7].str, tmp);
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
    char *desc_file = {"ressources/text/description/Prime_des"};
    char *buffer = get_buffer(desc_file);
    sfUint32 *tmp;

    win->player->name = "Prime";
    win->player->health = 150;
    win->player->actual_health = 150;
    win->player->strength = 70;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    if (buffer != NULL)
        str_to_unicode(buffer, &tmp);
    sfText_setUnicodeString(win->scene[HEROES].text[7].str, tmp);
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
    char *desc_file = {"ressources/text/description/Wyvera_des"};
    char *buffer = get_buffer(desc_file);
    sfUint32 *tmp;

    win->player->name = "Wyvera";
    win->player->health = 110;
    win->player->actual_health = 110;
    win->player->strength = 90;
    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    if (buffer != NULL)
        str_to_unicode(buffer, &tmp);
    sfText_setUnicodeString(win->scene[HEROES].text[7].str, tmp);
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