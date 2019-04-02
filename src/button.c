/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** button
*/

#include "../include/rpg.h"
#include "../include/my.h"

sfVector2f get_pos_text_button(button_t button, char *text)
{
    int len = my_strlen(text);
    sfVector2f size = sfRectangleShape_getSize(button.rect);
    int text_size = len * 35;
    sfVector2f new_pos = sfRectangleShape_getPosition(button.rect);

    new_pos.x += (size.x - text_size) / 2 + len * 2;
    new_pos.y += size.y / 2 - 35;
    return (new_pos);
}

int button_is_clicked(button_t button, sfVector2i click_position)
{
    sfVector2f pos_button = sfRectangleShape_getPosition(button.rect);
    sfVector2f size_button = sfRectangleShape_getSize(button.rect);

    if (click_position.x > pos_button.x &&
    click_position.x < size_button.x + pos_button.x) {
        if (click_position.y > pos_button.y &&
        click_position.y < size_button.y + pos_button.y) {
            return (1);
        }
    }
    return (0);
}

int button_is_hovered(button_t button, sfVector2i mouse_position)
{
    sfVector2f pos_button = sfRectangleShape_getPosition(button.rect);
    sfVector2f size_button = sfRectangleShape_getSize(button.rect);

    if (mouse_position.x > pos_button.x &&
    mouse_position.x < size_button.x + pos_button.x) {
        if (mouse_position.y > pos_button.y &&
        mouse_position.y < size_button.y + pos_button.y) {
            return (1);
        }
    }
    return (0);
}

void init_button_text(button_t *button, char *text, sfVector2f pos)
{
    button->font = sfFont_createFromFile("ressources/font/berlin.ttf");
    button->text = sfText_create();
    sfText_setString(button->text, text);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 50);
    sfText_setPosition(button->text, pos);
}

void init_button(button_t *button, sfVector2f position, sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    button->idle_color = sfRed;
    button->clicked_color = sfGreen;
    button->hovered_color = sfBlack;    
    sfRectangleShape_setFillColor(button->rect, button->idle_color);
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
}