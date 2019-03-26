/*
** EPITECH PROJECT, 2018
** my_malloc.c
** File description:
** my_malloc.c
*/

#include "../../../include/my.h"

char **my_malloc2d(int lines, int cols)
{
    char **buffer;

    buffer = (char **)malloc(sizeof(char *) * (lines + 1));
    if (buffer == NULL)
        return (NULL);
    for (int i = 0; i < lines; i++) {
        buffer[i] = (char *)malloc(sizeof(char) * (cols + 1));
        if (buffer[i] == NULL)
            return (NULL);
    }
    return (buffer);
}

int **my_malloc2d_int(int lines, int cols)
{
    int **buffer;

    buffer = (int **)malloc(sizeof(int *) * (lines + 1));
    if (buffer == NULL)
        return (NULL);
    for (int i = 0; i < lines; i++) {
        buffer[i] = (int *)malloc(sizeof(int) * (cols + 1));
        if (buffer[i] == NULL)
            return (NULL);
    }
    return (buffer);
}

short **my_malloc2d_short(int lines, int cols)
{
    short **buffer;

    buffer = (short **)malloc(sizeof(short *) * (lines + 1));
    if (buffer == NULL)
        return (NULL);
    for (int i = 0; i < lines; i++) {
        buffer[i] = (short *)malloc(sizeof(short) * (cols + 1));
        if (buffer[i] == NULL)
            return (NULL);
    }
    return (buffer);
}

char *my_malloc(int size)
{
    char *buffer = (char *)malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return (NULL);
    return (buffer);
}