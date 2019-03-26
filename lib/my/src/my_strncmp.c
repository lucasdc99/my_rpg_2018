/*
** EPITECH PROJECT, 2018
** my_strncmp.c
** File description:
** my_strncmp
*/

int check1(char c, char a);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int k = 0;

    for (int i = 0; s1[i] != '\0' && i < n; i++)
        k += check1(s1[i], s2[i]);
    if (k < 0)
        return (k);
    if (k > 0)
        return (k);
    else
        return (0);
}