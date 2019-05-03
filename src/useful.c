/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** useful
*/

#include "../include/rpg.h"
#include "../include/my.h"

int set_texture(window_t *win, char *name)
{
    sfTexture_destroy(win->scene[HEROES].sprite[0].texture);
    win->scene[HEROES].sprite[0].texture = sfTexture_createFromFile(name,
    NULL);
    if (win->scene[HEROES].sprite[0].texture == NULL)
        return (84);
    sfSprite_setTexture(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].texture, sfTrue);
    sfSprite_setScale(win->scene[HEROES].sprite[0].sprite,
    get_pos_float(15, 15));
    sfSprite_setTextureRect(win->scene[HEROES].sprite[0].sprite,
    win->scene[HEROES].sprite[0].rect);
    return (0);
}

void my_wait(window_t *win, int seconds)
{
    sfClock_restart(win->combat_clock);
    win->combat_time = sfClock_getElapsedTime(win->combat_clock);
    win->seconds = win->combat_time.microseconds / 1000000.0;
    while (win->seconds < seconds) {
        win->combat_time = sfClock_getElapsedTime(win->combat_clock);
        win->seconds = win->combat_time.microseconds / 100000.0;
    }
}

int is_inside_zone(sfVector2f limit1, sfVector2f limit2, sfVector2f pos)
{
    if (pos.x >= limit1.x && pos.x <= limit2.x) {
        if (pos.y >= limit1.y && pos.y <= limit2.y)
            return (1);
    }
    return (0);
}

int set_struct(window_t *win, int button, int text, int sprite)
{
    if (button > 0) {
        win->scene[win->page].button = malloc(sizeof(button_t) * button);
        if (win->scene[win->page].button == NULL)
            return (84);
    }
    if (text > 0) {
        win->scene[win->page].text = malloc(sizeof(text_t) * text);
        if (win->scene[win->page].text == NULL)
            return (84);
    }
    if (sprite > 0) {
        win->scene[win->page].sprite = malloc(sizeof(sprite_t) * sprite);
        if (win->scene[win->page].sprite == NULL)
            return (84);
    }
    win->scene[win->page].nb_text = text;
    win->scene[win->page].nb_button = button;
    win->scene[win->page].nb_sprite = sprite;
    return (0);
}

char *open_buff(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *buffer = NULL;

    if (fd < 0)
        return (NULL);
    buffer = malloc(sizeof(char) * 8400);
    if (buffer == NULL)
        return (NULL);
    if (read(fd, buffer, 8400) <= 0)
        return (NULL);
    buffer[8399] = '\0';
    close(fd);
    return (buffer);
}