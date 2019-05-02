/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** destroy
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *destroy_scene(window_t *win)
{
    int page = win->actual_page;

    for (int i = 0; i < win->scene[page].nb_button; i++) {
        sfRectangleShape_destroy(win->scene[page].button[i].shape);
    }
    for (int i = 0; i < win->scene[page].nb_sprite; i++) {
        sfSprite_destroy(win->scene[page].sprite[i].sprite);
        sfTexture_destroy(win->scene[page].sprite[i].texture);
    }
    for (int i = 0; i < win->scene[page].nb_text; i++) {
        sfText_destroy(win->scene[page].text[i].str);
    }
    if (page >= CASTLE && win->page == MAINMENU) {
        sfTexture_destroy(win->player->sprite->texture);
        sfSprite_destroy(win->player->sprite->sprite);
    }
    if (win->scene[page].nb_button > 0)
        free(win->scene[page].button);
    if (win->scene[page].nb_sprite > 0)
        free(win->scene[page].sprite);
    if (win->scene[page].nb_text > 0)
        free(win->scene[page].text);
    return (win);
}

void destroy_all(window_t *win)
{
    sfMusic_destroy(win->music->menu_song);
    sfMusic_destroy(win->music->button_sound);
    sfMusic_destroy(win->music->town_song);
    sfMusic_destroy(win->music->boss_song);
    sfMusic_destroy(win->music->door_close);
    sfMusic_destroy(win->music->door_open);
    sfMusic_destroy(win->music->stone_door);
    sfMusic_destroy(win->music->boss_battle);
    sfMusic_destroy(win->music->boss_final);
    sfMusic_destroy(win->music->special_attack);
    sfMusic_destroy(win->music->heal);
    sfMusic_destroy(win->music->enemy_attack);
    sfMusic_destroy(win->music->basic_attack);
    sfMusic_destroy(win->music->open_menus);
    sfFont_destroy(win->font_berlin);
    sfFont_destroy(win->font_title);
    free(win->music);
    free(win->player->sprite);
    free(win->player);
    free(win->scene);
    free(win);
}