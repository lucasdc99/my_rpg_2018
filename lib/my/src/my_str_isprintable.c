/*
** EPITECH PROJECT, 2018
** my_str_is_printable.c
** File description:
** my_str_is_printable
*/

int my_str_isprintable(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32)
            return (1);
        else
            return (0);
    }
    return (0);
}