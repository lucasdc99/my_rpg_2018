/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** str_to_unicode
*/

#include "../include/rpg.h"
#include "../include/my.h"

static sfUint32 check_unicode(char c, int *i)
{
    sfUint32 code[] = {'\n', 0x00E9, 0x00E0, 0x00EA, 0x00F9, 0x00FB,
        0x00E2, 0x00E8};
    char str[] = {'&', '_', '#', '{', '[', '@', '|', ']', '\0'};

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == c) {
            if (str[a] != '&')
                i[0] += 2;
            return (code[a]);
        }
    }
    return (c);
}

void str_to_unicode(char *str, sfUint32 *unistr[])
{
    sfUint32 tmp[300];
    int a = 0;

    unistr[0] = tmp;
    if (str != NULL && str[0] != '\0') {
        for (int i = 0; str[i] != '\0'; i++) {
            unistr[0][a++] = check_unicode(str[i], &i);
        }
        unistr[0][a] = '\0';
    }
}