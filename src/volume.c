/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** volume
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void set_volume(window_t *win)
{
    sfMusic_setVolume(win->music->menu_song, win->music->volume);
    sfMusic_setVolume(win->music->button_sound, win->music->volume);
    sfMusic_setVolume(win->music->town_song, win->music->volume);
    sfMusic_setVolume(win->music->boss_song, win->music->volume);
    sfMusic_setVolume(win->music->door_close, win->music->volume);
    sfMusic_setVolume(win->music->door_open, win->music->volume);
    sfMusic_setVolume(win->music->stone_door, win->music->volume);
    sfMusic_setVolume(win->music->boss_battle, win->music->volume);
    sfMusic_setVolume(win->music->boss_final, win->music->volume);
    sfMusic_setVolume(win->music->special_attack, win->music->volume);
    sfMusic_setVolume(win->music->heal, win->music->volume);
    sfMusic_setVolume(win->music->enemy_attack, win->music->volume);
    sfMusic_setVolume(win->music->basic_attack, win->music->volume);
    sfMusic_setVolume(win->music->open_menus, win->music->volume);
}

static int change_volume_string(window_t *win)
{
    char *str = malloc(sizeof(char) * 5);

    if (str == NULL)
        return (84);
    set_volume(win);
    str = my_itc(win->music->volume);
    str = my_strcat(str, "%");
    sfText_setString(win->scene[OPTIONS].text[4].str, str);
    return (0);
}

static int change_volume_pos(window_t *win, sfVector2i c_pos, sfVector2f size)
{
    int pos_volume = 1118;
    float diff = win->music->vol_pos - pos_volume;

    if (win->music->vol_pos >= 1118 && win->music->vol_pos <= 1500) {
        win->music->volume = (diff) * 0.264;
        if (change_volume_string(win) == 84)
            return (84);
        win->music->vol_pos = c_pos.x - size.x / 2;
        win->music->pos_sound = get_pos_float(win->music->vol_pos,
        800 - 250);
        sfRectangleShape_setPosition(win->scene[OPTIONS].button[4].shape,
        win->music->pos_sound);
    }
    return (0);
}

static int check_drag(window_t *win, sfVector2f pos, sfVector2f size)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    win->music->vol_pos = click_pos.x;

    if (win->page == OPTIONS && click_pos.x > pos.x &&
    click_pos.x < pos.x + size.x &&
    click_pos.y > pos.y && click_pos.y < pos.y + size.y) {
        if (change_volume_pos(win, click_pos, size) == 84)
            return (84);
    }
    return (0);
}

int drag_button(window_t *win)
{
    sfVector2f pos;
    sfVector2f size;

    if (win->actual_page == OPTIONS) {
        pos = sfRectangleShape_getPosition(win->scene[OPTIONS].button[4].shape);
        size = sfRectangleShape_getSize(win->scene[OPTIONS].button[4].shape);
        if (check_drag(win, pos, size) == 84)
            return (84);
    }
    return (0);
}