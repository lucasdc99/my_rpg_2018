/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** key_pressed
*/

#include "../include/rpg.h"
#include "../include/my.h"

void pick_sword(window_t *win)
{
    int actual_pos = -1;
    int type = 0;

    sfText_setString(win->text->str, "\n");
    sfSprite_setPosition(win->objects[SWORD].sprite, get_inv_pos(win->inv));
    actual_pos = get_actual_pos_inv(win->inv, get_pos_float(0, 0));
    win->inv->items[actual_pos].busy = 1;
    type = win->objects[SWORD].type;
    win->inv->items[actual_pos].name = get_name_from_type(type);
    win->objects[SWORD].item = 1;
    win->objects[SWORD].depth = 2;
    sfText_setString(win->text->str, "Appuyez sur Enter pour continuer");
    display_text_in_textbox(win->quests);
    win->pause = 1;
    win->talking = 1;
}

void pick_armor(window_t *win)
{
    int actual_pos = -1;
    int type = 0;

    sfText_setString(win->text->str, "\n");
    sfSprite_setPosition(win->objects[ARMOR].sprite, get_inv_pos(win->inv));
    actual_pos = get_actual_pos_inv(win->inv, get_pos_float(0, 0));
    win->inv->items[actual_pos].busy = 1;
    type = win->objects[ARMOR].type;
    win->inv->items[actual_pos].name = get_name_from_type(type);
    win->objects[ARMOR].item = 1;
    win->objects[ARMOR].depth = 2;
    display_text_in_textbox(win->quests);
    win->pause = 1;
    win->talking = 1;
}