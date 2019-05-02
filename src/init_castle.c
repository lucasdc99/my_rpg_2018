/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_castle
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void set_sprites(window_t *win)
{
    win->scene[CASTLE].sprite[5].rect = get_rect(19, 0, 11, 20);
    win->scene[CASTLE].sprite[6].rect = get_rect(19, 0, 11, 20);
    sfSprite_setTextureRect(win->scene[CASTLE].sprite[5].sprite,
    win->scene[CASTLE].sprite[5].rect);
    sfSprite_setTextureRect(win->scene[CASTLE].sprite[6].sprite,
    win->scene[CASTLE].sprite[6].rect);
    sfSprite_setScale(win->scene[CASTLE].sprite[5].sprite,
    get_pos_float(2, 2));
    sfSprite_setScale(win->scene[CASTLE].sprite[6].sprite,
    get_pos_float(2, 2));
}

static int init_sprites(window_t *win)
{
    int pos_x[] = {0, 307, 81, 1350, 1520, 421, 1473};
    int pos_y[] = {0, 560, 461, 508, 500, 263, 263};
    char *name[] = {
        "ressources/images/castle.png", "ressources/images/tree3.png",
        "ressources/images/tree3.png", "ressources/images/tree3.png",
        "ressources/images/tree2.png",
        "ressources/images/torch.png",
        "ressources/images/torch.png"};

    for (int i = 0; i < win->scene[CASTLE].nb_sprite; i++) {
        if (init_sprite(&win->scene[CASTLE].sprite[i], name[i],
        get_pos_float(pos_x[i], pos_y[i])) == 84)
            return (84);
        win->scene[CASTLE].sprite[i].depth = 1;
    }
    win->scene[CASTLE].sprite[0].depth = -1;
    set_sprites(win);
    return (0);
}

static int init_buttons(window_t *win, sfVector2f size)
{
    int order_button[] = {REPRENDRE, QUITTER};

    set_next_buttons(&win->scene[CASTLE].button[0], win->rect_buttons,
    order_button[0]);
    if (init_button(&win->scene[CASTLE].button[0], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (84);
    set_next_buttons(&win->scene[CASTLE].button[1], win->rect_buttons,
    order_button[1]);
    if (init_button(&win->scene[CASTLE].button[1], get_pos_float(-200, -200),
    size, win->texture_button) == 84)
        return (84);
    return (0);
}

window_t *init_castle(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);

    if (set_struct(win, 2, 1, 7) == 84)
        return (NULL);
    if (init_buttons(win, size) == 84)
        return (NULL);
    if (init_sprites(win) == 84)
        return (NULL);
    if (init_text(&win->scene[CASTLE].text[0], "TEKZERK",
    get_pos_float(550, 400), win->font_title) == 84)
        return (NULL);
    sfText_setCharacterSize(win->scene[CASTLE].text[0].str, 200);
    sfText_setFillColor(win->scene[CASTLE].text[0].str,
    sfColor_fromRGBA(255, 255, 255, 0));
    win->scene[CASTLE].button[0].callback = &quit_pause;
    win->scene[CASTLE].button[1].callback = &main_menu;
    return (win);
}