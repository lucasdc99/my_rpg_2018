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
    window_t *win = malloc(sizeof(window_t));
    FILE *fp;

    if (win == NULL || env == NULL || env[0] == NULL || check_env(env) == 84)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (display_help());
    win = create_window(win);
    win->player = parser(win->player, "ressources/text/config_player");
    win->inv = parser_inv(win->inv, "ressources/text/inventory");
    if (win->player == NULL) {
        win->no_saves = 1;
        // fp = fopen("ressources/text/config_player", "wb+");
        // fprintf(fp, "NAME = %s\n", "Ley-the-Monster-Whisperer");
        // fprintf(fp, "HEALTH = %d\n", 80);
        // fprintf(fp, "XP = %d\n", 100);
        // fprintf(fp, "STRENGTH = %d\n", 90);
        // fprintf(fp, "POSITION X = %f\n", 900.0);
        // fprintf(fp, "POSITION Y = %f\n", 527.0);
        // fprintf(fp, "PAGE = %d\n", CASTLE);
        // fclose(fp);
        win->player = malloc(sizeof(player_t) * 1);
        win->player->sprite = malloc(sizeof(sprite_t) * 1);
        win->player->sprite->sprite = NULL;
        win->player->sprite->texture = NULL;
        win->player->last_pos = get_pos_float(-100, -100);
        win->player->direction = 1;
        win->player->move_rect = 0;
        win->player->last_page = CASTLE;
        // win->inv = malloc(sizeof(inventory_t) * 1);
        // win->inv->items = malloc(sizeof(items_t) * 1);
        //win->player = parser(win->player, "ressources/text/config_player");
        // if (win->player == NULL)
        //     return (84);
    }
    if (win->inv == NULL)
        return (84);
    display(win);
    destroy_all(win);
    return (0);
}
