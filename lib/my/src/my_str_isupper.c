/*
** EPITECH PROJECT, 2018
** my_str_is_upper.c
** File description:
** my_str_is_upper.c
*/

int my_str_isupper(char const *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            return (1);
        else
            return (0);
    }
    return (0);
}