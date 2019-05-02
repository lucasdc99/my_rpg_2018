/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** print_descriptions
*/

#include "../include/rpg.h"
#include "../include/my.h"

void draw_desc_i_one(window_t *win, char *str, int hit, sfUint32 *tmp)
{
    hit = 30 + (win->player->strength / 10);
    str = my_strcat("Attaque Sp_éciale: -", my_itc(hit));
    str = my_strcat(str, " PV (_érosion)");
    str_to_unicode(str, &tmp);
    sfText_setUnicodeString(win->text->str, tmp);
}

void draw_desc_i_two(window_t *win, char *str, int hit, sfUint32 *tmp)
{
    hit = 30 + (win->player->strength / 10);
    str = my_strcat("R_ég_énaration: +", my_itc(hit));
    str = my_strcat(str, " PV");
    str_to_unicode(str, &tmp);
    sfText_setUnicodeString(win->text->str, tmp);
}

void draw_description(window_t *win, int i)
{
    sfUint32 *tmp;
    int hit = 0;
    char *str = NULL;

    sfText_setPosition(win->text->str, get_pos_float(600, 900));
    if (i == 0) {
        hit = 20 + (win->player->strength / 10);
        str = my_strcat("Attaque Basique: -", my_itc(hit));
        str = my_strcat(str, " PV");
        str_to_unicode(str, &tmp);
        sfText_setUnicodeString(win->text->str, tmp);
    }
    if (i == 1)
        draw_desc_i_one(win, str, hit, tmp);
    if (i == 2)
        draw_desc_i_two(win, str, hit, tmp);
}

void set_description_text(window_t *win, char *buffer)
{
    sfUint32 *tmp;

    sfText_setString(win->scene[HEROES].text[1].str, win->player->name);
    sfText_setString(win->scene[HEROES].text[3].str,
    my_itc(win->player->health));
    sfText_setString(win->scene[HEROES].text[5].str,
    my_itc(win->player->strength));
    if (buffer != NULL)
        str_to_unicode(buffer, &tmp);
    sfText_setUnicodeString(win->scene[HEROES].text[7].str, tmp);
}