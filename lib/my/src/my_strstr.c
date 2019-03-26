/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** find char * in char *
*/

int find_str(char *str, char *to_find)
{
    for (int i = 0; to_find[i] != '\0'; i++) {
        if (to_find[i] != str[i])
            return (0);
    }
    return (1);
}

char *my_strstr(char *str, char *to_find)
{
    if (str[0] != '\0') {
        if (find_str(str, to_find) == 0)
            return (my_strstr(str + 1, to_find));
    }
    return (str);
}