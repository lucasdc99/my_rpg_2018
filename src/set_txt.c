/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void set_text_ok(window_t *win)
{
    char *str = win->player->name;

    str = my_strcat(str, "\n");
    str = my_strcat(str, "Vie: ");
    str = my_strcat(str, my_itc(win->player->actual_health));
    str = my_strcat(str, "/");
    str = my_strcat(str, my_itc(win->player->health));
    str = my_strcat(str, "\n");
    str = my_strcat(str, "Puissance: ");
    str = my_strcat(str, my_itc(win->player->strength));
    str = my_strcat(str, "\n");
    sfText_setString(win->inv->text->str, str);
}

void set_text_inv(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f move_pos = get_pos_float(click_pos.x, click_pos.y);
    sfVector2f pos;
    int ok = 0;
    char *str = NULL;

    pos = sfSprite_getPosition(win->objects[ARMOR].sprite);
    if (is_inside_zone(get_pos_float(pos.x - 10, pos.y - 10), get_pos_float(pos.x + 80, pos.y + 80), move_pos) == 1) {
        str = my_strcat("Armure", "\n");
        str = my_strcat(str, "Vie + 20");
        sfText_setString(win->inv->text->str, str);
        ok = 1;
    }
    pos = sfSprite_getPosition(win->objects[SWORD].sprite);
    if (is_inside_zone(get_pos_float(pos.x - 10, pos.y - 10), get_pos_float(pos.x + 80, pos.y + 80), move_pos) == 1) {
        str = my_strcat("Dague", "\n");
        str = my_strcat(str, "Puissance + 20");
        sfText_setString(win->inv->text->str, str);
        ok = 1;
    }
    if (ok == 0)
        set_text_ok(win);
}