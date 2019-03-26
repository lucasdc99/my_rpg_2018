/*
** EPITECH PROJECT, 2018
** strupcase
** File description:
** strupcase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = str[i] - 32;
    return (str);
}