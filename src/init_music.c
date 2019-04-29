/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_music
*/

#include "../include/rpg.h"
#include "../include/my.h"

void init_music(music_t *music)
{
    music->volume = 100;
    music->vol_pos = 800;
    music->button_sound = sfMusic_createFromFile("ressources/music/button.ogg");
    music->menu_song = sfMusic_createFromFile("ressources/music/main_song.ogg");
}