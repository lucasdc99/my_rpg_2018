/*
** EPITECH PROJECT, 2018
** my_str_islower.c
** File description:
** my_str_islower.c
*/

int my_str_islower(char const *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            return (1);
        else
            return (0);
    }
    return (0);
}
