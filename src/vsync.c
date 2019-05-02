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

    if (win->vsync == 0) {
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox2.png",
        NULL);
    } else {
        texture = sfTexture_createFromFile("ressources/buttons/Checkbox.png",
        NULL);
    }
    if (texture == NULL)
        return (84);
    sfRectangleShape_setTexture(win->scene[OPTIONS].button[3].shape,
    texture, sfTrue);
    return (0);
}