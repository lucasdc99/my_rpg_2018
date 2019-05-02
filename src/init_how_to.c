/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_how_to
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_text_and_sprite(window_t *win, sfVector2f pos_window)
{
    init_sprite(&win->scene[HOW_TO_PLAY].sprite[0],
    "ressources/images/menu.png", get_pos_float(0, 0));
    init_text(&win->scene[HOW_TO_PLAY].text[0],
    "Tutoriel", pos_window, win->font_berlin);
}

static void setup_unicode_help(window_t *win, sfVector2f pos_window)
{
    char *buff = get_buffer("ressources/text/help");
    sfUint32 *tmp;

    init_text(&win->scene[HOW_TO_PLAY].text[1],
    buff, pos_window, win->font_berlin);
    str_to_unicode(buff, &tmp);
    sfText_setUnicodeString(win->scene[HOW_TO_PLAY].text[1].str, tmp);
}

window_t *init_how_to_play(window_t *win)
{
    sfVector2f size = get_pos_float(500, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window = {(size_window.x - size.x + 250) / 2, 50};

    set_struct(win, 1, 2, 1);
    init_text_and_sprite(win, pos_window);
    pos_window.x = 100;
    pos_window.y += 150;
    setup_unicode_help(win, pos_window);
    win->scene[HOW_TO_PLAY].button[0].callback = &main_menu;
    pos_window.x = (size_window.x - size.x - 20);
    pos_window.y = 900;
    set_next_buttons(&win->scene[HOW_TO_PLAY].button[0],
    win->rect_buttons, RETOUR);
    init_button(&win->scene[HOW_TO_PLAY].button[0], pos_window,
    size, win->texture_button);
    pos_window.x += 30;
    return (win);
}