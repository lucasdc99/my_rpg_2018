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
    music->button_sound = sfMusic_createFromFile(
    "ressources/music/button.ogg");
    music->menu_song = sfMusic_createFromFile(
    "ressources/music/main_song.ogg");
    music->town_song = sfMusic_createFromFile("ressources/music/town.ogg");
    music->boss_song = sfMusic_createFromFile("ressources/music/boss.ogg");
    init_music_two(music);
}

void init_music_two(music_t *music)
{
    music->door_open = sfMusic_createFromFile(
    "ressources/music/door_open.ogg");
    music->door_close = sfMusic_createFromFile(
    "ressources/music/door_close.ogg");
    music->stone_door = sfMusic_createFromFile(
    "ressources/music/stone_door.ogg");
    music->boss_battle = sfMusic_createFromFile(
    "ressources/music/boss_battle_music.ogg");
    music->boss_final = sfMusic_createFromFile(
    "ressources/music/boss_battle.ogg");
    music->basic_attack = sfMusic_createFromFile(
    "ressources/music/attack.ogg");
    music->special_attack = sfMusic_createFromFile(
    "ressources/music/mega_attack_boss.ogg");
    music->heal = sfMusic_createFromFile("ressources/music/heal.ogg");
    music->enemy_attack = sfMusic_createFromFile(
    "ressources/music/mega-attack.ogg");
    music->open_menus = sfMusic_createFromFile(
    "ressources/music/inventory.ogg");
}