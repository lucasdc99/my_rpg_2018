/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_text
*/

#include "../include/rpg.h"
#include "../include/my.h"

void display_text_in_textbox(quest_t *quest)
{
    static int fd = 0;
    char *str = NULL;
    sfUint32 *unistr = NULL;
    sfVector2f pos = sfSprite_getPosition(quest->sprite[1].sprite);
    int actual = 0;
    int a = 0;

    if (fd == 0) {
        fd = open("ressources/text/script_paroles", O_RDONLY);
        while (actual < quest->quete_done) {
            str = get_next_line(fd);
            if (str[0] == '\0')
                actual++;
        }
    }
    quest->sprite[1].depth = 1;
    sfText_setCharacterSize(quest->text[1].str, 30);
    str = get_next_line(fd);
    if (str != NULL) {
        unistr = malloc(sizeof(sfUint32) * my_strlen(str));
        for (int i = 0; str[i] != '\0'; i++) {
            switch (str[i])
            {
            case '&':
                unistr[a++] = '\n';
                break;
            case '8':
                unistr[a++] = 0x00E9;
                i += 2;
                break;
            case '7':
                unistr[a++] = 0x00E0;
                i += 2;
                break;
            case '6':
                unistr[a++] = 0x00EA;
                i += 2;
                break;
            case '5':
                unistr[a++] = 0x00F9;
                i += 2;
                break;
            case '4':
                unistr[a++] = 0x00FB;
                i += 2;
                break;
            case '3':
                unistr[a++] = 0x00E2;
                i += 2;
                break;
            default:
                unistr[a++] = str[i];
                break;
            }
        }
        unistr[a] = '\0';
    }
    if (str == NULL || str[0] == '\0') {
        quest->quete_done++;
    }
    else {
        sfText_setUnicodeString(quest->text[1].str, unistr);
    }
    sfText_setPosition(quest->text[1].str, get_pos_float(pos.x + 20, pos.y + 20));
}

void init_text(text_t *text, char *display, sfVector2f pos)
{
    text->str = sfText_create();
    text->font = sfFont_createFromFile("ressources/font/berlin.ttf");
    sfText_setFont(text->str, text->font);
    sfText_setColor(text->str, sfWhite);
    sfText_setCharacterSize(text->str, 50);
    sfText_setString(text->str, display);
    sfText_setPosition(text->str, pos);
}