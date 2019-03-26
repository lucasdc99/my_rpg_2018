/*
** EPITECH PROJECT, 2018
** my_str_capitalize.c
** File description:
** my_str_capitalize.c
*/

int alpha3(char *str, int i)
{
    if (str[i - 1] != ' ' && str[i] != ' ' && i != 0)
        return (0);
    return (1);
}

int alpha(char *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z')
        return (0);
    return (1);
}

int alpha2(char *str, int i)
{
    if (str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z')
        return (0);
    return (1);
}

char *my_strcapitalize(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if ((i == 0 && str[i] >= 'a' && str[i] <= 'z') || (alpha2(str, i) == 0))
            str[i] = str[i] - 'a' + 'A';
        else if ((alpha3(str, i) == 0) && (alpha(str, i) == 0))
            str[i] = str[i] - 'A'+ 'a';
    }
    return (str);
}