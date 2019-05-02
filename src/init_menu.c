/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_menu
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void loop_buttons(window_t *win)
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
        init_button(&win->scene[MAINMENU].button[i],
        get_pos_float(pos_window.x - 600, pos_window.y),
        size, win->texture_button);
        pos_window.y += size.y + 20;
    }
}

static void init_buttons(window_t *win)
{
    loop_buttons(win);
    if (win->no_saves == 0)
        win->scene[MAINMENU].button[0].callback = &play_game;
    else
        win->scene[MAINMENU].button[0].callback = NULL;
    win->scene[MAINMENU].button[1].callback = &heroes_menu;
    win->scene[MAINMENU].button[2].callback = &how_to_play;
    win->scene[MAINMENU].button[3].callback = &options;
    win->scene[MAINMENU].button[4].callback = &quit;
}

window_t *init_menu(window_t *win)
{
    set_struct(win, 5, 1, 1);
    init_text(&win->scene[MAINMENU].text[0], "Tekzerk",
    get_pos_float(700, 10), win->font_title);
    sfText_setColor(win->scene[MAINMENU].text[0].str, sfWhite);
    sfText_setCharacterSize(win->scene[MAINMENU].text[0].str, 150);
    init_sprite(&win->scene[MAINMENU].sprite[0],
    "ressources/pack/background/frame2.png", get_pos_float(0, 0));
    win->scene[MAINMENU].sprite[0].rect = get_rect(0, 0, 1920, 1080);
    init_buttons(win);
    sfSprite_setTextureRect(win->scene[MAINMENU].sprite[0].sprite,
    win->scene[MAINMENU].sprite[0].rect);
    if (sfMusic_getStatus(win->music->menu_song) == sfStopped)
        sfMusic_play(win->music->menu_song);
    return (win);
}