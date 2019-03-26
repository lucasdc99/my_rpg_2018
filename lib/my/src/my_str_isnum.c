/*
** EPITECH PROJECT, 2018
** my_str_is_num.c
** File description:
** my_str_is_num
*/

int my_str_isnum(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            return (1);
        else
            return (0);
    }
    return (0);
}