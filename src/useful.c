/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** useful
*/

#include "../include/rpg.h"
#include "../include/my.h"

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

void set_struct(window_t *win, int button, int text, int sprite)
{
    if (button > 0)
        win->scene[win->page].button = malloc(sizeof(button_t) * button);
    if (text > 0)
        win->scene[win->page].text = malloc(sizeof(text_t) * text);
    if (sprite > 0)
        win->scene[win->page].sprite = malloc(sizeof(sprite_t) * sprite);
    win->scene[win->page].nb_text = text;
    win->scene[win->page].nb_button = button;
    win->scene[win->page].nb_sprite = sprite;
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