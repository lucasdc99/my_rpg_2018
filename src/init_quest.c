/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_quest
*/

#include "../include/rpg.h"
#include "../include/my.h"

static int init_sprites_two(quest_t *quest)
{
    if (init_sprite(&quest->sprite[6], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 500)) == 84)
        return (84);
    if (init_sprite(&quest->sprite[7], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 600)) == 84)
        return (84);
    sfSprite_setScale(quest->sprite[1].sprite, get_pos_float(6, 6));
    sfSprite_setScale(quest->sprite[2].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[3].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[4].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[5].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[6].sprite, get_pos_float(0.2, 0.2));
    sfSprite_setScale(quest->sprite[7].sprite, get_pos_float(0.2, 0.2));
    return (0);
}

static int init_checkbox(quest_t *quest)
{
    if (init_sprite(&quest->sprite[4], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 300)) == 84)
        return (84);
    if (init_sprite(&quest->sprite[5], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 400)) == 84)
        return (84);
    if (init_sprites_two(quest) == 84)
        return (84);
    return (0);
}

static int init_sprites(quest_t *quest)
{
    if (init_sprite(&quest->sprite[0], "ressources/images/old_paper.png",
    get_pos_float(240, 50)) == 84)
        return (84);
    if (init_sprite(&quest->sprite[1],
    "ressources/images/generic-rpg-ui-text-box.png",
    get_pos_float(600, 50)) == 84)
        return (84);
    if (init_sprite(&quest->sprite[2], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 100)) == 84)
        return (84);
    if (init_sprite(&quest->sprite[3], "ressources/buttons/Checkbox.png",
    get_pos_float(1400, 200)) == 84)
        return (84);
    if (init_checkbox(quest) == 84)
        return (84);
    quest->sprite[1].depth = -1;
    quest->sprite[2].depth = -1;
    return (0);
}

static int init_next_quests(quest_t *quest, sfFont *font)
{
    if (init_text(&quest->text[3], "QUETE 3:    Aller parler au grand pere\n",
    get_pos_float(300, 300), font) == 84)
        return (84);
    if (init_text(&quest->text[4],
    "QUETE 4:    Trouver l'armure du grand pere\n",
    get_pos_float(300, 400), font) == 84)
        return (84);
    if (init_text(&quest->text[5], "QUETE 5:    Aller parler au grand pere\n",
    get_pos_float(300, 500), font) == 84)
        return (84);
    if (init_text(&quest->text[6], "QUETE 6:    Aller dans l'arene\n",
    get_pos_float(300, 600), font) == 84)
        return (84);
    return (0);
}

int init_quests(quest_t *quest, sfFont *font)
{
    if (init_sprites(quest) == 84)
        return (84);
    if (init_text(&quest->text[0], "QUETE 1:    Aller parler au grand pere\n",
    get_pos_float(300, 100), font) == 84)
        return (84);
    if (init_text(&quest->text[1], "bonjour\n",
    get_pos_float(0, 0), font) == 84)
        return (84);
    if (init_text(&quest->text[2],
    "QUETE 2:    Trouver l'epee du grand pere\n",
    get_pos_float(300, 200), font) == 84)
        return (84);
    return (init_next_quests(quest, font));
}