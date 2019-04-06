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

    if (win == NULL || env == NULL || env[0] == NULL || check_env(env) == 84)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (display_help());
    win = create_window(win);
    win->player = parser(win->player, "ressources/text/config_player");
    if (win->player == NULL)
        return (84);
    display(win);
    destroy_all_music(win);
    return (0);
}
