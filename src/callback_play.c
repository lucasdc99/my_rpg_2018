/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** callback_play
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int check_new_game(window_t *win)
{
    if (win->page == HEROES) {
        win->quests->quete_done = 15;
        display_text_in_textbox(win->quests);
        win->quests->sprite[1].depth = -1;
        win->quests->quete_done = 0;
        win->quests->combat = 0;
        save_quests(win);
        for (int i = 0; i < 15; i++)
            win->inv->items[i].name = NULL;
        if (save_inventory(win) == 84)
            return (84);
        win->player->last_pos = get_pos_float(930, 600);
        win->no_saves = 1;
        save_config_player(win);
    }
    return (0);
}

static int check_inv_quests(window_t *win)
{
    if (init_inventory(win->inv, win->font_berlin) == 84)
        return (84);
    if (init_player(win->player) == 84)
        return (84);
    if (set_player(win) == 84)
        return (84);
    if (init_objects(win->objects, win->inv) == 84)
        return (84);
    if (init_quests(win->quests, win->font_berlin) == 84)
        return (84);
    if (win->quests->quete_done < 5)
        win->quests->combat = 0;
    sfText_setString(win->text->str, "\n");
    sfMusic_stop(win->music->menu_song);
    return (0);
}

int play_game(window_t *win)
{
    sfMusic_play(win->music->button_sound);
    sfMusic_play(win->music->town_song);
    if (check_new_game(win) == 84)
        return (84);
    win->player = parser_player(win->player, "ressources/text/config_player");
    if (win->player == NULL)
        return (84);
    if (win->player->actual_health > win->player->health)
        win->player->actual_health = win->player->health;
    win->page = win->player->last_page;
    if (check_inv_quests(win) == 84)
        return (84);
    return (0);
}