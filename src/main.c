/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** main
*/

#include "../include/rpg.h"
#include "../include/my.h"

int check_env(char **env)
{
    for (int i = 0; env[i + 1] != NULL; i++) {
        if (my_strncmp(env[i], "DISPLAY", 8) == 0)
            return (0);
    }
    return (84);
}

int display_help(void)
{
    int fd;
    int size;
    char buff[460];

    fd = open("ressources/text/help", O_RDONLY);
    if (fd < 0)
        return (84);
    size = read(fd, buff, sizeof(buff));
    if (size <= 0)
        return (84);
    my_printf(buff);
    if (close(fd) < 0)
        return (84);
    return (0);
}

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
        win->no_saves = 1;
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
        win->no_saves = 1;
    if (win->inv == NULL) {
        win->no_saves = 1;
        if (define_inv(win) == 84)
            return (84);
        if (save_inventory(win) == 84)
            return (84);
    }
    if (check_quest_error(win) == 84)
        return (84);
    return (0);
}

static int parsing(window_t *win)
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

int main(int ac, char **av, char **env)
{
    window_t *win = malloc(sizeof(window_t) * 1);

    if (win == NULL || env == NULL || env[0] == NULL || check_env(env) == 84)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (display_help());
    win = create_window(win);
    if (win == NULL)
        return (84);
    if (init_music(win->music) == 84)
        return (84);
    if (parsing(win) == 84)
        return (84);
    destroy_all(win);
    return (0);
}