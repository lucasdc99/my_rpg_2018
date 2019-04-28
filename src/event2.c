/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** event2
*/

#include "../include/rpg.h"
#include "../include/my.h"

int open_buff(char *filename, char **buffer, int size)
{
    int fd = open(filename, O_RDONLY);

    if (fd < 0)
        return (84);
    if (read(fd, buffer[0], size) <= 0)
        return (84);
    buffer[0][size - 1] = '\0';
    close(fd);
    return (0);
}

int check_dead_zone(window_t *win, int move)
{
    static char **tab_castle = NULL;
    static char **tab_town = NULL;
    static char **tab_house1 = NULL;
    static char **tab_house2 = NULL;
    static char **tab_house3 = NULL;
    static char **tab_forest = NULL;
    static char **tab_final = NULL;
    static char **tab_boss = NULL;
    char **tab = NULL;
    sfVector2u size_win = sfRenderWindow_getSize(win->window);
    sfVector2f pos = sfSprite_getPosition(win->player->sprite->sprite);
    int scalex = size_win.x / 16;
    int scaley = size_win.y / 15;
    int x = pos.x / 16;
    int y = pos.y / 15;
    char *buffer_castle = malloc(sizeof(char) * 8400);
    char *buffer_town = malloc(sizeof(char) * 8400);
    char *buffer_house1 = malloc(sizeof(char) * 8400);
    char *buffer_house2 = malloc(sizeof(char) * 8400);
    char *buffer_house3 = malloc(sizeof(char) * 8400);
    char *buffer_forest = malloc(sizeof(char) * 8400);
    char *buffer_final = malloc(sizeof(char) * 8400);
    char *buffer_boss = malloc(sizeof(char) * 8400);

    if (tab_town == NULL || tab_castle == NULL || tab_house1 == NULL || tab_house2 == NULL || tab_house3 == NULL || tab_forest == NULL || tab_final == NULL || tab_boss == NULL) {
        if (open_buff("ressources/text/pos_castle", &buffer_castle, 8400) == 84)
            return (84);
        if (open_buff("ressources/text/pos_town", &buffer_town, 8400) == 84)
            return (84);
        if (open_buff("ressources/text/pos_house1", &buffer_house1, 8400) == 84)
            return (84);
        if (open_buff("ressources/text/pos_house2", &buffer_house2, 8400) == 84)
            return (84);
        if (open_buff("ressources/text/pos_house3", &buffer_house3, 8400) == 84)
            return (84);
        if (open_buff("ressources/text/pos_forest", &buffer_forest, 8400) == 84)
            return (84);
        if (open_buff("ressources/text/pos_final", &buffer_final, 8400) == 84)
            return (84);
        if (open_buff("ressources/text/pos_boss", &buffer_boss, 8400) == 84)
            return (84);
        if (buffer_town == NULL || buffer_castle == NULL || buffer_house1 == NULL || buffer_house2 == NULL || buffer_house3 == NULL || buffer_forest == NULL || buffer_final == NULL || buffer_boss == NULL)
            return (84);
        tab_castle = transform_2d(buffer_castle, '\n');
        tab_town = transform_2d(buffer_town, '\n');
        tab_house1 = transform_2d(buffer_house1, '\n');
        tab_house2 = transform_2d(buffer_house2, '\n');
        tab_house3 = transform_2d(buffer_house3, '\n');
        tab_forest = transform_2d(buffer_forest, '\n');
        tab_final = transform_2d(buffer_final, '\n');
        tab_boss = transform_2d(buffer_boss, '\n');
        if (tab_castle == NULL || tab_town == NULL || tab_house1 == NULL || tab_house2 == NULL || tab_house3 == NULL || tab_forest == NULL || tab_final == NULL || tab_boss)
            return (84);
    }
    if (win->actual_page == CASTLE)
        tab = tab_castle;
    if (win->actual_page == TOWN)
        tab = tab_town;
    if (win->actual_page == HOUSE1)
        tab = tab_house1;
    if (win->actual_page == HOUSE2)
        tab = tab_house2;
    if (win->actual_page == HOUSE3)
        tab = tab_house3;
    if (win->actual_page == FOREST)
        tab = tab_forest;
    if (win->actual_page == FINAL)
        tab = tab_final;
    if (win->actual_page == BOSS)
        tab = tab_boss;
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

void drag_button(window_t *win)
{
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(win->window);
    int pos_volume = 800;
    VOL_POS = click_pos.x;
    float diff = win->music->vol_posx - pos_volume; 

    sfVector2f pos = sfRectangleShape_getPosition(win->
    scene[OPTIONS].button[4].shape);
    sfVector2f size = sfRectangleShape_getSize(win->
    scene[OPTIONS].button[4].shape);
    if (win->page == OPTIONS && click_pos.x > pos.x && 
        click_pos.x < pos.x + size.x &&
        click_pos.y > pos.y && click_pos.y < pos.y + size.y) {
        if (VOL_POS >= VALUE_FIRST && VOL_POS <= 1056) {
            win->music->volume = (diff + (pos_volume - VALUE_FIRST)) * 0.264;
            change_volume_string(win);
            win->music->vol_posx = click_pos.x - size.x / 2;
            sfRectangleShape_setPosition(win->scene[OPTIONS].button[4].shape,
            get_pos_float(win->music->vol_posx, 800 - 250));
        }
    }
}

void change_volume_string(window_t *win)
{
    char *str = malloc(sizeof(char) * 5);

    sfMusic_setVolume(win->music->menu_song, win->music->volume);
    sfMusic_setVolume(win->music->button_sound, win->music->volume);
    str = my_itc(win->music->volume);
    str = my_strcat(str, "%");
    sfText_setString(win->scene[OPTIONS].text[4].str, str);
}

void get_good_move_call(window_t *win)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue ||
    sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        move_player_up(win);
    else if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue ||
    sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        move_player_left(win);
    else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue ||
    sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
        move_player_down(win);
    else if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue ||
    sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        move_player_right(win);
}

void close_door(window_t *win)
{
    sfVector2f pos_player = sfSprite_getPosition(win->player->sprite->sprite);

    if (is_inside_zone(get_pos_float(880, 750), get_pos_float(935, 850),
    pos_player) == 1) {
        sfSprite_setPosition(win->player->sprite->sprite,
        win->player->last_pos);
        win->page = TOWN;
    }
}