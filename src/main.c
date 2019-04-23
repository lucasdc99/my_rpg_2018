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
    close(fd);
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
    init_music(win->music);
    win->player = parser_player(win->player, "ressources/text/config_player");
    win->inv = parser_inv(win->inv, "ressources/text/inventory");
    win->quests = parser_quests(win->quests, "ressources/text/quests");
    if (win->player == NULL) {
        win->no_saves = 1;
        win->player = malloc(sizeof(player_t) * 1);
        win->player->sprite = malloc(sizeof(sprite_t) * 1);
        win->player->sprite->sprite = NULL;
        win->player->sprite->texture = NULL;
        win->player->last_pos = get_pos_float(-100, -100);
        win->player->direction = 1;
        win->player->move_rect = 0;
        win->player->last_page = CASTLE;
        save_config_player(win);
    }
    if (win->inv == NULL) {
        win->inv = malloc(sizeof(inventory_t) * 1);
        win->inv->sprite = malloc(sizeof(sprite_t) * 1);
        win->inv->items = malloc(sizeof(items_t) * 12);
        for (int i = 0; i < 12; i++)
            win->inv->items[i].name = NULL;
        save_inventory(win);
    }
    if (win->quests == NULL) {
        win->quests = malloc(sizeof(quest_t) * 1);
        win->quests->sprite = malloc(sizeof(sprite_t) * 6);
        win->quests->text = malloc(sizeof(text_t) * 5);
        win->quests->quete_done = 0;
        save_quests(win);
    }
    display(win);
    destroy_all(win);
    return (0);
}
