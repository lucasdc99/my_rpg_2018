/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** check_error_parsing
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int define_inv(window_t *win)
{
    win->inv = malloc(sizeof(inventory_t) * 1);
    if (win->inv == NULL)
        return (84);
    win->inv->sprite = malloc(sizeof(sprite_t) * 1);
    if (win->inv->sprite == NULL)
        return (84);
    win->inv->items = malloc(sizeof(items_t) * 15);
    if (win->inv->items == NULL)
        return (84);
    for (int i = 0; i < 15; i++)
        win->inv->items[i].name = NULL;
    return (0);
}

static int check_quest_error(window_t *win)
{
    if (win->quests == NULL) {
        win->states->no_saves = 1;
        win->quests = malloc(sizeof(quest_t) * 1);
        if (win->quests == NULL)
            return (84);
        win->quests->sprite = malloc(sizeof(sprite_t) * 6);
        if (win->quests->sprite == NULL)
            return (84);
        win->quests->text = malloc(sizeof(text_t) * 5);
        if (win->quests->text == NULL)
            return (84);
        win->quests->quete_done = 0;
        win->quests->combat = 0;
        save_quests(win);
    }
    return (0);
}

static int check_error_config(window_t *win)
{
    if (win->player == NULL || win->player->last_page == END) {
        if (reset_player(win) == 84)
            return (84);
    }
    if (win->player->last_pos.x < 0)
        win->states->no_saves = 1;
    if (win->inv == NULL) {
        win->states->no_saves = 1;
        if (define_inv(win) == 84)
            return (84);
        if (save_inventory(win) == 84)
            return (84);
    }
    if (check_quest_error(win) == 84)
        return (84);
    return (0);
}

int parsing(window_t *win)
{
    win->player = parser_player(win->player, "ressources/text/config_player");
    win->inv = parser_inv(win->inv, "ressources/text/inventory");
    win->quests = parser_quests(win->quests, "ressources/text/quests");
    if (check_error_config(win) == 84)
        return (84);
    if (display(win) == 84) {
        destroy_all(win);
        return (84);
    }
    return (0);
}