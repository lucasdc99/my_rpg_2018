/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_quest
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_sprites_two(quest_t *quest)
{
    init_sprite(&quest->sprite[6], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 500));
    init_sprite(&quest->sprite[7], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 600));
    sfSprite_setScale(quest->sprite[1].sprite, get_pos_float(6, 6));
    sfSprite_setScale(quest->sprite[2].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[3].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[4].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[5].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[6].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[7].sprite, get_pos_float(0.2, 0.2));
}

static void init_sprites(quest_t *quest)
{
    init_sprite(&quest->sprite[0], "ressources/old_paper.png",
    get_pos_float(240, 50));
    init_sprite(&quest->sprite[1],
    "ressources/pack/rpg-pack/UI/generic-rpg-ui-text-box.png",
    get_pos_float(600, 50));
    init_sprite(&quest->sprite[2], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 100));
    init_sprite(&quest->sprite[3], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 200));
    init_sprite(&quest->sprite[4], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 300));
    init_sprite(&quest->sprite[5], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 400));
    init_sprites_two(quest);
    quest->sprite[1].depth = -1;
    quest->sprite[2].depth = -1;
}

void init_quests(quest_t *quest, sfFont *font)
{
    init_sprites(quest);
    init_text(&quest->text[0], "QUETE 1:    Aller parler au grand pere\n",
    get_pos_float(300, 100), font);
    init_text(&quest->text[1], "bonjour\n", get_pos_float(0, 0), font);
    init_text(&quest->text[2], "QUETE 2:    Trouver l'epee du grand pere\n",
    get_pos_float(300, 200), font);
    init_text(&quest->text[3], "QUETE 3:    Aller parler au grand pere\n",
    get_pos_float(300, 300), font);
    init_text(&quest->text[4], "QUETE 4:    Trouver l'armure du grand pere\n",
    get_pos_float(300, 400), font);
    init_text(&quest->text[5], "QUETE 5:    Aller parler au grand pere\n",
    get_pos_float(300, 500), font);
    init_text(&quest->text[6], "QUETE 6:    Aller combattre le mechant\n",
    get_pos_float(300, 600), font);
}