/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** volume
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int change_volume_string(window_t *win)
{
    char *str = malloc(sizeof(char) * 5);

    if (str == NULL)
        return (84);
    sfMusic_setVolume(win->music->menu_song, win->music->volume);
    sfMusic_setVolume(win->music->button_sound, win->music->volume);
    str = my_itc(win->music->volume);
    str = my_strcat(str, "%");
    sfText_setString(win->scene[OPTIONS].text[4].str, str);
    return (0);
}

static int check_drag(window_t *win, sfVector2f pos, sfVector2f size)
{
    int pos_volume = 1118;
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    win->music->vol_pos = click_pos.x;
    float diff = win->music->vol_pos - pos_volume;

    if (win->page == OPTIONS && click_pos.x > pos.x &&
    click_pos.x < pos.x + size.x &&
    click_pos.y > pos.y && click_pos.y < pos.y + size.y) {
        if (win->music->vol_pos >= 1118 && win->music->vol_pos <= 1500) {
            win->music->volume = (diff) * 0.264;
            if (change_volume_string(win) == 84)
                return (84);
            win->music->vol_pos = click_pos.x - size.x / 2;
            sfRectangleShape_setPosition(win->scene[OPTIONS].button[4].shape,
            get_pos_float(win->music->vol_pos, 800 - 250));
        }
    }
    return (0);
}

int drag_button(window_t *win)
{
    sfVector2f pos = sfRectangleShape_getPosition(win->
    scene[OPTIONS].button[4].shape);
    sfVector2f size = sfRectangleShape_getSize(win->
    scene[OPTIONS].button[4].shape);

    if (check_drag(win, pos, size) == 84)
        return (84);
    return (0);
}