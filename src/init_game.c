/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_game
*/

#include "../include/rpg.h"
#include "../include/my.h"

void set_background(window_t *win, int i, char *filename)
{
    win->scene[GAME].background[i].texture = sfTexture_createFromFile(filename,
    NULL);
    win->scene[GAME].background[i].sprite = sfSprite_create();
    sfSprite_setTexture(win->scene[GAME].background[i].sprite,
    win->scene[GAME].background[i].texture, sfTrue);
    sfSprite_setPosition(win->scene[GAME].background[i].sprite,
    win->scene[GAME].background[i].pos);
    sfSprite_setScale(win->scene[GAME].background[i].sprite, get_pos_float(6, 6));
}

void load_background(window_t *win)
{
    int x = 0;
    int y = 0;
    char *filename = malloc(sizeof(char) * 58);

    for (int i = 0; i < 220; i++) {
        if (i % 20 == 0 && i != 0) {
            x = 0;
            y += 96;
        }
        win->scene[GAME].background[i].pos.x = x;
        win->scene[GAME].background[i].pos.y = y;
        filename = "ressources/pack/rpg-pack/tiles/generic-rpg-tile";
        filename = my_strcat(filename, win->scene[GAME].background->tab_pos[i]);
        filename = my_strcat(filename, ".png");
        set_background(win, i, filename);
        x += 96;
    }
}

window_t *init_game(window_t *win)
{
    int fd = open("ressources/text/pos_bg", O_RDONLY);
    char buff[660];

    read(fd, buff, sizeof(buff));
    win->scene[GAME].background = malloc(sizeof(background_t) * 222);
    win->scene[GAME].sprite = malloc(sizeof(sprite_t) * 1);
    win->scene[GAME].background->tab_pos = transform_pos_to_tab(buff);
    load_background(win);
    win->scene[GAME].nb_text = 0;
    win->scene[GAME].nb_button = 0;
    win->scene[GAME].nb_sprite = 1;
    win->scene[GAME].sprite[0].rect.top = 15;
    win->scene[GAME].sprite[0].rect.left = 15;
    win->scene[GAME].sprite[0].rect.width = 18;
    win->scene[GAME].sprite[0].rect.height = 18;
    init_sprite(&win->scene[GAME].sprite[0], "ressources/pack/Pixel_Champions/Magical Heroes/Glenys-the-Demonswordsman.png", get_pos_float(win->test, win->test2));
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->scene[GAME].sprite[0].sprite, win->scene[GAME].sprite[0].rect);
    return (win);
}