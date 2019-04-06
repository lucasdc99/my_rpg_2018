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
    win->scene[win->page].background[i].texture = sfTexture_createFromFile(filename,
    NULL);
    win->scene[win->page].background[i].sprite = sfSprite_create();
    sfSprite_setTexture(win->scene[win->page].background[i].sprite,
    win->scene[win->page].background[i].texture, sfTrue);
    sfSprite_setPosition(win->scene[win->page].background[i].sprite,
    win->scene[win->page].background[i].pos);
    sfSprite_setScale(win->scene[win->page].background[i].sprite, get_pos_float(6, 6));
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
        win->scene[win->page].background[i].pos.x = x;
        win->scene[win->page].background[i].pos.y = y;
        filename = "ressources/pack/rpg-pack/tiles/generic-rpg-tile";
        filename = my_strcat(filename, win->scene[win->page].background->tab_pos[i]);
        filename = my_strcat(filename, ".png");
        set_background(win, i, filename);
        x += 96;
    }
}

window_t *init_game(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    int fd = open("ressources/text/pos_bg", O_RDONLY);
    char buff[660];
    char *skin = malloc(sizeof(char) * 80);
    int order_button[] = {REPRENDRE, QUITTER};

    read(fd, buff, sizeof(buff));
    win->scene[GAME].background = malloc(sizeof(background_t) * 222);
    win->scene[GAME].sprite = malloc(sizeof(sprite_t) * 2);
    win->scene[GAME].button = malloc(sizeof(button_t) * 2);
    win->scene[GAME].background->tab_pos = transform_pos_to_tab(buff);
    load_background(win);
    win->scene[GAME].nb_text = 0;
    win->scene[GAME].nb_button = 2;
    win->scene[GAME].nb_sprite = 2;
    win->player->sprite->rect.top = 15;
    win->player->sprite->rect.left = 15;
    win->player->sprite->rect.width = 18;
    win->player->sprite->rect.height = 18;
    set_next_buttons(&win->scene[GAME].button[0], win->rect_buttons, order_button[0]);
    init_button(&win->scene[GAME].button[0], get_pos_float(-200, -200), size, win->texture_button);
    set_next_buttons(&win->scene[GAME].button[1], win->rect_buttons, order_button[1]);
    init_button(&win->scene[GAME].button[1], get_pos_float(-200, -200), size, win->texture_button);
    skin = my_strcat("ressources/pack/Pixel_Champions/Magical Heroes/", win->player->name);
    skin = my_strcat(skin, ".png");
    init_sprite(win->player->sprite, skin, get_pos_float(win->player->speed.x, win->player->speed.y));
    sfSprite_setScale(win->player->sprite->sprite, get_pos_float(3, 3));
    sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
    init_sprite(&win->scene[GAME].sprite[0], "ressources/pack/rpg-pack/decorations/generic-rpg-house-inn.png", get_pos_float(200, 200));
    init_sprite(&win->scene[GAME].sprite[1], "ressources/inventaire_de_merde.png", get_pos_float(-600, -300));
    sfSprite_setScale(win->scene[GAME].sprite[0].sprite, get_pos_float(2, 2));
    if (win->player->last_pos.x >= 0)
        sfSprite_setPosition(win->player->sprite->sprite, win->player->last_pos);
    else
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(500, 500));
    win->scene[GAME].button[0].callback = &quit_pause;
    win->scene[GAME].button[1].callback = &main_menu;
    return (win);
}