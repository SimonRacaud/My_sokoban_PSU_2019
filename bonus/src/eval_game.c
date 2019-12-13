/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** eval the game : end game
*/

#include "my_sokoban.h"

static int check_deadlock_box(map_t *map, int pos_box)
{
    int line_box = get_line(map, pos_box);
    int width = get_width_line(map, line_box);
    int have_wall_h = 0;
    int have_wall_v = 0;

    if (map->map[pos_box - 1] == '#' || map->map[pos_box + 1] == '#') {
        have_wall_h = 1;
    } else if (map->map[pos_box - 1] == 'X' || map->map[pos_box + 1] == 'X') {
        have_wall_h = 1;
    }
    if (map->map[pos_box - width] == '#' || map->map[pos_box + width] == '#')
        have_wall_v = 1;
    if (map->map[pos_box - width] == 'X' || map->map[pos_box + width] == 'X')
        have_wall_v = 1;
    if (have_wall_h && have_wall_v)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

int check_deadlock(map_t *map)
{
    int nb_fail = 0;

    for (int i = 0; i < map->nb_box; i++) {
        nb_fail += check_deadlock_box(map, map->box_pos[i]);
    }
    if (nb_fail == map->nb_box)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

int eval_game(map_t *map)
{
    for (int i = 0; i < map->nb_box; i++) {
        if (map->map[map->box_pos[i]] == 'O' && i == (map->nb_box - 1)) {
            return EXIT_WIN;
        } else if (map->map[map->box_pos[i]] != 'O')
            break;
    }
    return EXIT_SUCCESS;
}
