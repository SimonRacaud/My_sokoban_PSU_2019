/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** Display the game board
*/

#include "my_sokoban.h"

static const char *RESIZE_MSG = "Please, increase the size of the terminal.";
static const int RESIZE_MSG_LEN = 42;

static void display_char(char ca, char cb, int color)
{
    attron(A_BOLD);
    attron(COLOR_PAIR(color));
    addch(ca);
    addch(cb);
    attroff(COLOR_PAIR(color));
    attroff(A_BOLD);
}

static int check_size_terminal(map_t *map)
{
    if (LINES <= map->max_height || COLS <= map->max_width) {
        printw("%d %d - %d %d", LINES, COLS, map->max_width, map->max_height);
        mvprintw((LINES / 2), (COLS / 2) - (RESIZE_MSG_LEN / 2), RESIZE_MSG);
        refresh();
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

void display_map(map_t *map)
{
    clear();
    if (check_size_terminal(map) == EXIT_ERROR)
        return;
    for (int i = 0; i < map->size - 1; i++) {
        if (is_box_pos(i, map->box_pos, map->nb_box)) {
            display_char('[', ']', BOX_PAIR);
        } else if (i == map->player_pos) {
            display_char('o', 'o', PLAYER_PAIR);
        } else {
            if (map->map[i] == '#') {
                display_char(' ', ' ', WALL_PAIR);
            } else if (map->map[i] == 'O')
                display_char('_', '_', STORAGE_PAIR);
            if (map->map[i] == ' ') {
                display_char('.', '.', EMPTY_PAIR);
            } else if (map->map[i] == '\n')
                addch(map->map[i]);
        }
    }
    refresh();
}
