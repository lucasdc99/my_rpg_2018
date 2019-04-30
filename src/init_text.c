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
    sfVector2f pos = sfSprite_getPosition(quest->sprite[1].sprite);
    int actual = 0;

    printf("ok\n");
    if (fd == 0) {
        fd = open("ressources/text/script_paroles", O_RDONLY);
        while (actual < quest->quete_done) {
            str = get_next_line(fd);
            if (str[0] == '\0')
                actual++;
        }
    }
    printf("ok\n");
    quest->sprite[1].depth = 1;
    printf("ok\n");
    sfText_setCharacterSize(quest->text[1].str, 30);
    printf("ok\n");
    str = get_next_line(fd);
    printf("ok1\n");
    if (str != NULL) {
        for (int i = 0; str[i] != '\0'; i++) {
            printf("haha\n");
            if (str[i] == '&')
                str[i] = '\n';
        }
    }
    printf("aa\n");
    if (str == NULL || str[0] == '\0') {
        quest->quete_done++;
        printf("uu\n");
    }
    else {
        sfText_setString(quest->text[1].str, str);
        printf("oo\n");
    }
    printf("ok\n");
    sfText_setPosition(quest->text[1].str, get_pos_float(pos.x + 20, pos.y + 20));
    printf("okay\n");
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