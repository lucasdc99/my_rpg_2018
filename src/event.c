/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event
*/

#include "../include/rpg.h"
#include "../include/my.h"

void mouse_pressed_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].shape;
        if (button_is_clicked(win->scene[win->actual_page].button[i],
        click_pos)) {
            sfRectangleShape_setTextureRect(rect, win->scene[win->actual_page].button[i].rect_pressed);
        }
    }
}

void mouse_released_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].shape;
        if (button_is_clicked(win->scene[win->actual_page].button[i], click_pos)) {
            sfRectangleShape_setTextureRect(rect, win->scene[win->actual_page].button[i].rect_idle);
            if (win->scene[win->actual_page].button[i].callback != NULL)
                win->scene[win->actual_page].button[i].callback(win);
        }
    }
}

void mouse_moved_event(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    sfRectangleShape *rect;

    for (int i = 0; i < win->scene[win->actual_page].nb_button; i++) {
        rect = win->scene[win->actual_page].button[i].shape;
        if (button_is_hovered(win->scene[win->actual_page].button[i],
        click_pos)) {
            sfRectangleShape_setTextureRect(rect, win->scene[win->actual_page].button[i].rect_hovered);
        } else {
            sfRectangleShape_setTextureRect(rect, win->scene[win->actual_page].button[i].rect_idle);
        }
    }
}

int check_dead_zone(window_t *win, int move)
{
    static char **tab_castle = NULL;
    static char **tab_town = NULL;
    char **tab = NULL;
    char *buffer_castle = NULL;
    char *buffer_town = NULL;
    sfVector2u size_win = sfRenderWindow_getSize(win->window);
    sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);
    int scalex = size_win.x / 30;
    int scaley = size_win.y / 30;
    int x = pos.x / 30;
    int y = pos.y / 30;

    if (tab_town == NULL || tab_castle == NULL) {
        buffer_castle = get_buffer("ressources/text/pos_castle");
        buffer_town = get_buffer("ressources/text/pos_house");
        if (buffer_town == NULL || buffer_castle == NULL)
            return (84);
        tab_castle = transform_2d(buffer_castle, '\n');
        tab_town = transform_2d(buffer_town, '\n');
        if (tab_castle == NULL || tab_town == NULL)
            return (84);
    }
    if (win->actual_page == GAME)
        tab = tab_castle;
    if (win->actual_page == HOUSE)
        tab = tab_town;
    if (move == UP) {
        if (y - 1 >= 0 && tab[y - 1][x] == '2') {
            return (1);
        }
    }
    if (move == LEFT) {
        if (x - 1 >= 0 && tab[y][x - 1] == '2')
            return (1);
    }
    if (move == DOWN) {
        if (y + 1 < scaley - 1 && tab[y + 1][x] == '2')
            return (1);
    }
    if (move == RIGHT) {
        if (x + 1 < scalex - 2 && tab[y][x + 1] == '2')
            return (1);
    }
    return (0);
}

void move_player_up(window_t *win)
{
    if (check_dead_zone(win, UP) == 1) {
        if (win->player->direction != UP) {
            if (win->player->direction == DOWN)
                win->player->speed.y -= 5;
            if (win->player->direction == LEFT)
                win->player->speed.x += 5;
            if (win->player->direction == RIGHT)
                win->player->speed.x -= 5;
            win->player->direction = UP;
            win->player->sprite->rect.left = 15;
        }
        win->player->move_rect++;
        sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);
        pos.y -= 5;
        sfSprite_setPosition(win->player->sprite->sprite, pos);
        win->player->sprite->rect.top = 159;
        if (win->player->sprite->rect.left > 111)
            win->player->sprite->rect.left = 15;
        sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
        if ((win->player->move_rect % 5) == 0)
            win->player->sprite->rect.left += 48;
    }
}

void move_player_down(window_t *win)
{
    if (check_dead_zone(win, DOWN) == 1) {
        if (win->player->direction != DOWN) {
            if (win->player->direction == UP)
                win->player->speed.y += 5;
            if (win->player->direction == LEFT)
                win->player->speed.x += 5;
            if (win->player->direction == RIGHT)
                win->player->speed.x -= 5;
            win->player->direction = DOWN;
            win->player->sprite->rect.left = 15;
        }
        win->player->move_rect++;
        sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);        
        pos.y += 5;
        sfSprite_setPosition(win->player->sprite->sprite, pos);
        win->player->sprite->rect.top = 15;
        if (win->player->sprite->rect.left > 111)
            win->player->sprite->rect.left = 15;
        sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
        if ((win->player->move_rect % 5) == 0)
            win->player->sprite->rect.left += 48;
    }
}

void move_player_left(window_t *win)
{
    if (check_dead_zone(win, LEFT) == 1) {
        if (win->player->direction != LEFT) {
            if (win->player->direction == RIGHT)
                win->player->speed.x -= 5;
            if (win->player->direction == UP)
                win->player->speed.y += 5;
            if (win->player->direction == DOWN)
                win->player->speed.y -= 5;
            win->player->direction = LEFT;
            win->player->sprite->rect.left = 15;
        }
        win->player->move_rect++;
        sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);        
        pos.x -= 5;
        sfSprite_setPosition(win->player->sprite->sprite, pos);
        win->player->sprite->rect.top = 62;
        if (win->player->sprite->rect.left > 111)
            win->player->sprite->rect.left = 15;
        sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
        if ((win->player->move_rect % 5) == 0)
            win->player->sprite->rect.left += 48;
    }
}

void move_player_right(window_t *win)
{
    if (check_dead_zone(win, RIGHT) == 1) {
        if (win->player->direction != RIGHT) {
            if (win->player->direction == LEFT)
                win->player->speed.x += 5;
            if (win->player->direction == UP)
                win->player->speed.y += 5;
            if (win->player->direction == DOWN)
                win->player->speed.y -= 5;
            win->player->direction = RIGHT;
            win->player->sprite->rect.left = 15;
        }
        win->player->move_rect++;
        sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);        
        pos.x += 5;
        sfSprite_setPosition(win->player->sprite->sprite, pos);
        win->player->sprite->rect.top = 110;
        if (win->player->sprite->rect.left > 111)
            win->player->sprite->rect.left = 15;
        sfSprite_setTextureRect(win->player->sprite->sprite, win->player->sprite->rect);
        if ((win->player->move_rect % 5) == 0)
            win->player->sprite->rect.left += 48;
    }
}

void move_player(window_t *win)
{   
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue || sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        move_player_up(win);
    else if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue || sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        move_player_left(win);
    else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue || sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
        move_player_down(win);
    else if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue || sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        move_player_right(win);
}

void check_interaction(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (pos_player.x > 825 && pos_player.x < 1030) {
        if (pos_player.y < 360) {
            win->player->last_pos = sfSprite_getPosition(win->player->sprite->sprite);
            win->player->last_pos.y += 30;
            sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(900, 950));
            win->page = HOUSE;
        }
    }
}

void drag_button(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    int get_pos_volume = 800;

    win->music->vol_drag_posx = click_pos.x;
    float diff_between_volume = win->music->vol_drag_posx - get_pos_volume; 
    char *str = malloc(sizeof(char) * 5);

    sfVector2f get_pos_four = sfRectangleShape_getPosition(win->scene[OPTIONS].button[4].shape);
    sfVector2f get_size_four = sfRectangleShape_getSize(win->scene[OPTIONS].button[4].shape);


    if (win->page == OPTIONS && click_pos.x > get_pos_four.x && click_pos.x < get_pos_four.x + get_size_four.x &&
        click_pos.y > get_pos_four.y && click_pos.y < get_pos_four.y + get_size_four.y) {
        if (win->music->vol_drag_posx >= VALUE_FIRST && win->music->vol_drag_posx <= 1056) {
            win->music->volume = (diff_between_volume + (get_pos_volume - VALUE_FIRST)) * 0.264;
            sfMusic_setVolume(win->music->menu_song, win->music->volume);
            sfMusic_setVolume(win->music->button_sound, win->music->volume);
            str = my_itc(win->music->volume);
            str = my_strcat(str, "%");
            sfText_setString(win->scene[OPTIONS].text[4].str, str);
            win->music->vol_drag_posx = click_pos.x - get_size_four.x / 2;
            sfRectangleShape_setPosition(win->scene[OPTIONS].button[4].shape, get_pos_float(win->music->vol_drag_posx, 800 - 250));
        }
    }
}

void check_out(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (pos_player.x >= 820 && pos_player.x < 1050) {
        if (pos_player.y >= 955) {
            win->page = GAME;
            sfSprite_setPosition(win->player->sprite->sprite, get_pos_float(900, 380));
        }
    }
}

void open_inventory(window_t *win)
{
    win->pause = 1;
    win->inventory = 1;
    if (win->actual_page == GAME)
        sfSprite_setPosition(win->scene[GAME].sprite[1].sprite, get_pos_float(1200, 150));
    if (win->actual_page == HOUSE)
        sfSprite_setPosition(win->scene[HOUSE].sprite[0].sprite, get_pos_float(1200, 150));
    if (win->player->items->sword == 1)
        sfSprite_setPosition(win->scene[GAME].sprite[2].sprite, get_pos_float(1280, 370));
}

void close_inventory(window_t *win)
{
    win->pause = 0;
    win->inventory = 0;
    if (win->actual_page == GAME)
        sfSprite_setPosition(win->scene[GAME].sprite[1].sprite, get_pos_float(-600, -600));
    if (win->actual_page == HOUSE)
        sfSprite_setPosition(win->scene[HOUSE].sprite[0].sprite, get_pos_float(-600, -600));
    if (win->player->items->sword == 1)
        sfSprite_setPosition(win->scene[GAME].sprite[2].sprite, get_pos_float(-400, -400));
}

void open_quests_menu(window_t *win)
{
    printf("quests\n");
}

void open_characteristics(window_t *win)
{
    printf("chars\n");
}

void pause_game(window_t *win)
{
    sfVector2f size = get_pos_float(400, 100);
    sfVector2u size_window = sfRenderWindow_getSize(win->window);
    sfVector2f pos_window;
    pos_window.x = (size_window.x - size.x) / 2;
    pos_window.y = (size_window.y - size.y) / 4;
    win->pause = 1;
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape, get_pos_float(pos_window.x, pos_window.y));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape, get_pos_float(pos_window.x, pos_window.y + 200));
}

void unpause_game(window_t *win)
{
    win->pause = 0;
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[0].shape, get_pos_float(-600, -300));
    sfRectangleShape_setPosition(win->scene[win->actual_page].button[1].shape, get_pos_float(-600, -100));
}

void check_keyboard_input_ingame(window_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        if (win->inventory == 0)
            open_inventory(win);
        else if (win->inventory == 1)
            close_inventory(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        open_quests_menu(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyC)) {
        open_characteristics(win);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        check_item_pickup(win);
    }
}

void check_item_pickup(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);
    sfVector2f pos_element = sfSprite_getPosition(win->scene[GAME].sprite[2].sprite);

    printf("(%f%f)", pos_element.x, pos_element.y);
    if (pos_player.x > pos_element.x - 60 && pos_player.x <= pos_element.x + 30) {
        if (pos_player.y >= pos_element.y - 60 && pos_player.y <= pos_element.y + 20) {
            sfSprite_setPosition(win->scene[GAME].sprite[2].sprite, get_pos_float(-400, -400));
            win->player->items->sword = 1;
        }
    }
}

void global_event(window_t *win)
{

    if (win->event.type == sfEvtClosed)
        quit(win);
    if (win->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
            if (win->actual_page == MAINMENU)
                quit(win);
            if (win->actual_page == GAME || win->actual_page == HOUSE) {
                if (win->pause == 0)
                    pause_game(win);
                else if (win->pause == 1)
                    unpause_game(win);
            }
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (win->actual_page == OPTIONS)
            drag_button(win);
    }
    if (win->event.type == sfEvtMouseButtonPressed)
        mouse_pressed_event(win);
    if (win->event.type == sfEvtMouseButtonReleased)
        mouse_released_event(win);
    if (win->event.type == sfEvtMouseMoved)
        mouse_moved_event(win);
    if (win->event.type == sfEvtKeyPressed)
        if (win->actual_page == GAME || win->actual_page == HOUSE)
            check_keyboard_input_ingame(win);
}