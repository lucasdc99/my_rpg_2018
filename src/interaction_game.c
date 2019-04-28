/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

void open_door(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);
    sfIntRect rect;
    sfVector2f pos_door;

    if (win->quests->quete_done == 3)
        go_final(win);
    for (int i = 1; i < 4; i++) {
        rect = sfSprite_getTextureRect(win->scene[TOWN].sprite[i].sprite);
        pos_door = sfSprite_getPosition(win->scene[TOWN].sprite[i].sprite);
        if (pos_player.x >= pos_door.x - 20 && pos_player.x <= pos_door.x + 40) {
            if (pos_player.y >= pos_door.y && pos_player.y <= pos_door.y + 100) {
                rect.top = 64;
                sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite, rect);
            } else {
                if (rect.top >= 64) {
                    rect.top = 0;
                    sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite, rect);
                }
            }
            if (pos_player.y >= pos_door.y - 50 && pos_player.y <= pos_door.y + 20 && win->player->direction == UP) {
                win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
                win->player->last_pos.y += 50;
                pos_player.y -= 50;
                sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(880, 730));
                if (i == 1)
                    win->page = HOUSE1;
                if (i == 2)
                    win->page = HOUSE2;
                if (i == 3)
                    win->page = HOUSE3;
            }
        } else {
            if (rect.top >= 64) {
                rect.top = 0;
                sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite, rect);
            }
        }
    }
}

void pause_game(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 4;
    win->pause = 1;
    if (win->actual_page == TOWN) {
        sfSprite_setTexture(win->scene[TOWN].sprite[0].sprite, sfTexture_createFromFile("ressources/town_blur.png", NULL), sfTrue);
    }
    if (win->actual_page == CASTLE) {
        sfSprite_setTexture(win->scene[CASTLE].sprite[0].sprite, sfTexture_createFromFile("ressources/castle_blur.png", NULL), sfTrue);
    }
    if (win->actual_page == FOREST) {
        sfSprite_setTexture(win->scene[FOREST].sprite[0].sprite, sfTexture_createFromFile("ressources/forest_blur.png", NULL), sfTrue);
    }
    if (win->actual_page == FINAL) {
        sfSprite_setTexture(win->scene[FINAL].sprite[0].sprite, sfTexture_createFromFile("ressources/sbire_map_blur.png", NULL), sfTrue);
    }
    if (win->actual_page == BOSS) {
        sfSprite_setTexture(win->scene[BOSS].sprite[0].sprite, sfTexture_createFromFile("ressources/final_boss_blur.png", NULL), sfTrue);
    }
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape, get_pos_float(pos_window.x, pos_window.y));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape, get_pos_float(pos_window.x, pos_window.y + 200));
}

void unpause_game(window_t *win)
{
    win->pause = 0;
    if (win->actual_page == TOWN) {
        sfSprite_setTexture(win->scene[TOWN].sprite[0].sprite, sfTexture_createFromFile("ressources/town.png", NULL), sfTrue);
    }
    if (win->actual_page == CASTLE) {
        sfSprite_setTexture(win->scene[CASTLE].sprite[0].sprite, sfTexture_createFromFile("ressources/castle.png", NULL), sfTrue);
    }
    if (win->actual_page == FOREST) {
        sfSprite_setTexture(win->scene[FOREST].sprite[0].sprite, sfTexture_createFromFile("ressources/forest.png", NULL), sfTrue);
    }
    if (win->actual_page == FINAL) {
        sfSprite_setTexture(win->scene[FINAL].sprite[0].sprite, sfTexture_createFromFile("ressources/sbire_map.png", NULL), sfTrue);
    }
    if (win->actual_page == BOSS) {
        sfSprite_setTexture(win->scene[BOSS].sprite[0].sprite, sfTexture_createFromFile("ressources/final_boss.png", NULL), sfTrue);
    }
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape, get_pos_float(-600, -300));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape, get_pos_float(-600, -100));
}
