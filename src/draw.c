/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** draw
*/

#include "../include/rpg.h"
#include "../include/my.h"

void draw_inventory(window_t *win)
{
    sfVector2f pos;

    if (win->inventory == 1) {
        sfRenderWindow_drawSprite(win->window, win->inv->sprite->sprite, NULL);
        sfRenderWindow_drawSprite(win->window, win->inv->player, NULL);
        if (sfText_getString(win->inv->text) != NULL)
            sfRenderWindow_drawText(win->window, win->inv->text, NULL);
        for (int i = 0; i < win->nb_objects; i++) {
            pos = sfSprite_getPosition(win->objects[i].sprite);
            if (win->objects[i].item == 1 &&
            is_item_outside_inv(pos, win->inv) == 0) {
                sfRenderWindow_drawSprite(win->window,
                win->objects[i].sprite, NULL);
            }
            if (win->objects[i].item == 2) {
                sfRenderWindow_drawSprite(win->window,
                win->objects[i].sprite, NULL);
            }
        }
    }
}

void draw_quests(window_t *win)
{
    if (win->quest == 1) {
        for (int i = 0; i < win->quests->quete_done + 1; i++) {
            if (i < 1) {
                sfRenderWindow_drawSprite(win->window,
                win->quests->sprite[i].sprite, NULL);
                sfRenderWindow_drawText(win->window,
                win->quests->text[i].str, NULL);
            } else {
                sfRenderWindow_drawSprite(win->window,
                win->quests->sprite[i + 1].sprite, NULL);
                sfRenderWindow_drawText(win->window,
                win->quests->text[i + 1].str, NULL);
            }
        }
        for (int i = 2; i < win->quests->quete_done + 2; i++) {
            sfRenderWindow_drawSprite(win->window,
            win->quests->sprite[i].sprite, NULL);
        }
    }
}

void draw_sprites(window_t *win)
{
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == -1) {
            sfRenderWindow_drawSprite(win->window,
            win->scene[win->actual_page].sprite[i].sprite, NULL);
        }
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == 0 &&
        (win->pause == 0 || win->inventory == 1)) {
            sfRenderWindow_drawSprite(win->window,
            win->scene[win->actual_page].sprite[i].sprite, NULL);
        }
    }
    if (win->actual_page >= CASTLE && win->actual_page < COMBAT) {
        if (win->pause == 0 || win->inventory == 1) {
            sfRenderWindow_drawSprite(win->window,
            win->player->sprite->sprite, NULL);
        }
    }
    for (int i = 0; i < win->scene[win->actual_page].nb_sprite; i++) {
        if (win->scene[win->actual_page].sprite[i].depth == 1 &&
        (win->pause == 0 || win->inventory == 1)) {
            sfRenderWindow_drawSprite(win->window,
            win->scene[win->actual_page].sprite[i].sprite, NULL);
        }
    }
}

void draw_others(window_t *win)
{
    printf("ok\n");
    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
    printf("%d\n", win->scene[win->actual_page].nb_button);
        sfRenderWindow_drawRectangleShape(win->window,
        win->scene[win->actual_page].button[i].shape, NULL);
    }
    printf("ok3\n");
    for (int i = 0; i < win->scene[win->actual_page].nb_text; i++) {
        sfRenderWindow_drawText(win->window,
        win->scene[win->actual_page].text[i].str, NULL);
    }
    if (win->actual_page >= CASTLE && win->actual_page < COMBAT) {
        sfRenderWindow_drawText(win->window, win->text->str, NULL);
        if (win->quests->sprite[1].depth >= 0) {
            sfRenderWindow_drawSprite(win->window,
            win->quests->sprite[1].sprite, NULL);
            sfRenderWindow_drawText(win->window,
            win->quests->text[1].str, NULL);
        }
    }
}

window_t *draw_scene(window_t *win)
{
    sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
    draw_sprites(win);
    draw_others(win);
    draw_inventory(win);
    draw_quests(win);
    if (win->actual_page == COMBAT) {
        sfRenderWindow_drawText(win->window, win->enemy->text->str, NULL);
        sfRenderWindow_drawSprite(win->window,
        win->enemy->sprite->sprite, NULL);
    }
    if (win->actual_page == CASTLE && win->no_saves == 1)
        animation_begin(win);
    sfRenderWindow_display(win->window);
    return (win);
}