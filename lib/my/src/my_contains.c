/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** my_contains.c
*/

int my_contains(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}