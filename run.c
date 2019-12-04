/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game loop
*/

#include "my_sokoban.h"

static const char *resize_msg_g = "Please, increase the size of the terminal.";
static const int len_r_msg_g = 42;

void display_map(map_t *map)
{
    clear();
    if (LINES < map->max_height || COLS < map->max_width) {
        mvprintw((LINES / 2), (COLS / 2) - (len_r_msg_g / 2), resize_msg_g);
        refresh();
        return;
    }
    for (int i = 0; i < map->size; i++) {
        if (is_object_pos(dst, map->box_pos, map->nb_box))
            addch('X');
        else if (is_object_pos(dst, map->storage_pos, map->nb_storage))
            addch('O');
        else
            addch(map->map[i]);
    }
    printw(map->map);
    refresh();
}

int get_user_cmd(map_t *map)
{
    int c = 0;

    while (1) {
        if (LINES < map->max_height || COLS < map->max_width)
            display_map(map);
        c = getch();
        if (c == KEY_SPACE)
            return EXIT_RELOAD;
        if (c == KEY_DOWN || c == KEY_UP || c == KEY_LEFT || c == KEY_RIGHT)
            return c;
    }
}

int run(map_t *map)
{
    int key;
    int ret = -1;

    initscr();
    while (ret != EXIT_RELOAD && ret != EXIT_SUCCESS) {
        display_map(map);
        key = get_user_cmd(map);
        //player_check_and_move(map, key);
        if (key == EXIT_RELOAD)
            ret = EXIT_RELOAD;
    }
    endwin();
    return 0;
}
