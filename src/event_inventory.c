/*
** event_inventory.c for event in /home/wloic/repos/MUL_my_rpg_2018/src
**
** Made by loic.weiss@epitech.eu
** Login   <loic>
**
** Started on  Thu May 2 19:51:12 2019 loic.weiss@epitech.eu
** Last update Fri May 2 19:51:26 2019 loic.weiss@epitech.eu
*/

void global_event_condition_escape(window_t *win)
{
    if (win->actual_page == MAINMENU)
        quit(win);
    if (win->actual_page >= CASTLE && win->actual_page < COMBAT) {
        if (win->pause == 0 && win->inventory == 0 && win->quest == 0)
            pause_game(win);
        else if (win->inventory == 0 && win->quest == 0 &&
        win->talking == 0 && win->pause == 1) {
            unpause_game(win);
        }
        if (win->quest == 0 && win->pause == 1 && win->inventory == 1)
            close_inventory(win);
    }
}

void global_event(window_t *win)
{
    if (win->event.type == sfEvtClosed)
        quit(win);
    if (win->event.type == sfEvtKeyPressed) {
        if (win->actual_page >= CASTLE && win->actual_page < COMBAT)
            check_keyboard_input_ingame(win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            global_event_condition_escape(win);
    }
    global_event_condition(win);
}