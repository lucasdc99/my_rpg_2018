/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** draw
*/

#include "../include/rpg.h"
#include "../include/my.h"

window_t *draw_scene(window_t *win)
{
    sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == -1)
            sfRenderWindow_drawSprite(win->window, win->scene[win->actual_page].sprite[i].sprite, NULL);
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == 0 && (win->pause == 0 || win->inventory == 1))
            sfRenderWindow_drawSprite(win->window, win->scene[win->actual_page].sprite[i].sprite, NULL);
    }
    if (win->actual_page >= CASTLE) {
        if (win->pause == 0 || win->inventory == 1)
            sfRenderWindow_drawSprite(win->window, win->player->sprite->sprite, NULL);
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == 1 && (win->pause == 0 || win->inventory == 1))
            sfRenderWindow_drawSprite(win->window, win->scene[win->actual_page].sprite[i].sprite, NULL);
    }
    if (win->actual_page >= CASTLE) {
        if (win->pause == 0 || win->inventory == 1)
            sfRenderWindow_drawSprite(win->window, win->player->sprite->sprite, NULL);
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        sfRenderWindow_drawRectangleShape(win->window,
        win->scene[win->actual_page].button[i].shape, NULL);
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_text; i++) {
        sfRenderWindow_drawText(win->window,
        win->scene[win->actual_page].text[i].str, NULL);
    }
    if (win->inventory == 1) {
        sfRenderWindow_drawSprite(win->window, win->inv->sprite->sprite, NULL);
        sfRenderWindow_drawSprite(win->window, win->inv->player, NULL);
        if (sfText_getString(win->inv->text) != NULL)
            sfRenderWindow_drawText(win->window, win->inv->text, NULL);   
        for (int i = 0; i < win->nb_objects; i++) {
            if (win->objects[i].item == 1 && is_item_outside_inv(sfSprite_getPosition(win->objects[i].sprite), win->inv) == 0)
                sfRenderWindow_drawSprite(win->window, win->objects[i].sprite, NULL);
            if (win->objects[i].item == 2)
                sfRenderWindow_drawSprite(win->window, win->objects[i].sprite, NULL);
        }     
    }
    if (win->actual_page >= CASTLE) {
        sfRenderWindow_drawText(win->window, win->text->str, NULL);
        if (win->quests->sprite[1].depth >= 0) {
            sfRenderWindow_drawSprite(win->window, win->quests->sprite[1].sprite, NULL);
            sfRenderWindow_drawText(win->window, win->quests->text[1].str, NULL);
        } 
    }
    if (win->quest == 1) {
        sfRenderWindow_drawSprite(win->window, win->quests->sprite[0].sprite, NULL);
        sfRenderWindow_drawText(win->window, win->quests->text[0].str, NULL);
    }
    sfRenderWindow_display(win->window);
    return (win);
}