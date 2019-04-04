/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_options
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *init_options(window_t *win)
{
    sfVector2f size = get_pos_float(500, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;
    sfTexture *texture;
    char **text = transform_2d("OPTIONS\nFPS\nVSYNC\nMusic\n0\n");
    int order_button[] = {SAUVEGARDER, CURSEUR, CURSEUR, CURSEUR, CURSEUR};

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = 800;
    win->scene[OPTIONS].button = malloc(sizeof(button_t) * 5);
    win->scene[OPTIONS].text = malloc(sizeof(text_t) * 5);
    win->scene[OPTIONS].nb_text = 5;
    win->scene[OPTIONS].nb_button = 5;
    win->scene[OPTIONS].nb_sprite = 0;
    win->vol_register = (win->volume + VALUE_FIRST) * 1.284;
    init_text(&win->scene[OPTIONS].text[0], text[0], get_pos_float(pos_window.x + 150, 10));
    init_text(&win->scene[OPTIONS].text[1], text[1], get_pos_float(pos_window.x, 210));
    init_text(&win->scene[OPTIONS].text[2], text[2], get_pos_float(pos_window.x, pos_window.y - 430));
    init_text(&win->scene[OPTIONS].text[3], text[3], get_pos_float(pos_window.x, pos_window.y - 230));
    init_text(&win->scene[OPTIONS].text[4], text[4], get_pos_float(pos_window.x + 400, pos_window.y - 250));
    set_next_buttons(&win->scene[MAINMENU].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[OPTIONS].button[0], pos_window, size, win->texture_button);
    set_next_buttons(&win->scene[MAINMENU].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[OPTIONS].button[1], get_pos_float(pos_window.x + 200, 200), get_pos_float(80, 80), win->texture_button);
    set_next_buttons(&win->scene[MAINMENU].button[2], win->rect_buttons, order_button[2]);
    init_button(&win->scene[OPTIONS].button[2], get_pos_float(pos_window.x + 400, 200), get_pos_float(80, 80), win->texture_button);
    set_next_buttons(&win->scene[MAINMENU].button[3], win->rect_buttons, order_button[3]);
    init_button(&win->scene[OPTIONS].button[3], get_pos_float(pos_window.x + 200, pos_window.y - 450), get_pos_float(100, 100), win->texture_button);
    set_next_buttons(&win->scene[MAINMENU].button[4], win->rect_buttons, order_button[4]);
    init_button(&win->scene[OPTIONS].button[4], get_pos_float(pos_window.x + 200, pos_window.y - 250), get_pos_float(150, 100), win->texture_button);
    if (win->fps == 60) {
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[1].shape, win->scene[OPTIONS].button[1].rect_idle);
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[2].shape, win->scene[OPTIONS].button[2].rect_pressed);
    } else {
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[1].shape, win->scene[OPTIONS].button[1].rect_pressed);
        sfRectangleShape_setTextureRect(win->scene[OPTIONS].button[2].shape, win->scene[OPTIONS].button[2].rect_idle);
    }
    if (win->vsync == 0)
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox2.png", NULL);
    else
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox.png", NULL);
    pos_window.x += 20;
    pos_window.y += 10;
    sfRectangleShape_setTexture(win->scene[OPTIONS].button[3].shape,
    texture, sfTrue);
    win->scene[OPTIONS].button[0].callback = &main_menu;
    win->scene[OPTIONS].button[1].callback = &change_fps;
    win->scene[OPTIONS].button[2].callback = &change_fps;
    win->scene[OPTIONS].button[3].callback = &change_vsync;
    win->scene[OPTIONS].button[4].callback = NULL;
    return (win);
}