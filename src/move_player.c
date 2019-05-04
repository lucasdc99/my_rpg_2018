/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_player
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void set_speed(window_t *win, int dir)
{
    if (win->player->direction == UP && dir != UP)
        win->player->speed.y += 5;
    if (win->player->direction == DOWN && dir != DOWN)
        win->player->speed.y -= 5;
    if (win->player->direction == LEFT && dir != LEFT)
        win->player->speed.x += 5;
    if (win->player->direction == RIGHT && dir != RIGHT)
        win->player->speed.x -= 5;
}

void move_player_up(window_t *win)
{
    if (check_dead_zone(win, UP) == 1) {
        if (win->player->direction != UP) {
            set_speed(win, UP);
            win->player->direction = UP;
            win->player->sprite->rect.left = 15;
        }
        win->player->move_rect++;
        sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);
        pos.y -= 5;
        sfSprite_setPosition(win->player->sprite->sprite, pos);
        win->player->sprite->rect.top = 159;
        animate_player_walk(win);
    }
}

void move_player_down(window_t *win)
{
    if (check_dead_zone(win, DOWN) == 1) {
        if (win->player->direction != DOWN) {
            set_speed(win, DOWN);
            win->player->direction = DOWN;
            win->player->sprite->rect.left = 15;
        }
        win->player->move_rect++;
        sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);
        pos.y += 5;
        sfSprite_setPosition(win->player->sprite->sprite, pos);
        win->player->sprite->rect.top = 15;
        animate_player_walk(win);
    }
}

void move_player_left(window_t *win)
{
    if (check_dead_zone(win, LEFT) == 1) {
        if (win->player->direction != LEFT) {
            set_speed(win, LEFT);
            win->player->direction = LEFT;
            win->player->sprite->rect.left = 15;
        }
        win->player->move_rect++;
        sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);
        pos.x -= 5;
        sfSprite_setPosition(win->player->sprite->sprite, pos);
        win->player->sprite->rect.top = 62;
        animate_player_walk(win);
    }
}

void move_player_right(window_t *win)
{
    if (check_dead_zone(win, RIGHT) == 1) {
        if (win->player->direction != RIGHT) {
            set_speed(win, RIGHT);
            win->player->direction = RIGHT;
            win->player->sprite->rect.left = 15;
        }
        win->player->move_rect++;
        sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);
        pos.x += 5;
        sfSprite_setPosition(win->player->sprite->sprite, pos);
        win->player->sprite->rect.top = 110;
        animate_player_walk(win);
    }
}