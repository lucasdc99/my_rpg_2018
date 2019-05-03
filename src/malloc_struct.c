/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** malloc_struct
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int malloc_struct_end(window_t *win)
{
    win->inv->text = malloc(sizeof(text_t) * 1);
    if (win->inv->text == NULL)
        return (84);
    win->text = malloc(sizeof(text_t) * 1);
    if (win->text == NULL)
        return (84);
    win->music = malloc(sizeof(music_t) * 1);
    if (win->music == NULL)
        return (84);
    win->objects = malloc(sizeof(sprite_t) * win->nb_objects);
    if (win->objects == NULL)
        return (84);
    win->positions = malloc(sizeof(pos_t) * 1);
    if (win->positions == NULL)
        return (84);
    return (0);
}

static int malloc_struct_game(window_t *win)
{
    win->enemy = malloc(sizeof(enemy_t) * 1);
    if (win->enemy == NULL)
        return (84);
    win->enemy->sprite = malloc(sizeof(sprite_t) * 1);
    if (win->enemy->sprite == NULL)
        return (84);
    win->enemy->text = malloc(sizeof(text_t) * 1);
    if (win->enemy->text == NULL)
        return (84);
    win->inv = malloc(sizeof(inventory_t) * 1);
    if (win->inv == NULL)
        return (84);
    win->inv->sprite = malloc(sizeof(sprite_t) * 1);
    if (win->inv->sprite == NULL)
        return (84);
    win->inv->items = malloc(sizeof(items_t) * 15);
    if (win->inv->items == NULL)
        return (84);
    return (malloc_struct_end(win));
}

int malloc_struct(window_t *win)
{
    win->scene = malloc(sizeof(scene_t) * 14);
    if (win->scene == NULL)
        return (84);
    win->quests = malloc(sizeof(quest_t) * 1);
    if (win->quests == NULL)
        return (84);
    win->quests->sprite = malloc(sizeof(sprite_t) * 8);
    if (win->quests->sprite == NULL)
        return (84);
    win->quests->text = malloc(sizeof(text_t) * 7);
    if (win->quests->text == NULL)
        return (84);
    win->player = malloc(sizeof(player_t) * 1);
    if (win->player == NULL)
        return (84);
    win->player->sprite = malloc(sizeof(sprite_t) * 1);
    if (win->player->sprite == NULL)
        return (84);
    return (malloc_struct_game(win));
}