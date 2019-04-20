/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback
*/

#include "../include/rpg.h"
#include "../include/my.h"

void main_menu(window_t *win)
{
    FILE *fp;

    if (win->page >= CASTLE) {
        fp = fopen("ressources/text/config_player", "wb+");
        win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
        if (win->player->last_pos.x <= 20)
            win->player->last_pos.x = 100;
        if (win->player->last_pos.y <= 20)
            win->player->last_pos.y = 100;
        fprintf(fp, "NAME = %s\n", win->player->name);
        fprintf(fp, "HEALTH = %d\n", win->player->health);
        fprintf(fp, "XP = %d\n", win->player->xp);
        fprintf(fp, "STRENGTH = %d\n", win->player->strength);
        fprintf(fp, "POSITION X = %f\n", win->player->last_pos.x);
        fprintf(fp, "POSITION Y = %f\n", win->player->last_pos.y);
        fprintf(fp, "PAGE = %d\n", win->actual_page);
        fclose(fp);
        save_inventory(win);
    }
    win->pause = 0;
    sfMusic_play(win->music->button_sound);
    if (sfMusic_getStatus(win->music->menu_song) == sfStopped)
        sfMusic_play(win->music->menu_song);
    win->page = MAINMENU;
}

void heroes_menu(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = HEROES;
}

void how_to_play(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = HOW_TO_PLAY;
}

void options(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    win->page = OPTIONS;
}

void quit(window_t *win)
{
    sfRenderWindow_close(win->window);
}

void quit_pause(window_t *win)
{
    unpause_game(win);
}

void basic_attack(window_t *win)
{
    sfIntRect rect;

    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT1].sprite[0].sprite);
        rect.left += 50;
        if (rect.left >= 400)
            rect.left = 297;
        sfSprite_setTextureRect(win->scene[COMBAT1].sprite[0].sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window, win->scene[COMBAT1].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->combat);
        win->combat_time = sfClock_getElapsedTime(win->combat);
        win->seconds = win->combat_time.microseconds / 1000000.0;
        while (win->seconds < 1) {
            win->combat_time = sfClock_getElapsedTime(win->combat);
            win->seconds = win->combat_time.microseconds / 100000.0;
        }
    }
    sfSprite_setTextureRect(win->scene[COMBAT1].sprite[0].sprite, get_rect(297, 56, 30, 30));
}

void special_attack(window_t *win)
{
    sfIntRect rect;

    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT1].sprite[0].sprite);
        rect.top = 8;
        rect.left += 50;
        if (rect.left >= 400)
            rect.left = 297;
        sfSprite_setTextureRect(win->scene[COMBAT1].sprite[0].sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window, win->scene[COMBAT1].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->combat);
        win->combat_time = sfClock_getElapsedTime(win->combat);
        win->seconds = win->combat_time.microseconds / 1000000.0;
        while (win->seconds < 1) {
            win->combat_time = sfClock_getElapsedTime(win->combat);
            win->seconds = win->combat_time.microseconds / 100000.0;
        }
    }
    sfSprite_setTextureRect(win->scene[COMBAT1].sprite[0].sprite, get_rect(297, 56, 30, 30));
}

void stats_attack(window_t *win)
{
    sfIntRect rect;

    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT1].sprite[0].sprite);
        rect.top = 150;
        if (i == 7)
            rect.left += 50;
        sfSprite_setTextureRect(win->scene[COMBAT1].sprite[0].sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window, win->scene[COMBAT1].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->combat);
        win->combat_time = sfClock_getElapsedTime(win->combat);
        win->seconds = win->combat_time.microseconds / 1000000.0;
        while (win->seconds < 1) {
            win->combat_time = sfClock_getElapsedTime(win->combat);
            win->seconds = win->combat_time.microseconds / 100000.0;
        }
    }
    sfSprite_setTextureRect(win->scene[COMBAT1].sprite[0].sprite, get_rect(297, 56, 30, 30));
}

void play_game(window_t *win)
{
    FILE *fp;

    sfMusic_play(win->music->button_sound);
    if (win->page == HEROES) {
        win->no_saves = 1;
        fp = fopen("ressources/text/config_player", "wb+");
        fprintf(fp, "NAME = %s\n", win->player->name);
        fprintf(fp, "HEALTH = %d\n", win->player->health);
        fprintf(fp, "XP = %d\n", win->player->xp);
        fprintf(fp, "STRENGTH = %d\n", win->player->strength);
        fprintf(fp, "POSITION X = %f\n", 500.0);
        fprintf(fp, "POSITION Y = %f\n", 500.0);
        fprintf(fp, "PAGE = %d\n", CASTLE);
        fclose(fp);
    }
    init_inventory(win->inv);
    win->player = parser(win->player, "ressources/text/config_player");
    win->page = win->player->last_page;
    init_player(win);
    init_objects(win->objects, win->inv);
    init_quests(win->quests);
    sfMusic_stop(win->music->menu_song);
}