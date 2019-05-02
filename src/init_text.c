/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_text
*/

#include "../include/rpg.h"
#include "../include/my.h"

// void check_unicode()
// {
//     int x = {}
// }

void str_to_unicode(char *str, sfUint32 *unistr[])
{
    sfUint32 tmp[300];
    int a = 0;

    unistr[0] = tmp;
    if (str != NULL && str[0] != '\0') {
        for (int i = 0; str[i] != '\0'; i++) {
            switch (str[i]) {
            case '&':
                unistr[0][a++] = '\n';
                break;
            case '_':
                unistr[0][a++] = 0x00E9;
                i += 2;
                break;
            case '#':
                unistr[0][a++] = 0x00E0;
                i += 2;
                break;
            case '{':
                unistr[0][a++] = 0x00EA;
                i += 2;
                break;
            case '[':
                unistr[0][a++] = 0x00F9;
                i += 2;
                break;
            case '@':
                unistr[0][a++] = 0x00FB;
                i += 2;
                break;
            case '|':
                unistr[0][a++] = 0x00E2;
                i += 2;
                break;
            case ']':
                unistr[0][a++] = 0x00E8;
                i += 2;
                break;
            default:
                unistr[0][a++] = str[i];
                break;
            }
        }
        unistr[0][a] = '\0';
    }
}

void display_text_in_textbox(quest_t *quest)
{
    static int fd = 0;
    char *str = NULL;
    sfUint32 *unistr;
    sfVector2f pos;
    int actual = 0;
    static int opened = 0;

    if (quest->quete_done == 15) {
        if (fd != 0) {
            close(fd);
            fd = 0;
        }
        return;
    }
    pos = sfSprite_getPosition(quest->sprite[1].sprite);
    if (fd == 0) {
        fd = open("ressources/text/script_paroles", O_RDONLY);
        while (actual < quest->quete_done) {
            opened++;
            str = get_next_line(fd);
            if (str == NULL || str[0] == '\0')
                actual++;
        }
    }
    if (opened == 0 || str == NULL || str[0] == '\0')
        str = get_next_line(fd);
    if (opened != 0)
        opened = 0;
    quest->sprite[1].depth = 1;
    sfText_setCharacterSize(quest->text[1].str, 30);
    str_to_unicode(str, &unistr);
    if (str == NULL || str[0] == '\0' || unistr == NULL || unistr[0] == '\0') {
        quest->quete_done++;
    } else {
        sfText_setUnicodeString(quest->text[1].str, unistr);
    }
    sfText_setPosition(quest->text[1].str, get_pos_float(pos.x + 20, pos.y + 20));
}

void init_text(text_t *text, char *display, sfVector2f pos, sfFont *font)
{
    text->str = sfText_create();
    sfText_setFont(text->str, font);
    sfText_setColor(text->str, sfWhite);
    sfText_setCharacterSize(text->str, 50);
    sfText_setString(text->str, display);
    sfText_setPosition(text->str, pos);
}