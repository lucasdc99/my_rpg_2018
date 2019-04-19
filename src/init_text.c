/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_text
*/

#include "../include/rpg.h"
#include "../include/my.h"

void display_text_in_textbox(quest_t *quest, char *text)
{
    quest->sprite[1].depth = 1;
    sfText_setString(quest->text[0].str, text);
    sfText_setPosition(quest->text[0].str, sfSprite_getPosition(quest->sprite[1].sprite));
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