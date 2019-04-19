/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_quest
*/

#include "../include/rpg.h"
#include "../include/my.h"

void init_quests(quest_t *quest)
{
    init_sprite(&quest->sprite[0], "ressources/old_paper.png", get_pos_float(240, 50));
    init_sprite(&quest->sprite[1], "ressources/pack/rpg-pack/UI/generic-rpg-ui-text-box.png", get_pos_float(800, 50));
    sfSprite_setScale(quest->sprite[1].sprite, get_pos_float(3, 3));
    quest->sprite[1].depth = -1;
    init_text(&quest->text[0], "QUETE 1:    Aller parler au grand pere\n", get_pos_float(300, 150));
}