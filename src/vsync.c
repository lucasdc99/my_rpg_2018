/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** vsync
*/

#include "../include/rpg.h"
#include "../include/my.h"

int set_vsync(window_t *win)
{
    sfTexture *texture = NULL;

    if (win->states->vsync == 0) {
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox2.png",
        NULL);
    } else {
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox.png",
        NULL);
    }
    if (texture == NULL)
        return (84);
    win->scene[OPTIONS].button[3].rect_idle = get_rect(0, 0, 350, 350);
    win->scene[OPTIONS].button[3].rect_hovered = get_rect(0, 0, 350, 350);
    win->scene[OPTIONS].button[3].rect_pressed = get_rect(0, 0, 350, 350);
    sfRectangleShape_setTexture(win->scene[OPTIONS].button[3].shape,
    texture, sfTrue);
    return (0);
}