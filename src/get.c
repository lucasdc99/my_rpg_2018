/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get
*/

#include "../include/rpg.h"
#include "../include/my.h"

sfIntRect get_rect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfVector2f get_pos_float(float x, float y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfVector2i get_pos_int(int x, int y)
{
    sfVector2i vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

char *get_buffer(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *buff = NULL;
    char *tmp = NULL;

    if (fd < 0)
        return (NULL);
    buff = get_next_line(fd);
    if (buff == NULL)
        return (NULL);
    buff = my_strcat(buff, "\n");
    tmp = get_next_line(fd);
    while (tmp != NULL) {
        buff = my_strcat(buff, tmp);
        buff = my_strcat(buff, "\n");
        tmp = get_next_line(fd);
    }
    close(fd);
    return (buff);
}