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
    if (str == NULL)
        return (NULL);
    for (; *str != '=' && *str != '\0'; str++);
    if (*str == '\0')
        return (NULL);
    str += 2;
    return (str);
}

static int parse_int(char *str)
{
    if (str == NULL)
        return (-1);
    for (; *str != '=' && *str != '\0'; str++);
    if (*str == '\0')
        return (-1);
    str += 2;
    return (my_getnbr(str));
}

player_t *parser(player_t *player, char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd < 0)
        return (NULL);
    player->name = parse_string(get_next_line(fd));
    if (player->name == NULL)
        return (NULL);
    player->health = parse_int(get_next_line(fd));
    if (player->health < 0)
        return (NULL);
    player->xp = parse_int(get_next_line(fd));
    if (player->xp < 0)
        return (NULL);
    player->strength = parse_int(get_next_line(fd));
    if (player->strength < 0)
        return (NULL);
    player->last_pos.x = parse_int(get_next_line(fd));
    player->last_pos.y = parse_int(get_next_line(fd));
    player->last_page = parse_int(get_next_line(fd));
    return (player);
}