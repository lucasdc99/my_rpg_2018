/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"


void open_door(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);
    sfIntRect rect;
    sfVector2f pos_door;

    if (win->quests->quete_done == 3)
        go_final(win);
    for (int i = 1; i < 4; i++) {
        rect = sfSprite_getTextureRect(win->scene[TOWN].sprite[i].sprite);
        pos_door = sfSprite_getPosition(win->scene[TOWN].sprite[i].sprite);
        if (pos_player.x >= pos_door.x - 20 && pos_player.x <= pos_door.x + 40) {
            if (pos_player.y >= pos_door.y && pos_player.y <= pos_door.y + 100) {
                rect.top = 64;
                sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite, rect);
            } else {
                if (rect.top >= 64) {
                    rect.top = 0;
                    sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite, rect);
                }
            }
            if (pos_player.y >= pos_door.y - 50 && pos_player.y <= pos_door.y + 20 && win->player->direction == UP) {
                win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
                win->player->last_pos.y += 50;
                pos_player.y -= 50;
                sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(880, 730));
                if (i == 1)
                    win->page = HOUSE1;
                if (i == 2)
                    win->page = HOUSE2;
                if (i == 3)
                    win->page = HOUSE3;
            }
        } else {
            if (rect.top >= 64) {
                rect.top = 0;
                sfSprite_setTextureRect(win->scene[TOWN].sprite[i].sprite, rect);
            }
        }
    }
}

void close_inventory(window_t *win)
{
    win->pause = 0;
    win->inventory = 0;
    if (win->actual_page == TOWN) {
        for (int i = 1; i < win->scene[TOWN].nb_sprite; i++)
            win->scene[TOWN].sprite[i].depth = 0;
    }
}

void open_quest(window_t *win)
{
    win->quest = 1;
    win->pause = 1;
    if (win->actual_page == TOWN) {
        for (int i = 1; i < win->scene[TOWN].nb_sprite; i++)
            win->scene[TOWN].sprite[i].depth = -1;
    }
}

void close_quest(window_t *win)
{
    win->quest = 0;
    win->pause = 0;
    if (win->actual_page == TOWN) {
        for (int i = 1; i < win->scene[TOWN].nb_sprite; i++)
            win->scene[TOWN].sprite[i].depth = 0;
    }
}

void pause_game(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;

    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 4;
    win->pause = 1;
    if (win->actual_page == TOWN) {
        sfSprite_setTexture(win->scene[TOWN].sprite[0].sprite, sfTexture_createFromFile("ressources/town_blur.png", NULL), sfTrue);
    }
    if (win->actual_page == CASTLE) {
        sfSprite_setTexture(win->scene[CASTLE].sprite[0].sprite, sfTexture_createFromFile("ressources/castle_blur.png", NULL), sfTrue);
    }
    if (win->actual_page == FOREST) {
        sfSprite_setTexture(win->scene[FOREST].sprite[0].sprite, sfTexture_createFromFile("ressources/forest_blur.png", NULL), sfTrue);
    }
    if (win->actual_page == FINAL) {
        sfSprite_setTexture(win->scene[FINAL].sprite[0].sprite, sfTexture_createFromFile("ressources/sbire_map_blur.png", NULL), sfTrue);
    }
    if (win->actual_page == BOSS) {
        sfSprite_setTexture(win->scene[BOSS].sprite[0].sprite, sfTexture_createFromFile("ressources/final_boss_blur.png", NULL), sfTrue);
    }
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape, get_pos_float(pos_window.x, pos_window.y));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape, get_pos_float(pos_window.x, pos_window.y + 200));
}

void unpause_game(window_t *win)
{
    win->pause = 0;
    if (win->actual_page == TOWN) {
        sfSprite_setTexture(win->scene[TOWN].sprite[0].sprite, sfTexture_createFromFile("ressources/town.png", NULL), sfTrue);
    }
    if (win->actual_page == CASTLE) {
        sfSprite_setTexture(win->scene[CASTLE].sprite[0].sprite, sfTexture_createFromFile("ressources/castle.png", NULL), sfTrue);
    }
    if (win->actual_page == FOREST) {
        sfSprite_setTexture(win->scene[FOREST].sprite[0].sprite, sfTexture_createFromFile("ressources/forest.png", NULL), sfTrue);
    }
    if (win->actual_page == FINAL) {
        sfSprite_setTexture(win->scene[FINAL].sprite[0].sprite, sfTexture_createFromFile("ressources/sbire_map.png", NULL), sfTrue);
    }
    if (win->actual_page == BOSS) {
        sfSprite_setTexture(win->scene[BOSS].sprite[0].sprite, sfTexture_createFromFile("ressources/final_boss.png", NULL), sfTrue);
    }
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape, get_pos_float(-600, -300));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape, get_pos_float(-600, -100));
}

void check_keyboard_input_ingame(window_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        if (win->inventory == 0 && win->pause == 0 && win->quest == 0)
            open_inventory(win);
        else if (win->quest == 0 && win->pause == 1 && win->inventory == 1)
            close_inventory(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        if (win->quest == 0 && win->inventory == 0 && win->pause == 0)
            open_quest(win);
        else if (win->inventory == 0 && win->pause == 1 && win->quest == 1)
            close_quest(win);
    }
}

sfVector2f get_nearest_item_pos(inventory_t *inv, sfVector2f move_pos)
{
    sfVector2f pos = {10, 10};

    for (int i = 0; i < 15; i++) {
        if (move_pos.x >= inv->items[i].pos.x - 10 && move_pos.x < inv->items[i].pos.x + 80) {
            if (move_pos.y >= inv->items[i].pos.y - 10 && move_pos.y < inv->items[i].pos.y + 80) {
                pos.x = inv->items[i].pos.x;
                pos.y = inv->items[i].pos.y;
                return (pos);
            }
        }
    }
    return (get_inv_pos(inv));
}

char *get_name_from_type(int type)
{
    if (type == SWORD)
        return ("Dague");
    if (type == ARMOR)
        return ("Armure");
    if (type == HELMET)
        return ("Casque");
    return ("\n");
}


int get_actual_pos_inv(inventory_t *inv, sfVector2f move_pos)
{
    int not_busy = -1;

    for (int i = 0; i < 15; i++) {
        if (inv->items[i].busy == 0 && not_busy == -1)
            not_busy = i;
        if (move_pos.x >= inv->items[i].pos.x - 10 && move_pos.x < inv->items[i].pos.x + 80) {
            if (move_pos.y >= inv->items[i].pos.y - 10 && move_pos.y < inv->items[i].pos.y + 80) {
                return (i);
            }
        }
    }
    printf("%d\n", not_busy);
    return (not_busy);
}

int is_item_outside_inv(sfVector2f move_pos, inventory_t *inv)
{
    sfVector2f pos_inv = sfSprite_getPosition(inv->sprite->sprite);
    sfVector2u size_inv = sfTexture_getSize(sfSprite_getTexture(inv->sprite->sprite));

    if (move_pos.x < pos_inv.x || move_pos.x > pos_inv.x + size_inv.x)
        return (1);
    if (move_pos.y < pos_inv.y || move_pos.y > pos_inv.y + size_inv.y)
        return (1);
    return (0);
}

void check_drag_and_drop_inv(window_t *win)
{
    sfVector2i click_pos;
    sfVector2f move_pos;
    sfVector2f pos;
    int actual_pos = 0;

    for (int i = 0; i < win->nb_objects; i++) {
        click_pos = sfMouse_getPositionRenderWindow(win->window);
        move_pos = get_pos_float(click_pos.x, click_pos.y);
        if (win->objects[i].item == 2 && win->objects[i].depth == 2) {
            sfSprite_setPosition(win->objects[i].sprite, get_inv_pos(win->inv));
            actual_pos = get_actual_pos_inv(win->inv, move_pos);
            win->inv->items[actual_pos].name = get_name_from_type(win->objects[i].type);
            if (actual_pos >= 12 && my_strcmp(win->inv->items[actual_pos].name, "Dague") == 0) {
                win->player->strength += 20;
            }
            win->objects[i].item = 1;
            if (is_item_outside_inv(move_pos, win->inv) == 0) {
                pos = get_nearest_item_pos(win->inv, move_pos);
                if (win->inv->items[actual_pos].busy == 0)
                    sfSprite_setPosition(win->objects[i].sprite, pos);
                else
                    sfSprite_setPosition(win->objects[i].sprite, get_inv_pos(win->inv));
                win->inv->items[actual_pos].busy = 1;
            } else {
                sfSprite_setPosition(win->objects[i].sprite, sfSprite_getPosition(win->player->sprite->sprite));
                win->objects[i].depth = 0;
                win->inv->items[actual_pos].name = NULL;
                save_inventory(win);
            }
        }
    }
}

void drag_and_drop_inv(window_t *win)
{
    sfVector2i click_pos;
    sfVector2f move_pos;
    sfVector2f pos_item;
    int actual_pos = 0;
    int item = -1;

    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 2)
            item = i;
    }
    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 1 && win->objects[i].depth == 2) {
            click_pos = sfMouse_getPositionRenderWindow(win->window);
            move_pos = get_pos_float(click_pos.x, click_pos.y);
            pos_item = sfSprite_getPosition(win->objects[i].sprite);
            if (move_pos.x >= pos_item.x - 10 && move_pos.x < pos_item.x + 20) {
                if (move_pos.y >= pos_item.y - 10 && move_pos.y < pos_item.y + 20) {
                    actual_pos = get_actual_pos_inv(win->inv, move_pos);
                    win->objects[i].item = 2;
                    win->inv->items[actual_pos].busy = 0;
                    win->inv->items[actual_pos].name = NULL;
                    item = i;
                }
            }
        }
    }
    for (int i = 0; i < win->nb_objects && item == -1; i++) {
        if (win->objects[i].item == 2)
            item = i;
    }
    click_pos = sfMouse_getPositionRenderWindow(win->window);
    move_pos = get_pos_float(click_pos.x, click_pos.y);
    if (item != -1)
        sfSprite_setPosition(win->objects[item].sprite, move_pos);
}

void close_textbox(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->quests->sprite[1].depth >= 1) {
        if (is_inside_zone(get_pos_float(550, 700), get_pos_float(600, 780), pos_player) == 0 && is_inside_zone(get_pos_float(700, 700), get_pos_float(740, 780), pos_player) == 0 && is_inside_zone(get_pos_float(1120, 750), get_pos_float(1210, 800), pos_player) == 0) {
            win->quests->sprite[1].depth = -1;
            sfText_setString(win->text->str, "\n");
        }
    }
}

void check_pickup_sword(window_t *win, sfVector2f pos_player)
{
    int actual_pos = -1;

    if (win->objects[SWORD].depth == 0) {
        if (is_inside_zone(get_pos_float(700, 700), get_pos_float(740, 780), pos_player) == 1) {
            sfText_setString(win->text->str, "Appuyez sur E\n");
            if (sfKeyboard_isKeyPressed(sfKeyE)) {
                sfText_setString(win->text->str, "\n");
                sfSprite_setPosition(win->objects[SWORD].sprite, get_inv_pos(win->inv));
                actual_pos = get_actual_pos_inv(win->inv, get_pos_float(0, 0));
                win->inv->items[actual_pos].busy = 1;
                win->inv->items[actual_pos].name = get_name_from_type(win->objects[SWORD].type);
                win->objects[SWORD].item = 1;
                win->objects[SWORD].depth = 2;
                display_text_in_textbox(win->quests, "Vous avez trouve une Epee !\n");
                win->quests->quete_done++;
            }
        } else if (is_inside_zone(get_pos_float(550, 700), get_pos_float(600, 780), pos_player) == 0) {
            sfText_setString(win->text->str, "\n");
        }
    }
}

void talk_to_old(window_t *win, sfVector2f pos_player)
{
    if (win->quests->sprite[1].depth <= 0) {
        if (is_inside_zone(get_pos_float(550, 700), get_pos_float(600, 780), pos_player) == 1) {
            sfText_setString(win->text->str, "Appuyez sur E\n");
            if (sfKeyboard_isKeyPressed(sfKeyE)) {
                sfText_setString(win->text->str, "\n");
                display_text_in_textbox(win->quests, "Bonjour\n");
                win->quests->quete_done++;
            }
        } else if (is_inside_zone(get_pos_float(700, 700), get_pos_float(740, 780), pos_player) == 0) {
            sfText_setString(win->text->str, "\n");
        }
    }
}

void check_pickup_armor(window_t *win, sfVector2f pos_player)
{
    int actual_pos = -1;

    if (win->quests->sprite[1].depth <= 0) {
        if (win->objects[ARMOR].depth == 0) {
            if (is_inside_zone(get_pos_float(1120, 750), get_pos_float(1220, 860), pos_player) == 1) {
                sfText_setString(win->text->str, "Appuyez sur E\n");
                if (sfKeyboard_isKeyPressed(sfKeyE)) {
                    sfText_setString(win->text->str, "\n");
                    sfSprite_setPosition(win->objects[ARMOR].sprite, get_inv_pos(win->inv));
                    actual_pos = get_actual_pos_inv(win->inv, get_pos_float(0, 0));
                    win->inv->items[actual_pos].busy = 1;
                    win->inv->items[actual_pos].name = get_name_from_type(win->objects[ARMOR].type);
                    win->objects[ARMOR].item = 1;
                    win->objects[ARMOR].depth = 2;
                    display_text_in_textbox(win->quests, "Vous avez trouve une Armure !\n");
                    win->quests->quete_done++;
                }
            } else if (is_inside_zone(get_pos_float(550, 700), get_pos_float(600, 780), pos_player) == 0) {
                sfText_setString(win->text->str, "\n");
            }
        }
    }
}

void check_item_pickup(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (win->actual_page == TOWN) {
        if (win->quests->quete_done == 0)
            talk_to_old(win, pos_player);
        if (win->quests->quete_done == 1)
            check_pickup_sword(win, pos_player);
    }
    if (win->actual_page == FOREST) {
        if (win->quests->quete_done == 2)
            check_pickup_armor(win, pos_player);
    }
}

void set_text_inv(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f move_pos = get_pos_float(click_pos.x, click_pos.y);
    int ok = 0;
    char *str = win->player->name;
    
    for (int i = 0; i < 15; i++) {
        if (move_pos.x >= win->inv->items[i].pos.x - 10 && move_pos.x < win->inv->items[i].pos.x + 80) {
            if (move_pos.y >= win->inv->items[i].pos.y - 10 && move_pos.y < win->inv->items[i].pos.y + 80) {
                ok = 1;
                sfText_setString(win->inv->text, win->inv->items[i].name);
            }
        }
    }
    if (ok == 0) {
        str = my_strcat(str, "\n");
        str = my_strcat(str, "Vie: ");
        str = my_strcat(str, my_itc(win->player->health));
        str = my_strcat(str, "\n");
        str = my_strcat(str, "Puissance: ");
        str = my_strcat(str, my_itc(win->player->strength));
        str = my_strcat(str, "\n");
        sfText_setString(win->inv->text, str);
    }
}

void global_event(window_t *win)
{
    if (win->event.type == sfEvtClosed)
        quit(win);
    if (win->event.type == sfEvtKeyPressed) {
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT)
            check_keyboard_input_ingame(win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
            if (win->actual_page == MAINMENU)
                quit(win);
            if (win->actual_page >= CASTLE && win->actual_page < COMBAT) {
                if (win->pause == 0 && win->inventory == 0 && win->quest == 0)
                    pause_game(win);
                else if (win->inventory == 0 && win->quest == 0 && win->pause == 1)
                    unpause_game(win);
            }
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (win->actual_page == OPTIONS)
            drag_button(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT && win->inventory == 1)
            drag_and_drop_inv(win);
    }
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased) {
        mouse_released_event(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT && win->inventory == 1)
            check_drag_and_drop_inv(win);
    }
    if (win->event.type == sfEvtMouseMoved) {
        mouse_moved_event(win);
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT && win->inventory == 1)
            set_text_inv(win);
    }
}