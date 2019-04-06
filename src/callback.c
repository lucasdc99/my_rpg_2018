/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** callback
*/

#include "../include/rpg.h"
#include "../include/my.h"

void main_menu(window_t *win)
{
    win->pause = 0;
    win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
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
    FILE *fp;

    fp = fopen("ressources/text/config_player", "wb+");
    fprintf(fp, "NAME = %s\n", win->player->name);
    fprintf(fp, "HEALTH = %d\n", win->player->health);
    fprintf(fp, "XP = %d\n", win->player->xp);
    fprintf(fp, "STRENGTH = %d\n", win->player->strength);
    fprintf(fp, "POSITION X = %f\n", win->player->last_pos.x);
    fprintf(fp, "POSITION Y = %f\n", win->player->last_pos.y);
    fclose(fp);
    sfRenderWindow_close(win->window);
}

void quit_pause(window_t *win)
{
    win->pause = 0;
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape, get_pos_float(-200, -200));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape, get_pos_float(-200, -200));
}

void play_game(window_t *win)
{
    FILE *fp;

    if (win->page == HEROES) {
        fp = fopen("ressources/text/config_player", "wb+");
        fprintf(fp, "NAME = %s\n", win->player->name);
        fprintf(fp, "HEALTH = %d\n", win->player->health);
        fprintf(fp, "XP = %d\n", win->player->xp);
        fprintf(fp, "STRENGTH = %d\n", win->player->strength);
        fclose(fp);
    }
    sfMusic_stop(win->music->menu_song);
    win->page = GAME;
}