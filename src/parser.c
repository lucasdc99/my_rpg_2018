/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** parser
*/

#include "../include/rpg.h"
#include "../include/my.h"

static char *parse_string(char *str)
{
    for (; *str != '='; (*str)++);
    str += 2;
    if (my_strcmp(str, "NULL") == 0)
        return (NULL);
    return (str);
}

static int parse_int(char *str)
{
    for (; *str != '='; (*str)++);
    str += 2;
    return (my_getnbr(str));
}

int parser(player_t *player, char *filename)
{
    int fd = open(filename, O_RDONLY);

    player->name = parse_string(get_next_line(fd));
    player->health = parse_int(get_next_line(fd));
    player->xp = parse_int(get_next_line(fd));
    return (0);
}