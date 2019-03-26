/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcompare
*/

int check1(char s1, char s2)
{
    if (s1 < s2)
        return (-1);
    else if (s1 > s2)
        return (1);
    else
        return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (check1(s1[i], s2[i]));
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-1);
    else if (s2[i] == '\0' && s1[i] != '\0')
        return (1);
    return (0);
}
