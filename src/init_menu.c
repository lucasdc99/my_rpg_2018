/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_menu
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int loop_buttons(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window = {
        (size_window.x - size.x) / 2,
        (size_window.y - size.y) / 4};
    int order_button[] = {JOUER, NOUVEAU, TUTORIEL, PARAM, QUITTER};

    for (int i = 0; i < win->scene[MAINMENU].nb_button; i++) {
        set_next_buttons(&win->scene[MAINMENU].button[i],
        win->rect_buttons, order_button[i]);
        if (init_button(&win->scene[MAINMENU].button[i],
        get_pos_float(pos_window.x - 600, pos_window.y),
        size, win->texture_button) == 84)
            return (84);
        pos_window.y += size.y + 20;
    }
    return (0);
}

static int init_buttons(window_t *win)
{
    if (loop_buttons(win) == 84)
        return (84);
    if (win->no_saves == 0)
        win->scene[MAINMENU].button[0].callback = &play_game;
    else
        win->scene[MAINMENU].button[0].callback = NULL;
    win->scene[MAINMENU].button[1].callback = &heroes_menu;
    win->scene[MAINMENU].button[2].callback = &how_to_play;
    win->scene[MAINMENU].button[3].callback = &options;
    win->scene[MAINMENU].button[4].callback = &quit;
    return (0);
}

window_t *init_menu(window_t *win)
{
    if (set_struct(win, 5, 1, 1) == 84)
        return (NULL);
    if (init_text(&win->scene[MAINMENU].text[0], "Tekzerk",
    get_pos_float(700, 10), win->font_title) == 84)
        return (NULL);
    sfText_setColor(win->scene[MAINMENU].text[0].str, sfWhite);
    sfText_setCharacterSize(win->scene[MAINMENU].text[0].str, 150);
    if (init_sprite(&win->scene[MAINMENU].sprite[0],
    "ressources/images/frame2.png", get_pos_float(0, 0)) == 84)
        return (NULL);
    win->scene[MAINMENU].sprite[0].rect = get_rect(0, 0, 1920, 1080);
    if (init_buttons(win) == 84)
        return (NULL);
    sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite,
    win->scene[MAINMENU].sprite[0].rect);
    if (sfMusic_getStatus(win->music->menu_song) == sfStopped)
        sfMusic_play(win->music->menu_song);
    return (win);
}