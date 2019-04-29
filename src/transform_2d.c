/*
** EPITECH PROJECT, 2019
** transform_2d
** File description:
** transform_2d
*/

#include "../include/my.h"

static int count_lines(char *str, char sep)
{
    int count = 0;

    if (str == NULL)
        return (-1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep)
            count++;
    }
    return (++count);
}

char **transform_2d(char *tmp, char sep)
{
    char **str_2d = malloc(sizeof(char *) * (count_lines(tmp, sep) + 1));
    char *str = my_strdup(tmp);
    int j = 0;
    int k = 0;
    int i = 0;

    if (tmp == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            str[i++] = '\0';
            str_2d[j++] = &str[k];
            k = i;
        }
    }
    str[i] = '\0';
    str_2d[j++] = &str[k];
    k = i;
    str_2d[j] = NULL;
    return (str_2d);
}