/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game loop
*/

#include "my_sokoban.h"

int get_user_cmd(map_t *map)
{
    int c = 0;

    while (1) {
        display_map(map);
        c = getch();
        if (c == KEY_SPACE) {
            return EXIT_RELOAD;
        } else if (c == K_DOWN || c == K_UP || c == K_LEFT || c == K_RIGHT) {
            return c;
        }
    }
}

int my_init_color(void)
{
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        return EXIT_ERROR;
    }
    start_color();
    init_pair(EMPTY_PAIR, COLOR_BLACK, COLOR_BLACK);
    init_pair(WALL_PAIR, COLOR_WHITE, COLOR_WHITE);
    init_pair(PLAYER_PAIR, COLOR_WHITE, COLOR_RED);
    init_pair(BOX_PAIR, COLOR_WHITE, COLOR_CYAN);
    init_pair(STORAGE_PAIR, COLOR_WHITE, COLOR_BLUE);
    return EXIT_SUCCESS;
}

static int init_game(map_t *map)
{
    initscr();
    if (my_init_color() == EXIT_ERROR)
        return EXIT_ERROR;
    display_map(map);
    return EXIT_SUCCESS;
}

int run(map_t *map)
{
    int key;
    int ret = EXIT_SUCCESS;

    if (init_game(map) == EXIT_ERROR)
        return EXIT_ERROR;
    while (ret == EXIT_SUCCESS) {
        key = get_user_cmd(map);
        ret = player_check_and_move(map, key);
        if (ret == EXIT_FAIL || ret == EXIT_WIN) {
            display_map(map);
        } else if (key == EXIT_RELOAD)
            ret = EXIT_RELOAD;
    }
    endwin();
    if (ret == EXIT_WIN)
        ret = EXIT_SUCCESS;
    return ret;
}
