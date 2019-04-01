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
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;
    sfTexture *texture;
    win->test = 500;
    win->test2 = 500;
    char **text = transform_2d("OPTIONS\nFPS\nVSYNC\nMusic\nBack to main menu\n30\n60\n");

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = 800;
    win->scene[OPTIONS].button = malloc(sizeof(button_t) * 5);
    win->scene[OPTIONS].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[OPTIONS].text = malloc(sizeof(text_t) * 1);
    win->scene[OPTIONS].nb_text = 1;
    win->scene[OPTIONS].nb_button = 5;
    win->scene[OPTIONS].nb_sprite = 1;
    init_text(&win->scene[OPTIONS].text[0], text[0], get_pos_float(pos_window.x, 10));
    init_button(&win->scene[OPTIONS].button[0], pos_window, size);
    init_button(&win->scene[OPTIONS].button[1], get_pos_float(pos_window.x + 200, 200), get_pos_float(80, 80));
    init_button(&win->scene[OPTIONS].button[2], get_pos_float(pos_window.x + 400, 200), get_pos_float(80, 80));
    init_button(&win->scene[OPTIONS].button[3], get_pos_float(pos_window.x + 200, pos_window.y - 450), get_pos_float(100, 100));
    init_button(&win->scene[OPTIONS].button[4], get_pos_float(pos_window.x + 200, pos_window.y - 250), get_pos_float(150, 100));
    win->scene[OPTIONS].button[1].idle_color = sfRed;
    win->scene[OPTIONS].button[2].idle_color = sfYellow;
    sfRectangleShape_setFillColor(win->scene[OPTIONS].button[2].rect,
    win->scene[OPTIONS].button[2].idle_color);
    sfRectangleShape_setFillColor(win->scene[OPTIONS].button[1].rect,
    win->scene[OPTIONS].button[1].idle_color);
    if (win->vsync == 0)
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox2.png", NULL);
    else
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox.png", NULL);
    pos_window.x += 20;
    pos_window.y += 10;
    init_button_text(&win->scene[OPTIONS].button[0], text[4], pos_window);
    init_button_text(&win->scene[OPTIONS].button[1], text[5], get_pos_float(pos_window.x + 200, 200));
    init_button_text(&win->scene[OPTIONS].button[2], text[6], get_pos_float(pos_window.x + 400, 200));
    init_button_text(&win->scene[OPTIONS].button[3], NULL, get_pos_float(pos_window.x + 200, pos_window.y - 450));
    init_button_text(&win->scene[OPTIONS].button[4], my_strcat(my_itc(win->volume), "%"), get_pos_float(pos_window.x + 200, pos_window.y - 250));
    sfRectangleShape_setTexture(win->scene[OPTIONS].button[3].rect,
    texture, sfTrue);
    win->scene[OPTIONS].button[0].callback = &main_menu;
    win->scene[OPTIONS].button[1].callback = &change_fps;
    win->scene[OPTIONS].button[2].callback = &change_fps;
    win->scene[OPTIONS].button[3].callback = &change_vsync;
    win->scene[OPTIONS].button[4].callback = &change_music;
    init_sprite(&win->scene[OPTIONS].sprite[0], "ressources/pack/rpg-pack/atlas.png", get_pos_float(win->test, win->test2));
    //sfSprite_setPosition(&win->scene[MAINMENU].sprite[0], posatlas);
    return (win);
}