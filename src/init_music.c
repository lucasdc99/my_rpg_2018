/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_music
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int create_music_end(music_t *music)
{
    char *path = {"ressources/music/"};
    char *name[] = {"main_song.ogg", "town.ogg", "boss.ogg"};

    music->menu_song = sfMusic_createFromFile(my_strcat(path, name[0]));
    if (music->menu_song == NULL)
        return (84);
    music->town_song = sfMusic_createFromFile(my_strcat(path, name[1]));
    if (music->town_song == NULL)
        return (84);
    music->boss_song = sfMusic_createFromFile(my_strcat(path, name[2]));
    if (music->boss_song == NULL)
        return (84);
    return (0);
}

static int create_music_boss(music_t *music)
{
    char *path = {"ressources/music/"};
    char *name[] = {"mega-attack.ogg", "inventory.ogg", "button.ogg"};

    music->enemy_attack = sfMusic_createFromFile(my_strcat(path, name[0]));
    if (music->enemy_attack == NULL)
        return (84);
    music->open_menus = sfMusic_createFromFile(my_strcat(path, name[1]));
    if (music->open_menus == NULL)
        return (84);
    music->button_sound = sfMusic_createFromFile(my_strcat(path, name[2]));
    if (music->button_sound == NULL)
        return (84);
    if (create_music_end(music) == 84)
        return (84);
    return (0);
}

static int create_music_other(music_t *music)
{
    char *path = {"ressources/music/"};
    char *name[] = {"boss_battle.ogg", "attack.ogg",
        "mega_attack_boss.ogg", "heal.ogg"};

    music->boss_final = sfMusic_createFromFile(my_strcat(path, name[0]));
    if (music->boss_final == NULL)
        return (84);
    music->basic_attack = sfMusic_createFromFile(my_strcat(path, name[1]));
    if (music->basic_attack == NULL)
        return (84);
    music->special_attack = sfMusic_createFromFile(my_strcat(path, name[2]));
    if (music->special_attack == NULL)
        return (84);
    music->heal = sfMusic_createFromFile(my_strcat(path, name[3]));
    if (music->heal == NULL)
        return (84);
    if (create_music_boss(music) == 84)
        return (84);
    return (0);
}

static int create_musics(music_t *music)
{
    char *path = {"ressources/music/"};
    char *name[] = {"door_open.ogg", "door_close.ogg", "stone_door.ogg",
        "boss_battle_music.ogg"};

    music->door_open = sfMusic_createFromFile(my_strcat(path, name[0]));
    if (music->door_open == NULL)
        return (84);
    music->door_close = sfMusic_createFromFile(my_strcat(path, name[1]));
    if (music->door_close == NULL)
        return (84);
    music->stone_door = sfMusic_createFromFile(my_strcat(path, name[2]));
    if (music->stone_door == NULL)
        return (84);
    music->boss_battle = sfMusic_createFromFile(my_strcat(path, name[3]));
    if (music->boss_battle == NULL)
        return (84);
    if (create_music_other(music) == 84)
        return (84);
    return (0);
}

int init_music(music_t *music)
{
    music->pos_sound = get_pos_float(1400, 550);
    music->volume = 100;
    music->vol_pos = 800;
    if (create_musics(music) == 84)
        return (84);
    sfMusic_setLoop(music->boss_battle, sfTrue);    
    sfMusic_setLoop(music->boss_song, sfTrue);    
    sfMusic_setLoop(music->boss_final, sfTrue);    
    sfMusic_setLoop(music->town_song, sfTrue);    
    return (0);
}