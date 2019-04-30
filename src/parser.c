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

inventory_t *parser_inv(inventory_t *inv, char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd < 0)
        return (NULL);
    for (int i = 0; i < 15; i++) {
        inv->items[i].name = get_next_line(fd);
        if (my_strcmp(inv->items[i].name, "(null)") == 0) {
            inv->items[i].name = NULL;
        } else
            inv->items[i].busy = 1;
    }
    close(fd);
    return (inv);
}

quest_t *parser_quests(quest_t *quest, char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *str;

    if (fd < 0)
        return (0);
    str = get_next_line(fd);
    if (str == NULL)
        quest->quete_done = 0;
    else
        quest->quete_done = my_getnbr(str);
    close(fd);
    return (quest);
}

player_t *parser_player(player_t *player, char *filename)
{
    int fd = open(filename, O_RDONLY);

    if (fd < 0)
        return (NULL);
    player->name = parse_string(get_next_line(fd));
    player->health = parse_int(get_next_line(fd));
    player->xp = parse_int(get_next_line(fd));
    player->strength = parse_int(get_next_line(fd));
    player->last_pos.x = parse_int(get_next_line(fd));
    player->last_pos.y = parse_int(get_next_line(fd));
    player->last_page = parse_int(get_next_line(fd));
    if (player->name == NULL || player->health <= 0 || player->xp < 0 ||
    player->strength < 0 || player->last_pos.x < 0 || player->last_pos.y < 0 ||
    player->last_page < 0) {
        return (NULL);
    }
    while (get_next_line(fd) != NULL)
        get_next_line(fd);
    close(fd);
    return (player);
}