/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include "../include/rpg.h"
#include "../include/my.h"

int check_existing_inventory(window_t *win, char *name)
{
    for (int i = 0; i < 15; i++) {
        if (win->inv->items[i].name != NULL &&
        my_strcmp(win->inv->items[i].name, name) == 0) {
            return (1);
        }
    }
    return (0);
}

void save_inventory(window_t *win)
{
    FILE *fp = fopen("ressources/text/inventory", "wb+");

    for (int i = 0; i < 15; i++) {
        if (win->inv->items[i].name == NULL)
            fwrite("(null)", sizeof(char), 6, fp);
        else
            fwrite(win->inv->items[i].name, sizeof(char), my_strlen(win->inv->items[i].name), fp);
        fwrite("\n", sizeof(char), 1, fp);
    }
    fclose(fp);
}

void open_inventory(window_t *win)
{
    win->pause = 1;
    win->inventory = 1;
    if (win->actual_page == TOWN) {
        for (int i = 1; i < win->scene[TOWN].nb_sprite; i++)
            win->scene[TOWN].sprite[i].depth = -1;
    }
    sfMusic_play(win->music->open_menus);
}

void check_equip_stuff(window_t *win, int actual_pos, int i)
{
    int type = -1;

    type = my_strcmp(win->inv->items[actual_pos].name, "Dague");
    if (actual_pos >= 12 && type == 0) {
        if (win->objects[SWORD].equiped == 0)
            win->player->strength += 20;
        win->objects[i].equiped = 1;
    }
    type = my_strcmp(win->inv->items[actual_pos].name, "Armure");
    if (actual_pos >= 12 && type == 0) {
        if (win->objects[ARMOR].equiped == 0) {
            win->player->health += 20;
            win->player->actual_health += 20;
        }
        win->objects[i].equiped = 1;
    }
}

void check_desequip_stuff(window_t *win, int actual_pos, int i)
{
    int type = -1;

    type = my_strcmp(win->inv->items[actual_pos].name, "Dague");
    if (actual_pos < 12 && type == 0) {
        if (win->objects[SWORD].equiped == 1)
            win->player->strength -= 20;
        win->objects[i].equiped = 0;
    }
    type = my_strcmp(win->inv->items[actual_pos].name, "Armure");
    if (actual_pos < 12 && type == 0) {
        if (win->objects[ARMOR].equiped == 1) {
            win->player->health -= 20;
            win->player->actual_health -= 20;
        }
        win->objects[i].equiped = 0;
    }
}

static void put_position_in_inv(window_t *win, sfVector2f m_p, int a_p, int i)
{
    sfVector2f pos;

    if (is_item_outside_inv(m_p, win->inv) == 0) {
        pos = get_nearest_item_pos(win->inv, m_p);
        if (win->inv->items[a_p].busy == 0)
            sfSprite_setPosition(win->objects[i].sprite, pos);
        else
            sfSprite_setPosition(win->objects[i].sprite,
            get_inv_pos(win->inv));
        win->inv->items[a_p].busy = 1;
    } else {
        pos = get_inv_pos(win->inv);
        sfSprite_setPosition(win->objects[i].sprite, pos);
        win->inv->items[a_p].busy = 1;
    }
}

void check_drag_and_drop_inv(window_t *win)
{
    sfVector2i click_pos;
    sfVector2f move_pos;
    int actual_pos = 0;
    int type = 0;

    for (int i = 0; i < win->nb_objects; i++) {
        click_pos = sfMouse_getPositionRenderWindow(win->window);
        move_pos = get_pos_float(click_pos.x, click_pos.y);
        if (win->objects[i].item == 2 && win->objects[i].depth == 2) {
            sfSprite_setPosition(win->objects[i].sprite,
            get_inv_pos(win->inv));
            actual_pos = get_actual_pos_inv(win->inv, move_pos);
            type = win->objects[i].type;
            win->inv->items[actual_pos].name = get_name_from_type(type);
            win->objects[i].item = 1;
            check_equip_stuff(win, actual_pos, i);
            check_desequip_stuff(win, actual_pos, i);
            put_position_in_inv(win, move_pos, actual_pos, i);
        }
    }
}