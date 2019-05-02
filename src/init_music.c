/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_music
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void create_musics(music_t *music)
{
    char *path = {"ressources/music/"};
    char *name[] = {"door_open.ogg", "door_close.ogg", "stone_door.ogg",
        "boss_battle_music.ogg", "boss_battle.ogg", "attack.ogg",
        "mega_attack_boss.ogg", "heal.ogg", "mega-attack.ogg", "inventory.ogg",
        "button.ogg", "main_song.ogg", "town.ogg", "boss.ogg"};

    music->door_open = sfMusic_createFromFile(my_strcat(path, name[0]));
    music->door_close = sfMusic_createFromFile(my_strcat(path, name[1]));
    music->stone_door = sfMusic_createFromFile(my_strcat(path, name[2]));
    music->boss_battle = sfMusic_createFromFile(my_strcat(path, name[3]));
    music->boss_final = sfMusic_createFromFile(my_strcat(path, name[4]));
    music->basic_attack = sfMusic_createFromFile(my_strcat(path, name[5]));
    music->special_attack = sfMusic_createFromFile(my_strcat(path, name[6]));
    music->heal = sfMusic_createFromFile(my_strcat(path, name[7]));
    music->enemy_attack = sfMusic_createFromFile(my_strcat(path, name[8]));
    music->open_menus = sfMusic_createFromFile(my_strcat(path, name[9]));
    music->button_sound = sfMusic_createFromFile(my_strcat(path, name[10]));
    music->menu_song = sfMusic_createFromFile(my_strcat(path, name[11]));
    music->town_song = sfMusic_createFromFile(my_strcat(path, name[12]));
    music->boss_song = sfMusic_createFromFile(my_strcat(path, name[13]));
}

void init_music(music_t *music)
{
    music->volume = 100;
    music->vol_pos = 800;
    create_musics(music);
}