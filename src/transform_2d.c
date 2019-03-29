/*
** EPITECH PROJECT, 2019
** transform_2d
** File description:
** transform_2d
*/

#include "my.h"

int count_lines(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] != '\0')
            count++;
    }
    return (count);
}

int len_line(char *str, int i)
{
    int count = 0;
    int a = 0;

    while (count < i) {
        if (str[a] == '\0')
            return (-1);
        if (str[a] == '\n' && str[a + 1] != '\0')
            count++;
        a++;
    }
    count = 0;
    a++;
    while (str[a] != '\n' && str[a + 1] != '\0') {
        count++;
        a++;
    }
    count++;
    return (count);
}

char **transform_pos_to_tab(char *str)
{
    int x = 0;
    int y = 0;
    char **tab = malloc(sizeof(char *) * 122);

    for (int i = 0; i < 121; i++)
        tab[i] = malloc(sizeof(char) * 5);
    for (int i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n') {
            tab[y][x] = '\0';
            x = 0;
            y++;
        } else {
            tab[y][x] = str[i];
            x++;
        }
    }
    tab[y][x] = '\0';
    tab[y + 1] = NULL;
    return (tab);
}

char **transform_2d(char *str)
{
    char **str_2d = malloc(sizeof(char *) * (count_lines(str) + 1));
    int j = 0;
    int k = 0;

    for (int i = 0; i < count_lines(str) + 1; i++)
        str_2d[i] = malloc(sizeof(char) * (len_line(str, i) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str_2d[j][k] = '\0';
            j++;
            k = 0;
        } else {
            str_2d[j][k] = str[i];
            k++;
        }
    }
    return (str_2d);
}