/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game loop
*/

#include "my_sokoban.h"

void display_map(map_t *map)
{
    printw(map->map);
    refresh();
}

int get_user_cmd()
{
    int c = 0;

    while (c != 410) {
        c = getch();
        refresh();
        if (c == KEY_SPACE)
            return EXIT_RELOAD;
    }
}

void player_check_and_move(map_t *map)
{

}

void player_move()
{

}

void eval_game()
{

}

int run(map_t *map)
{
    int c;
    int ret = -1;

    initscr();
    while (ret != EXIT_RELOAD && ret != EXIT_SUCCESS) {
        display_map(map);
        c = get_user_cmd();
        player_check_and_move(map);
        if (c == EXIT_RELOAD)
            ret = EXIT_RELOAD;
    }
    endwin();
    return 0;
}
