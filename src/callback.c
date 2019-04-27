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
    if (win->page >= CASTLE) {
        win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
        if (win->player->last_pos.x <= 20)
            win->player->last_pos.x = 100;
        if (win->player->last_pos.y <= 20)
            win->player->last_pos.y = 100;
        save_config_player(win);
        save_inventory(win);
        save_quests(win);
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

void enemy_attack(window_t *win)
{
    sfIntRect rect;

    sfClock_restart(win->combat_clock);
    win->combat_time = sfClock_getElapsedTime(win->combat_clock);
    win->seconds = win->combat_time.microseconds / 1000000.0;
    while (win->seconds < 10) {
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 100000.0;
    }
    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->enemy->sprite->sprite);
        rect.left += 50;
        if (rect.left >= 400)
            rect.left = 297;
        sfSprite_setTextureRect(win->enemy->sprite->sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window, win->enemy->sprite->sprite, NULL);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->combat_clock);
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 1000000.0;
        while (win->seconds < 1) {
            win->combat_time = sfClock_getElapsedTime(win->combat_clock);
            win->seconds = win->combat_time.microseconds / 100000.0;
        }
    }
    sfSprite_setTextureRect(win->enemy->sprite->sprite, get_rect(297, 56, 30, 30));
    win->player->health -= 20;
    if (win->player->health <= 0) {
        win->page = END;
    } else
        sfText_setString(win->scene[COMBAT].text[0].str, my_itc(win->player->health));
    win->turn = 0;
}

void basic_attack(window_t *win)
{
    sfIntRect rect;

    if (win->turn == 1)
        return;
    sfClock_restart(win->combat_clock);
    win->combat_time = sfClock_getElapsedTime(win->combat_clock);
    win->seconds = win->combat_time.microseconds / 1000000.0;
    while (win->seconds < 10) {
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 100000.0;
    }
    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT].sprite[0].sprite);
        rect.left += 50;
        if (rect.left >= 400)
            rect.left = 297;
        sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window, win->scene[COMBAT].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->combat_clock);
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 1000000.0;
        while (win->seconds < 1) {
            win->combat_time = sfClock_getElapsedTime(win->combat_clock);
            win->seconds = win->combat_time.microseconds / 100000.0;
        }
    }
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite, get_rect(297, 56, 30, 30));
    win->enemy->health -= 20;
    if (win->enemy->health <= 0) {
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(900, 650));
        win->page = FINAL;
    } else {
        sfText_setString(win->enemy->text->str, my_itc(win->enemy->health));
        win->turn = 1;
    }
}

void special_attack(window_t *win)
{
    sfIntRect rect;

    if (win->turn == 1)
        return;
    sfClock_restart(win->combat_clock);
    win->combat_time = sfClock_getElapsedTime(win->combat_clock);
    win->seconds = win->combat_time.microseconds / 1000000.0;
    while (win->seconds < 2) {
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 100000.0;
    }
    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT].sprite[0].sprite);
        rect.top = 8;
        rect.left += 50;
        if (rect.left >= 400)
            rect.left = 297;
        sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window, win->scene[COMBAT].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->combat_clock);
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 1000000.0;
        while (win->seconds < 1) {
            win->combat_time = sfClock_getElapsedTime(win->combat_clock);
            win->seconds = win->combat_time.microseconds / 100000.0;
        }
    }
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite, get_rect(297, 56, 30, 30));
    win->enemy->health -= 30;
    if (win->enemy->health <= 0) {
        sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(900, 700));
        win->page = FINAL;
    } else {
        sfText_setString(win->enemy->text->str, my_itc(win->enemy->health));
        win->turn = 1;
    }
}

void stats_attack(window_t *win)
{
    sfIntRect rect;

    if (win->turn == 1)
        return;
    for (int i = 0; i < 10; i++) {
        rect = sfSprite_getTextureRect(win->scene[COMBAT].sprite[0].sprite);
        rect.top = 150;
        if (i == 7)
            rect.left += 50;
        sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite, rect);
        sfRenderWindow_clear(win->window, sfColor_fromRGB(25, 31, 38));
        sfRenderWindow_drawSprite(win->window, win->scene[COMBAT].sprite[0].sprite, NULL);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->combat_clock);
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 1000000.0;
        while (win->seconds < 1) {
            win->combat_time = sfClock_getElapsedTime(win->combat_clock);
            win->seconds = win->combat_time.microseconds / 100000.0;
        }
    }
    sfSprite_setTextureRect(win->scene[COMBAT].sprite[0].sprite, get_rect(297, 56, 30, 30));
    win->player->health += 30;
    sfText_setString(win->scene[COMBAT].text[0].str, my_itc(win->player->health));
    win->turn = 1;
}

void play_game(window_t *win)
{
    int actual_pos = 0;

    sfMusic_play(win->music->button_sound);
    if (win->page == HEROES) {
        win->quests->quete_done = 0;
        save_quests(win);
        for (int i = 0; i < 15; i++)
            win->inv->items[i].name = NULL;
        save_inventory(win);
        win->player->last_pos = get_pos_float(900, 600);
        win->no_saves = 1;
        save_config_player(win);
    }
    win->player = parser_player(win->player, "ressources/text/config_player");
    win->page = win->player->last_page;
    init_inventory(win->inv);
    init_player(win->player);
    set_player(win);
    init_objects(win->objects, win->inv);
    if (win->quests->quete_done >= 2) {
        if (check_existing_inventory(win, "Dague") == 1) {
            sfSprite_setPosition(win->objects[SWORD].sprite, get_inv_pos(win->inv));
            actual_pos = get_actual_pos_inv(win->inv, get_pos_float(0, 0));
            win->inv->items[actual_pos].busy = 1;
            win->inv->items[actual_pos].name = get_name_from_type(SWORD);
            win->objects[SWORD].item = 1;
            win->objects[SWORD].depth = 2;
        }
    }
    init_quests(win->quests);
    sfMusic_stop(win->music->menu_song);
}